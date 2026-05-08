#include "gamescene.h"
#include "player.h"
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QLabel>

 bool GameScene::gameRunning=false;

GameScene::GameScene(QWidget *parent)
    : QWidget{parent}
{
    //设置背景图
    this->setAttribute(Qt::WA_StyledBackground,true);
    this->setStyleSheet(
        "GameScene {"
        "background-image:url(:/image/gamescene.jpg);"
        "background-repeat:no-repeat;"
        "background-position:center;"
        "background-attachment:fixed;"
        "}"
        );
    //设置返回按钮
    backButton=new QPushButton("返回",this);
    backButton->setFixedSize(75,50);
    backButton->setStyleSheet(
        "QPushButton {"
        "color:black;"
        "background-color:rgba(255,255,255,200);"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        "}"
        "QPushButton:hover {"
        "background-color:rgba(255,255,255,150);"
        "}"
        );
    backButton->setFocusPolicy(Qt::NoFocus);
    //设置暂停按钮
    pauseButton=new QPushButton("暂停" ,this);
    pauseButton->setFixedSize(75,50);
    pauseButton->setStyleSheet(
        "QPushButton {"
        "color:black;"
        "background-color:rgba(255,255,255,200);"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        "}"
        "QPushButton:hover {"
        "background-color:rgba(255,255,255,150);"
        "}"
        );
    pauseButton->setFocusPolicy(Qt::NoFocus);
    //设置计分板
    scoreboard=new QLabel(this);
    scoreboard->setText("当前分数：" +QString::number(score));
    scoreboard->setAlignment(Qt::AlignCenter);
    scoreboard->setFixedSize(200,50);
    scoreboard->setStyleSheet(
        "color:red;"
        "background-color:white;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    //设置地面
    ground=new QFrame(this);
    ground->setFrameShape(QFrame::Box);
    ground->setFrameShadow(QFrame::Plain);
    ground->setLineWidth(1);
    ground->setFixedHeight(150);
    ground->setStyleSheet(
        "background-color:green；"
        );

    player=new Player(this);
    player->setFocus();
    player->show();

    //设置页面布局
    mainlayout=new QVBoxLayout(this);

    toplayout=new QHBoxLayout(this);

    toplayout->setContentsMargins(20,20,20,20);
    toplayout->addWidget(backButton,0,Qt::AlignLeft|Qt::AlignTop);
    toplayout->addStretch();
    toplayout->addWidget(scoreboard,0,Qt::AlignTop);
    toplayout->addStretch();
    toplayout->addWidget(pauseButton,0,Qt::AlignRight|Qt::AlignTop);

    mainlayout->setContentsMargins(0,0,0,0);
    mainlayout->addLayout(toplayout);
    mainlayout->addStretch();
    mainlayout->addWidget(ground);

    this->setLayout(mainlayout);
    //发出返回主界面和暂停信号
    connect(backButton,&QPushButton::clicked,this,&GameScene::onBackButtonClicked);
    connect(pauseButton,&QPushButton::clicked,this,&GameScene::onPauseButtonClicked);

    //设置计时器
    gametimer=new QTimer(this);
    connect(gametimer,&QTimer::timeout,this,&GameScene::updateTime);
    gametimer->start(32);

    scoretimer=new QTimer(this);
    connect(scoretimer,&QTimer::timeout,this,&GameScene::updateScore);
    scoretimer->start(1500);
}
//使玩家随窗口大小变化始终处于地面上
void GameScene::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    playerY=this->height()-groundH-player->height();
    player->move(100,playerY);
}
void GameScene::onBackButtonClicked(){
    emit backClicked();
    gameRunning=false;
}
void GameScene::onPauseButtonClicked(){
    emit pauseClicked();
    gameRunning=false;
}
void GameScene::updateTime(){
    if(gameRunning==true){
    player->Player::fall();
    }
}
void GameScene::updateScore(){
    if(gameRunning==true){
    score+=1;
    scoreboard->setText("当前分数："+QString::number(score));
    }
}

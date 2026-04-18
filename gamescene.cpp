#include "gamescene.h"
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

GameScene::GameScene(QWidget *parent)
    : QWidget{parent}
{
    backButton=new QPushButton("返回",this);
    backButton->setFixedSize(75,50);
    backButton->setStyleSheet(
        "color:red;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );
    //设置暂停按钮
    pauseButton=new QPushButton("暂停" ,this);
    pauseButton->setFixedSize(75,50);
    pauseButton->setStyleSheet(
        "color:red;"
        "background-color:yellow;"
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

    player=new QLabel(this);
    player->setFixedSize(50,80);
    player->setStyleSheet(
        "background-color:white;"
        );

    //设置页面布局
    mainlayout=new QVBoxLayout(this);

    toplayout=new QHBoxLayout(this);

    toplayout->setContentsMargins(20,20,20,20);
    toplayout->addWidget(backButton,0,Qt::AlignLeft|Qt::AlignTop);
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
}
void GameScene::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    groundH=150;
    playerY=this->height()-groundH-player->height();
    player->move(100,playerY);
}
void GameScene::onBackButtonClicked(){
    emit backClicked();
}
void GameScene::onPauseButtonClicked(){
    emit pauseClicked();
}
#include "startscene.h"
#include "gamescene.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>


StartScene::StartScene(QWidget *parent)
    : QWidget{parent}
{
    //设置背景图
    setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet(
        "StartScene {"
        "background-image: url(:/image/startscene.jpg);"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "background-attachment: fixed;"
        "}"
        );
    this->update();
    //设置游戏标题
    titleLabel=new QLabel("Rushing  Goose",this);
    titleLabel->setFixedSize(300,80);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "color:red;"
        "background-color:rgba(255,255,255,200);"
        "font-size:36px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );
    //设置“开始游戏”按钮
    startButton=new QPushButton("开始游戏",this);
    startButton->setFixedSize(150,50);
    startButton->setStyleSheet(
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
    //设置“退出游戏”按钮
    quitButton=new QPushButton("退出游戏",this);
    quitButton->setFixedSize(150,50);
    quitButton->setStyleSheet(
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
    //设置页面布局
    layout=new QVBoxLayout(this);
    layout->addStretch(2);
    layout->addWidget(titleLabel,0,Qt::AlignHCenter);
    layout->addStretch(2);
    layout->addWidget(startButton,0,Qt::AlignHCenter);
    layout->addStretch(1);
    layout->addWidget(quitButton,0,Qt::AlignHCenter);
    layout->addStretch(2);

    this->setLayout(layout);

    //发出开始游戏和退出游戏的信号
    connect(startButton,&QPushButton::clicked,this,&StartScene::onStartButtonClicked);
    connect(quitButton,&QPushButton::clicked,this,&QApplication::quit);

}

void StartScene::onStartButtonClicked()
{
    emit startGameClicked();
    GameScene::gameRunning=true;
}


#include "gamescene.h"
#include <QLabel>

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

GameScene::GameScene(QWidget *parent)
    : QWidget{parent}
{
    waitingScene=new QLabel("游戏内容待开发……",this);

    waitingScene->setFixedSize(350,80);
    waitingScene->setAlignment(Qt::AlignCenter);
    waitingScene->setStyleSheet(
        "color:black;"
        "background-color:gray;"
        "font-size:36px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    backButton=new QPushButton("返回",this);

    backButton->setFixedSize(75,50);
    backButton->setStyleSheet(
        "color:red;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    pauseButton=new QPushButton("暂停" ,this);

    pauseButton->setFixedSize(75,50);
    pauseButton->setStyleSheet(
        "color:red;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    mainlayout=new QVBoxLayout(this);

    toplayout=new QHBoxLayout(this);

    toplayout->setContentsMargins(20,20,20,20);
    toplayout->addWidget(backButton,0,Qt::AlignLeft|Qt::AlignTop);
    toplayout->addStretch();
    toplayout->addWidget(pauseButton,0,Qt::AlignRight|Qt::AlignTop);

    mainlayout->addLayout(toplayout);
    mainlayout->addStretch();
    mainlayout->addWidget(waitingScene,0,Qt::AlignHCenter);
    mainlayout->addStretch();

    connect(backButton,&QPushButton::clicked,this,&GameScene::onBackButtonClicked);
    connect(pauseButton,&QPushButton::clicked,this,&GameScene::onPauseButtonClicked);

}
void GameScene::onBackButtonClicked(){
    emit backClicked();
}
void GameScene::onPauseButtonClicked(){
    emit pauseClicked();
}
#include "pausescene.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

PauseScene::PauseScene(QWidget *parent)
    : QWidget{parent}
{
    pauseLabel=new QLabel("游戏暂停",this);
    pauseLabel->setFixedSize(300,80);
    pauseLabel->setAlignment(Qt::AlignCenter);
    pauseLabel->setStyleSheet(
        "color:red;"
        "background-color:yellow;"
        "font-size:36px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    backButton=new QPushButton("返回游戏",this);
    backButton->setFixedSize(125,50);
    backButton->setStyleSheet(
        "color:black;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    quitButton=new QPushButton("退出游戏",this);
    quitButton->setFixedSize(125,50);
    quitButton->setStyleSheet(
        "color:black;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    mainlayout=new QVBoxLayout(this);
    mainlayout->setContentsMargins(200,0,200,0);
    mainlayout->addStretch(1);
    mainlayout->addWidget(pauseLabel,0,Qt::AlignHCenter|Qt::AlignTop);
    mainlayout->addStretch(4);

    bottomlayout=new QHBoxLayout(this);
    bottomlayout->addWidget(backButton,0,Qt::AlignBottom);
    bottomlayout->addWidget(quitButton,0,Qt::AlignBottom);

    mainlayout->addLayout(bottomlayout);
    mainlayout->addStretch(1);

    connect(backButton,&QPushButton::clicked,this,&PauseScene::onBackButtonClicked);
    connect(quitButton,&QPushButton::clicked,this,&PauseScene::onQuitButtonClicked);

}
void PauseScene::onBackButtonClicked(){
    emit backClicked();
}
void PauseScene::onQuitButtonClicked(){
    emit quitClicked();
}

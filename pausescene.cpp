#include "pausescene.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

PauseScene::PauseScene(QWidget *parent)
    : QWidget{parent}
{
    //设置暂停标题
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
    //设置返回按钮
    continueButton=new QPushButton("继续游戏",this);
    continueButton->setFixedSize(125,50);
    continueButton->setStyleSheet(
        "color:black;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );
    //设置退出按钮
    quitButton=new QPushButton("退出游戏",this);
    quitButton->setFixedSize(125,50);
    quitButton->setStyleSheet(
        "color:black;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );
    //设置页面布局
    mainlayout=new QVBoxLayout(this);
    mainlayout->setContentsMargins(200,0,200,0);
    mainlayout->addStretch(1);
    mainlayout->addWidget(pauseLabel,0,Qt::AlignHCenter|Qt::AlignTop);
    mainlayout->addStretch(4);

    bottomlayout=new QHBoxLayout(this);
    bottomlayout->addWidget(continueButton,0,Qt::AlignBottom);
    bottomlayout->addWidget(quitButton,0,Qt::AlignBottom);

    mainlayout->addLayout(bottomlayout);
    mainlayout->addStretch(1);

    this->setLayout(mainlayout);
    //发出继续游戏和退出的信号
    connect(continueButton,&QPushButton::clicked,this,&PauseScene::onContinueButtonClicked);
    connect(quitButton,&QPushButton::clicked,this,&PauseScene::onQuitButtonClicked);

}
void PauseScene::onContinueButtonClicked(){
    emit continueClicked();
}
void PauseScene::onQuitButtonClicked(){
    emit quitClicked();
}

#include "gamescene.h"
#include <QLabel>

#include <QPushButton>
#include <QVBoxLayout>

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

    returnButton=new QPushButton("返回",this);

    returnButton->setFixedSize(75,50);
    returnButton->setStyleSheet(
        "color:red;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    layout=new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(waitingScene,0,Qt::AlignHCenter);
    layout->addStretch();

    connect(returnButton,&QPushButton::clicked,this,&GameScene::onReturnButtonClicked);

}
void GameScene::onReturnButtonClicked(){
    emit returnClicked();
}
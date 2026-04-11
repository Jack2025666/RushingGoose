#include "startscene.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>


StartScene::StartScene(QWidget *parent)
    : QWidget{parent}
{
    titleLabel=new QLabel("Rushing  Goose",this);

    titleLabel->setFixedSize(300,80);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "color:red;"
        "background-color:yellow;"
        "font-size:36px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    startButton=new QPushButton("开始游戏",this);
    startButton->setFixedSize(150,50);
    startButton->setStyleSheet(
        "color:black;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    quitButton=new QPushButton("退出游戏",this);
    quitButton->setFixedSize(150,50);
    quitButton->setStyleSheet(
        "color:black;"
        "background-color:yellow;"
        "font-size:18px;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    layout=new QVBoxLayout(this);
    layout->addStretch(2);
    layout->addWidget(titleLabel,0,Qt::AlignHCenter);
    layout->addStretch(2);
    layout->addWidget(startButton,0,Qt::AlignHCenter);
    layout->addStretch(1);
    layout->addWidget(quitButton,0,Qt::AlignHCenter);
    layout->addStretch(2);

    setLayout(layout);


    connect(startButton,&QPushButton::clicked,this,&StartScene::onStartButtonClicked);
    connect(quitButton,&QPushButton::clicked,this,&QApplication::quit);

}

void StartScene::onStartButtonClicked()
{
    emit startGameClicked();
}


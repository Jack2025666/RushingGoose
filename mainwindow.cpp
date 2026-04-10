#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startscene.h"
#include "gamescene.h"
#include "gameoverscene.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    StartScene *startScene=new StartScene(this);
    GameScene *gameScene=new GameScene(this);
    GameoverScene *gameoverScene=new GameoverScene(this);

    stackedWidget=new QStackedWidget(this);
    setCentralWidget(stackedWidget);
    stackedWidget->addWidget(startScene);
    stackedWidget->addWidget(gameScene);
    stackedWidget->addWidget(gameoverScene);

    connect(startScene,&StartScene::startGameClicked,this,[this](){stackedWidget->setCurrentIndex(1);});

    connect(gameScene,&GameScene::returnClicked,this,[this](){stackedWidget->setCurrentIndex(0);});

}

MainWindow::~MainWindow()
{
    delete ui;
}

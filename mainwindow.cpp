#include "mainwindow.h"
#include "startscene.h"
#include "gamescene.h"
#include "gameoverscene.h"
#include "pausescene.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Rushing Goose");
    this->resize(800,600);
    this->setMinimumSize(800,600);

    StartScene *startScene=new StartScene(this);
    GameScene *gameScene=new GameScene(this);
    GameoverScene *gameoverScene=new GameoverScene(this);
    PauseScene *pauseScece=new PauseScene(this);

    stackedWidget=new QStackedWidget(this);
    setCentralWidget(stackedWidget);
    stackedWidget->addWidget(startScene);
    stackedWidget->addWidget(gameScene);
    stackedWidget->addWidget(pauseScece);
    stackedWidget->addWidget(gameoverScene);

    connect(startScene,&StartScene::startGameClicked,this,[this](){stackedWidget->setCurrentIndex(1);});

    connect(gameScene,&GameScene::backClicked,this,[this](){stackedWidget->setCurrentIndex(0);});
    connect(gameScene,&GameScene::pauseClicked,this,[this](){stackedWidget->setCurrentIndex(2);});

    connect(pauseScece,&PauseScene::backClicked,this,[this](){stackedWidget->setCurrentIndex(1);});
    connect(pauseScece,&PauseScene::quitClicked,this,[this](){stackedWidget->setCurrentIndex(0);});
}
MainWindow::~MainWindow()
{
}

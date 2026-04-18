#include "mainwindow.h"
#include "startscene.h"
#include "gamescene.h"
#include "gameoverscene.h"
#include "pausescene.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置窗口标题和默认大小
    this->setWindowTitle("Rushing Goose");
    this->resize(800,600);
    this->setMinimumSize(800,600);
    //将页面添加到QStackedWidget
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
    //接收开始游戏信号
    connect(startScene,&StartScene::startGameClicked,this,[this](){stackedWidget->setCurrentIndex(1);});
    //接收返回主界面和暂停信号
    connect(gameScene,&GameScene::backClicked,this,[this](){stackedWidget->setCurrentIndex(0);});
    connect(gameScene,&GameScene::pauseClicked,this,[this](){stackedWidget->setCurrentIndex(2);});
    //接收继续游戏和退出游戏信号
    connect(pauseScece,&PauseScene::continueClicked,this,[this](){stackedWidget->setCurrentIndex(1);});
    connect(pauseScece,&PauseScene::quitClicked,this,[this](){stackedWidget->setCurrentIndex(0);});
}
MainWindow::~MainWindow()
{
}

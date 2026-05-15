#include "mainwindow.h"
#include "startscene.h"
#include "gamescene.h"
#include "gameoverscene.h"
#include "pausescene.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("🦢 Rushing Goose");
    this->resize(800, 600);
    this->setMinimumSize(800, 600);

    startScene = new StartScene(this);
    gameScene = new GameScene(this);
    gameoverScene = new GameoverScene(this);
    pauseScene = new PauseScene(this);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);
    stackedWidget->addWidget(startScene);
    stackedWidget->addWidget(gameScene);
    stackedWidget->addWidget(pauseScene);
    stackedWidget->addWidget(gameoverScene);

    // 开始游戏 → 设置难度 → 进入游戏
    connect(startScene, &StartScene::startGameClicked, this, [this]() {
        int diff = startScene->getSelectedDifficulty();
        gameScene->setDifficulty(diff);
        gameScene->resetGame();
        stackedWidget->setCurrentIndex(GamePage);
    });

    connect(gameScene, &GameScene::backClicked, this, [this]() {
        gameScene->resetGame();
        stackedWidget->setCurrentIndex(StartPage);
    });

    connect(gameScene, &GameScene::pauseClicked, this, [this]() {
        stackedWidget->setCurrentIndex(PausePage);
    });

    connect(pauseScene, &PauseScene::continueClicked, this, [this]() {
        GameScene::gameRunning = true;
        stackedWidget->setCurrentIndex(GamePage);
        gameScene->setFocus();
    });

    connect(pauseScene, &PauseScene::quitClicked, this, [this]() {
        gameScene->resetGame();
        stackedWidget->setCurrentIndex(StartPage);
    });

    connect(gameScene, &GameScene::gameOver, this, &MainWindow::onGameOver);

    connect(gameoverScene, &GameoverScene::restartClicked, this, &MainWindow::onRestartGame);

    connect(gameoverScene, &GameoverScene::backToMenuClicked, this, &MainWindow::onBackToMenu);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onGameOver(int finalScore)
{
    gameoverScene->setFinalScore(finalScore);
    stackedWidget->setCurrentIndex(GameoverPage);
}

void MainWindow::onRestartGame()
{
    gameScene->resetGame();
    stackedWidget->setCurrentIndex(GamePage);
}

void MainWindow::onBackToMenu()
{
    gameScene->resetGame();
    stackedWidget->setCurrentIndex(StartPage);
}

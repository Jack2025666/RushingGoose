#include "gamescene.h"
#include "player.h"
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include <QRandomGenerator>

bool GameScene::gameRunning = false;

GameScene::GameScene(QWidget *parent)
    : QWidget{parent}
{
    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet(
        "GameScene {"
        "background-image:url(:/image/gamescene.jpg);"
        "background-repeat:no-repeat;"
        "background-position:center;"
        "background-attachment:fixed;"
        "}"
        );

    backButton = new QPushButton("返回", this);
    backButton->setFixedSize(75, 50);
    backButton->setStyleSheet(
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
    backButton->setFocusPolicy(Qt::NoFocus);

    pauseButton = new QPushButton("暂停", this);
    pauseButton->setFixedSize(75, 50);
    pauseButton->setStyleSheet(
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
    pauseButton->setFocusPolicy(Qt::NoFocus);

    scoreboard = new QLabel(this);
    scoreboard->setText("分数：0");
    scoreboard->setAlignment(Qt::AlignCenter);
    scoreboard->setFixedSize(150, 50);
    scoreboard->setStyleSheet(
        "color:red;"
        "background-color:white;"
        "font-size:18px;"
        "font-weight:bold;"
        "border-radius:18px;"
        "border:1px solid black;"
        );

    // 难度显示标签
    difficultyLabel = new QLabel(this);
    difficultyLabel->setText("普通");
    difficultyLabel->setAlignment(Qt::AlignCenter);
    difficultyLabel->setFixedSize(80, 40);
    difficultyLabel->setStyleSheet(
        "color:white;"
        "background-color:#f39c12;"
        "font-size:14px;"
        "font-weight:bold;"
        "border-radius:10px;"
        );

    ground = new QFrame(this);
    ground->setFrameShape(QFrame::Box);
    ground->setFrameShadow(QFrame::Plain);
    ground->setLineWidth(1);
    ground->setFixedHeight(150);
    ground->setStyleSheet(
        "background-color: #4CAF50;"
        "border: none;"
        );

    player = new Player(this);
    player->show();

    mainlayout = new QVBoxLayout(this);
    toplayout = new QHBoxLayout(this);

    toplayout->setContentsMargins(20, 20, 20, 20);
    toplayout->addWidget(backButton, 0, Qt::AlignLeft | Qt::AlignTop);
    toplayout->addStretch();
    toplayout->addWidget(difficultyLabel, 0, Qt::AlignTop);
    toplayout->addSpacing(10);
    toplayout->addWidget(scoreboard, 0, Qt::AlignTop);
    toplayout->addStretch();
    toplayout->addWidget(pauseButton, 0, Qt::AlignRight | Qt::AlignTop);

    mainlayout->setContentsMargins(0, 0, 0, 0);
    mainlayout->addLayout(toplayout);
    mainlayout->addStretch();
    mainlayout->addWidget(ground);

    this->setLayout(mainlayout);

    connect(backButton, &QPushButton::clicked, this, &GameScene::onBackButtonClicked);
    connect(pauseButton, &QPushButton::clicked, this, &GameScene::onPauseButtonClicked);

    gametimer = new QTimer(this);
    connect(gametimer, &QTimer::timeout, this, &GameScene::updateTime);
    gametimer->start(32);

    scoretimer = new QTimer(this);
    connect(scoretimer, &QTimer::timeout, this, &GameScene::updateScore);
    scoretimer->start(1500);

    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();
}

void GameScene::setDifficulty(int diff)
{
    currentDifficulty = diff;
    switch (diff) {
    case 0:  // 简单
        baseObstacleSpeed = 5;
        baseSpawnInterval = 100;
        difficultyLabel->setText("简单");
        difficultyLabel->setStyleSheet(
            "color:white;"
            "background-color:#27ae60;"
            "font-size:14px;"
            "font-weight:bold;"
            "border-radius:10px;"
            );
        break;
    case 1:  // 普通
        baseObstacleSpeed = 8;
        baseSpawnInterval = 70;
        difficultyLabel->setText("普通");
        difficultyLabel->setStyleSheet(
            "color:white;"
            "background-color:#f39c12;"
            "font-size:14px;"
            "font-weight:bold;"
            "border-radius:10px;"
            );
        break;
    case 2:  // 困难
        baseObstacleSpeed = 12;
        baseSpawnInterval = 50;
        difficultyLabel->setText("困难");
        difficultyLabel->setStyleSheet(
            "color:white;"
            "background-color:#e74c3c;"
            "font-size:14px;"
            "font-weight:bold;"
            "border-radius:10px;"
            );
        break;
    }
    obstacleSpeed = baseObstacleSpeed;
    spawnInterval = baseSpawnInterval;
}

void GameScene::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    playerY = this->height() - groundH - player->height();
    player->move(100, playerY);
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Up) {
        player->jump();
        event->accept();
        return;
    }
    QWidget::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    QWidget::keyReleaseEvent(event);
}

void GameScene::onBackButtonClicked()
{
    emit backClicked();
    gameRunning = false;
}

void GameScene::onPauseButtonClicked()
{
    emit pauseClicked();
    gameRunning = false;
}

void GameScene::updateTime()
{
    if (!gameRunning) return;

    player->fall();

    obstacleTimer++;
    if (obstacleTimer >= spawnInterval) {
        spawnObstacle();
        obstacleTimer = 0;
        // 随时间加快，但有下限
        spawnInterval = qMax(baseSpawnInterval - 20, 30);
    }

    moveObstacles();
    checkCollision();
    cleanupObstacles();
}

void GameScene::updateScore()
{
    if (!gameRunning) return;
    score += 1;
    // 每10分加速一次
    if (score % 10 == 0) {
        obstacleSpeed = qMin(baseObstacleSpeed + 8, 20);
    }
    scoreboard->setText("分数：" + QString::number(score));
}

void GameScene::spawnObstacle()
{
    QLabel *obsLabel = new QLabel(this);
    int h = QRandomGenerator::global()->bounded(40, 101);
    obsLabel->setFixedSize(40, h);
    obsLabel->setStyleSheet(
        "background-color: #c0392b;"
        "border-radius: 5px;"
        "border: 2px solid #922b21;"
        );
    obsLabel->show();

    int groundTop = this->height() - groundH - h;
    obsLabel->move(this->width(), groundTop);

    Obstacle obs;
    obs.label = obsLabel;
    obs.speed = obstacleSpeed;
    obs.active = true;
    obstacles.append(obs);
}

void GameScene::moveObstacles()
{
    for (auto &obs : obstacles) {
        if (obs.active) {
            obs.label->move(obs.label->x() - obs.speed, obs.label->y());
        }
    }
}

void GameScene::checkCollision()
{
    QRect playerRect = player->getCollisionRect();
    for (const auto &obs : obstacles) {
        if (!obs.active) continue;
        QRect obsRect(obs.label->x() + 3, obs.label->y() + 3,
                      obs.label->width() - 6, obs.label->height() - 6);
        if (playerRect.intersects(obsRect)) {
            gameRunning = false;
            emit gameOver(score);
            return;
        }
    }
}

void GameScene::cleanupObstacles()
{
    for (int i = obstacles.size() - 1; i >= 0; --i) {
        if (obstacles[i].label->x() + obstacles[i].label->width() < 0) {
            delete obstacles[i].label;
            obstacles.removeAt(i);
        }
    }
}

void GameScene::resetGame()
{
    for (auto &obs : obstacles) {
        delete obs.label;
    }
    obstacles.clear();

    score = 0;
    scoreboard->setText("分数：" + QString::number(score));

    // 重置速度为当前难度的基础速度
    obstacleSpeed = baseObstacleSpeed;
    spawnInterval = baseSpawnInterval;
    obstacleTimer = 0;

    playerY = this->height() - groundH - player->height();
    player->resetPosition(playerY);

    gameRunning = true;
    this->setFocus();
}

#include "gameoverscene.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

GameoverScene::GameoverScene(QWidget *parent)
    : QWidget{parent}
{
    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet(
        "GameoverScene {"
        "background-color: #2c3e50;"
        "}"
        );

    titleLabel = new QLabel("游戏结束", this);
    titleLabel->setFixedSize(300, 80);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "color: #e74c3c;"
        "background-color: rgba(255,255,255,200);"
        "font-size: 36px;"
        "font-weight: bold;"
        "border-radius: 18px;"
        "border: 2px solid #e74c3c;"
        );

    scoreLabel = new QLabel("最终分数：0", this);
    scoreLabel->setFixedSize(300, 60);
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setStyleSheet(
        "color: #2c3e50;"
        "background-color: rgba(255,255,255,200);"
        "font-size: 24px;"
        "border-radius: 15px;"
        "border: 1px solid black;"
        );

    restartButton = new QPushButton("重新开始", this);
    restartButton->setFixedSize(150, 50);
    restartButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #27ae60;"
        "font-size: 18px;"
        "font-weight: bold;"
        "border-radius: 18px;"
        "border: none;"
        "}"
        "QPushButton:hover {"
        "background-color: #2ecc71;"
        "}"
        );
    restartButton->setFocusPolicy(Qt::NoFocus);

    backButton = new QPushButton("返回主界面", this);
    backButton->setFixedSize(150, 50);
    backButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #2980b9;"
        "font-size: 18px;"
        "font-weight: bold;"
        "border-radius: 18px;"
        "border: none;"
        "}"
        "QPushButton:hover {"
        "background-color: #3498db;"
        "}"
        );
    backButton->setFocusPolicy(Qt::NoFocus);

    layout = new QVBoxLayout(this);
    layout->addStretch(2);
    layout->addWidget(titleLabel, 0, Qt::AlignHCenter);
    layout->addStretch(1);
    layout->addWidget(scoreLabel, 0, Qt::AlignHCenter);
    layout->addStretch(2);
    layout->addWidget(restartButton, 0, Qt::AlignHCenter);
    layout->addStretch(1);
    layout->addWidget(backButton, 0, Qt::AlignHCenter);
    layout->addStretch(2);

    this->setLayout(layout);

    connect(restartButton, &QPushButton::clicked, this, &GameoverScene::onRestartClicked);
    connect(backButton, &QPushButton::clicked, this, &GameoverScene::onBackClicked);
}

void GameoverScene::setFinalScore(int s)
{
    finalScore = s;
    scoreLabel->setText("最终分数：" + QString::number(finalScore));
}

void GameoverScene::onRestartClicked()
{
    emit restartClicked();
}

void GameoverScene::onBackClicked()
{
    emit backToMenuClicked();
}

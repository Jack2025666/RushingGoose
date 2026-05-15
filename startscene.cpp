#include "startscene.h"
#include "gamescene.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QFont>

StartScene::StartScene(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet(
        "StartScene {"
        "background-image: url(:/image/startscene.jpg);"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "background-attachment: fixed;"
        "}"
        );
    this->update();

    // 游戏标题
    titleLabel = new QLabel("🦢 Rushing Goose 🦢", this);
    titleLabel->setFixedSize(400, 80);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont;
    titleFont.setPointSize(28);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet(
        "color: #2c3e50;"
        "background-color: rgba(255,255,255,220);"
        "border-radius: 20px;"
        "border: 3px solid #3498db;"
        );

    // 难度选择标签
    difficultyLabel = new QLabel("选择难度", this);
    difficultyLabel->setFixedSize(150, 40);
    difficultyLabel->setAlignment(Qt::AlignCenter);
    difficultyLabel->setStyleSheet(
        "color: #2c3e50;"
        "background-color: rgba(255,255,255,200);"
        "font-size: 18px;"
        "font-weight: bold;"
        "border-radius: 10px;"
        );

    // 难度按钮
    easyButton = new QPushButton("简单", this);
    easyButton->setFixedSize(100, 45);
    easyButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #27ae60;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #2ecc71; }"
        );
    easyButton->setFocusPolicy(Qt::NoFocus);

    normalButton = new QPushButton("普通", this);
    normalButton->setFixedSize(100, 45);
    normalButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #f39c12;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #f1c40f; }"
        );
    normalButton->setFocusPolicy(Qt::NoFocus);

    hardButton = new QPushButton("困难", this);
    hardButton->setFixedSize(100, 45);
    hardButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #e74c3c;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #c0392b; }"
        );
    hardButton->setFocusPolicy(Qt::NoFocus);

    // 难度按钮布局
    difficultyLayout = new QHBoxLayout();
    difficultyLayout->addWidget(easyButton);
    difficultyLayout->addSpacing(20);
    difficultyLayout->addWidget(normalButton);
    difficultyLayout->addSpacing(20);
    difficultyLayout->addWidget(hardButton);

    // 开始游戏按钮
    startButton = new QPushButton("🎮 开始游戏", this);
    startButton->setFixedSize(180, 55);
    startButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #3498db;"
        "font-size: 20px;"
        "font-weight: bold;"
        "border-radius: 20px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #2980b9; }"
        );
    startButton->setFocusPolicy(Qt::NoFocus);

    // 退出游戏按钮
    quitButton = new QPushButton("退出游戏", this);
    quitButton->setFixedSize(150, 50);
    quitButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #7f8c8d;"
        "font-size: 18px;"
        "border-radius: 18px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #95a5a6; }"
        );
    quitButton->setFocusPolicy(Qt::NoFocus);

    // 主布局
    layout = new QVBoxLayout(this);
    layout->addStretch(2);
    layout->addWidget(titleLabel, 0, Qt::AlignHCenter);
    layout->addStretch(2);
    layout->addWidget(difficultyLabel, 0, Qt::AlignHCenter);
    layout->addSpacing(10);
    layout->addLayout(difficultyLayout);
    layout->addStretch(1);
    layout->addWidget(startButton, 0, Qt::AlignHCenter);
    layout->addStretch(1);
    layout->addWidget(quitButton, 0, Qt::AlignHCenter);
    layout->addStretch(2);

    this->setLayout(layout);

    // 信号连接
    connect(startButton, &QPushButton::clicked, this, &StartScene::onStartButtonClicked);
    connect(quitButton, &QPushButton::clicked, this, &QApplication::quit);
    connect(easyButton, &QPushButton::clicked, this, &StartScene::onEasyClicked);
    connect(normalButton, &QPushButton::clicked, this, &StartScene::onNormalClicked);
    connect(hardButton, &QPushButton::clicked, this, &StartScene::onHardClicked);
}

void StartScene::onStartButtonClicked()
{
    emit startGameClicked();
}

void StartScene::onEasyClicked()
{
    selectedDifficulty = 0;
    easyButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #27ae60;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: 3px solid white;"
        "}"
        );
    normalButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #f39c12;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #f1c40f; }"
        );
    hardButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #e74c3c;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #c0392b; }"
        );
}

void StartScene::onNormalClicked()
{
    selectedDifficulty = 1;
    easyButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #27ae60;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #2ecc71; }"
        );
    normalButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #f39c12;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: 3px solid white;"
        "}"
        );
    hardButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #e74c3c;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #c0392b; }"
        );
}

void StartScene::onHardClicked()
{
    selectedDifficulty = 2;
    easyButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #27ae60;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #2ecc71; }"
        );
    normalButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #f39c12;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: none;"
        "}"
        "QPushButton:hover { background-color: #f1c40f; }"
        );
    hardButton->setStyleSheet(
        "QPushButton {"
        "color: white;"
        "background-color: #e74c3c;"
        "font-size: 16px;"
        "font-weight: bold;"
        "border-radius: 15px;"
        "border: 3px solid white;"
        "}"
        );
}

#include "player.h"
#include <QKeyEvent>
#include <QDebug>
#include <QFont>

Player::Player(QWidget *parent) : QLabel(parent)
{
    this->setFixedSize(60, 60);
    // 使用emoji显示大鹅 🦢
    this->setText("🦢");
    this->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(40);
    this->setFont(font);
    this->setStyleSheet("background: transparent;");
    this->setFocusPolicy(Qt::NoFocus);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Up) {
        this->jump();
        event->accept();
        return;
    }
    QLabel::keyPressEvent(event);
}

void Player::jump()
{
    // 二段跳：只要跳跃次数小于最大次数就可以跳
    if (jumpCount < maxJumpCount) {
        velocity = jumpForce;
        onGround = false;
        jumpCount++;
    }
}

void Player::fall()
{
    this->move(this->x(), this->y() + velocity);
    velocity += gravity;

    int groundLimit = this->parentWidget()->height() - 150 - this->height();
    if (this->y() >= groundLimit) {
        this->move(this->x(), groundLimit);
        velocity = 0;
        onGround = true;
        jumpCount = 0;  // 落地后重置跳跃次数
    }
}

void Player::resetPosition(int groundY)
{
    this->move(100, groundY);
    velocity = 0;
    onGround = true;
    jumpCount = 0;
}

QRect Player::getCollisionRect() const
{
    return QRect(this->x() + 10, this->y() + 10, this->width() - 20, this->height() - 20);
}

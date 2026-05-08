#include "player.h"
#include "gamescene.h"
#include <QWidget>
#include <QKeyEvent>

//设置方块样式
Player::Player(QWidget *parent):QLabel(parent)
{
    this->setFixedSize(50,80);
    this->setStyleSheet(
        "background-color:white;"
        );
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();
}
//键盘捕捉
void Player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space){
        this->Player::jump();
        event->accept();
        return;
    }
}
//跳跃函数
void Player::jump(){
    if(velocity==0){
    velocity=-15;
    }
    qDebug()<<"Jump!The velocity is "<<velocity;
}
//下落函数
void Player::fall(){
    this->move(this->x(),this->y()+velocity);
    velocity++;
    if(this->y()>=this->parentWidget()->height()-230){
        velocity=0;
    }
}
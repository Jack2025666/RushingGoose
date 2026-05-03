#include "player.h"
#include "gamescene.h"
#include <QWidget>
#include <QKeyEvent>

Player::Player(QWidget *parent):QLabel(parent)
{
    this->setFixedSize(50,80);
    this->setStyleSheet(
        "background-color:white;"
        );
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();
}
void Player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space){
        this->Player::jump();
        event->accept();
        return;
    }
}
void Player::jump(){
    if(velocity==0){
    velocity=-10;
    }
}
void Player::fall(){
    this->move(this->x(),this->y()+velocity);
    velocity++;
    if(this->y()>=this->parentWidget()->height()-230){
        velocity=0;
    }
}
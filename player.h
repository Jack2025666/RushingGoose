#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>

class Player : public QLabel
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);
    void jump();
    void fall();
    void resetPosition(int groundY);
    bool isOnGround() const { return onGround; }
    QRect getCollisionRect() const;
    void resetJumpCount() { jumpCount = 0; }  // 重置跳跃次数

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int velocity = 0;
    bool onGround = true;
    int gravity = 1;
    int jumpForce = -15;
    int jumpCount = 0;      // 当前跳跃次数
    int maxJumpCount = 2;   // 最大跳跃次数（二段跳）
};

#endif // PLAYER_H

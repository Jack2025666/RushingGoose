#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>

class GameScene;
class Player : public QLabel
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent=nullptr);
    void jump();
    void fall();
protected:
void keyPressEvent(QKeyEvent *event)override;
private:
    int velocity=0;

};

#endif // PLAYER_H

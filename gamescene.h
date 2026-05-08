#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "startscene.h"
#include "pausescene.h"
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QFrame>
#include <QResizeEvent>

class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QTimer;
class QFrame;
class Player;
class QLabel;

class GameScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);
    static bool gameRunning;
protected:
    void resizeEvent(QResizeEvent *event)override;
private:
    QPushButton *backButton,*pauseButton;
    QVBoxLayout *mainlayout;
    QHBoxLayout *toplayout;
    QTimer *gametimer,*scoretimer;
    QFrame *ground;
    Player *player;
    QLabel *scoreboard;

    int groundH=150;
    int playerY;
    int score=0;
private slots:
    void onBackButtonClicked();
    void onPauseButtonClicked();
    void updateTime();
    void updateScore();

signals:
    void backClicked();
    void pauseClicked();
};

#endif // GAMESCENE_H

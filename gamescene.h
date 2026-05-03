#ifndef GAMESCENE_H
#define GAMESCENE_H

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

class GameScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event)override;
private:
    QPushButton *backButton,*pauseButton;
    QVBoxLayout *mainlayout;
    QHBoxLayout *toplayout;
    QTimer *gametimer;
    QFrame *ground;
    Player *player;

    int groundH;
    int playerY;

private slots:
    void onBackButtonClicked();
    void onPauseButtonClicked();
    void updateTime();

signals:
    void backClicked();
    void pauseClicked();
};

#endif // GAMESCENE_H

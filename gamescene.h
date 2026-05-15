#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QFrame>
#include <QResizeEvent>
#include <QList>

class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class Player;
class QLabel;

struct Obstacle {
    QLabel *label;
    int speed;
    bool active;
};

class GameScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);
    static bool gameRunning;
    int getScore() const { return score; }
    void resetGame();
    void setDifficulty(int diff);  // 设置难度

protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    QPushButton *backButton, *pauseButton;
    QVBoxLayout *mainlayout;
    QHBoxLayout *toplayout;
    QTimer *gametimer, *scoretimer;
    QFrame *ground;
    Player *player;
    QLabel *scoreboard;
    QLabel *difficultyLabel;  // 显示当前难度

    int groundH = 150;
    int playerY;
    int score = 0;
    int baseObstacleSpeed = 8;  // 基础障碍物速度（提高）
    int obstacleSpeed = 8;
    int obstacleTimer = 0;
    int baseSpawnInterval = 70;  // 基础生成间隔
    int spawnInterval = 70;
    int currentDifficulty = 1;  // 当前难度

    QList<Obstacle> obstacles;

    void spawnObstacle();
    void moveObstacles();
    void checkCollision();
    void cleanupObstacles();

private slots:
    void onBackButtonClicked();
    void onPauseButtonClicked();
    void updateTime();
    void updateScore();

signals:
    void backClicked();
    void pauseClicked();
    void gameOver(int finalScore);
};

#endif // GAMESCENE_H

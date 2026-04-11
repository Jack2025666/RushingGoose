#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

class GameScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);
private:
    QLabel *waitingScene;
    QPushButton *backButton,*pauseButton;
    QVBoxLayout *mainlayout;
    QHBoxLayout *toplayout;

private slots:
    void onBackButtonClicked();
    void onPauseButtonClicked();

signals:
    void backClicked();
    void pauseClicked();
};

#endif // GAMESCENE_H

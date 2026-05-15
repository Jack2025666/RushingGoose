#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include <QObject>
#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;

class GameoverScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameoverScene(QWidget *parent = nullptr);
    void setFinalScore(int s);

signals:
    void restartClicked();
    void backToMenuClicked();

private:
    QLabel *titleLabel;
    QLabel *scoreLabel;
    QPushButton *restartButton;
    QPushButton *backButton;
    QVBoxLayout *layout;
    int finalScore = 0;

private slots:
    void onRestartClicked();
    void onBackClicked();
};

#endif // GAMEOVERSCENE_H

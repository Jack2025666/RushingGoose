#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QObject>
#include <QWidget>
class QPushButton;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;

class StartScene : public QWidget
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);
    int getSelectedDifficulty() const { return selectedDifficulty; }

private:
    QPushButton *startButton, *quitButton;
    QPushButton *easyButton, *normalButton, *hardButton;
    QLabel *titleLabel;
    QLabel *difficultyLabel;
    QVBoxLayout *layout;
    QHBoxLayout *difficultyLayout;
    int selectedDifficulty = 1; // 0=简单, 1=普通, 2=困难

private slots:
    void onStartButtonClicked();
    void onEasyClicked();
    void onNormalClicked();
    void onHardClicked();

signals:
    void startGameClicked();
};

#endif // STARTSCENE_H

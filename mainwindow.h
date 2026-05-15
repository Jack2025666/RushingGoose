#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStackedWidget;
class StartScene;
class GameScene;
class PauseScene;
class GameoverScene;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    QStackedWidget *stackedWidget;
    StartScene *startScene;
    GameScene *gameScene;
    PauseScene *pauseScene;
    GameoverScene *gameoverScene;

    enum PageIndex {
        StartPage = 0,
        GamePage = 1,
        PausePage = 2,
        GameoverPage = 3
    };

private slots:
    void onGameOver(int finalScore);
    void onRestartGame();
    void onBackToMenu();
};

#endif // MAINWINDOW_H

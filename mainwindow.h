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
    StartScene *startScene;
    GameScene *gameScene;
    PauseScene *pauseScene;
    GameoverScene *gameoverScene;

private:
    QStackedWidget *stackedWidget;
};
#endif // MAINWINDOW_H

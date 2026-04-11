#ifndef PAUSESCENE_H
#define PAUSESCENE_H

#include <QObject>
#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

class PauseScene : public QWidget
{
    Q_OBJECT
public:
    explicit PauseScene(QWidget *parent = nullptr);
private:
    QLabel *pauseLabel;
    QPushButton *backButton;
    QPushButton *quitButton;
    QVBoxLayout *mainlayout;
    QHBoxLayout *bottomlayout;
private slots:
    void onBackButtonClicked();
    void onQuitButtonClicked();
signals:
    void backClicked();
    void quitClicked();
};

#endif // PAUSESCENE_H

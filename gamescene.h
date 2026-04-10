#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;

class GameScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);
private:
    QLabel *waitingScene;
    QPushButton *returnButton;
    QVBoxLayout *layout;

private slots:
    void onReturnButtonClicked();

signals:
    void returnClicked();
};

#endif // GAMESCENE_H

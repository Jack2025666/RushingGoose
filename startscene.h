#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QObject>
#include <QWidget>
class QPushButton;
class QLabel;
class QVBoxLayout;

class StartScene : public QWidget
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);
private:
    QPushButton *startButton,*quitButton;
    QLabel *titleLabel;
    QVBoxLayout *layout;

private slots:
    void onStartButtonClicked();

signals:
    void startGameClicked();
};

#endif // STARTSCENE_H

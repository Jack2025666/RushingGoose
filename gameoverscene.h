#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include <QObject>
#include <QWidget>

class GameoverScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameoverScene(QWidget *parent = nullptr);

signals:
};

#endif // GAMEOVERSCENE_H

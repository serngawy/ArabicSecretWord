#ifndef GAMETYPEFRAME_H
#define GAMETYPEFRAME_H

#include <QFrame>
#include "gameintroframe.h"

namespace Ui {
    class GameTypeFrame;
}

class GameTypeFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GameTypeFrame(QWidget *parent = 0);
    ~GameTypeFrame();
    GameIntroFrame* gameIntro;
    //add theams

private:
    Ui::GameTypeFrame *ui;

private slots:
    void OpenGameIntro();
};

#endif // GAMETYPEFRAME_H

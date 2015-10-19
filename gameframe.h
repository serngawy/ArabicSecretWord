#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QFrame>
#include "mylabel.h"
#include "lettersgenratoir.h"
#include "QParallelAnimationGroup"
#include "myword.h"
#include "QTimer"
#include "hintframe.h"

namespace Ui {
    class GameFrame;
}

class GameFrame : public QFrame
{
    Q_OBJECT

public:
    enum AnimType {
        Center=0,
        Random=1,
        Tiles=2
    };
    explicit GameFrame(QWidget *parent = 0);
    ~GameFrame();
    void LoadGame(myWord myword);
    void StartAnimation(int animType);
    void StartGame();
    void Pause();
    HintFrame* hFrame;
    //add theam
    //add hint theam
    //add timer time
    //add game speed
    //add animation type

private:
    Ui::GameFrame *ui;
    QList<myLabel*> myLabelList;
    QParallelAnimationGroup *centergroup;
    QParallelAnimationGroup *randomgroup;
    QParallelAnimationGroup *tiledgroup;
    LettersGenratoir* letGen;
    int interval;
    bool pauseGame;
    int currentSelectedId;
    myWord secretWord;
    QTimer* myTimer;

    void ChangeLabelsPosition();

private slots:
    void timerEvent();
    void mySelctedLabelClick(int idx);
    void Match();
    void PauseGame();
    void Back();
    void Hint();
    void WordInfromation();

};

#endif // GAMEFRAME_H

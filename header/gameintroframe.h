#ifndef GAMEINTROFRAME_H
#define GAMEINTROFRAME_H

#include <QFrame>
#include "xmlengine.h"
#include <QPropertyAnimation>
#include "gameframe.h"
#include "wordinfoframe.h"

namespace Ui {
    class GameIntroFrame;
}

class GameIntroFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GameIntroFrame(QWidget *parent = 0);
    ~GameIntroFrame();
     GameFrame* gFrame;
     WordInfoFrame* wInfoFrame;
     QStringList wordsScore;
     void ShowInfromationWord(QString info,QString Score,QString cityName);
     void LoadGame(bool nextOrCurrent);
     //add theam
     //add btn theam
     //add levels numbers
private:
    Ui::GameIntroFrame *ui;
    QPropertyAnimation* m_transition1;
    QPropertyAnimation* m_transition2;
    XmlEngine* xml;
    int lastword;
    QString CheckScore(QString newScore,QString oldScore);
private slots:
    void NextWords();
    void PrevoiusWords();
    void StartGame(int wordID);
    void atExit();

protected:


};

#endif // GAMEINTROFRAME_H

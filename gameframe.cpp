#include "gameframe.h"
#include "ui_gameframe.h"
#include "QParallelAnimationGroup"
#include "QPropertyAnimation"
#include "QTimer"
#include "lettersgenratoir.h"
#include "QAbstractTransition"
#include "QSignalTransition"
#include "QAbstractAnimation"
#include "gameintroframe.h"
#include "optionframe.h"

GameFrame::GameFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GameFrame)
{
    ui->setupUi(this);

    int dx=(ui->frameBlocks->width()/2)-27;
    int dy=(ui->frameBlocks->height()/2)-27;
    tiledgroup = new QParallelAnimationGroup(ui->frameBlocks);
    centergroup = new QParallelAnimationGroup(ui->frameBlocks);
    randomgroup = new QParallelAnimationGroup(ui->frameBlocks);
    letGen=new LettersGenratoir();
    hFrame=new HintFrame(this);
    hFrame->setVisible(false);

    myTimer=new QTimer(this);
   // myTimer->setInterval(1000);
    for(int i=0;i<55;i++)
    {
       myLabel* mylab=new myLabel(ui->frameBlocks);
       mylab->setObjectName("lb_"+QString("%1").arg(i));
       mylab->SetMyIndex(i);
       mylab->SetPosition(qrand() % 600,qrand() % 250);
       mylab->SetBackGroundImage("2");//QString("%1").arg(i%4)
       connect(mylab,SIGNAL(myLabelClick(int)),this,SLOT(mySelctedLabelClick(int)));
       myLabelList<<mylab;

       QPropertyAnimation *anim = new QPropertyAnimation(mylab, "pos",ui->frameBlocks);
       anim->setDuration(10 + i * 25);
      // anim->setStartValue(mylab->pos());
       anim->setEndValue(QPoint(dx,dy));
       anim->setEasingCurve(QEasingCurve::InOutBack);
       centergroup->addAnimation(anim);

       QPropertyAnimation *anim1 = new QPropertyAnimation(mylab, "pos",ui->frameBlocks);
       anim1->setDuration(10 + i * 25);
       //anim1->setStartValue(mylab->pos());
       anim1->setEndValue(QPoint(qrand() % 600,qrand() % 250));
       anim1->setEasingCurve(QEasingCurve::InOutBack);
       randomgroup->addAnimation(anim1);

       QPropertyAnimation *anim2 = new QPropertyAnimation(mylab, "pos",ui->frameBlocks);
       anim2->setDuration(10 + i * 25);
      // anim2->setStartValue(mylab->pos());
       anim2->setEndValue(QPoint((i%11)*myLabelList.at(i)->width()+1,(i%5)*myLabelList.at(i)->height()));
       anim2->setEasingCurve(QEasingCurve::InOutBack);
       tiledgroup->addAnimation(anim2);

    }

    connect(tiledgroup,SIGNAL(finished()),myTimer,SLOT(start()));
    connect(ui->pushBtn_Match,SIGNAL(clicked()),this,SLOT(Match()));
    connect(ui->pushBtn_Hint,SIGNAL(clicked()),this,SLOT(Hint()));
    connect(ui->pushBtn_Pause,SIGNAL(clicked()),this,SLOT(PauseGame()));
    connect(ui->pushBtn_Close,SIGNAL(clicked()),this,SLOT(Back()));
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(WordInfromation()));
    connect(myTimer,SIGNAL(timeout()),this,SLOT(timerEvent()));

}

void GameFrame::mySelctedLabelClick(int idx)
{
    if(!pauseGame)
    {
        if(myLabelList.at(idx)->IsBlocked())
        {
            int pair=myLabelList.at(idx)->GetMyPair();
            myLabelList.at(idx)->SetNonBlocked();
            myLabelList.at(pair)->SetNonBlocked();
        }
        else
        {
            if(currentSelectedId!=-1)
            {
                if(currentSelectedId!=idx)
                {
                    QString stCurrent=myLabelList.at(currentSelectedId)->text();
                    QString stNew=myLabelList.at(idx)->text();
                    if(!stCurrent.compare(stNew))
                    {
                     myLabelList.at(idx)->SetBlocked();
                     myLabelList.at(idx)->SetMyPair(currentSelectedId);
                     myLabelList.at(currentSelectedId)->SetBlocked();
                     myLabelList.at(currentSelectedId)->SetMyPair(idx);;

                     currentSelectedId=-1;
                    }
                    else
                    {
                      myLabelList.at(idx)->SetNonActive();;
                      myLabelList.at(currentSelectedId)->SetNonActive();
                      currentSelectedId=-1;
                    }
                }
                else
                {
                   myLabelList.at(idx)->SetNonActive();
                   currentSelectedId=-1;
                }
            }
            else
            {
                  currentSelectedId=idx;
                  myLabelList.at(idx)->SetActive();
            }
        }
    }
}

GameFrame::~GameFrame()
{
    delete ui;
}

void GameFrame::LoadGame(myWord myword)
{
    if(myword.id>20)
        myTimer->setInterval(500);
    else
        myTimer->setInterval(1000);

    secretWord=myword;
    QStringList gameLet= letGen->GenerateLetters(secretWord.word);
    currentSelectedId=-1;
    ui->lineEdit->setText("");
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    for(int i=0;i<myLabelList.length();i++)
    {
       myLabelList.at(i)->SetLetter(gameLet.at(i));
       myLabelList.at(i)->SetNonBlocked();
    }

}


void GameFrame::ChangeLabelsPosition()
{
    int n=qrand()%55;
    int xn=myLabelList.at(n)->geometry().x();
    int yn=myLabelList.at(n)->geometry().y();

    int nn=qrand()%55;
    int xnn=myLabelList.at(nn)->geometry().x();
    int ynn=myLabelList.at(nn)->geometry().y();

    myLabelList.at(n)->SetPosition(xnn,ynn);
    myLabelList.at(nn)->SetPosition(xn,yn);
}

void GameFrame::timerEvent()
{
    if(secretWord.id!=0)
        ChangeLabelsPosition();

    if(interval%2==0)
    {
       int sec=ui->lcdNumber_2->value();
       ui->lcdNumber_2->display(++sec);
       if(sec>59)
       {
          int min=ui->lcdNumber->value();
          ui->lcdNumber->display(++min);
          ui->lcdNumber_2->display(0);
       }
    }
    if(OptionFrame::CrazyGame && secretWord.id!=0)
        ChangeLabelsPosition();
    interval++;
}

void GameFrame::StartGame()
{
    StartAnimation(Tiles);
    pauseGame=false;
    interval=0;

}

void GameFrame::Match()
{
    int count=0;

    for(int i=0;i<myLabelList.length();i++)
        if(!myLabelList.at(i)->IsBlocked())
            count++;

    if(secretWord.word.length()%2 == 0)
        count--;

    if(count > secretWord.word.length())
    {
        hFrame->SetHintText(0);
        hFrame->showFullScreen();
    }
    else
    {
        QString word=ui->lineEdit->text();

        if(!secretWord.word.compare(word))
        {
            myTimer->stop();
            QString score=QString("%1").arg(ui->lcdNumber->value());
            score.append(".");
            score.append(QString("%1").arg(ui->lcdNumber_2->value()));

            GameIntroFrame *mW=qobject_cast<GameIntroFrame *>(this->parent());
            //mW->wordsScore<<score;
            mW->ShowInfromationWord(secretWord.infromation,score,secretWord.word);
        }
        else
        {
           hFrame->SetHintText(1);
           hFrame->showFullScreen();
        }
    }
}

void GameFrame::Hint()
{
    hFrame->SetHintText(secretWord.Hint);
    hFrame->showFullScreen();
}

void GameFrame::Pause()
{
    if(!pauseGame)
    {
        myTimer->stop();
        ui->pushBtn_Pause->setStyleSheet("border-image: url(:/image/images/WordsBtn/GameBtns_17.png);");
        pauseGame=true;
        StartAnimation(Center);
    }
}

void GameFrame::PauseGame()
{
    if(pauseGame)
    {
        StartGame();
        ui->pushBtn_Pause->setStyleSheet("border-image: url(:/image/images/WordsBtn/GameBtns_10.png);");
    }
    else
    {
        myTimer->stop();
        ui->pushBtn_Pause->setStyleSheet("border-image: url(:/image/images/WordsBtn/GameBtns_17.png);");
        pauseGame=true;
        StartAnimation(Center);
    }
}

void GameFrame::WordInfromation()
{
   /* if(myLabelList.at(0)->styleSheet().contains("2",Qt::CaseSensitive))
        for(int i=0;i<myLabelList.length();i++)
        {
            myLabelList.at(i)->SetBackGroundImage("1");
        }
    else if(myLabelList.at(0)->styleSheet().contains("1",Qt::CaseSensitive))
        for(int i=0;i<myLabelList.length();i++)
        {
            myLabelList.at(i)->SetBackGroundImage("0");
        }
    else
        for(int i=0;i<myLabelList.length();i++)
        {
            myLabelList.at(i)->SetBackGroundImage("2");
        }*/
}

void GameFrame::Back()
{
    myTimer->stop();
   // pauseGame=false;
    StartAnimation(Random);
    this->close();
}

void GameFrame::StartAnimation(int animType)
{
    if(animType==0)
    {
       centergroup->start(QAbstractAnimation::KeepWhenStopped);

    }
    else if(animType==1)
    {
       randomgroup->start(QAbstractAnimation::KeepWhenStopped);
    }
    else if(animType==2)
    {
        QTimer::singleShot(600,tiledgroup,SLOT(start()));//tiledgroup->start(QAbstractAnimation::KeepWhenStopped);
    }
}

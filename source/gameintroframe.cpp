#include "gameintroframe.h"
#include "ui_gameintroframe.h"
#include <QObject>
#include "QGraphicsScene"
#include "QGraphicsGridLayout"
#include "QGraphicsLayoutItem"
#include "QTextEdit"
#include <QtGui/QApplication>
#include <QtGui/QGraphicsProxyWidget>
#include "QGraphicsSceneMouseEvent"
#include "QGridLayout"
#include "QLayoutItem"
#include "mybotton.h"
#include "xmlengine.h"


GameIntroFrame::GameIntroFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GameIntroFrame)
{
    ui->setupUi(this);

    xml=new XmlEngine();
    wordsScore=xml->GetScores();

    gFrame=new GameFrame(this);
    gFrame->setVisible(false);
    wInfoFrame=new WordInfoFrame(this);
    wInfoFrame->setVisible(false);

     int count=0;
     QGridLayout* layout1=new QGridLayout();
     QGridLayout* layout2=new QGridLayout();

     for(int i=0;i<3;i++)
     {
         layout1->setRowMinimumHeight(i,91);
         layout2->setRowMinimumHeight(i,91);
         for(int j=0;j<7;j++)
         {
              myBotton* btn1;
              if(count<wordsScore.length())
               {
                 btn1=new myBotton(ui->widget1,count,0);
                 btn1->SetScoreText(wordsScore.at(count));
               }
             else if(count==wordsScore.length())
                btn1=new myBotton(0,count,1);
             else
                btn1=new myBotton(0,count,2);

             myBotton* btn2;
             if(count+21<wordsScore.length())
              {
                btn2=new myBotton(ui->widget2,count+21,0);
                btn2->SetScoreText(wordsScore.at(count+21));
              }
             else if(count+21==wordsScore.length())
               btn2=new myBotton(0,count+21,1);
             else
               btn2=new myBotton(0,count+21,2);


             connect(btn1,SIGNAL(myBtnClick(int)),this,SLOT(StartGame(int)));
             connect(btn2,SIGNAL(myBtnClick(int)),this,SLOT(StartGame(int)));
             layout1->addWidget(btn1,i,j,1,1,Qt::AlignCenter);
             layout2->addWidget(btn2,i,j,1,1,Qt::AlignCenter);
             count++;
             layout1->setColumnMinimumWidth(j,84);
             layout2->setColumnMinimumWidth(j,84);
         }
     }


     ui->widget1->setLayout(layout1);
     ui->widget2->setLayout(layout2);
     ui->stackedWidget->setCurrentIndex(0);
    lastword=-1;


     QRect pixRect = QRect(QPoint(0, 0), ui->stackedWidget->size());
     pixRect.moveCenter(QPoint( width()/2-20, 0 ));

     m_transition1 = new QPropertyAnimation(ui->widget1, "pos", this);
     m_transition1->setDuration(800);
     m_transition1->setStartValue(QPoint(-(ui->widget1->width()), ui->widget1->y()));
     m_transition1->setEndValue( QPoint(pixRect.x(), ui->widget1->y()) );
     m_transition1->setEasingCurve(QEasingCurve::OutQuad);

     m_transition2 = new QPropertyAnimation(ui->widget2, "pos", this);
     m_transition2->setDuration(800);
     m_transition2->setStartValue(QPoint((ui->widget1->width()), ui->widget1->y()));
     m_transition2->setEndValue( QPoint(pixRect.x(), ui->widget1->y()) );
     m_transition2->setEasingCurve(QEasingCurve::OutQuad);



    connect(ui->pushBtn_Close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushBtn_Prev,SIGNAL(clicked()),this,SLOT(PrevoiusWords()));
    connect(ui->pushBtn_Next,SIGNAL(clicked()),this,SLOT(NextWords()));
    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(atExit()));
}

void GameIntroFrame::atExit()
{
    xml->SetScores(wordsScore);
}

void GameIntroFrame::StartGame(int wordID)
{
    if(wordID <= wordsScore.length())
    {
        if(lastword!=wordID)
        {
            lastword=wordID;
            myWord secretWord=xml->GetWord(wordID);
            if(wordID < wordsScore.length())
            {
                wInfoFrame->SetInfoText(secretWord.infromation,secretWord.id,secretWord.word);
                wInfoFrame->showFullScreen();
            }
            else
            {
                gFrame->LoadGame(secretWord);
                gFrame->showFullScreen();
                gFrame->StartGame();
                if(secretWord.id==0)
                {
                    gFrame->hFrame->SetHintText(2);
                    gFrame->hFrame->showFullScreen();
                }
                else if(secretWord.id==21)
                {
                    gFrame->hFrame->SetHintText(3);
                    gFrame->hFrame->showFullScreen();
                }
            }
        }
        else
        {
            if(wordID < wordsScore.length())
            {
               //wInfoFrame->SetInfoText(secretWord.infromation,secretWord.id,secretWord.word);
                wInfoFrame->showFullScreen();
            }
            else
            {
                gFrame->showFullScreen();
                gFrame->StartGame();
            }
        }
    }
}

void GameIntroFrame::NextWords()
{
    if(ui->stackedWidget->currentIndex()==0)
    {
        ui->stackedWidget->setCurrentIndex(1);
        m_transition2->start();
    }

}

void GameIntroFrame::PrevoiusWords()
{
    if(ui->stackedWidget->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(0);
        m_transition1->start();
    }
}

GameIntroFrame::~GameIntroFrame()
{
    delete ui;
}


void GameIntroFrame::ShowInfromationWord(QString info,QString Score,QString cityName)
{
    wInfoFrame->SetInfoText(info,lastword,cityName);

    if(lastword<21)
    {

        myBotton *btn=ui->widget1->findChild<myBotton*>("Btn_"+QString("%1").arg(lastword));//qobject_cast<myBotton *>(ui->widget1->childAt(15,15));//ui->widget1->children().at(lastword));
        QString sc=this->CheckScore(Score,btn->text());
        if(lastword<wordsScore.length())
            wordsScore.replace(lastword,sc);
        else
            wordsScore<<sc;

        btn->SetScoreText(sc);
        btn->SetImage(0);
        int id=lastword+1;
        if(id<21)
           btn=ui->widget1->findChild<myBotton*>("Btn_"+QString("%1").arg(id));//qobject_cast<myBotton *>(ui->widget1->children().at(lastword));
        else
            btn=ui->widget2->findChild<myBotton*>("Btn_"+QString("%1").arg(id));//qobject_cast<myBotton *>(ui->widget2->children().at(lastword));

        btn->SetImage(1);

    }
    else
    {
        myBotton* btn=ui->widget2->findChild<myBotton*>("Btn_"+QString("%1").arg(lastword));//qobject_cast<myBotton*>(ui->widget2->children().at(lastword));
        QString sc=this->CheckScore(Score,btn->text());
        if(lastword<wordsScore.length())
            wordsScore.replace(lastword,sc);
        else
            wordsScore<<sc;

        btn->SetScoreText(sc);
        btn->SetImage(0);
        int id=lastword+1;
        if(id<42)
        {
           btn=ui->widget2->findChild<myBotton*>("Btn_"+QString("%1").arg(id));//qobject_cast<myBotton*>(ui->widget2->children().at(lastword));
           btn->SetImage(1);
        }
    }
    wInfoFrame->showFullScreen();
}

void GameIntroFrame::LoadGame(bool nextOrCurrent)
{
    if(nextOrCurrent)
        lastword++;

    myWord secretWord=xml->GetWord(lastword);
    gFrame->LoadGame(secretWord);
    gFrame->showFullScreen();
    gFrame->StartGame();

}

QString  GameIntroFrame::CheckScore(QString newScore, QString oldScore)
{
    if(oldScore.isEmpty()|| oldScore.isNull())
        return newScore;

    if(newScore.toDouble()<oldScore.toDouble())
        return newScore;
    else
        return oldScore;
}

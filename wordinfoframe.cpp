#include "wordinfoframe.h"
#include "ui_wordinfoframe.h"
#include "QGraphicsScene"
#include "QImage"
#include "gameintroframe.h"

WordInfoFrame::WordInfoFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::WordInfoFrame)
{
    ui->setupUi(this);
    QGraphicsScene* scene=new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    connect(ui->pushBtn_Next,SIGNAL(clicked()),this,SLOT(NextWord()));
    connect(ui->pushBtn_replay,SIGNAL(clicked()),this,SLOT(RestartGame()));
}

WordInfoFrame::~WordInfoFrame()
{
    delete ui;
}

void WordInfoFrame::SetInfoText(QString info,int infoID,QString cityName)
{
    ui->textBrowser->setText(info);//"<font color=black>"+info+"</font>");
    ui->graphicsView->scene()->clear();
    QImage img(qApp->applicationDirPath()+"/CitiesInfoImage/city_"+QString("%1").arg(infoID)+".jpg");
    QPixmap pix=QPixmap::fromImage(img);
    ui->graphicsView->scene()->addPixmap(pix);
    ui->pushBtn_Next->setEnabled(infoID<41);
    int id=ui->label_city->text().indexOf(":");
    QString test=ui->label_city->text().remove(id+2,ui->label_city->text().length());
    ui->label_city->setText("<font color=black>"+test+cityName+"</font>");
}

void WordInfoFrame::NextWord()
{
     GameIntroFrame *mW=qobject_cast<GameIntroFrame *>(this->parent());
     mW->LoadGame(true);
     this->close();
}

void WordInfoFrame::RestartGame()
{
    GameIntroFrame *mW=qobject_cast<GameIntroFrame *>(this->parent());
    mW->LoadGame(false);
    this->close();
}

#include "gametypeframe.h"
#include "ui_gametypeframe.h"

GameTypeFrame::GameTypeFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GameTypeFrame)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(OpenGameIntro()));
    gameIntro=new GameIntroFrame(this);
    gameIntro->setVisible(false);
}

void GameTypeFrame::OpenGameIntro()
{
    gameIntro->showFullScreen();
}

GameTypeFrame::~GameTypeFrame()
{
    delete ui;
}

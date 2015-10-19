#include "optionframe.h"
#include "ui_optionframe.h"

bool OptionFrame::CrazyGame=false;

OptionFrame::OptionFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OptionFrame)
{
    ui->setupUi(this);
    connect(ui->pushBtn_Crazy,SIGNAL(clicked()),this,SLOT(CrazyGameOption()));

}

OptionFrame::OptionFrame(QWidget *parent,bool crazy) :
    QFrame(parent),
    ui(new Ui::OptionFrame)
{
    ui->setupUi(this);
    CrazyGame=crazy;
    connect(ui->pushBtn_Crazy,SIGNAL(clicked()),this,SLOT(CrazyGameOption()));
    if(CrazyGame)
       ui->pushBtn_Crazy->setStyleSheet("border-image: url(:/image/images/Menu Screen/Normal Btns/Btns_Slices_12.png);");

 }

void OptionFrame::CrazyGameOption()
{

    if(CrazyGame)
        ui->pushBtn_Crazy->setStyleSheet("border-image: url(:/image/images/Menu Screen/Normal Btns/Btns_Slices_22.png);");
    else
        ui->pushBtn_Crazy->setStyleSheet("border-image: url(:/image/images/Menu Screen/Normal Btns/Btns_Slices_12.png);");

    CrazyGame=!CrazyGame;
}

QString OptionFrame::GetCrazyState()
{
     if(CrazyGame)
        return "true";
     else
        return "false";
}


OptionFrame::~OptionFrame()
{
    delete ui;
}

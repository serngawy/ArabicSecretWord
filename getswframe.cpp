#include "getswframe.h"
#include "ui_getswframe.h"

GetSWFrame::GetSWFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GetSWFrame)
{
    ui->setupUi(this);
}

GetSWFrame::~GetSWFrame()
{
    delete ui;
}

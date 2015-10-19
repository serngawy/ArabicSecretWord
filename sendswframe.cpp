#include "sendswframe.h"
#include "ui_sendswframe.h"

SendSWFrame::SendSWFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SendSWFrame)
{
    ui->setupUi(this);
}

SendSWFrame::~SendSWFrame()
{
    delete ui;
}

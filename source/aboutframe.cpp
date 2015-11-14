#include "aboutframe.h"
#include "ui_aboutframe.h"

AboutFrame::AboutFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AboutFrame)
{
    ui->setupUi(this);
}

void AboutFrame::mousePressEvent(QMouseEvent *)
{
    this->close();
}

AboutFrame::~AboutFrame()
{
    delete ui;
}

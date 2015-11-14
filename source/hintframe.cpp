#include "hintframe.h"
#include "ui_hintframe.h"
#include "xmlengine.h"

HintFrame::HintFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HintFrame)
{
    ui->setupUi(this);
    XmlEngine* xml=new XmlEngine();
    messages=xml->GetMessages();
}

void HintFrame::SetHintText(int messageID)
{
    ui->textBrowser->setText(messages.at(messageID));
}

void HintFrame::SetHintText(QString message)
{
    ui->textBrowser->setText(message);
}


HintFrame::~HintFrame()
{
    delete ui;
}

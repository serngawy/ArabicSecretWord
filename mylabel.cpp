#include "mylabel.h"
#include <QFrame>
#include <QPalette>



myLabel::myLabel(QWidget *parent) :
   QLabel(parent)
{
    this->setFrameStyle(1);

    setMinimumSize(57,54);
    setMaximumSize(57,54);

    this->setAlignment(Qt::AlignCenter);
    myIndex=-1;
    check=false;
    state=false;

    QFont  myFont;
    myFont.setBold(true);
    myFont.setPointSize(10);
    this->setFont(myFont);
}


void myLabel::mousePressEvent(QMouseEvent *ev)
{
    emit myLabelClick(GetMyIndex());
}

void myLabel::SetActive()
{
    this->setStyleSheet("border-image: url(:/image/images/WordsBtn/Active.png);");
    check=true;
}

void myLabel::SetNonActive()
{
    this->setStyleSheet(mylabelSyle);
    check=false;
}

void myLabel::SetPosition(int x,int y)
{
    this->setGeometry(x,y,this->width(),this->height());
}

void myLabel::SetLetter(QString Letter)
{
  this->setText("<font color=black>"+Letter+"</font>");

}

QString myLabel::GetLetter()
{
    return this->text();
}

bool myLabel::IsBlocked()
{
    return state;
}

void myLabel::SetBlocked()
{
    state=true;
    this->setStyleSheet("border-image: url(:/image/images/WordsBtn/Dimmed.png);");
}

void myLabel::SetNonBlocked()
{
    check = state=false;
     this->setStyleSheet(mylabelSyle);
}

void myLabel::SetMyIndex(int index)
{
    myIndex=index;
}

int myLabel::GetMyIndex()
{
    return myIndex;
}
void myLabel::SetBackGroundImage(QString themeName)
{
    mylabelSyle="border-image: url(:/image/images/WordsBtn/"+themeName+".png);";
    this->setStyleSheet(mylabelSyle);
}

void myLabel::SetMyPair(int pairIndex)
{
    myPair=pairIndex;
}

int myLabel::GetMyPair()
{
    return myPair;
}

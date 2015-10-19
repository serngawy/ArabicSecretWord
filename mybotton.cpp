#include "mybotton.h"
#include "QPushButton"
#include "QString"

myBotton::myBotton(QWidget *parent) :
    QLabel(parent)
{

}

myBotton::myBotton(QWidget *parent,int id,int solvedAssignLockImage) :
    QLabel(parent)
{
    wordId=id;
    setMinimumSize(70,71);
    setMaximumSize(70,71);
    setObjectName("Btn_"+QString("%1").arg(id));
    if(solvedAssignLockImage==0)
        setStyleSheet("border-image: url(:/image/images/Cities_Images/"+QString("%1").arg(wordId)+".png);");
    else if(solvedAssignLockImage==1)
        setStyleSheet("border-image: url(:/image/images/Game Levels/"+QString("%1").arg(wordId)+".png);");
    else if(solvedAssignLockImage==2)
        setStyleSheet("border-image: url(:/image/images/WordsBtn/LockedLevels.png);");

    setMargin(5);
    setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    QFont font;
    font.setBold(true);
    font.setPointSize(6);
    setFont(font);

    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    QBrush brush1(QColor(120, 120, 120, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
    this->setPalette(palette);
}

void myBotton::mousePressEvent(QMouseEvent *)
{
    emit myBtnClick(wordId);
}

void myBotton::SetImage(int solvedAssignLockImage)
{
    if(solvedAssignLockImage==0)
        setStyleSheet("border-image: url(:/image/images/Cities_Images/"+QString("%1").arg(wordId)+".png);");
    else if(solvedAssignLockImage==1)
        setStyleSheet("border-image: url(:/image/images/Game Levels/"+QString("%1").arg(wordId)+".png);");
    else if(solvedAssignLockImage==2)
        setStyleSheet("border-image: url(:/image/images/WordsBtn/LockedLevels.png);");

}

void myBotton::SetScoreText(QString Score)
{
    setText(Score);
}

/*void myBotton::mousePressEvent(QMouseEvent* e)
{
  setStyleSheet("image: url(:/SoraICON/SoraICON/"+QString("%1").arg(SoraId)+".png);");

}

void myBotton::mouseReleaseEvent(QMouseEvent *e)
{
   setStyleSheet("border-image: url(:/SoraICON/SoraICON/"+QString("%1").arg(SoraId)+".png);");
}*/

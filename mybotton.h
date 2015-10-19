#ifndef MYBOTTON_H
#define MYBOTTON_H

#include <QObject>
#include <QPushButton>
#include "QLabel"

class myBotton : public QLabel
{
    Q_OBJECT
public:
    explicit myBotton(QWidget *parent = 0);
    myBotton(QWidget *parent,int id,int solvedAssignLockImage);
    void mousePressEvent(QMouseEvent *);
    //void mouseReleaseEvent(QMouseEvent *e);
    void SetImage(int solvedAssignLockImage);//add style string ,change type to bool for locked
    void SetScoreText(QString Score);
    int wordId;

signals:
   void myBtnClick(int Id);

public slots:

};

#endif // MYBOTTON_H

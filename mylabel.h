#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void SetLetter(QString Letter);
    void SetPosition(int x,int y);
    QString GetLetter();
    bool IsBlocked();
    void SetBlocked();
    void SetNonBlocked();
    void SetActive();
    void SetNonActive();
    void SetMyIndex(int index);
    int GetMyIndex();
    void SetBackGroundImage(QString themeName);//change in code to style string
    void SetMyPair(int pairIndex);
    int GetMyPair();
    void SetSize(int lblWidth,int lblhieght);
private:
    bool check;
    bool state;
    int myIndex;
    QString mylabelSyle;
    int myPair;
 signals:
    void myLabelClick(int idx);

public slots:

};

#endif // MYLABEL_H

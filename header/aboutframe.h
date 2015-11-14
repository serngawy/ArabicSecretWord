#ifndef ABOUTFRAME_H
#define ABOUTFRAME_H

#include <QFrame>

namespace Ui {
    class AboutFrame;
}

class AboutFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AboutFrame(QWidget *parent = 0);
    ~AboutFrame();
    void mousePressEvent(QMouseEvent *);

private:
    Ui::AboutFrame *ui;

};

#endif // ABOUTFRAME_H

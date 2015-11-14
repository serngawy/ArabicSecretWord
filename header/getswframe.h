#ifndef GETSWFRAME_H
#define GETSWFRAME_H

#include <QFrame>

namespace Ui {
    class GetSWFrame;
}

class GetSWFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GetSWFrame(QWidget *parent = 0);
    ~GetSWFrame();

private:
    Ui::GetSWFrame *ui;
};

#endif // GETSWFRAME_H

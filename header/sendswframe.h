#ifndef SENDSWFRAME_H
#define SENDSWFRAME_H

#include <QFrame>

namespace Ui {
    class SendSWFrame;
}

class SendSWFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SendSWFrame(QWidget *parent = 0);
    ~SendSWFrame();

private:
    Ui::SendSWFrame *ui;
};

#endif // SENDSWFRAME_H

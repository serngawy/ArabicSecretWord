#ifndef HELPFRAME_H
#define HELPFRAME_H

#include <QFrame>

namespace Ui {
    class HelpFrame;
}

class HelpFrame : public QFrame
{
    Q_OBJECT

public:
    explicit HelpFrame(QWidget *parent = 0);
    ~HelpFrame();

private:
    Ui::HelpFrame *ui;
};

#endif // HELPFRAME_H

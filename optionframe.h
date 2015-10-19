#ifndef OPTIONFRAME_H
#define OPTIONFRAME_H

#include <QFrame>

namespace Ui {
    class OptionFrame;
}

class OptionFrame : public QFrame
{
    Q_OBJECT

public:
    explicit OptionFrame(QWidget *parent = 0);
    OptionFrame(QWidget *parent,bool crazy);
    ~OptionFrame();
    static bool CrazyGame;
    QString GetCrazyState();

private:
    Ui::OptionFrame *ui;

private slots:
    void CrazyGameOption();
};

#endif // OPTIONFRAME_H

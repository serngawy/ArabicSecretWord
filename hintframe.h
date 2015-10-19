#ifndef HINTFRAME_H
#define HINTFRAME_H

#include <QFrame>


namespace Ui {
    class HintFrame;
}

class HintFrame : public QFrame
{
    Q_OBJECT

public:
    explicit HintFrame(QWidget *parent = 0);
    ~HintFrame();
    void SetHintText(QString message);
    void SetHintText(int messageID);

private:
    Ui::HintFrame *ui;
    QStringList messages;

};

#endif // HINTFRAME_H

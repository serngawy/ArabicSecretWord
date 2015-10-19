#ifndef WORDINFOFRAME_H
#define WORDINFOFRAME_H

#include <QFrame>

namespace Ui {
    class WordInfoFrame;
}

class WordInfoFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WordInfoFrame(QWidget *parent = 0);
    ~WordInfoFrame();
    void SetInfoText(QString info,int infoID,QString cityName);

private:
    Ui::WordInfoFrame *ui;

private slots:
    void NextWord();
    void RestartGame();
};

#endif // WORDINFOFRAME_H

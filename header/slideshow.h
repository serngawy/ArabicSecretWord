#ifndef SLIDESHOW_H
#define SLIDESHOW_H
#include <QWidget>
#include <qmediaimageviewer.h>

class QAbstractButton;
class QLabel;
class QStackedLayout;

class QMediaPlaylist;

QT_USE_NAMESPACE

class SlideShow : public QWidget
{
    Q_OBJECT
public:
    //explicit SlideShow(QWidget *parent = 0);
    SlideShow(QWidget *parent,int wV,int hV);
    SlideShow(QWidget *parent);
    void playAll(QString imageDir);
    bool eventFilter(QObject *obj, QEvent *ev);
    void SetDirectory(QString imageDir);
    void Play();
    void Stop();
    void ShowSkipButton(bool visible);
    void Loop(bool loop);
    void SetSlideTime(int frameTime);
    void PlayFile(QString mediaFile);


private:
    QMediaImageViewer *imageViewer;
    QMediaPlaylist *playlist;
    QLabel *statusLabel;
    QStackedLayout *viewerLayout;

private slots:
    void ViewerChangeStatus(QMediaImageViewer::State state);
};


#endif // SLIDESHOW_H

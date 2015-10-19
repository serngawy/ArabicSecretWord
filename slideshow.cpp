#include "slideshow.h"

#include <qmediaservice.h>
#include <qmediaplaylist.h>
#include <qvideowidget.h>
#include "mainwindow.h"
#include <QMainWindow>


 #include <QtGui>


SlideShow::SlideShow(QWidget *parent)
    : QWidget(parent)
    , imageViewer(0)
    , playlist(0)
    , statusLabel(0)
    , viewerLayout(0)
{
    imageViewer = new QMediaImageViewer(this);
    playlist = new QMediaPlaylist;
    imageViewer->bind(playlist);

    QVideoWidget *videoWidget = new QVideoWidget;

    videoWidget->setGeometry(0,0,640,360);

    imageViewer->bind(videoWidget);
    imageViewer->setTimeout(40);
    statusLabel = new QLabel("Skip");
    statusLabel->setGeometry(0,0,30,15);

    statusLabel->installEventFilter(this);
    statusLabel->setAlignment(Qt::AlignTop);



    viewerLayout = new QStackedLayout;
    viewerLayout->setStackingMode(QStackedLayout::StackAll);
    viewerLayout->addWidget(videoWidget);
    viewerLayout->addWidget(statusLabel);
    setLayout(viewerLayout);

    this->setStyleSheet("border-image: url(:/image/images/backgrounds/Background_Transparent.png);");

    connect(imageViewer,SIGNAL(stateChanged(QMediaImageViewer::State)),this,SLOT(close()));
}

 SlideShow::SlideShow(QWidget *parent,int wV,int hV)
     : QWidget(parent)
     , imageViewer(0)
     , playlist(0)
     , statusLabel(0)
     , viewerLayout(0)
 {
     imageViewer = new QMediaImageViewer(this);
     playlist = new QMediaPlaylist;
     imageViewer->bind(playlist);

     QVideoWidget *videoWidget = new QVideoWidget;

     videoWidget->setGeometry(0,0,wV,hV);

     imageViewer->bind(videoWidget);
     imageViewer->setTimeout(50);
     statusLabel = new QLabel("Skip");
     statusLabel->setGeometry(0,0,30,15);

     statusLabel->installEventFilter(this);
     statusLabel->setAlignment(Qt::AlignTop);



     viewerLayout = new QStackedLayout;
     viewerLayout->setStackingMode(QStackedLayout::StackAll);
     viewerLayout->addWidget(videoWidget);
     viewerLayout->addWidget(statusLabel);
     setLayout(viewerLayout);

     this->setStyleSheet("border-image: url(:/image/images/backgrounds/Background_Transparent.png);");

     connect(imageViewer,SIGNAL(stateChanged(QMediaImageViewer::State)),this,SLOT(close()));
 }



 void SlideShow::ViewerChangeStatus(QMediaImageViewer::State state)
 {

 }


 void SlideShow::playAll(QString imageDir)
 {
     if (!imageDir.isEmpty()) {
         playlist->clear();

         //QDir dir(imageDir);

        // foreach (const QString &fileName, dir.entryList(QDir::Files))
         for(int i=0;i<114;i++)
             playlist->addMedia(QUrl::fromLocalFile(imageDir+QString("%1").arg(i)+".jpg"));

         imageViewer->play();
     }
 }

 bool SlideShow::eventFilter(QObject *obj, QEvent *ev)
 {

     if(obj==statusLabel && ev->type()==QEvent::MouseButtonPress)
        this->close();

     return true;
 }

 void SlideShow::PlayFile(QString mediaFile)
 {
     if (!mediaFile.isEmpty()) {
         playlist->clear();

         playlist->addMedia(QUrl::fromLocalFile(mediaFile));

         imageViewer->play();
     }
 }

 void SlideShow::SetDirectory(QString imageDir)
 {
     if (!imageDir.isEmpty())
     {
         playlist->clear();
         QDir dir(imageDir);
         foreach (const QString &fileName, dir.entryList(QDir::Files))
             playlist->addMedia(QUrl::fromLocalFile(dir.absoluteFilePath(fileName)));
     }
 }

 void SlideShow::Loop(bool loop)
 {
     if(loop)
       playlist->setPlaybackMode(QMediaPlaylist::Loop);
      else
         playlist->setPlaybackMode(QMediaPlaylist::Sequential);
 }

 void SlideShow::ShowSkipButton(bool visible)
 {
     statusLabel->setVisible(visible);
 }

 void SlideShow::Play()
 {

     imageViewer->play();
 }


 void SlideShow::Stop()
 {
     imageViewer->stop();
 }

 void SlideShow::SetSlideTime(int frameTime)
 {
      imageViewer->setTimeout(frameTime);
 }


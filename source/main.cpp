#include "mainwindow.h"
#include <QtGui/QApplication>
#include "QSplashScreen"
#include "gameframe.h"
#include "gameintroframe.h"
#include "gametypeframe.h"


#ifdef Q_OS_SYMBIAN
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>
#include <QSymbianEvent>
#include <w32std.h>
#endif


class MyApplication : public QApplication
  {
  public:
    MyApplication( int argc, char** argv ) : QApplication( argc, argv ) {}

  #ifdef Q_OS_SYMBIAN
  protected:
    bool symbianEventFilter( const QSymbianEvent* symbianEvent ) {
      const TWsEvent *event = symbianEvent->windowServerEvent();

      if( !event ) {
        return false;
      }

      switch( event->Type() )
      {
         case EEventFocusLost:
            {
               if(this->activeWindow()->objectName()=="MainWindow")
                {
                   MainWindow *w=qobject_cast<MainWindow *>(this->activeWindow());
                   w->settFrame->SoundLostFocuse();
                   GameFrame* gFrame=w->findChild<GameFrame*>("GameFrame");
                  if(gFrame!=NULL)
                    gFrame->Pause();

                }
             }
              break;
        default:
          break;
      }

      // Always return false so we don't stop
      // the event from being processed
      return false;
    }
  #endif // Q_OS_SYMBIAN
  };


int main(int argc, char *argv[])
{
    MyApplication app(argc, argv);

    #ifdef Q_OS_SYMBIAN
        CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
        TRAPD(error,
        if (appUi)
        {
            appUi->SetOrientationL(CAknAppUi::EAppUiOrientationLandscape);
        }
        );
    #endif

    QPixmap pixmap(QPixmap(app.applicationDirPath()+"/loading.jpg"));
    QSplashScreen splash(pixmap);
    splash.showFullScreen();
    splash.raise();
    MainWindow mainWindow;
    QTimer::singleShot(4000,&splash, SLOT(close()));
    QTimer::singleShot(1000, &mainWindow, SLOT(showFullScreen()));

    return app.exec();
}



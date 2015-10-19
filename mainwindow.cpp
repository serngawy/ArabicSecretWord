#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>
#include "QMessageBox"
#include "QMenu"
#include "slideshow.h"
#include "QVBoxLayout"
#include "QGraphicsAnchorLayout"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SlideShow* slideWidget=new SlideShow(this);
    slideWidget->setGeometry(0,0,640,360);
    slideWidget->Loop(false);
    slideWidget->ShowSkipButton(true);
    slideWidget->playAll(qApp->applicationDirPath()+"/VideoRendered/");
    slideWidget->showFullScreen();

    xml=new XmlEngine();
    QStringList settings=xml->GetSettings();
    optFrame=new OptionFrame(this,settings.at(1)=="true");
    optFrame->setVisible(false);
    settFrame=new SettingFrame(this,settings.at(0)=="OFF");
    settFrame->setVisible(false);
    gtFrame=new GameTypeFrame(this);
    gtFrame->setVisible(false);


connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OpenOption()));
connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(OpenSetting()));
connect(ui->pushBtn_GType,SIGNAL(clicked()),this,SLOT(openGameTypes()));
connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(OnClose()));


 settFrame->setGeometry(ui->pushButton_2->x(),settFrame->y()+20,settFrame->width(),settFrame->height());
 optFrame->setGeometry(optFrame->x(),optFrame->y()+5,optFrame->width(),optFrame->height());

/* QVBoxLayout* grid=new QVBoxLayout();
 SlideShow* myview=new SlideShow(ui->frame,ui->frame->width(),ui->frame->height());
 myview->setVisible(true);
 myview->Loop(true);
 myview->ShowSkipButton(false);
 myview->playAll("F:/output02");//D:/Work/output02
 grid->addWidget(myview,1,Qt::AlignAbsolute);
 ui->frame->setLayout(grid);
 myview->show();*/

}

void MainWindow::SwitchSound()
{
    if(settFrame->GetSoundState()=="true")
    {

    }
}



void MainWindow::OnClose()
{
    QStringList settings;
    settings<<settFrame->GetSoundState();
    settings<<optFrame->GetCrazyState();
    xml->SaveSettings(settings);
}

void  MainWindow::openGameTypes()
{
    gtFrame->showFullScreen();
}

void MainWindow::OpenSetting()
{
    if(settFrame->isVisible())
        settFrame->close();
    else
       settFrame->setVisible(true);
}

void MainWindow::OpenOption()
{
    if(optFrame->isVisible())
        optFrame->close();
    else
       optFrame->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}



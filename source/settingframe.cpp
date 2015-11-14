#include "settingframe.h"
#include "ui_settingframe.h"
#include "phonon"

SettingFrame::SettingFrame(QWidget *parent,bool mute) :
    QFrame(parent),
    ui(new Ui::SettingFrame)
{
    ui->setupUi(this);


    aFrame=new AboutFrame(this->parentWidget());
    aFrame->setVisible(false);
    aFrame->setGeometry(640/4,10,aFrame->width(),aFrame->height());
    hFrame=new HelpFrame(this->parentWidget());
    hFrame->setVisible(false);


    soundcls=new SoundClass(qApp->applicationDirPath()+"/sound.mp3");

    if(mute)
       ui->pushBtn_Sound->setStyleSheet("border-image: url(:/image/images/Settings Menu/Normal btns/Btns_Slices_43.png);");
    else
       soundcls->PlaySound();



    connect(ui->pushBtn_exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(ui->pushBtn_About,SIGNAL(clicked()),this,SLOT(OpenAbout()));
    connect(ui->pushBtn_Help,SIGNAL(clicked()),this,SLOT(OpenHelp()));
    connect(ui->pushBtn_Sound,SIGNAL(clicked()),this,SLOT(ChangeSound()));
}

SettingFrame::SettingFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingFrame)
{
    ui->setupUi(this);

    aFrame=new AboutFrame(this->parentWidget());
    aFrame->setVisible(false);

    hFrame=new HelpFrame(this->parentWidget());
    hFrame->setVisible(false);
    soundcls=new SoundClass(qApp->applicationDirPath()+"/sound.mp3");
    //soundcls->PlaySound();

    connect(ui->pushBtn_exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(ui->pushBtn_About,SIGNAL(clicked()),this,SLOT(OpenAbout()));
    connect(ui->pushBtn_Help,SIGNAL(clicked()),this,SLOT(OpenHelp()));
    connect(ui->pushBtn_Sound,SIGNAL(clicked()),this,SLOT(ChangeSound()));
}

SettingFrame::~SettingFrame()
{
    delete ui;
}

void SettingFrame::OpenAbout()
{
    aFrame->showFullScreen();
}

void SettingFrame::OpenHelp()
{
    hFrame->showFullScreen();
}

void SettingFrame::ChangeSound()
{
    if(soundcls->IsPlay())
    {
        soundcls->StopSound();
        ui->pushBtn_Sound->setStyleSheet("border-image: url(:/image/images/Settings Menu/Normal btns/Btns_Slices_43.png);");
    }
    else
    {
        soundcls->PlaySound();
        ui->pushBtn_Sound->setStyleSheet("border-image: url(:/image/images/Settings Menu/Normal btns/Btns_Slices_41.png);");
    }
}

QString SettingFrame::GetSoundState()
{
    if(soundcls->IsPlay())
        return "ON";
    else
        return "OFF";
}

void SettingFrame::SoundLostFocuse()
{
    if(ui->pushBtn_Sound->styleSheet()=="border-image: url(:/image/images/Settings Menu/Normal btns/Btns_Slices_41.png);")
    {
        soundcls->StopSound();
        ui->pushBtn_Sound->setStyleSheet("border-image: url(:/image/images/Settings Menu/Normal btns/Btns_Slices_43.png);");
    }
}



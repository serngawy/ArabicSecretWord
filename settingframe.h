#ifndef SETTINGFRAME_H
#define SETTINGFRAME_H

#include <QFrame>
#include "helpframe.h"
#include "aboutframe.h"
#include "soundclass.h"
#include "xmlengine.h"

namespace Ui {
    class SettingFrame;
}

class SettingFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SettingFrame(QWidget *parent = 0);
    SettingFrame(QWidget *parent,bool mute);
    ~SettingFrame();
    QString GetSoundState();
    void SoundLostFocuse();

private:
    Ui::SettingFrame *ui;
    HelpFrame* hFrame;
    AboutFrame* aFrame;
    SoundClass* soundcls;



private slots:
    void OpenHelp();
    void OpenAbout();
    void ChangeSound();



};

#endif // SETTINGFRAME_H

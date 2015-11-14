#ifndef SOUNDCLASS_H
#define SOUNDCLASS_H

#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include "QObject"
#include <QSound>
#include "QMediaPlayer"

class SoundClass :public QObject
{
public:
    SoundClass();
    SoundClass(QString filePath);
    void PlaySoundFile(QString filePath);
    void StopSound();
    void PlaySound();
    bool IsPlay();

private:
   // Phonon::MediaObject *mediaObject;
   // Phonon::AudioOutput *audioOutput;
   // QSound* mySound;
   // bool play;
    QMediaPlayer *player;

};

#endif // SOUNDCLASS_H

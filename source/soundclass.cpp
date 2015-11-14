#include "soundclass.h"
#include "QObject"
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include <QtCore/QCoreApplication>
#include "QSound"
#include "QSound"
#include "QMediaPlaylist"

SoundClass::SoundClass()
{
   // mediaObject=new Phonon::MediaObject(0);
   // audioOutput=new Phonon::AudioOutput(Phonon::MusicCategory,0);
   // Phonon::createPath(mediaObject,audioOutput);
}



SoundClass::SoundClass(QString filePath)
{
   /* mediaObject=new Phonon::MediaObject(0);
    audioOutput=new Phonon::AudioOutput(Phonon::MusicCategory,0);

    Phonon::createPath(mediaObject,audioOutput);
    mediaObject->setCurrentSource(filePath);


    mediaObject->
   // mySound=new QSound(filePath,qApp);
    //mySound->setLoops(100);
    play=false;*/

    player = new QMediaPlayer;
    //connect(player,SIGNAL())

    QUrl url = QUrl::fromLocalFile(filePath);//path + QLatin1String("/qml/lightapp/moto.wav"));
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(url);
    playlist->setPlaybackMode( QMediaPlaylist::Loop );
    player->setPlaylist( playlist );
    playlist->setCurrentIndex(0);
    player->setVolume(60);
   // player->play();
}


void SoundClass::PlaySoundFile(QString filePath)
{
   // QString fileName(filePath);
   // mediaObject->setCurrentSource(filePath);
   // mediaObject->play();
   // mySound->play(filePath);
}

void SoundClass::StopSound()
{
   // mediaObject->stop();
   // mySound->stop();
   // play=false;
    player->stop();
}

void SoundClass::PlaySound()
{
   // mySound->play();
   // play=true;
   // mediaObject->play();
    player->play();
}

 bool SoundClass::IsPlay()
 {
   return player->state()== QMediaPlayer::PlayingState;
 }

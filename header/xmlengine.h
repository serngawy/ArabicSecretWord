#ifndef XMLENGINE_H
#define XMLENGINE_H


#include <QtCore/QPointer>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtXml/QXmlStreamReader>
#include "myword.h"
#include "gamesubject.h"


class XmlEngine
{
public:
    XmlEngine();
    XmlEngine(QString xmlDirectories);
    QStringList GetLetters();
    myWord GetWord(int index);//add word file
    void SaveSettings(QStringList settings);
    QStringList GetSettings();
    QStringList GetScores();//score file
    void SetScores(QStringList scores);//score file
    QStringList GetMessages();
    QList<GameSubject*> GetGameSubjects();

private:
    QString Directory;
    QString RefineString(QByteArray fineText);




};

#endif // XMLENGINE_H

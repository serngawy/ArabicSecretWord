#include "xmlengine.h"
#include <QMessageBox>
#include <QFile>
#include <QList>
#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "QApplication"
#include "myword.h"
#include "QTextStream"
#include "QTextCodec"

XmlEngine::XmlEngine()
{
    Directory=qApp->applicationDirPath();
}
XmlEngine::XmlEngine (QString xmlDirectories)
{
    Directory=xmlDirectories;
}


QStringList XmlEngine::GetSettings()
{
    QStringList settings;
    QFile* file = new QFile(Directory+"/Settings.xml");

    if (!file->open(QIODevice::ReadOnly| QIODevice::Text))
        return settings;
    QXmlStreamReader xml(file);

    while(!xml.atEnd() &&!xml.hasError())
    {

            QXmlStreamReader::TokenType token = xml.readNext();
            if(token == QXmlStreamReader::StartDocument)
            {
                    continue;
            }
            if(token == QXmlStreamReader::StartElement)
            {
                if(xml.name() == "Settings")
                   continue;

                QXmlStreamAttributes attrs = xml.attributes();
                QStringRef attrValue = attrs.value("attrValue");
                if(xml.name() == "Sound")
                   settings<<attrValue.toString();
                else if(xml.name()=="Crazy")
                    settings<<attrValue.toString();

            }
    }

    xml.clear();
    file->close();
    return settings;
}


QStringList XmlEngine::GetLetters()
{
    QFile* file = new QFile(Directory+"/Letters.txt");
    QStringList letters;
    if (!file->open(QFile::ReadOnly))//QIODevice::ReadOnly| QIODevice::Text
        return letters;

    QXmlStreamReader xml(RefineString(file->readAll()));

    while(!xml.atEnd() &&!xml.hasError())
    {

            QXmlStreamReader::TokenType token = xml.readNext();
            if(token == QXmlStreamReader::StartDocument)
            {
                    continue;
            }
            if(token == QXmlStreamReader::StartElement)
            {
                if(xml.name() == "Letters")
                   continue;

                QXmlStreamAttributes attrs = xml.attributes();
                QStringRef attrValue = attrs.value("symbol");
                letters<<attrValue.toString();

            }
    }

    xml.clear();
    file->close();
    return letters;
}

myWord XmlEngine::GetWord(int index)
{
    QFile* file = new QFile(Directory+"/words_city.txt");
    myWord my_word;

    if (!file->open(QFile::ReadOnly))
        return my_word;

    QXmlStreamReader xml(RefineString(file->readAll()));

    QString id=QString("%1").arg(index);
    while(!xml.atEnd() &&!xml.hasError())
    {

            QXmlStreamReader::TokenType token = xml.readNext();
            if(token == QXmlStreamReader::StartDocument)
            {
                    continue;
            }
            if(token == QXmlStreamReader::StartElement)
            {
              if(xml.name() == "Words")
                continue;

              if(xml.name()=="Word")
              {
                 QXmlStreamAttributes attrs = xml.attributes();
                 QStringRef attrValueId = attrs.value("id");
                 if(!attrValueId.toString().compare(id))
                 {
                     QStringRef attrValueT = attrs.value("text");
                     QStringRef attrValueH = attrs.value("hint");
                     my_word.Hint=attrValueH.toString();
                     my_word.id=index;
                     my_word.word=attrValueT.toString();
                     my_word.infromation= xml.readElementText();
                     xml.clear();
                     file->close();
                     return my_word;
                }
              }
            }
    }

    xml.clear();
    file->close();
    return my_word;
}



void XmlEngine::SaveSettings(QStringList settings)
{
    QFile* file = new QFile(Directory+"/Settings.xml");

    if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QXmlStreamWriter xml(file);

    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Settings");

    xml.writeEmptyElement("Sound");
    xml.writeAttribute("attrValue",settings.at(0));

    xml.writeEmptyElement("Crazy");
    xml.writeAttribute("attrValue",settings.at(1));


    xml.writeEndElement();
    xml.writeEndDocument();


    file->close();

}

QString XmlEngine::RefineString(QByteArray fineText)
{
   // QTextCodec *codec = QTextCodec::codecForName("UTF-16");
    QTextCodec *codec = QTextCodec::codecForMib(1015);
    QTextStream in(&fineText);
    in.setAutoDetectUnicode(false);
    in.setCodec(codec);
    return in.readAll();
    //QMessageBox::information(0)

}

QStringList XmlEngine::GetScores()
{
    QStringList scores;
    QFile* file = new QFile(Directory+"/Solve_city.xml");

    if (!file->open(QIODevice::ReadOnly| QIODevice::Text))
        return scores;
    QXmlStreamReader xml(file);

    while(!xml.atEnd() &&!xml.hasError())
    {

            QXmlStreamReader::TokenType token = xml.readNext();
            if(token == QXmlStreamReader::StartDocument)
            {
                    continue;
            }
            if(token == QXmlStreamReader::StartElement)
            {
                if(xml.name() == "Words")
                   continue;

               QXmlStreamAttributes attrs = xml.attributes();
               QStringRef attrValue = attrs.value("solve");
               scores<<attrValue.toString();


            }
    }

    xml.clear();
    file->close();
    return scores;
}

void XmlEngine::SetScores(QStringList scores)
{
    QFile* file = new QFile(Directory+"/Solve_city.xml");

    if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Words");

    for(int i=0;i<scores.length();i++)
    {
        xml.writeEmptyElement("Word");
        xml.writeAttribute("solve",scores.at(i));
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
}

QStringList XmlEngine::GetMessages()
{
    QFile* file = new QFile(Directory+"/Messages.txt");
    QStringList messages;
    if (!file->open(QFile::ReadOnly))//QIODevice::ReadOnly| QIODevice::Text
        return messages;

    QXmlStreamReader xml(RefineString(file->readAll()));

    while(!xml.atEnd() &&!xml.hasError())
    {

            QXmlStreamReader::TokenType token = xml.readNext();
            if(token == QXmlStreamReader::StartDocument)
            {
                    continue;
            }
            if(token == QXmlStreamReader::StartElement)
            {
                if(xml.name() == "Messages")
                   continue;

                QXmlStreamAttributes attrs = xml.attributes();
                QStringRef attrValue = attrs.value("Text");
                messages<<attrValue.toString();

            }
    }

    xml.clear();
    file->close();
    return messages;
}

QList<GameSubject*> XmlEngine::GetGameSubjects()
{
    QList<GameSubject*> game_Subjects;
    return game_Subjects;
}

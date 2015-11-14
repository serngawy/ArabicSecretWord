#include "lettersgenratoir.h"
#include <QList>
#include <QString>
#include <QStringList>
#include <QXmlStreamReader>
#include <QFile>
#include <QXmlStreamWriter>
#include <QDataStream>
#include <QTextStream>
#include "xmlengine.h"
#include "qapplication.h"



LettersGenratoir::LettersGenratoir()
{

}


QStringList LettersGenratoir::GenerateLetters(int wordID)
{
    XmlEngine* xmlEng=new XmlEngine();
     QStringList LangLetters;
     LangLetters=xmlEng->GetLetters();
     int langLetCount=LangLetters.length();

     myWord my_word=xmlEng->GetWord(wordID);

     QString SecretWord=my_word.word;
     SecretWord=DecryptWord(SecretWord,LangLetters);
     QStringList gameLetters;


     int len= SecretWord.length();
     int i;
     for(i=0;i<len;i++)
     {
       QString st(SecretWord.at(i));
       gameLetters<<st;
     }
     if((len%2)==0)
     {
         gameLetters<<"-";
         len++;
     }
     for(i=len;i<40;i++)
     {
       int idx=qrand()%langLetCount;
       gameLetters<<LangLetters.at(idx);
       gameLetters<<LangLetters.at(idx);
     }
     for(int j=0;j<20;j++)
         gameLetters.swap(j,j+j);

    // gameLetters<<SecretWord;
    // gameLetters<<tempList.at(1);
     return gameLetters;
}

QStringList LettersGenratoir::GenerateLetters(QString SecretWord)
{
     XmlEngine* xmlEng=new XmlEngine();
     QStringList LangLetters;
     LangLetters=xmlEng->GetLetters();
     int langLetCount=LangLetters.length();
     QStringList gameLetters;

     int len= SecretWord.length();
     int i;
     for(i=0;i<len;i++)
     {
       QString st(SecretWord.at(i));
       gameLetters<<st;
     }
     if((len%2)==0)
     {
         gameLetters<<"-";
         len++;
     }
     for(i=len;i<55;i++)
     {
       int idx=qrand()%langLetCount;
       gameLetters<<LangLetters.at(idx);
       gameLetters<<LangLetters.at(idx);
     }
     for(int j=0;j<20;j++)
         gameLetters.swap(j,j+j);

     return gameLetters;
}

QString LettersGenratoir::EnecryptWord(QString Word)
{
    //C=P+K % len
    XmlEngine* xmlEng=new XmlEngine();
    QStringList LangLetters;
    LangLetters=xmlEng->GetLetters();
    return this->EnecryptWord(Word,LangLetters);
}

QString LettersGenratoir::EnecryptWord(QString Word, QStringList LangLetters)
{
    int langLetCount=LangLetters.length();
    QList<int> key;
    key<<3<<5<<7<<11<<13<<19;
    QList<int> planText;
    for(int i=0;i<Word.count();i++)
    {
        QChar p=Word.at(i);
        planText<<LangLetters.indexOf(p,0);
    }

    QString cipherText="";
    QString tempStr="";
    for(int j=0;j<planText.length();j++)
    {
        int c=(planText.at(j)+key.at(j%key.length()))%langLetCount;
        cipherText.append(LangLetters.at(c));
        tempStr.append(LangLetters.at((c+1)%langLetCount));
    }
    QChar s1=cipherText.at(0);
    QChar s2=cipherText.at(cipherText.count()-1);
    int s3=LangLetters.indexOf(s1)+LangLetters.indexOf(s2);
    if(s3>langLetCount-1)
        s3=s3-langLetCount;

    tempStr.insert(0,s1);
    tempStr.insert(1,s2);
    tempStr.insert(2,LangLetters.at(s3));
    tempStr.append(LangLetters.at(s3));

    return tempStr;
}


QString LettersGenratoir::DecryptWord(QString EncWord)
{
    //P=C-K % len
    if(EncWord.length()<4)
        return "";

    XmlEngine* xmlEng=new XmlEngine();
    QStringList LangLetters;
    LangLetters=xmlEng->GetLetters();
    return DecryptWord(EncWord,LangLetters);
}

QString LettersGenratoir::DecryptWord(QString EncWord, QStringList LangLetters)
{
    //P=C-K % len
    int langLetCount=LangLetters.length();
    QChar s1=EncWord.at(0);
    QChar s2=EncWord.at(1);
    QChar s3=EncWord.at(2);
    if(s3!= EncWord.at(EncWord.count()-1))
        return "";

    int id=LangLetters.indexOf(s1)+LangLetters.indexOf(s2);

    if(id>langLetCount-1)
        id=id-langLetCount;

    if(id != LangLetters.indexOf(s3))
        return "";

    EncWord.remove(0,3);
    EncWord.remove(EncWord.count()-1,1);

    QList<int> key;
    key<<3<<5<<7<<11<<13<<19;
    QList<int> cipherText;
    for(int i=0;i<EncWord.count();i++)
    {
        QChar c=EncWord.at(i);
        int id=LangLetters.indexOf(c,0);
        if(id == 0)
            cipherText<<25;
        else
            cipherText<<(id-1);
    }

    QString planText="";
    for(int j=0;j<cipherText.length();j++)
    {
        int p=(cipherText.at(j)-key.at(j%key.length()))%langLetCount;
        if(p<0)
            p=langLetCount+p;
        planText.append(LangLetters.at(p));
    }

    return planText;
}

void LettersGenratoir::GenerateWords()
{
    XmlEngine* xmlEng=new XmlEngine();
    QStringList LangLetters;
    LangLetters=xmlEng->GetLetters();

    QStringList SWords;

    SWords<<"NOKIA"<<"LOVE"<<"YOU"<<"LION"<<"HUGS"<<"MONEY"<<"TIGER"<<"ANT"
            <<"PEACH"<<"CHIKEN"<<"FLOWER"<<"BRAIN"<<"FATHER"<<"WOMEN"<<"HOUSE"
            <<"FAIR"<<"LIBERTY"<<"EARTH"<<"ORANGE"<<"PICTURE"<<"MONKEYS"<<"OCEAN"
            <<"GIRLS"<<"MOTHER"<<"COUNTRY"<<"MOBILES"<<"EGYPT"<<"TANK"<<"STINKY"
            <<"SCHOOL"<<"DOCTORS"<<"SECRET"<<"APPLE"<<"LIPSTICK"<<"SISTER"
            <<"WEATHER"<<"COLLAGE"<<"ELEPHANT"<<"PEACE"<<"PRETTY"<<"PENGUIN"
            <<"FINLAND"<<"BEAUTIFUL"<<"BUSINESS"<<"EMPLOYEE"<<"CHOCOLAT"<<"COCONUT"
            <<"SCIENCE"<<"PINEAPPLE"<<"LETTERS"<<"SKILLS"<<"PEOPLE"<<"CONNECTING"
            <<"BANANA";

    QStringList hints;

    hints<<"Big Mobile Company"<<"Like Adore"<<"Pronoun"<<"Wild Animal"<<"Embrace"<<"needs for buying"
            <<"Wild Animal"<<"Small Insect"<<"Fruit"<<"Bird"<<"Plant"<<"Necessary for Thinking"
            <<"Someone Close to You"<<"Lady"<<"Home Sweet Home"<<"Justice"<<"Freedom"<<"Planet"
            <<"Fruit"<<"You Draw it"<<"Funny Animals"<<"Large Area of Water"<<"Not a Boy"
            <<"Who raised You Up"<<"Land"<<"Cell Phone"<<"Country"<<"Container"<<"With Bad Odor"
            <<"Teaching Center"<<"Physicians"<<"You Whisper it"<<"Fruit"<<"Girls Wear it"<<"One of the Family"
            <<"Climate"<<"Teaching Center"<<"Huge Animal"<<"World Wide Wish"<<"Beautiful"<<"Bird Lives in Cold Areas"
            <<"Country"<<"Pretty"<<"Get The Money"<<"In The Job"<<"Something Made by Coco & Milk"<<"Tropical Fruit"
            <<"Knowledge about the World"<<"Tropical Fruit"<<"To Form a Word"<<"Somethings you may have or Gifted"
            <<"Group of Persons"<<"Nokia ... People"<<"Fruits that Monkeys Eat";

    QFile* file = new QFile(qApp->applicationDirPath()+"/words.xml");


    if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QXmlStreamWriter xml(file);

    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Words");

    for(int i=0 ;i<SWords.length();i++)
    {
        QString w=EnecryptWord(SWords.at(i),LangLetters);
        xml.writeEmptyElement("Word");
        xml.writeAttribute("hint",hints.at(i));
        xml.writeAttribute("text",w);
    }


    xml.writeEndElement();
    xml.writeEndDocument();


    file->close();

}

QStringList LettersGenratoir::GetSolvedWords(int Ids)
{
    QStringList words;
    if(Ids !=-1)
    {
        int count=0;
        XmlEngine* xmlEng=new XmlEngine();
        QStringList LangLetters;
        LangLetters=xmlEng->GetLetters();
        QFile* file = new QFile(qApp->applicationDirPath()+"/words.xml");

        if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
            return words;

        QXmlStreamReader xml(file);
        while(!xml.atEnd() &&!xml.hasError() && count < Ids)
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
                  QStringRef attrValueT = attrs.value("text");
                  count++;
                  words<<DecryptWord(attrValueT.toString(),LangLetters).insert(0,QString("%1").arg(count)+"-");
                }
        }

        xml.clear();
        file->close();
    }
    return words;
}

void LettersGenratoir::GenerateExpressWords()
{
    XmlEngine* xmlEng=new XmlEngine();
    QStringList LangLetters;
    LangLetters=xmlEng->GetLetters();

    QStringList SWords;

    SWords<<"SNOW"<<"JUICE"<<"PEACH"<<"YOGURT"<<"FIVE"<<"SQUID"<<"FROG"<<"ROCKET"<<"BOGEY"
            <<"SOFA"<<"VICTORY"<<"POLAND"<<"VIRUS"<<"MILK"<<"BRUSH"<<"NOSE"
            <<"PRISON"<<"DOOR"<<"HUMMER"<<"HUNTER"<<"PICTURE"<<"MONKEYS"<<"OCEAN"
            <<"HEAVEN"<<"MOTHER"<<"WEEK"<<"BUFFALO"<<"SPOON"<<"ZOO"<<"JOGGING"
            <<"PURPLE"<<"DOCTORS"<<"SECRET"<<"APPLE"<<"JAUNARY"<<"SISTER"
            <<"WEATHER"<<"GOOD"<<"ELEPHANT"<<"PEACE"<<"PRETTY"<<"PENGUIN"
            <<"ELECTRICITY"<<"GREET"<<"BUSINESS"<<"MEDICINE"<<"CHOCOLAT"<<"COCONUT"
            <<"SCIENCE"<<"PINEAPPLE"<<"LETTERS"<<"BISCUITS"<<"BOTTOM"<<"SKILLS"<<"WEDDING"<<"PEOPLE"<<"ZIGZAG"
            <<"MUSHROOM"<<"BANANA"<<"SLEEP"<<"BOOK"<<"FOOT"<<"FINISH";


    QStringList hints;

    hints<<"Like Ice"<<"Something to Drink"<<"Fruit"<<"Diary Milk Product"<<"Odd Number"<<"Live Under the Sea"<<"One of the Amphibians"
            <<"In the Space"<<"Ogre"<<"You Sit on"<<"Trimph"<<"Country"<<"Cause Diseases"
            <<"With Breakfast"<<"To Fix your Hair"<<"In your Face"<<"Jail"<<"You open and Close it"<<"Tool"
            <<"Sniper"<<"You Draw it"<<"Funny Animals"<<"Large Area of Water"<<"Not The Hell"
            <<"Who raised You Up"<<"7 Days"<<"Animal Farm"<<"You eat With"<<"Full of Animals"<<"Sports Like Walking"
            <<"Color"<<"Physicians"<<"You Whisper it"<<"Fruit and Company"<<"a Month"<<"One of the Family"
            <<"Climate"<<"Nice or Cute"<<"Huge Animal"<<"World Wide Wish"<<"Beautiful"<<"Bird Lives in Cold Areas"
            <<"In the Plug & Volt"<<"Saying Hi"<<"Get The Money"<<"You Take it when you are ill"<<"Something Made by Coco & Milk"<<"Tropical Fruit"
            <<"Knowledge about the World"<<"Tropical Fruit"<<"To Form a Word"<<"With Tea"<<"Deep"<<"Somethings you may have or Gifted"
            <<"Occasion of Marriage"<<"Group of Persons"<<"Not Strait"<<"Like Fungus"<<"Fruit"<<"When you are Tired"
            <<"You read it"<<"In your Legs"<<"The End";

    QFile* file = new QFile(qApp->applicationDirPath()+"/words.xml");


    if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QXmlStreamWriter xml(file);

    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Words");
    int j=0;
    for(int i=0 ;i<SWords.length();i++)
    {
        QString w=EnecryptWord(SWords.at(i),LangLetters);
        xml.writeEmptyElement("Word");
        xml.writeAttribute("hint",hints.at(i));
        xml.writeAttribute("text",w);
        j++;
    }


    xml.writeEndElement();
    xml.writeEndDocument();


    file->close();

}

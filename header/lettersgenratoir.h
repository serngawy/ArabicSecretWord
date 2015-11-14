#ifndef LETTERSGENRATOIR_H
#define LETTERSGENRATOIR_H
#include <QList>
#include <QString>
#include <QStringList>


class LettersGenratoir
{
public:
     LettersGenratoir();
     QStringList GenerateLetters(int wordID);//add number of letters
     QStringList GenerateLetters(QString SecretWord);//add number of letters
     QString DecryptWord(QString EncWord);
     QString DecryptWord(QString EncWord,QStringList LangLetters);
     QString EnecryptWord(QString Word);
     QString EnecryptWord(QString Word,QStringList LangLetters);
     void GenerateWords();
     QStringList GetSolvedWords(int Ids);
     void GenerateExpressWords();
};

#endif // LETTERSGENRATOIR_H

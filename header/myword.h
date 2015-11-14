#ifndef MYWORD_H
#define MYWORD_H

#include "QString"

class myWord
{
public:
    myWord();

    QString word;
    QString Hint;
    QString infromation;
    QString timeSolve;
    int id;
    QString GameTime;
    int GameLettersNo;
};

#endif // MYWORD_H

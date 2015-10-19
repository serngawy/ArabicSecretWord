#ifndef GAMESUBJECT_H
#define GAMESUBJECT_H

#include <QObject>

class GameSubject : public QObject
{
    Q_OBJECT
public:
    explicit GameSubject(QObject *parent = 0);
    QString SubjectName;
    QString SubjectImage;
    QString LevelTheam;
    QString GameTheam;
    QString InfoTheam;
    QString HintTheam;
    QString BtnLevelTheam;
    QString BtnSolvedTheam;
    QString BtnLockTheam;
    QString LetterTheam;
    QString LetterActiveTheam;
    QString LetterBlockTheam;
    QString WordsFile;
    QString SolvedWordsFile;
    int LevelsNo;
signals:

public slots:

};

#endif // GAMESUBJECT_H

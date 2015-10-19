#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "settingframe.h"
#include "optionframe.h"
#include "gametypeframe.h"
#include "slideshow.h"
#include "xmlengine.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:


    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    XmlEngine* xml;
    void SwitchSound();
    SettingFrame* settFrame;
    GameTypeFrame* gtFrame;
    GameIntroFrame* gameIntro;
    GameFrame* gFrame;
    WordInfoFrame* wInfoFrame;

private:
    Ui::MainWindow *ui;
    OptionFrame* optFrame;


private slots:
    void OpenOption();
    void OpenSetting();
    void openGameTypes();
    void OnClose();

};

#endif // MAINWINDOW_H

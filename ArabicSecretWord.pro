# Add files and directories to ship with the application 
# by adapting the examples below.

#file1.source = Letters.txt
dir1.source = C:\QtProject\ArabicSecretWord\VideoRendered
dir2.source = C:\QtProject\ArabicSecretWord\CitiesInfoImage
#DEPLOYMENTFOLDERS =  dir1 dir2

addFiles1.sources = Letters.txt\
                    words_city.txt\
                    images/WordsBtn/loading.jpg\
                    sound.mp3\
                    Settings.xml\
                    Solve_city.xml\
                    Messages.txt
addFiles1.path = .
#DEPLOYMENT += addFiles1


#LIBS += -lcone -leikcore -lavkon

symbian:TARGET.UID3 = 0xE45139F6 # 0x20046E0F

DEPLOYMENT.installer_header = 0xA000D7CE  # 0x2002CCCF

 QT += phonon

# Smart Installer package's UID
# This UID is from the protected range 
# and therefore the package will fail to install if self-signed
# By default qmake uses the unprotected range value if unprotected UID is defined for the application
# and 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
CONFIG += mobility
MOBILITY += multimedia

SOURCES += main.cpp mainwindow.cpp \
    xmlengine.cpp \
    mylabel.cpp \
    lettersgenratoir.cpp \
    slideshow.cpp \
    soundclass.cpp \
    settingframe.cpp \
    optionframe.cpp \
    gametypeframe.cpp \
    gameintroframe.cpp \
    gameframe.cpp \
    mybotton.cpp \
    myword.cpp \
    hintframe.cpp \
    wordinfoframe.cpp \
    helpframe.cpp \
    sendswframe.cpp \
    getswframe.cpp \
    aboutframe.cpp \
    gamesubject.cpp
HEADERS += mainwindow.h \
    xmlengine.h \
    mylabel.h \
    lettersgenratoir.h \
    slideshow.h \
    soundclass.h \
    settingframe.h \
    optionframe.h \
    gametypeframe.h \
    gameintroframe.h \
    gameframe.h \
    mybotton.h \
    myword.h \
    hintframe.h \
    wordinfoframe.h \
    helpframe.h \
    sendswframe.h \
    getswframe.h \
    aboutframe.h \
    gamesubject.h
FORMS += mainwindow.ui \
    loadingwin.ui \
    settingframe.ui \
    optionframe.ui \
    gametypeframe.ui \
    gameintroframe.ui \
    gameframe.ui \
    hintframe.ui \
    wordinfoframe.ui \
    helpframe.ui \
    sendswframe.ui \
    getswframe.ui \
    aboutframe.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

RESOURCES += \
    Images.qrc

OTHER_FILES += \
    words_city.txt \
    Letters.txt \
    images/WordsBtn/loading.jpg \
    Solve_city.xml \
    Messages.txt \
    Settings.xml \
    sound.mp3 \
    CitiesInfoImage/city_41.jpg \
    CitiesInfoImage/city_40.jpg \
    CitiesInfoImage/city_39.jpg \
    CitiesInfoImage/city_38.jpg \
    CitiesInfoImage/city_37.jpg \
    CitiesInfoImage/city_36.jpg \
    CitiesInfoImage/city_35.jpg \
    CitiesInfoImage/city_34.jpg \
    CitiesInfoImage/city_33.jpg \
    CitiesInfoImage/city_32.jpg \
    CitiesInfoImage/city_31.jpg \
    CitiesInfoImage/city_30.jpg \
    CitiesInfoImage/city_29.jpg \
    CitiesInfoImage/city_28.jpg \
    CitiesInfoImage/city_27.jpg \
    CitiesInfoImage/city_26.jpg \
    CitiesInfoImage/city_25.jpg \
    CitiesInfoImage/city_24.jpg \
    CitiesInfoImage/city_23.jpg \
    CitiesInfoImage/city_22.jpg \
    CitiesInfoImage/city_21.jpg \
    CitiesInfoImage/city_20.jpg \
    CitiesInfoImage/city_19.jpg \
    CitiesInfoImage/city_18.jpg \
    CitiesInfoImage/city_17.jpg \
    CitiesInfoImage/city_16.jpg \
    CitiesInfoImage/city_15.jpg \
    CitiesInfoImage/city_14.jpg \
    CitiesInfoImage/city_13.jpg \
    CitiesInfoImage/city_12.jpg \
    CitiesInfoImage/city_11.jpg \
    CitiesInfoImage/city_10.jpg \
    CitiesInfoImage/city_9.jpg \
    CitiesInfoImage/city_8.jpg \
    CitiesInfoImage/city_7.jpg \
    CitiesInfoImage/city_6.jpg \
    CitiesInfoImage/city_5.jpg \
    CitiesInfoImage/city_4.jpg \
    CitiesInfoImage/city_3.jpg \
    CitiesInfoImage/city_2.jpg \
    CitiesInfoImage/city_1.jpg \
    CitiesInfoImage/city_0.jpg \
    VideoRendered/113.jpg \
    VideoRendered/112.jpg \
    VideoRendered/111.jpg \
    VideoRendered/110.jpg \
    VideoRendered/109.jpg \
    VideoRendered/108.jpg \
    VideoRendered/107.jpg \
    VideoRendered/106.jpg \
    VideoRendered/105.jpg \
    VideoRendered/104.jpg \
    VideoRendered/103.jpg \
    VideoRendered/102.jpg \
    VideoRendered/101.jpg \
    VideoRendered/100.jpg \
    VideoRendered/99.jpg \
    VideoRendered/98.jpg \
    VideoRendered/97.jpg \
    VideoRendered/96.jpg \
    VideoRendered/95.jpg \
    VideoRendered/94.jpg \
    VideoRendered/93.jpg \
    VideoRendered/92.jpg \
    VideoRendered/91.jpg \
    VideoRendered/90.jpg \
    VideoRendered/89.jpg \
    VideoRendered/88.jpg \
    VideoRendered/87.jpg \
    VideoRendered/86.jpg \
    VideoRendered/85.jpg \
    VideoRendered/84.jpg \
    VideoRendered/83.jpg \
    VideoRendered/82.jpg \
    VideoRendered/81.jpg \
    VideoRendered/80.jpg \
    VideoRendered/79.jpg \
    VideoRendered/78.jpg \
    VideoRendered/77.jpg \
    VideoRendered/76.jpg \
    VideoRendered/75.jpg \
    VideoRendered/74.jpg \
    VideoRendered/73.jpg \
    VideoRendered/72.jpg \
    VideoRendered/71.jpg \
    VideoRendered/70.jpg \
    VideoRendered/69.jpg \
    VideoRendered/68.jpg \
    VideoRendered/67.jpg \
    VideoRendered/66.jpg \
    VideoRendered/65.jpg \
    VideoRendered/64.jpg \
    VideoRendered/63.jpg \
    VideoRendered/62.jpg \
    VideoRendered/61.jpg \
    VideoRendered/60.jpg \
    VideoRendered/59.jpg \
    VideoRendered/58.jpg \
    VideoRendered/57.jpg \
    VideoRendered/56.jpg \
    VideoRendered/55.jpg \
    VideoRendered/54.jpg \
    VideoRendered/53.jpg \
    VideoRendered/52.jpg \
    VideoRendered/51.jpg \
    VideoRendered/50.jpg \
    VideoRendered/49.jpg \
    VideoRendered/48.jpg \
    VideoRendered/47.jpg \
    VideoRendered/46.jpg \
    VideoRendered/45.jpg \
    VideoRendered/44.jpg \
    VideoRendered/43.jpg \
    VideoRendered/42.jpg \
    VideoRendered/41.jpg \
    VideoRendered/40.jpg \
    VideoRendered/39.jpg \
    VideoRendered/38.jpg \
    VideoRendered/37.jpg \
    VideoRendered/36.jpg \
    VideoRendered/35.jpg \
    VideoRendered/34.jpg \
    VideoRendered/33.jpg \
    VideoRendered/32.jpg \
    VideoRendered/31.jpg \
    VideoRendered/30.jpg \
    VideoRendered/29.jpg \
    VideoRendered/28.jpg \
    VideoRendered/27.jpg \
    VideoRendered/26.jpg \
    VideoRendered/25.jpg \
    VideoRendered/24.jpg \
    VideoRendered/23.jpg \
    VideoRendered/22.jpg \
    VideoRendered/21.jpg \
    VideoRendered/20.jpg \
    VideoRendered/19.jpg \
    VideoRendered/18.jpg \
    VideoRendered/17.jpg \
    VideoRendered/16.jpg \
    VideoRendered/15.jpg \
    VideoRendered/14.jpg \
    VideoRendered/13.jpg \
    VideoRendered/12.jpg \
    VideoRendered/11.jpg \
    VideoRendered/10.jpg \
    VideoRendered/9.jpg \
    VideoRendered/8.jpg \
    VideoRendered/7.jpg \
    VideoRendered/6.jpg \
    VideoRendered/5.jpg \
    VideoRendered/4.jpg \
    VideoRendered/3.jpg \
    VideoRendered/2.jpg \
    VideoRendered/1.jpg \
    VideoRendered/0.jpg \
    qtc_packaging/debian_fremantle/rules \
    qtc_packaging/debian_fremantle/README \
    qtc_packaging/debian_fremantle/copyright \
    qtc_packaging/debian_fremantle/control \
    qtc_packaging/debian_fremantle/compat \
    qtc_packaging/debian_fremantle/changelog

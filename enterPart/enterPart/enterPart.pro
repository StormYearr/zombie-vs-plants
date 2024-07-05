QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dialog.cpp \
    Forgotten.cpp \
    ground.cpp \
    login.cpp \
    main.cpp \
    MainWindow.cpp \
    signUp.cpp \
    zambi.cpp

HEADERS += \
    Dialog.h \
    Forgotten.h \
    MainWindow.h \
    ground.h \
    login.h \
    signUp.h \
    zambi.h

FORMS += \
    Dialog.ui \
    Forgotten.ui \
    MainWindow.ui \
    login.ui \
    signUp.ui \
    zambi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

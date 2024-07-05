QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brain.cpp \
    ground.cpp \
    main.cpp \
    mainwindow.cpp \
    z1.cpp \
    z2.cpp \
    z3.cpp \
    z4.cpp \
    z5.cpp \
    z6.cpp

HEADERS += \
    brain.h \
    ground.h \
    mainwindow.h \
    z1.h \
    z2.h \
    z3.h \
    z4.h \
    z5.h \
    z6.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    images_pack.qrc

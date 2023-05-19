QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib/drawGraph.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    lib/ConsoleGraph.h \
    lib/FileEngine.h \
    lib/Graph.h \
    lib/GraphMutator.h \
    lib/GraphTraversal.h \
    lib/ShortestPath.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
##linux sfml
##INCLUDEPATH += /usr/include/SFML
##LIBS += -L/usr/include/SFML -lsfml-graphics -lsfml-window -lsfml-system
#windows
INCLUDEPATH += C:\SFML-2.5.1\include
LIBS += -LC:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += lib/Graph.cpp \
           lib/FileEngine.cpp \
           lib/GraphMutator.cpp \
           lib/GraphTraversal.cpp \
           lib/ShortestPath.cpp \
           lib/ConsoleGraph.cpp

RESOURCES += \
    resources.qrc

DISTFILES += \
    fonts/Quicksand-Medium.ttf

######################################################################
# Automatically generated by qmake (2.01a) jeu. juin 14 18:35:51 2007
######################################################################

TEMPLATE = app
QT += xml
TARGET = 
DEPENDPATH += . build src ui
INCLUDEPATH += . src build
CONFIG +=   qt \
  debug \
  warn_on \
  console

# Input
HEADERS += src/chrono.h \
           src/color.h \
           src/data.h \
           src/engine.h \
           src/engine_state.h \
           src/keyboard.h \
           src/mainwinimpl.h \
           src/ocdocument.h \
           src/ocdocument_mainwin.h \
           src/ocdocument_engine.h \
           src/ocview.h \
           src/ocview_mainwin.h \
           src/ocview_engine.h \
           src/pilot.h \
           src/position.h \
           src/rpm.h \
           src/temperature.h \
           src/track.h \
           src/vehicule.h \
           src/messageimpl.h 
FORMS += ui/about.ui ui/dialog.ui ui/mainwin.ui ui/message.ui ui/questions.ui ui/testwin.ui
SOURCES += src/chrono.cpp \
           src/data.cpp \
           src/engine.cpp \
           src/engine_state.cpp \
           src/main.cpp \
           src/mainwinimpl.cpp \
           src/ocdocument.cpp \
           src/ocdocument_mainwin.cpp \
           src/ocdocument_engine.cpp \
           src/ocview.cpp \
           src/ocview_mainwin.cpp \
           src/ocview_engine.cpp \
           src/pilot.cpp \
           src/position.cpp \
           src/rpm.cpp \
           src/temperature.cpp \
           src/track.cpp \
           src/vehicule.cpp \
           src/messageimpl.cpp 

TEMPLATE = app

QT += gui \
  core \
  xml

TARGET = 

DEPENDPATH += . build src ui

INCLUDEPATH += . src build

CONFIG +=   qt \
  debug \
  warn_on \
  console

DESTDIR +=   bin

OBJECTS_DIR +=   build

MOC_DIR +=   build

UI_DIR +=   build

DEFINES += QT_NO_CAST_FROM_ASCII

TRANSLATIONS = translations/openchrono_fr_FR.ts

RESOURCES = openchrono.qrc

# Input
HEADERS += src/chrono.h \
  src/color.h \
  src/data.h \
  src/engine.h \
  src/engine_state.h \
  src/keyboard.h \
  src/logdata.h \
  src/logtime.h \
  src/ocview.h \
  src/ocview_mainwin.h \
  src/ocview_about.h \
  src/ocview_engine.h \
  src/ocview_plot.h \
  src/pilot.h \
  src/position.h \
  src/rpm.h \
  src/temperature.h \
  src/testwinimpl.h \
  src/ticker.h \
  src/track.h \
  src/vehicule.h \
  src/qaccelerometer.h \
  src/qrpmmeter.h \


FORMS += \
  ui/mainwin.ui \
  ui/message.ui \
  ui/questions.ui \
  ui/testwin.ui \

SOURCES += src/chrono.cpp \
  src/data.cpp \
  src/engine.cpp \
  src/engine_state.cpp \
  src/logdata.cpp \
  src/logtime.cpp \
  src/main.cpp \
  src/ocview.cpp \
  src/ocview_mainwin.cpp \
  src/ocview_about.cpp \
  src/ocview_engine.cpp \
  src/ocview_plot.cpp \
  src/pilot.cpp \
  src/position.cpp \
  src/rpm.cpp \
  src/temperature.cpp \
  src/testwinimpl.cpp \
  src/ticker.cpp \
  src/track.cpp \
  src/vehicule.cpp \
  src/qaccelerometer.cpp \
  src/qrpmmeter.cpp \


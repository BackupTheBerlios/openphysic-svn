TEMPLATE = app

QT += \
  gui \
  core \
  xml \
  webkit \
  network \

TARGET = 

DEPENDPATH += . build src ui

INCLUDEPATH += . src build

CONFIG += \
  qt \
  debug \
  warn_on \
  console

DESTDIR +=   bin

OBJECTS_DIR +=   build

MOC_DIR +=   build

UI_DIR +=   build

# Input
HEADERS += \
  src/browser.h \

FORMS += \
  ui/browser.ui \

SOURCES += \
  src/main.cpp \
  src/browser.cpp \


TEMPLATE = app
QT = gui \
core
CONFIG += qt \
release \
warn_on \
console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/dialog.ui
HEADERS = src/dialogimpl.h
SOURCES = src/dialogimpl.cpp \
	src/main.cpp

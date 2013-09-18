QT -= gui
QT += concurrent

TARGET = GraphicSystem
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += \
    GraphicSystem.cpp \
    Animation.cpp

HEADERS += \
    GraphicSystem.h \
    Animation.h \
    Frame.h

# sfml-system
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-system-d
else:unix: LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-system

INCLUDEPATH += $$PWD/../../../../SFML_project/SFML_install/include
DEPENDPATH += $$PWD/../../../../SFML_project/SFML_install/include

# sfml-graphics
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-graphics-d
else:unix: LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../../../SFML_project/SFML_install/include
DEPENDPATH += $$PWD/../../../../SFML_project/SFML_install/include

# sfml-window
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-window
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-window-d
else:unix: LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -lsfml-window

INCLUDEPATH += $$PWD/../../../../SFML_project/SFML_install/include
DEPENDPATH += $$PWD/../../../../SFML_project/SFML_install/include

# TGUI
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../TGUI_project/TGUI_install/lib/ -ltgui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../TGUI_project/TGUI_install/lib/ -ltgui-d
else:unix: LIBS += -L$$PWD/../../../../TGUI_project/TGUI_install/lib/ -ltgui

INCLUDEPATH += $$PWD/../../../../TGUI_project/TGUI_install/include
DEPENDPATH += $$PWD/../../../../TGUI_project/TGUI_install/include

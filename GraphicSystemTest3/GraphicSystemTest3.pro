QT       += core widgets qml quick

TARGET = GraphicSystemTest3
TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle

HEADERS += \
    CQmlGui.h \
    Test.h
SOURCES += main.cpp \
    CQmlGui.cpp \
    Test.cpp

# installs things
install_data_to_pwd.path = $$OUT_PWD
install_data_to_pwd.files += data

INSTALLS += install_data_to_pwd

# GraphicSystem
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GraphicSystem/release/ -lGraphicSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GraphicSystem/debug/ -lGraphicSystem
else:unix: LIBS += -L$$OUT_PWD/../GraphicSystem/ -lGraphicSystem

INCLUDEPATH += $$PWD/../GraphicSystem
DEPENDPATH += $$PWD/../GraphicSystem

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GraphicSystem/release/libGraphicSystem.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GraphicSystem/debug/libGraphicSystem.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../GraphicSystem/libGraphicSystem.a

# sfml-system
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-system-d
else:unix: LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-system

INCLUDEPATH += $$PWD/../../../../SFML_project/SFML_install/include $$PWD/../../../SFML_project/SFML_install/include
DEPENDPATH += $$PWD/../../../../SFML_project/SFML_install/include $$PWD/../../../SFML_project/SFML_install/include

# sfml-graphics
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-graphics-d
else:unix: LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../../../SFML_project/SFML_install/include $$PWD/../../../SFML_project/SFML_install/include
DEPENDPATH += $$PWD/../../../../SFML_project/SFML_install/include $$PWD/../../../SFML_project/SFML_install/include

# sfml-window
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-window
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-window-d
else:unix: LIBS += -L$$PWD/../../../../SFML_project/SFML_install/lib/ -L$$PWD/../../../SFML_project/SFML_install/lib/ -lsfml-window

INCLUDEPATH += $$PWD/../../../../SFML_project/SFML_install/include $$PWD/../../../SFML_project/SFML_install/include
DEPENDPATH += $$PWD/../../../../SFML_project/SFML_install/include $$PWD/../../../SFML_project/SFML_install/include

# TGUI
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../TGUI_project/TGUI_install/lib/ -L$$PWD/../../../TGUI_project/TGUI_install/lib/ -ltgui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../TGUI_project/TGUI_install/lib/ -L$$PWD/../../../TGUI_project/TGUI_install/lib/ -ltgui-d
else:unix: LIBS += -L$$PWD/../../../../TGUI_project/TGUI_install/lib/ -L$$PWD/../../../TGUI_project/TGUI_install/lib/ -ltgui

INCLUDEPATH += $$PWD/../../../../TGUI_project/TGUI_install/include $$PWD/../../../TGUI_project/TGUI_install/include
DEPENDPATH += $$PWD/../../../../TGUI_project/TGUI_install/include $$PWD/../../../TGUI_project/TGUI_install/include

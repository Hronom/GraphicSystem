TEMPLATE = subdirs

SUBDIRS += \
    GraphicSystem \
    GraphicSystemTest

GraphicSystemTest.depends = GraphicSystem

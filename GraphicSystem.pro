TEMPLATE = subdirs

SUBDIRS += \
    GraphicSystem \
    GraphicSystemTest \
    GraphicSystemTest2 \
    GraphicSystemTest3

GraphicSystemTest.depends = GraphicSystem
GraphicSystemTest2.depends = GraphicSystem
GraphicSystemTest3.depends = GraphicSystem

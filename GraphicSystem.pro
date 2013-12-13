TEMPLATE = subdirs

SUBDIRS += \
    GraphicSystem \
    GraphicSystemTest \
    GraphicSystemTest2 \
    GraphicSystemTest3 \
    GraphicSystemTest4

GraphicSystemTest.depends = GraphicSystem
GraphicSystemTest2.depends = GraphicSystem
GraphicSystemTest3.depends = GraphicSystem
GraphicSystemTest4.depends = GraphicSystem
GraphicSystemTest5.depends = GraphicSystem

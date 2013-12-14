#ifndef SFMLENGINE_H
#define SFMLENGINE_H

#include <QQuickView>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "SFMLEngine.h"

class MyQmlGUIWin: public QQuickView
{
public:
    MyQmlGUIWin(int width, int height, QWindow *parent = 0);
    virtual ~MyQmlGUIWin();
};

#endif

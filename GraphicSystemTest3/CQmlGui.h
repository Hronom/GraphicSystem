#ifndef CQMLGUI_H
#define CQMLGUI_H

#include <QQuickView>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class CQmlGui : public QQuickView
{
private:

public:
    CQmlGui(QString fileName, int width, int height, QWindow *parent = 0);
    virtual ~CQmlGui();
};

#endif

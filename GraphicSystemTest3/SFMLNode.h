#ifndef SFMLNODE_H
#define SFMLNODE_H

#include "SFMLEngine.h"

#include <QSGGeometryNode>
#include <QSGTextureMaterial>
#include <QSGTexture>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class SFMLNode : public QSGGeometryNode
{
private:
    QSGTextureMaterial m_material;
    QSGOpaqueTextureMaterial m_materialO;
    QSGTexture *m_texture;

    SFMLEngine *m_sfmlEngine;
    QSize m_size;
    bool m_dirtyFBO;

public:
    SFMLNode();
    virtual ~SFMLNode();

    void setSFMLEngine(SFMLEngine *par_sfmlEngine);

    void setSize(QSize par_size);

    void update();
};

#endif

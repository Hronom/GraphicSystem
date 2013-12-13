#ifndef SFMLEngine_H
#define SFMLEngine_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <QOpenGLContext>
#include <QOpenGLFramebufferObjectFormat>
#include <QSGTexture>
#include <QQuickWindow>
#include <QOffscreenSurface>

class SFMLEngine: public QObject, public sf::RenderTarget
{
    Q_OBJECT
private:
    QOffscreenSurface *m_surface;
    QOpenGLContext *m_sfmlContext;
    QOpenGLFramebufferObject *m_fbo;

public:
    SFMLEngine();
    ~SFMLEngine();

    GLuint getTextureID();

    void saveOnHDD();

    void display();

protected:
    virtual sf::Vector2u getSize() const;
    virtual bool activate(bool par_active);
};

#endif

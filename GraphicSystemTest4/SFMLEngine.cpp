#include "SFMLEngine.h"

#include "SFMLItem.h"
#include "SFMLEngine.h"

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QDebug>

SFMLEngine::SFMLEngine(): QObject(0)
{
    qmlRegisterType<SFMLItem>("SFML", 1, 0, "SFMLItem");
    qmlRegisterType<SFMLEngine>("SFML", 1, 0, "SFMLEngine");   

    QSurfaceFormat surfaceFormat;
    surfaceFormat.setRenderableType(QSurfaceFormat::OpenGL);

    m_surface = new QOffscreenSurface();
    m_surface->create();

    m_sfmlContext = new QOpenGLContext();
    m_sfmlContext->setFormat(surfaceFormat);
    if(m_sfmlContext->create() == false)
        qDebug()<<Q_FUNC_INFO<<"Shit happens with QOpenGLContext create";

    if(m_sfmlContext->makeCurrent(m_surface) == false)
        qDebug()<<Q_FUNC_INFO<<"Shit happens with QOpenGLContext makeCurrent";

    QOpenGLFramebufferObjectFormat fboFormat;
    //fboFormat.setSamples(16);
    fboFormat.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);

    m_fbo = new QOpenGLFramebufferObject(800, 600, fboFormat);
    if(m_fbo->bind() == false)
        qDebug()<<Q_FUNC_INFO<<"Shit happens with QOpenGLFramebufferObject bind";
}

SFMLEngine::~SFMLEngine()
{
    delete m_sfmlContext;
}

GLuint SFMLEngine::getTextureID()
{
    return m_fbo->texture();
}

void SFMLEngine::saveOnHDD()
{
    m_fbo->toImage().save("test.png");
}

void SFMLEngine::display()
{
    m_sfmlContext->swapBuffers(m_surface);
}

sf::Vector2u SFMLEngine::getSize() const
{
    qDebug()<<"SFMLEngine::getSize";

    sf::Vector2u size;
    size.x = 800;
    size.y = 600;

    return size;
}

bool SFMLEngine::activate(bool par_active)
{
    qDebug()<<"SFMLEngine::activate"<<par_active;

    bool returnValue;
    returnValue = false;

    if(par_active)
    {
        qDebug()<<"SFMLEngine::activateSFMLContent";

        returnValue = m_sfmlContext->makeCurrent(m_surface);

        if(!m_fbo->isBound())
        {
            qDebug()<<"SFMLEngine::m_fbo->bind()";
            m_fbo->bind();
        }
    }
    else
    {
        qDebug()<<"SFMLEngine::doneSFMLContent";

        m_fbo->release();
        m_sfmlContext->doneCurrent();
    }

    return returnValue;
}

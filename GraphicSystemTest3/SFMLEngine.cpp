#include "SFMLEngine.h"

#include "SFMLItem.h"
#include "SFMLEngine.h"

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QDebug>
#include <QOpenGLTexture>

SFMLEngine::SFMLEngine(): QObject(0), RenderTarget()
{
    qDebug()<<"SFMLEngine::SFMLEngine";

    qmlRegisterType<SFMLItem>("SFML", 1, 0, "SFMLItem");
    qmlRegisterType<SFMLEngine>("SFML", 1, 0, "SFMLEngine");   

    QSurfaceFormat surfaceFormat;
    surfaceFormat.setRenderableType(QSurfaceFormat::OpenGL);
    surfaceFormat.setProfile(QSurfaceFormat::CompatibilityProfile);

    m_surface = new QOffscreenSurface();
    m_surface->setFormat(surfaceFormat);
    m_surface->create();

    m_sfmlContext = new QOpenGLContext();
    m_sfmlContext->setFormat(surfaceFormat);
    if(m_sfmlContext->create() == false)
        qDebug()<<Q_FUNC_INFO<<"Shit happens with QOpenGLContext create";

    if(m_sfmlContext->makeCurrent(m_surface) == false)
        qDebug()<<Q_FUNC_INFO<<"Shit happens with QOpenGLContext makeCurrent";

    QOpenGLFramebufferObjectFormat fboFormat;    
    fboFormat.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    fboFormat.setTextureTarget(GL_TEXTURE_2D);
    fboFormat.setInternalTextureFormat(GL_RGBA8);

    m_size.x = 800;
    m_size.y = 600;

    m_fbo = new QOpenGLFramebufferObject(m_size.x, m_size.y, fboFormat);
    if(m_fbo->bind() == false)
        qDebug()<<Q_FUNC_INFO<<"Shit happens with QOpenGLFramebufferObject bind";

    sf::RenderTarget::initialize();
}

SFMLEngine::~SFMLEngine()
{
    qDebug()<<"SFMLEngine::~SFMLEngine";

    delete m_sfmlContext;
}

GLuint SFMLEngine::getTextureID()
{
    qDebug()<<"SFMLEngine::getTextureID";

    return m_fbo->texture();
}

void SFMLEngine::saveOnHDD()
{
    qDebug()<<"SFMLEngine::saveOnHDD";

    m_fbo->toImage().save("test.png", "PNG", 100);
}

void SFMLEngine::display()
{
    qDebug()<<"SFMLEngine::display";

    m_sfmlContext->swapBuffers(m_surface);
}

sf::Vector2u SFMLEngine::getSize() const
{
    qDebug()<<"SFMLEngine::getSize";

    return m_size;
}

bool SFMLEngine::activate(bool par_active)
{
    qDebug()<<"SFMLEngine::activate";

    bool returnValue;
    returnValue = false;

    if(par_active)
    {
        qDebug()<<"activate SFML content";

        QOpenGLContext *currentContext;
        currentContext = QOpenGLContext::currentContext();
        if(currentContext != 0)
            currentContext->doneCurrent();

        returnValue = m_sfmlContext->makeCurrent(m_surface);

        if(!m_fbo->isBound())
        {
            qDebug()<<"m_fbo->bind()";
            m_fbo->bind();
        }

        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }
    else
    {
        qDebug()<<"done SFML content";

        m_fbo->release();
        m_sfmlContext->doneCurrent();
    }

    return returnValue;
}

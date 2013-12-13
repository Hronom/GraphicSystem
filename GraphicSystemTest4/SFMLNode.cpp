#include "SFMLNode.h"
#include <QDebug>

SFMLNode::SFMLNode(): QSGGeometryNode()
{
    m_texture = 0;
    m_dirtyFBO = false;

    QSGGeometryNode::setMaterial(&m_material);
    QSGGeometryNode::setOpaqueMaterial(&m_materialO);
}

SFMLNode::~SFMLNode()
{

}

void SFMLNode::setSFMLEngine(SFMLEngine *par_sfmlEngine)
{
    m_sfmlEngine = par_sfmlEngine;
}

void SFMLNode::setSize(QSize par_size)
{
    if(par_size != m_size)
    {
        m_size = par_size;
        m_dirtyFBO = true;
        QSGGeometryNode::markDirty(DirtyGeometry);
    }
}

void SFMLNode::update()
{
    if(m_dirtyFBO)
    {
        qDebug()<<"SFMLNode::update";

        if(m_texture != 0)
            delete m_texture;
        //m_texture = m_sfmlEngine->createTextureFromID(m_sfmlEngine->getTextureID(), QSize(100, 100));

        m_material.setTexture(m_texture);
        m_materialO.setTexture(m_texture);


        /*{
            m_sfmlEngine->activateSFMLContent();
            m_sfmlEngine->sfmlContext()->functions()->glBindFramebuffer(GL_FRAMEBUFFER_EXT, m_ogreFboId);
        }

        {
            if (m_renderTarget)
                Ogre::TextureManager::getSingleton().remove("RttTex");

            int samples = m_sfmlEngine->ogreContext()->format().samples();
            m_rttTexture = Ogre::TextureManager::getSingleton().createManual("RttTex",
                                                                             Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                                                             Ogre::TEX_TYPE_2D,
                                                                             m_size.width(),
                                                                             m_size.height(),
                                                                             0,
                                                                             Ogre::PF_R8G8B8A8,
                                                                             Ogre::TU_RENDERTARGET, 0, false,
                                                                             samples);

            m_renderTarget = m_rttTexture->getBuffer()->getRenderTarget();

            m_renderTarget->addViewport(m_camera);
            m_renderTarget->getViewport(0)->setClearEveryFrame(true);
            m_renderTarget->getViewport(0)->setBackgroundColour(Ogre::ColourValue::Black);
            m_renderTarget->getViewport(0)->setOverlaysEnabled(false);

            Ogre::Real aspectRatio = Ogre::Real(m_size.width()) / Ogre::Real(m_size.height());
            m_camera->setAspectRatio(aspectRatio);

            QSGGeometry::updateTexturedRectGeometry(&m_geometry,
                                                    QRectF(0, 0, m_size.width(), m_size.height()),
                                                    QRectF(0, 0, 1, 1));

            Ogre::GLTexture *nativeTexture = static_cast<Ogre::GLTexture *>(m_rttTexture.get());

            delete m_texture;
            m_texture = m_ogreEngineItem->createTextureFromId(nativeTexture->getGLID(), m_size);

            m_material.setTexture(m_texture);
            m_materialO.setTexture(m_texture);
        }

        {
            if (!m_renderTarget)
                return 0;

            Ogre::GLFrameBufferObject *ogreFbo = 0;
            m_renderTarget->getCustomAttribute("FBO", &ogreFbo);
            Ogre::GLFBOManager *manager = ogreFbo->getManager();
            manager->bind(m_renderTarget);

            GLint id;
            glGetIntegerv(GL_FRAMEBUFFER_BINDING, &id);

            m_ogreFboId = id;
            m_dirtyFBO = false;
        }

        {
            if(m_ogreFboId != 0)
            {
                Ogre::GLFrameBufferObject *ogreFbo = NULL;
                m_renderTarget->getCustomAttribute("FBO", &ogreFbo);
                Ogre::GLFBOManager *manager = ogreFbo->getManager();
                manager->unbind(m_renderTarget);
            }

            m_ogreEngineItem->doneOgreContext();
        }*/
    }
}

#include "SFMLItem.h"
#include "SFMLNode.h"
#include <QDebug>
#include <QSGSimpleRectNode>

SFMLItem::SFMLItem(QQuickItem *parent): QQuickItem(parent)
{
    QQuickItem::setFlag(QQuickItem::ItemHasContents);
    QQuickItem::setSmooth(false);
    //setQuickWindow(parent);
    startTimer(16);
    m_sfmlEngine = 0;
}

void SFMLItem::setSFMLEngine(SFMLEngine *par_sfmlEngine)
{
    qDebug()<<"x_test";
    m_sfmlEngine = par_sfmlEngine;

    //QQuickItem::window();
    QQuickItem::update();
}

SFMLEngine* SFMLItem::sfmlEngine()
{
    return m_sfmlEngine;
}

QSGNode* SFMLItem::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *paintData)
{
    /*if (width() <= 0 || height() <= 0 || !m_camera || !m_camera->camera() || !m_ogreEngineItem) {
        delete oldNode;
        return 0;
    }

    OgreNode *node = static_cast<OgreNode *>(oldNode);
    if (!node)
    {
        node = new OgreNode();
        node->setOgreEngineItem(m_ogreEngineItem);
        node->setCamera(m_camera->camera());
    }

    node->setSize(QSize(width(), height()));
    node->update();
    // mark texture dirty, otherwise Qt will not trigger a redraw (preprocess())
    node->markDirty(QSGNode::DirtyMaterial);

    return node;*/

    SFMLNode *node = static_cast<SFMLNode *>(oldNode);
    if(node == 0)
    {
        if(m_sfmlEngine != 0)
        {
            node = new SFMLNode();
            node->setSFMLEngine(m_sfmlEngine);
            qDebug()<<"test";
            //node->setColor(Qt::red);
        }
        else
        {
            return node;
        }
    }
    else
        return node;

    node->setSize(QSize(QQuickItem::width(), QQuickItem::height()));
    node->update();
    // mark texture dirty, otherwise Qt will not trigger a redraw (preprocess())
    node->markDirty(QSGNode::DirtyMaterial);

    return node;
}

void SFMLItem::timerEvent(QTimerEvent *)
{
    QQuickItem::update();
}

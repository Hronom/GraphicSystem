#ifndef SFMLITEM_H
#define SFMLITEM_H

#include <QQuickItem>
#include "SFMLEngine.h"

class SFMLItem: public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(SFMLEngine *sfmlEngine READ sfmlEngine WRITE setSFMLEngine)
private:
    int m_timerID;
    SFMLEngine *m_sfmlEngine;

public:
    SFMLItem(QQuickItem *parent = 0);
    void setSFMLEngine(SFMLEngine *par_sfmlEngine);
    SFMLEngine* sfmlEngine();

protected:
    virtual QSGNode* updatePaintNode(QSGNode *node, UpdatePaintNodeData *paintData);

    void timerEvent(QTimerEvent *);
};

#endif

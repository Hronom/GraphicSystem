#include "CQmlGui.h"
#include "GraphicSystem.h"

#include <QPainter>
#include <QQuickItem>
#include <QtGui>

CQmlGui::CQmlGui(QString fileName, int width, int height, QWindow *parent): QQuickView(parent)
{
    setSource(QUrl::fromLocalFile(fileName));

    //QQuickView::setColor(Qt::transparent);
    QQuickView::setSurfaceType(QSurface::OpenGLSurface);
    QQuickView::setClearBeforeRendering(false);
}

CQmlGui::~CQmlGui()
{
}

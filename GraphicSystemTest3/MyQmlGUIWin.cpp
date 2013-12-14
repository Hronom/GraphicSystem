#include "MyQmlGUIWin.h"
#include "GraphicSystem.h"

#include <QPainter>
#include <QQuickItem>
#include <QtGui>

MyQmlGUIWin::MyQmlGUIWin(int width, int height, QWindow *parent): QQuickView(parent)
{
    QQuickView::setSurfaceType(QSurface::OpenGLSurface);
    QQuickView::setClearBeforeRendering(true);
}

MyQmlGUIWin::~MyQmlGUIWin()
{
}

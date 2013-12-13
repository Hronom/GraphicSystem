#include "Test.h"

#include <QThread>
#include <QApplication>
#include <QOpenGLContext>
#include <QDebug>

Test::Test(QObject *parent): QObject(parent)
{
    qDebug()<<Q_FUNC_INFO<<QThread::currentThreadId();

    window.create(sf::VideoMode(800, 600), "Test");

    init();

    this->moveToThread(QThread::currentThread());
}

Test::Test(sf::WindowHandle handle, QObject *parent): QObject(parent)
{
    qDebug()<<Q_FUNC_INFO<<QThread::currentThreadId();

    window.create(handle);
    m_SFMLContext = QOpenGLContext::currentContext();
    window.setActive(false);

    //qDebug()<<renderTexture.create(800, 600);
    //renderTexture.setActive(false);

    init();
}

void Test::init()
{
    font.loadFromFile("data/fonts/DejaVuSans.ttf");

    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

sf::WindowHandle Test::getWinID()
{
    return window.getSystemHandle();
}

Test::~Test()
{

}

bool Test::update()
{
    QApplication::processEvents();
    return true;
}

void Test::paintSFML()
{
    qDebug()<<Q_FUNC_INFO<<QThread::currentThreadId();

    window.setActive(true);

    window.clear(sf::Color::White);

    window.draw(text);

    //window.display();
    window.setActive(false);
}

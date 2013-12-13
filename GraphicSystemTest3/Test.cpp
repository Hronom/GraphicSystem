#include "Test.h"

#include <QThread>
#include <QApplication>
#include <QDebug>

Test::Test(QObject *parent): QObject(parent)
{
    qDebug()<<Q_FUNC_INFO<<QThread::currentThreadId();

    window.create(sf::VideoMode(800, 600), "Test");
    window.setActive(false);

    init();

    this->moveToThread(QThread::currentThread());
}

Test::~Test()
{

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

bool Test::update()
{
    QApplication::processEvents();
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
            return false;
        }
    }
    return true;
}

sf::WindowHandle Test::getWinID()
{
    return window.getSystemHandle();
}

void Test::paintSFML()
{
    qDebug()<<Q_FUNC_INFO<<QThread::currentThreadId();

    //window.pushGLStates();

    window.setActive(true);

    window.clear(sf::Color::White);

    window.draw(text);

    window.display();
    window.setActive(false);

    //window.popGLStates();

    /*window.pushGLStates();

    window.setActive(true);

    window.clear(sf::Color::White);

    window.draw(text);

    window.display();

    window.popGLStates();*/
}

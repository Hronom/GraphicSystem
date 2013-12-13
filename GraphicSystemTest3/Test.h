#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Test : public QObject
{
    Q_OBJECT
private:
    sf::RenderWindow window;

    sf::RenderTexture renderTexture;

    sf::Font font;
    sf::Text text;

public:
    Test(QObject *parent = 0);
    virtual ~Test();

    void init();
    bool update();

    sf::WindowHandle getWinID();

public slots:
    void paintSFML();
};

#endif

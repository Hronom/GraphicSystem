#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QOpenGLContext>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Test : public QObject
{
    Q_OBJECT
private:
    QOpenGLContext *m_SFMLContext;

    sf::RenderWindow window;

    sf::RenderTexture renderTexture;

    sf::Font font;
    sf::Text text;

public:
    Test(QObject *parent = 0);
    Test(sf::WindowHandle handle, QObject *parent = 0);

    void init();

    sf::WindowHandle getWinID();

    virtual ~Test();

    bool update();

public slots:
    void paintSFML();
};

#endif

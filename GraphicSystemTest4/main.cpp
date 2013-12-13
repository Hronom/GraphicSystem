#include "MyQmlGUIWin.h"

#include "SFMLItem.h"
#include "SFMLEngine.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <QQmlContext>
#include <QApplication>
#include <QDebug>


int main(int argc, char **argv)
{
    QApplication *app;
    app = new QApplication(argc, argv);

    SFMLEngine *engine;
    engine = new SFMLEngine();

    sf::Font font;
    font.loadFromFile("data/fonts/DejaVuSans.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setRadius(40);
    shape.setPosition(100, 100);

    // set a 10-pixel wide orange outline
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    engine->clear();
    engine->draw(text);
    engine->draw(shape);
    engine->display();

    engine->saveOnHDD();


    int returnCode;
    //returnCode = app->exec();

    delete app;

    return 0;
}

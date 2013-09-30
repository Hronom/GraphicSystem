#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "Animation.h"

#include <QString>
#include <QHash>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

class AnimatedSprite: public sf::Drawable, public sf::Transformable
{
private:
    sf::Texture *m_texture;
    sf::IntRect m_textureRect; // Rectangle defining the area of the source texture to display
    sf::Vertex m_vertices[4]; // Vertices defining the sprite's geometry

    QHash<QString, Animation> m_animations;
    Animation *m_currentAnimation;

public:
    AnimatedSprite(sf::Texture *par_texture);
    ~AnimatedSprite();

    void injectUpdate(const qint64 &par_timeSinceLastUpdate);

    void addAnimation(const QString &par_name, const Animation &par_animation);
    QList<QString> animations();

    void playAnimation(const QString &par_name, bool par_mirrorX = false, bool par_mirrorY = false);
    QString getPlayAnimationName() const;
    bool isPlayAnimationMirrored() const;

    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

    static AnimatedSprite* loadFromFile(const QString &par_fileName);

private:
    virtual void draw(sf::RenderTarget &par_target, sf::RenderStates par_states) const;
    void setTextureRect(const sf::IntRect &par_rectangle);
    void updatePositions();
    void updateTexCoords();
};

#endif

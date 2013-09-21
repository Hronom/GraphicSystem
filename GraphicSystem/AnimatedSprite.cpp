#include "AnimatedSprite.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <cstdlib>

AnimatedSprite::AnimatedSprite(sf::Texture *par_texture)
{
    m_texture = par_texture;
    m_currentAnimation = 0;
}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    if(m_currentAnimation != 0)
    {
        m_currentAnimation->injectUpdate(par_timeSinceLastUpdate);

        if(m_currentAnimation->needSwitchFrame())
        {
            Frame frame;
            frame = m_currentAnimation->nextFrame();
            setTextureRect(frame.rectangle);
            // Setting origin for left down point for proper animation
            sf::Transformable::setOrigin(frame.origin);
        }
    }
}

void AnimatedSprite::addAnimation(const QString &par_name, const Animation &par_animation)
{
    m_animations.insert(par_name, par_animation);
}

QList<QString> AnimatedSprite::animations()
{
    return m_animations.keys();
}

void AnimatedSprite::playAnimation(const QString &par_name, bool par_mirror)
{
    QHash<QString, Animation>::Iterator iter;
    iter = m_animations.find(par_name);

    if(iter != m_animations.end())
    {
        m_currentAnimation = &iter.value();
        m_currentAnimation->resetAnimation();
    }
}

sf::FloatRect AnimatedSprite::getLocalBounds() const
{
    float width = static_cast<float>(std::abs(m_textureRect.width));
    float height = static_cast<float>(std::abs(m_textureRect.height));

    return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AnimatedSprite::getGlobalBounds() const
{
    return sf::Transformable::getTransform().transformRect(getLocalBounds());
}

void AnimatedSprite::draw(sf::RenderTarget &par_target, sf::RenderStates par_states) const
{
    if(m_texture)
    {
        par_states.transform *= sf::Transformable::getTransform();
        par_states.texture = m_texture;
        par_target.draw(m_vertices, 4, sf::Quads, par_states);
    }
}

void AnimatedSprite::setTextureRect(const sf::IntRect &par_rectangle)
{
    if(par_rectangle != m_textureRect)
    {
        m_textureRect = par_rectangle;
        updatePositions();
        updateTexCoords();
    }
}

void AnimatedSprite::updatePositions()
{
    sf::FloatRect bounds = getLocalBounds();

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(0, bounds.height);
    m_vertices[2].position = sf::Vector2f(bounds.width, bounds.height);
    m_vertices[3].position = sf::Vector2f(bounds.width, 0);
}

void AnimatedSprite::updateTexCoords()
{
    float left = static_cast<float>(m_textureRect.left);
    float right = left + m_textureRect.width;
    float top = static_cast<float>(m_textureRect.top);
    float bottom = top + m_textureRect.height;

    m_vertices[0].texCoords = sf::Vector2f(left, top);
    m_vertices[1].texCoords = sf::Vector2f(left, bottom);
    m_vertices[2].texCoords = sf::Vector2f(right, bottom);
    m_vertices[3].texCoords = sf::Vector2f(right, top);
}

#include "AnimatedSprite.h"

#include "GraphicSystem.h"

#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

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

void AnimatedSprite::playAnimation(const QString &par_name, bool par_mirrorX, bool par_mirrorY)
{
    QHash<QString, Animation>::Iterator iter;
    iter = m_animations.find(par_name);

    if(iter != m_animations.end())
    {
        Animation *newAnimation;
        newAnimation = &iter.value();
        if(m_currentAnimation != newAnimation)
        {
            m_currentAnimation = newAnimation;
            m_currentAnimation->resetAnimation();

            // scale
            {
                bool needScale = false;

                float scaleX = 1.0f;
                if( ( par_mirrorX && Transformable::getScale().x >= 0 ) ||
                        ( ! par_mirrorX && Transformable::getScale().x <= 0 ) )
                {
                    scaleX = -1.0f;
                    needScale = true;
                }

                float scaleY = 1.0f;
                if( ( par_mirrorY && Transformable::getScale().y >= 0 ) ||
                        ( ! par_mirrorY && Transformable::getScale().y <= 0 ) )
                {
                    scaleY = -1.0f;
                    needScale = true;
                }

                if(needScale)
                    Transformable::scale(scaleX, scaleY);
            }
        }
    }
    else
    {
        qDebug()<<"Animation not found";
    }
}

QString AnimatedSprite::getPlayAnimationName() const
{
    if(m_currentAnimation != 0)
        return m_currentAnimation->getName();
    else
        return "";
}

bool AnimatedSprite::isPlayAnimationMirrored() const
{
    if(Transformable::getScale().x <= 0 || Transformable::getScale().y <= 0)
        return true;
    else
        return false;
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

AnimatedSprite* AnimatedSprite::loadFromFile(const QString &par_fileName)
{
    QFile file(par_fileName);
    if(!file.open(QIODevice::ReadOnly))
        return 0;

    QJsonDocument doc;
    doc = QJsonDocument::fromJson(file.readAll());

    file.close();

    QJsonObject rootObject;
    rootObject = doc.object();

    QString textureFileName;
    textureFileName = rootObject.value("texture_file").toString();

    if(!textureFileName.isEmpty())
    {
        QFileInfo fileInfo;
        fileInfo.setFile(file);

        sf::Texture *texture;
        texture = GraphicSystem::instance()->getTexture(fileInfo.absolutePath() + "/" + textureFileName);

        AnimatedSprite *animatedSprite;
        animatedSprite = new AnimatedSprite(texture);

        QJsonArray animationsList;
        animationsList = rootObject.value("animations").toArray();

        for(int animationIndex = 0; animationIndex < animationsList.size(); ++animationIndex)
        {
            QJsonObject animationElem;
            animationElem = animationsList.at(animationIndex).toObject();

            QString animationName;
            animationName = animationElem.value("name").toString("Unknown");

            double framesDelay;
            framesDelay = animationElem.value("frames_delay").toDouble();

            bool repeatable;
            repeatable = animationElem.value("repeatable").toBool();

            Animation animation(animationName, framesDelay, repeatable);

            QJsonArray framesList;
            framesList = animationElem.value("frames").toArray();

            for(int frameIndex = 0; frameIndex < framesList.size(); ++frameIndex)
            {
                QJsonObject frameElem;
                frameElem = framesList.at(frameIndex).toObject();

                Frame frame;
                frame.rectangle.left = frameElem.value("x").toDouble();
                frame.rectangle.top = frameElem.value("y").toDouble();
                frame.rectangle.width = frameElem.value("width").toDouble();
                frame.rectangle.height = frameElem.value("height").toDouble();
                frame.origin.x = frameElem.value("origin_x").toDouble(frame.rectangle.left) - frame.rectangle.left;
                frame.origin.y = frameElem.value("origin_y").toDouble(frame.rectangle.top + frame.rectangle.height) - frame.rectangle.top;

                animation.addFrame(frame);
            }

            animatedSprite->addAnimation(animation.getName(), animation);
        }

        return animatedSprite;
    }
    else
        return 0;
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

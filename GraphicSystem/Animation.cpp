#include "Animation.h"

Animation::Animation(const QString &par_name, const float &par_framesDelay, bool par_repeatable)
{
    m_name = par_name;
    m_framesDelay = par_framesDelay;
    m_repeatable = par_repeatable;
    m_currentTime = 0;
    m_currentFrame = m_frames.begin();
}

Animation::~Animation()
{
}

void Animation::addFrame(const Frame &par_frame)
{
    m_frames.append(par_frame);
    m_currentFrame = m_frames.begin();
}

void Animation::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    m_currentTime += par_timeSinceLastUpdate;
}

bool Animation::needSwitchFrame()
{
    if(m_currentTime >= m_framesDelay)
        return true;
    else
        return false;
}

Frame Animation::frame()
{
    if(m_currentFrame != m_frames.end())
    {
        return (*m_currentFrame);
    }
    else
    {
        Frame frame;
        frame.rectangle = sf::IntRect(0, 0, 0, 0);
        frame.origin = sf::Vector2f(0, 0);
        return frame;
    }
}

Frame Animation::nextFrame()
{
    ++m_currentFrame;

    if(m_currentFrame != m_frames.end())
    {
        m_currentTime = 0;
        return (*m_currentFrame);
    }
    else if(m_repeatable)
    {
        m_currentTime = 0;
        m_currentFrame = m_frames.begin();
        return (*m_currentFrame);
    }
    else
    {
        m_currentTime = 0;
        --m_currentFrame;
        return (*m_currentFrame);
    }
}

void Animation::resetAnimation()
{
    m_currentTime = 0;
    m_currentFrame = m_frames.begin();
}

QString Animation::getName()
{
    return m_name;
}

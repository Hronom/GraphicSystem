#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"

#include <QString>
#include <QList>

#include <SFML/Graphics.hpp>

class Animation
{
private:
    QString m_name;
    float m_framesDelay;
    bool m_repeatable;
    float m_currentTime;

    QList<Frame> m_frames;
    QList<Frame>::Iterator m_currentFrame;

public:
    Animation(const QString &par_name, const float &par_framesDelay, bool par_repeatable);
    ~Animation();

    void addFrame(const Frame &par_frame);

    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
    bool needSwitchFrame();
    Frame frame();
    Frame nextFrame();
    void resetAnimation();
    QString getName();
};

#endif

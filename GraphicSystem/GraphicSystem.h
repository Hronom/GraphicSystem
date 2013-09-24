#ifndef GRAPHICSYSTEM_H
#define GRAPHICSYSTEM_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include <QHash>
#include <QString>

class GraphicSystem
{
private:
    static GraphicSystem* m_instance;

    QString m_windowTitle;
    QString m_fontPath;

    sf::RenderWindow *m_window;
    tgui::Gui *m_gui;

    sf::Color m_backgroundColor;

    QHash<QString, sf::Texture*> m_textures;

public:
    static bool initialize(const QString &par_windowTitle, const QString &par_fontPath);
    static void shutdown();
    static GraphicSystem* instance();

private:
    GraphicSystem(const QString &par_windowTitle, const QString &par_fontPath);
    ~GraphicSystem();

public:
    void injectPreUpdate(const float& par_timeSinceLastUpdate);
    void injectPostUpdate(const float& par_timeSinceLastUpdate);

    void setWindowTitle(const QString &par_title);
    void setBackgroundColor(const sf::Color &par_color);

    sf::RenderWindow* getWindow();
    int getWindowHeight();
    int getWindowWidth();
    void setView(const sf::View &par_view);
    tgui::Gui* getGUI();

    bool pollWindowEvent(sf::Event &par_event);
    bool handleGUIEvent(sf::Event &par_event);
    bool pollGUICallback(tgui::Callback &par_callback);

    sf::Texture* getTexture(const QString &par_filePath);
};

#endif

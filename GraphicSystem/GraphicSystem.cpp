#include "GraphicSystem.h"

#include <QDebug>

GraphicSystem* GraphicSystem::m_instance = NULL;

bool GraphicSystem::initialize()
{
    qDebug()<<"Initialize:"<<"GraphicSystem";
    m_instance = new GraphicSystem();
    return true;
}

void GraphicSystem::shutdown()
{
    qDebug()<<"Shutdown:"<<"GraphicSystem";
    delete m_instance;
    m_instance = NULL;
}

GraphicSystem* GraphicSystem::instance()
{
    return m_instance;
}

GraphicSystem::GraphicSystem()
{
    m_window = new sf::RenderWindow();
    m_window->create(sf::VideoMode(800, 600), "SFML Render Window");
    //m_window->setVerticalSyncEnabled(true);
    m_window->setFramerateLimit(60);

    m_gui = new tgui::Gui((*m_window));
    // Load the font (you should check the return value to make sure that it is loaded)
    m_gui->setGlobalFont("data/fonts/DejaVuSans.ttf");

    m_backgroundColor = sf::Color::Black;
}

GraphicSystem::~GraphicSystem()
{
    m_gui->unbindGlobalCallback();
    m_gui->uncheckRadioButtons();
    m_gui->unfocusWidgets();
    m_gui->removeAllWidgets();
    delete m_gui; // TODO WTF in linux here?
    //m_window->close();
    delete m_window;
}

void GraphicSystem::injectPreUpdate(const float &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    // clear the window with black color
    m_window->clear(m_backgroundColor);
}

void GraphicSystem::injectPostUpdate(const float &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_window->isOpen())
    {
        m_gui->draw(true);
        // end the current frame
        m_window->display();
    }
}

void GraphicSystem::setWindowTitle(const QString &par_title)
{
    m_window->setTitle(par_title.toStdWString());
}

void GraphicSystem::setBackgroundColor(const sf::Color &par_color)
{
    m_backgroundColor = par_color;
}

sf::RenderWindow* GraphicSystem::getWindow()
{
    return m_window;
}

int GraphicSystem::getWindowHeight()
{
    return m_window->getSize().y;
}

int GraphicSystem::getWindowWidth()
{
    return m_window->getSize().x;
}

void GraphicSystem::setView(const sf::View &par_view)
{
    m_window->setView(par_view);
}

tgui::Gui* GraphicSystem::getGUI()
{
    return m_gui;
}

bool GraphicSystem::pollWindowEvent(sf::Event &par_event)
{
    return m_window->pollEvent(par_event);
}

bool GraphicSystem::handleGUIEvent(sf::Event &par_event)
{
    return m_gui->handleEvent(par_event);
}

bool GraphicSystem::pollGUICallback(tgui::Callback &par_callback)
{
    if(m_window->isOpen())
        return m_gui->pollCallback(par_callback);
    else
        return false;
}

sf::Texture* GraphicSystem::getTexture(const QString &par_filePath)
{
    QHash<QString, sf::Texture*>::Iterator iter;
    iter = m_textures.find(par_filePath);
    if(iter == m_textures.end())
    {
        sf::Texture *texture;
        texture = new sf::Texture();
        texture->loadFromFile(par_filePath.toStdString());
        m_textures.insert(par_filePath, texture);
        return texture;
    }
    else
        return iter.value();
}

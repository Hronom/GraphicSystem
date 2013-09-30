#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <QString>
#include <QJsonArray>
#include <QHash>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

class Map;

class MapLoader
{
private:
    struct TileInfo
    {
        sf::Texture *m_texture;
        sf::Vector2f m_pos;
        sf::Vector2f m_size;
    };

    MapLoader() {}
    ~MapLoader() {}

public:
    static Map* load(const QString &par_mapFile);

private:
    static bool parseTilesets(const QJsonArray &par_tilesets, QHash<double, TileInfo> *par_tiles);
    static bool parseLayers(const QJsonArray &par_layers, const QHash<double, TileInfo> *const par_tiles, Map * par_map);
};

#endif

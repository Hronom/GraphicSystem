#include "MapLoader.h"

#include "Map.h"

#include <QHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Map* MapLoader::load(const QString &par_mapFile)
{
    Map *map;
    map = new Map();

    QFile file(par_mapFile);
    if(!file.open(QIODevice::ReadOnly))
        return 0;

    QJsonDocument doc;
    doc = QJsonDocument::fromJson(file.readAll());

    file.close();

    QJsonObject rootObject;
    rootObject = doc.object();

    // Parse map parameters
    {
        map->m_width = rootObject.value("width").toDouble();
        map->m_height = rootObject.value("height").toDouble();

        map->m_tileWidth = rootObject.value("tilewidth").toDouble();
        map->m_tileHeight = rootObject.value("tileheight").toDouble();

        map->m_orientation = rootObject.value("orientation").toString();

        map->m_version = rootObject.value("version").toDouble();

        // TODO parse properties here
    }

    QJsonArray tilesets;
    tilesets = rootObject.value("tilesets").toArray();

    QJsonArray layers;
    layers = rootObject.value("layers").toArray();
}

bool MapLoader::parseTilesets(const QJsonArray &par_tilesets, QHash<double, TileInfo> *par_tiles)
{

}

bool MapLoader::parseLayers(const QJsonArray &par_layers, const QHash<double, TileInfo> *const par_tiles, Map *par_map)
{

}

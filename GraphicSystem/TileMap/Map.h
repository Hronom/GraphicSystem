#ifndef MAP_H
#define MAP_H

#include <QString>
#include <QHash>
#include <QList>

class MapTile;

class Map
{
    friend class MapLoader;
private:
    double m_width;
    double m_height;

    double m_tileWidth;
    double m_tileHeight;

    QString m_orientation;

    double m_version;

    QHash<QString, QString> m_properties;

    QList<QList<MapTile>> m_mapTiles;

public:
    Map();
    ~Map();
};

#endif

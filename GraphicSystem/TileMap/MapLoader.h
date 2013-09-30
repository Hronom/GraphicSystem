#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <QString>

class Map;

class MapLoader
{
private:
    MapLoader() {}
    ~MapLoader() {}

public:
    static Map* load(const QString &par_mapFile);
};

#endif

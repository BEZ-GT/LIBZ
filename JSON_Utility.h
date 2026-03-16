#ifndef JSON_UTILITY_H
#define JSON_UTILITY_H

#include "Library.h"
#include <QJsonObject>

class Item;

namespace JSON_Utility {

    bool saveItems(const Library& lib,const QString &filePath);
    bool loadItems(Library& lib,const QString &filePath);
    Item* FromJson(const QJsonObject& obj);

}

#endif // JSON_UTILITY_H

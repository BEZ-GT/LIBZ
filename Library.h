#ifndef LIBRARY_H
#define LIBRARY_H

#include <QList>
#include "Item.h"


class Library {

private:

    QList<Item*> items;

public:

    Library();

    QList<Item*>& getItems() const;
    QList<Item*> FilterItems(const QString& query) const;
    QList<bool> IsFiltered(const QString& query) const;
    void AddItem(Item* new_item);
    void RemoveItem(int index) ;
    int Size() const;

    Item* operator[] (int index) ;
    const Item* operator[] (int index) const;


};

#endif // LIBRARY_H

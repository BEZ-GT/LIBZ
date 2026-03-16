#ifndef ITEMLISTPREVIEW_H
#define ITEMLISTPREVIEW_H

#include "Library.h"
#include "Item.h"
#include "ItemPreview.h"
#include <QWidget>
#include <QListWidget>

class ItemListPreview : public QWidget
{
    Q_OBJECT

private:

    Library& library;
    QListWidget* listview;

public:

    explicit ItemListPreview(Library& lib,QWidget *parent = nullptr);
    virtual ~ItemListPreview()= default;

    QListWidgetItem* CurrentListItem();
    int CurrentListIndex();
    ItemPreview* CurrentListWidget();
    void AddItemToList(Item* item);

    void Clear();
    bool isEmpty();
    void ShowAll();

public slots:

    void FilterItems(const QString& query);

signals:
    void itemSelected(int index);
};

#endif // ITEMLISTPREVIEW_H

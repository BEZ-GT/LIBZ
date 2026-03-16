#ifndef ITEMPREVIEW_H
#define ITEMPREVIEW_H

#include <QWidget>
#include <QLabel>
#include "Item.h"

class ItemPreview : public QWidget
{
    Q_OBJECT

private:

    Item& item;
    QLabel* title;
    QLabel* id;
    QLabel* language_year;

public:

    explicit ItemPreview(Item& item,QWidget *parent = nullptr);
    virtual ~ItemPreview()= default;

    void UpdatePreview();

signals:
};

#endif // ITEMPREVIEW_H

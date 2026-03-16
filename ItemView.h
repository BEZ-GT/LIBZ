#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include "Item.h"
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class ItemView : public QWidget
{
    Q_OBJECT

private:

    QLabel* cover;
    QLabel* type_label;
    QLabel* type;
    QLabel* id_label;
    QLabel* id;
    QLabel* title_label;
    QLabel* title;
    QLabel* year_label;
    QLabel* year;
    QLabel* lang_label;
    QLabel* lang;
    QLabel* publisher_label;
    QLabel* publisher;
    QLabel* genre_label;
    QLabel* genre;
    QWidget* visitorwidget;

    QVBoxLayout* right_layout;

public:
    explicit ItemView(QWidget *parent = nullptr);

    void displayItem(const Item* item);

signals:
};

#endif // ITEMVIEW_H

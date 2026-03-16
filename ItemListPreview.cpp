#include "ItemListPreview.h"
#include <QVBoxLayout>

ItemListPreview::ItemListPreview(Library& lib,QWidget *parent) : QWidget(parent),library(lib){

    setStyleSheet(
        "QListWidget {border-radius: 10px;background-color:rgba(45,45,45,255);}"
        "QListWidget::item {border-radius: 10px;background-color:rgba(45,45,45,255);}"
        "QListWidget::item:hover {background-color:rgba(210,0,255,50);}"
        "QListWidget::item:selected {border:none;outline:none;background-color:rgba(210,0,255,120);}"
        "QListWidget::item:focus {border:none;outline:none;background-color:rgba(210,0,255,120);}"
        );

    QVBoxLayout* layout = new QVBoxLayout(this);

    listview = new QListWidget(this);
    layout->addWidget(listview);

    for(int i=0;i<library.Size();i++){

        AddItemToList(library[i]);
    }

    connect(listview,&QListWidget::itemClicked,this,[this](QListWidgetItem* item) {

        int index = listview->row(item);
        emit itemSelected(index);

        });

    connect(listview,&QListWidget::currentRowChanged,this,[this](int row) {

        emit itemSelected(row);

    });

    listview->setMinimumWidth(55);

    layout->setContentsMargins(0,0,0,0);
}

void ItemListPreview::AddItemToList(Item* item) {

    QListWidgetItem* listitem = new QListWidgetItem();
    listitem->setSizeHint(QSize(150,75));
    ItemPreview* itemprev = new ItemPreview(*item, listview);
    listview->addItem(listitem);
    listview->setItemWidget(listitem,itemprev);

}

QListWidgetItem* ItemListPreview::CurrentListItem() {

    QListWidgetItem* current_q_item = listview->currentItem();

        return current_q_item;
}
ItemPreview* ItemListPreview::CurrentListWidget() {

    return static_cast<ItemPreview*>(listview->itemWidget(CurrentListItem()));

}
int ItemListPreview::CurrentListIndex(){

    return listview->currentRow();
}

void ItemListPreview::Clear() {

    listview->clear();

}

bool ItemListPreview::isEmpty() {

    if(listview->count()==0) return true;

    else return false;

}

void ItemListPreview::ShowAll() {

    for(int i=0;i<listview->count();i++){

        QListWidgetItem* item = listview->item(i);

        if (item->isHidden()) item->setHidden(false);

    }

}

void ItemListPreview::FilterItems(const QString& query) {

    if(query.isEmpty()) return;

    this->ShowAll();

    QList<bool> filter = library.IsFiltered(query);

    for(int i=0;i<filter.size();i++){

        if (filter[i]==false) {

            QListWidgetItem* index_item = listview->item(i);

            index_item->setHidden(true);

        }

    }

}

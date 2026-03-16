#include "ItemPreview.h"
#include <QPixmap>
#include <QGridLayout>


ItemPreview::ItemPreview(Item& item,QWidget *parent) : QWidget(parent),item(item) {

    setStyleSheet(

        "QLabel {background-color:rgba(45,45,45,0);color:white ; border-radius: 4px ; padding: 3px;}"
        "QLabel {font-family: 'Arial Rounded MT' ; font-size:14px ; font-weight:bold ;}"

        );

    QGridLayout* layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignCenter);

    title = new QLabel(item.getTitle(),this);

    QHBoxLayout* other_info = new QHBoxLayout(this);

    id = new QLabel(item.getID(),this);
    id->setStyleSheet("color:yellow; text-decoration: underline");
    id->setMinimumWidth(100);
    language_year = new QLabel(item.getLanguage()+' '+item.getYear(),this);

    other_info->addWidget(id,Qt::AlignLeft);
    other_info->addWidget(language_year,Qt::AlignLeft);

    QPixmap image(":/icons/assets/icons/" + (item.getType()).toLower() + "_icon.png");
    QLabel* icon = new QLabel(this);
    icon->setPixmap(image.scaledToHeight(45,Qt::SmoothTransformation));
    icon->setMinimumWidth(55);

    layout->addWidget(icon,0,0,2,1);
    layout->addWidget(title,0,1,1,2);

    layout->addLayout(other_info,1,1,1,1);

}

void ItemPreview::UpdatePreview() {

    title->setText(item.getTitle());
    id->setText(item.getID());
    language_year->setText(item.getLanguage()+' '+item.getYear());

}

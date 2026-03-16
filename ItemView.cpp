#include "ItemView.h"
#include "ItemInfoVisitor.h"
#include <QPixmap>
#include <QHBoxLayout>
#include <QGridLayout>

ItemView::ItemView(QWidget *parent): QWidget(parent) {

    setStyleSheet("QLabel {color:white ; border-radius: 4px ; padding: 7px;}"
                  "QLabel {font-family: 'Arial Rounded MT' ; font-size:14px ; font-weight:bold ;}"
                  ".highlighted-label { color: purple ; background-color: cyan ;text-align:center; qproperty-alignment: 'AlignCenter';}"
                  );

    QHBoxLayout* main_layout = new QHBoxLayout(this);

    cover = new QLabel(this);
    cover->setContentsMargins(0,0,0,0);

    main_layout->addWidget(cover,0,Qt::AlignTop | Qt::AlignRight);

    right_layout = new QVBoxLayout(this);

    QGridLayout* labels = new QGridLayout(this);
    labels->setContentsMargins(0,0,0,0);

    type_label = new QLabel(this);
    type_label->setProperty("class", "highlighted-label");
    type = new QLabel(this);

    id_label = new QLabel(this);
    id_label->setProperty("class", "highlighted-label");
    id = new QLabel(this);

    title_label = new QLabel(this);
    title_label->setProperty("class", "highlighted-label");
    title = new QLabel(this);

    year_label = new QLabel(this);
    year_label->setProperty("class", "highlighted-label");
    year = new QLabel(this);

    lang_label = new QLabel(this);
    lang_label->setProperty("class", "highlighted-label");
    lang = new QLabel(this);

    publisher_label = new QLabel(this);
    publisher_label->setProperty("class", "highlighted-label");
    publisher = new QLabel(this);

    genre_label = new QLabel(this);
    genre_label->setProperty("class", "highlighted-label");
    genre = new QLabel(this);

    visitorwidget = new QWidget(this);


    labels->addWidget(type_label,0,0,1,1);
    labels->addWidget(type,0,1,1,1);
    labels->addWidget(id_label,1,0,1,1);
    labels->addWidget(id,1,1,1,1);
    labels->addWidget(title_label,2,0,1,1);
    labels->addWidget(title,2,1,1,1);
    labels->addWidget(year_label,3,0,1,1);
    labels->addWidget(year,3,1,1,1);
    labels->addWidget(lang_label,4,0,1,1);
    labels->addWidget(lang,4,1,1,1);
    labels->addWidget(publisher_label,5,0,1,1);
    labels->addWidget(publisher,5,1,1,1);
    labels->addWidget(genre_label,6,0,1,1);
    labels->addWidget(genre,6,1,1,1);

    right_layout->addLayout(labels);
    right_layout->addWidget(visitorwidget);

    main_layout->addLayout(right_layout);

    main_layout->setContentsMargins(10,5,10,10);

}

void ItemView::displayItem(const Item* item){

    QPixmap image(item->getArtPath());
    cover->setPixmap(image.scaledToHeight(360,Qt::SmoothTransformation));

    type_label->setText("TYPE");
    type->setText(item->getType());

    id_label->setText("ID");
    id->setText(item->getID());

    title_label->setText("TITLE");
    title->setText(item->getTitle());

    year_label->setText("YEAR");
    year->setText(item->getYear());

    lang_label->setText("LANGUAGE");
    lang->setText(item->getLanguage());

    publisher_label->setText("PUBLISHER");
    publisher->setText(item->getPublisher());

    genre_label->setText("GENRE");
    genre->setText(item->getGenre());

    right_layout->removeWidget(visitorwidget);
    delete visitorwidget;

    ItemInfoVisitor visitor;
    item->accept(visitor);
    visitorwidget = visitor.getWidget();

    right_layout->addWidget(visitorwidget);
}

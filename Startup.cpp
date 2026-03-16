#include "Startup.h"
#include <QVBoxLayout>


StartUp::StartUp(QWidget *parent) : QWidget(parent) {

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    setStyleSheet(

        "QPushButton { color: white ; background-color: cyan ; border-radius: 15px ; }"
        "QPushButton { font-family: 'Arial Rounded MT' ; font-size:30px ; font-weight: bold ; letter-spacing: 2px ; }"
        "QPushButton:hover { color: white ; background-color:purple !important ; border-radius: 15px ; }"
        );

    newbutton = new QPushButton(this);
    loadbutton = new QPushButton(this);

    QSpacerItem* spacertop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    QSpacerItem* spacermid = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
    QSpacerItem* spacerbottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    QIcon iconnew(":/icons/assets/icons/new_icon.png");
    newbutton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    newbutton->setIcon(iconnew);
    newbutton->setIconSize(QSize(200, 200));
    newbutton->setFixedSize(420,160);
    newbutton->setText("  NEW LIBRARY");

    QIcon iconopen(":/icons/assets/icons/load_icon.png");
    loadbutton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    loadbutton->setIcon(iconopen);
    loadbutton->setIconSize(QSize(200,200));
    loadbutton->setFixedSize(420,160);
    loadbutton->setText(" LOAD LIBRARY");

    layout->addItem(spacertop);
    layout->addWidget(newbutton);
    layout->addItem(spacermid);
    layout->addWidget(loadbutton);
    layout->addItem(spacerbottom);

setLayout(layout);

}

QPushButton* StartUp::GetNewButton(){return newbutton;}
QPushButton* StartUp::GetLoadButton(){return loadbutton;}


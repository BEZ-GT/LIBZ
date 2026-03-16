#include "LibManagement.h"
#include "AddEditItemDialog.h"
#include "Book.h"
#include "Movie.h"
#include "Game.h"
#include <QMessageBox>
#include <QSplitter>
#include <QStackedWidget>
#include "JSON_Utility.h"

LibManagement::LibManagement(Library& s_lib,QWidget *parent) : QWidget(parent),library(s_lib) {

    setStyleSheet(
        "QMessageBox {background-color:rgba(40, 24, 50, 255); font-family: 'Arial Rounded MT'; font-size:14px; font-weight:bold;}"
        "QPushButton {background:rgba(69,69,69,255) ;height:40px;border-radius: 20px;padding: 4px}"
        "QPushButton {font-family: 'Arial Rounded MT' ; font-size:25px ; font-weight:bold ;}"
        "QMessageBox QLabel {color:white;}"
        "QMessageBox QPushButton {color:white;height: 23px;border-radius: 5px;border:2px solid rgba(255,255,255,255);background:rgba(69,69,69,255);font-family: 'Arial Rounded MT' ; font-size:15px ; font-weight:bold ;}"
        "QMessageBox QPushButton:hover {background:rgba(210,0,255,50)}"
        );

    QVBoxLayout* main_layout = new QVBoxLayout(this);

    QHBoxLayout* menu_bar = new QHBoxLayout(this);
    menu_bar->setAlignment(this,Qt::AlignLeft | Qt::AlignCenter);

    saveButton = new QPushButton("  SAVE",this);
    saveButton->setIcon(QIcon(":/icons/assets/icons/save_icon.png"));
    saveButton->setIconSize(QSize(25,25));
    saveButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    saveButton->setStyleSheet("QPushButton {border:4px solid rgba(255,255,255,255);}"
                             "QPushButton:hover {background:rgba(0,14,255,50);}");

    closeButton = new QPushButton("  CLOSE",this);
    closeButton->setIcon(QIcon(":/icons/assets/icons/close_icon.png"));
    closeButton->setIconSize(QSize(25,25));
    closeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    closeButton->setStyleSheet("QPushButton {border:4px solid rgba(255,255,255,255);}"
                              "QPushButton:hover {background:rgba(255,0,0,50);}");

    menu_bar->addWidget(saveButton);
    menu_bar->addWidget(closeButton);

    main_layout->addLayout(menu_bar);
    main_layout->addItem(new QSpacerItem(10,10));

    QHBoxLayout* crud_bar = new QHBoxLayout(this);

        searchBar = new QLineEdit(this);
        searchBar->setPlaceholderText("Enter Search");
        QIcon search_icon(":/icons/assets/icons/search_icon.png");
        searchBar->addAction(search_icon,QLineEdit::LeadingPosition);
        searchBar->setFixedHeight(48);
        searchBar->setStyleSheet("QLineEdit {background:rgba(69,69,69,255);border:4px solid rgba(210,0,255,255);border-radius: 20px;padding: 4px;font-family: 'Arial Rounded MT' ; font-size:20px ; font-weight:bold ;}"
                                 "QLineEdit:hover {background:rgba(210,0,255,50)}"
                                 "QLineEdit:focus {background:rgba(210,0,255,50)}");

        QHBoxLayout* modifybuttons = new QHBoxLayout(this);

            addButton = new QPushButton("  Add",this);
            addButton->setIcon(QIcon(":/icons/assets/icons/addItem_icon.png"));
            addButton->setIconSize(QSize(25,25));
            addButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
            addButton->setStyleSheet("QPushButton {border:4px solid rgba(0,14,255,255);}"
                                     "QPushButton:hover {background:rgba(0,14,255,50);}");

            editButton = new QPushButton("  Edit",this);
            editButton->setIcon(QIcon(":/icons/assets/icons/editItem_icon.png"));
            editButton->setIconSize(QSize(25,25));
            editButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
            editButton->setStyleSheet("QPushButton {border:4px solid rgba(225,255,0,255);}"
                                      "QPushButton:hover {background:rgba(225,255,0,75);}");

            deleteButton = new QPushButton(" Delete",this);
            deleteButton->setIcon(QIcon(":/icons/assets/icons/deleteItem_icon.png"));
            deleteButton->setIconSize(QSize(25,25));
            deleteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
            deleteButton->setStyleSheet("QPushButton {border:4px solid rgba(255,0,114,255);}"
                                      "QPushButton:hover {background:rgba(255,0,114,50);}");

            modifybuttons->addWidget(addButton);
            modifybuttons->addWidget(editButton);
            modifybuttons->addWidget(deleteButton);

    crud_bar->addWidget(searchBar,0,Qt::AlignLeft);
    crud_bar->addLayout(modifybuttons);
    crud_bar->setContentsMargins(0,0,0,0);

    main_layout->addLayout(crud_bar);

    QSplitter* splitter = new QSplitter(Qt::Horizontal,this);

    list = new ItemListPreview(library,this);

    itemview = new ItemView(this);
    itemview->hide();

    splitter->addWidget(list);
    splitter->addWidget(itemview);
    splitter->setCollapsible(0,false);
    splitter->setCollapsible(1,false);

    splitter->setContentsMargins(0,0,0,0);

    main_layout->addWidget(splitter);
    main_layout->setContentsMargins(10,10,10,10);
    main_layout->setSpacing(10);

    connect(list,&ItemListPreview::itemSelected,this,&LibManagement::updateItemView);
    connect(addButton, &QPushButton::clicked, this, &LibManagement::addItem);
    connect(editButton, &QPushButton::clicked, this, &LibManagement::editItem);
    connect(deleteButton, &QPushButton::clicked, this, &LibManagement::deleteItem);
/*
    connect(searchBar,&QLineEdit::returnPressed,this,[this](){

        list->FilterItems(searchBar->text());

    });
*/
    connect(searchBar,&QLineEdit::textChanged,this,[this](const QString& text){

        if(text.isEmpty()) list->ShowAll();
        list->FilterItems(text);
    });

}

void LibManagement::keyPressEvent(QKeyEvent *event) {

    if (event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_S) {
        saveItemsToFile();
    }

    if (event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_N) {
        addItem();
    }


}



QPushButton* LibManagement::GetSaveButton(){ return saveButton;}
QPushButton* LibManagement::GetCloseButton(){ return closeButton;}

void LibManagement::updateItemView(int itemIndex) {

    if (itemIndex>=0 && itemIndex<library.Size()) {

       itemview->displayItem(library[itemIndex]);

           if (itemview->isHidden()) itemview->show();
        }

}

void LibManagement::addItem() {

    AddEditItemDialog* dialog = new AddEditItemDialog(this);

    if(dialog->exec()==QDialog::Accepted) {

        if(dialog->getType()=="Book") {

            Book* new_book = new Book("Book",
                                     dialog->getID(),
                                     dialog->getArtworkPath(),
                                     dialog->getTitle(),
                                     dialog->getYear(),
                                     dialog->getLanguage(),
                                     dialog->getPublisher(),
                                     dialog->getGenre(),

                                     dialog->getAuthor(),
                                     dialog->getStyle(),
                                     dialog->getPages());
            library.AddItem(new_book);
            list->AddItemToList(new_book);

        }

        if(dialog->getType()=="Movie") {

            Movie* new_movie = new Movie("Movie",
                                     dialog->getID(),
                                     dialog->getArtworkPath(),
                                     dialog->getTitle(),
                                     dialog->getYear(),
                                     dialog->getLanguage(),
                                     dialog->getPublisher(),
                                     dialog->getGenre(),

                                     dialog->getDuration(),
                                     dialog->getDirector(),
                                     dialog->getCast());

            library.AddItem(new_movie);
            list->AddItemToList(new_movie);

        }

        if(dialog->getType()=="Game") {

            Game* new_game = new Game("Game",
                                     dialog->getID(),
                                     dialog->getArtworkPath(),
                                     dialog->getTitle(),
                                     dialog->getYear(),
                                     dialog->getLanguage(),
                                     dialog->getPublisher(),
                                     dialog->getGenre(),

                                     dialog->getPlatform(),
                                     dialog->getPegi(),
                                     dialog->getPlayers(),
                                     dialog->getDeveloper(),
                                     dialog->getEngine()
                                     );
            library.AddItem(new_game);
            list->AddItemToList(new_game);

        }

    }

}

void LibManagement::editItem() {

    if(list->isEmpty()){

                QMessageBox::warning(this,"Error","Library is empty!");
        return;
    }

    Item* item = library[list->CurrentListIndex()];

    if(item) {

        AddEditItemDialog* dialog = new AddEditItemDialog(this);

        dialog->setType(item->getType());
        dialog->GetTypeSelector()->setDisabled(true);
        dialog->setID(item->getID());
        dialog->setArtworkPath(item->getArtPath());
        dialog->setTitle(item->getTitle());
        dialog->setYear(item->getYear());
        dialog->setLanguage(item->getLanguage());
        dialog->setPublisher(item->getPublisher());
        dialog->setGenre(item->getGenre());

        if(dynamic_cast<Book*>(item)){

            Book* edit_book = static_cast<Book*>(item);

            dialog->setAuthor(edit_book->getAuthor());
            dialog->setStyle(edit_book->getStyle());
            dialog->setPages(edit_book->getPages());

            if(dialog->exec()==QDialog::Accepted) {

                edit_book->setID(dialog->getID());

                if (dialog->getArtworkPath().isEmpty()) edit_book->setArtPath(":/icons/assets/icons/book_icon.png");
                else edit_book->setArtPath(dialog->getArtworkPath());

                edit_book->setTitle(dialog->getTitle());
                edit_book->setYear(dialog->getYear());
                edit_book->setLanguage(dialog->getLanguage());
                edit_book->setPublisher(dialog->getPublisher());
                edit_book->setGenre(dialog->getGenre());

                edit_book->setAuthor(dialog->getAuthor());
                edit_book->setStyle(dialog->getStyle());
                edit_book->setPages(dialog->getPages());

                list->CurrentListWidget()->UpdatePreview();

                }

        }

        if(dynamic_cast<Movie*>(item)){

            Movie* edit_movie = static_cast<Movie*>(item);

            dialog->setDuration(edit_movie->getDuration());
            dialog->setDirector(edit_movie->getDirector());
            dialog->setCast(edit_movie->getCast());

            if(dialog->exec()==QDialog::Accepted) {

                edit_movie->setID(dialog->getID());

                if (dialog->getArtworkPath().isEmpty()) edit_movie->setArtPath(":/icons/assets/icons/movie_icon.png");
                else edit_movie->setArtPath(dialog->getArtworkPath());

                edit_movie->setTitle(dialog->getTitle());
                edit_movie->setYear(dialog->getYear());
                edit_movie->setLanguage(dialog->getLanguage());
                edit_movie->setPublisher(dialog->getPublisher());
                edit_movie->setGenre(dialog->getGenre());

                edit_movie->setDuration(dialog->getDuration());
                edit_movie->setDirector(dialog->getDirector());
                edit_movie->setCast(dialog->getCast());

                list->CurrentListWidget()->UpdatePreview();

                }

        }

        if(dynamic_cast<Game*>(item)){

            Game* edit_game = static_cast<Game*>(item);

            dialog->setPlatform(edit_game->getPlatform());
            dialog->setPegi(edit_game->getPegi());
            dialog->setPlayers(edit_game->getPlayers());
            dialog->setDeveloper(edit_game->getDev());
            dialog->setEngine(edit_game->getEngine());

            if(dialog->exec()==QDialog::Accepted) {

                edit_game->setID(dialog->getID());

                if (dialog->getArtworkPath().isEmpty()) edit_game->setArtPath(":/icons/assets/icons/game_icon.png");
                else edit_game->setArtPath(dialog->getArtworkPath());

                edit_game->setTitle(dialog->getTitle());
                edit_game->setYear(dialog->getYear());
                edit_game->setLanguage(dialog->getLanguage());
                edit_game->setPublisher(dialog->getPublisher());
                edit_game->setGenre(dialog->getGenre());

                edit_game->setPlatform(dialog->getPlatform());
                edit_game->setPegi(dialog->getPegi());
                edit_game->setPlayers(dialog->getPlayers());
                edit_game->setDev(dialog->getDeveloper());
                edit_game->setEngine(dialog->getEngine());

                list->CurrentListWidget()->UpdatePreview();

                }

        }

        itemview->displayItem(item);

    } else {

        QMessageBox::warning(this,"Error","Please Select an Item");
    }

}

void LibManagement::deleteItem() {

    if(list->isEmpty()) {

        QMessageBox::warning(this,"Error","Library is empty!");
        return;

    }

    QListWidgetItem* widget_item = list->CurrentListItem();

    if (widget_item) {

        int ret = QMessageBox::question(this,"Attention","Current Item Will Be Deleted.\n" "Continue?",QMessageBox::Yes | QMessageBox::Cancel,QMessageBox::Cancel);
        if (ret == QMessageBox::Yes) {

            itemview->hide();
            Item* del_ptr = library[list->CurrentListIndex()];
            int del_index = list->CurrentListIndex();

            delete widget_item;
            library.RemoveItem(del_index);
            delete del_ptr;
        }

    } else {

        QMessageBox::warning(this,"Error","Please Select an Item");

    }

}

void LibManagement::saveItemsToFile() {

    QString filePath = QFileDialog::getSaveFileName(this, "Save Library", "", "JSON Files (*.json)");

    if (!filePath.isEmpty()) {

    bool success = JSON_Utility::saveItems(library,filePath);

        if(!success) {

            QMessageBox::warning(this,"Error","Unable To Open File For Saving");

        }
    }
}

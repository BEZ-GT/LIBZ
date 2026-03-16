#include "Library.h"
#include "Book.h"
#include "Movie.h"
#include "Game.h"


Library::Library() {}

QList<Item*> Library::FilterItems(const QString& query) const {

    QList<Item*> filtered_items;

    for(int i=0;i<items.size();i++){

        Item* item = items[i];

        if (((item->getID()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getTitle()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getYear()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getLanguage()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getPublisher()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getGenre()).contains(query,Qt::CaseInsensitive))) {

            filtered_items.push_back(item);

        }

        else if (dynamic_cast<Book*>(item)) {

            Book* book = static_cast<Book*>(item);

            if (((book->getAuthor()).contains(query,Qt::CaseInsensitive)) ||
                ((book->getStyle()).contains(query,Qt::CaseInsensitive)) ||
                (QString::number(book->getPages()).contains(query,Qt::CaseInsensitive))) {

                filtered_items.push_back(book);

            }

        }

        else if (dynamic_cast<Movie*>(item)) {

            Movie* movie = static_cast<Movie*>(item);

            if (((movie->getCast().join(" ")).contains(query,Qt::CaseInsensitive)) ||
                ((movie->getDirector()).contains(query,Qt::CaseInsensitive)) ||
                (QString::number(movie->getDuration()).contains(query,Qt::CaseInsensitive))) {

                filtered_items.push_back(movie);

            }

        }

        else if (dynamic_cast<Game*>(item)) {

            Game* game = static_cast<Game*>(item);

            if (((game->getPlatform()).contains(query,Qt::CaseInsensitive)) ||
                ((game->getPegi()).contains(query,Qt::CaseInsensitive)) ||
                (QString::number(game->getPlayers()).contains(query,Qt::CaseInsensitive)) ||
                ((game->getDev()).contains(query,Qt::CaseInsensitive)) ||
                ((game->getEngine()).contains(query,Qt::CaseInsensitive))) {

                filtered_items.push_back(game);

            }
        }
    }

    return filtered_items;
}

QList<bool> Library::IsFiltered(const QString& query) const{

    QList<bool> is_filtered;

    for(int i=0;i<items.size();i++){

        Item* item = items[i];
        Book* book = nullptr;
        Movie* movie = nullptr;
        Game* game = nullptr;

        if (((item->getID()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getTitle()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getYear()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getLanguage()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getPublisher()).contains(query,Qt::CaseInsensitive)) ||
            ((item->getGenre()).contains(query,Qt::CaseInsensitive))) {

            is_filtered.push_back(true);

        }

        else if ((book = dynamic_cast<Book*>(item)) &&

                (((book->getAuthor()).contains(query,Qt::CaseInsensitive)) ||
                ((book->getStyle()).contains(query,Qt::CaseInsensitive)) ||
                (QString::number(book->getPages()).contains(query,Qt::CaseInsensitive)))) {

                is_filtered.push_back(true);

            }

        else if ((movie = dynamic_cast<Movie*>(item)) &&

                (((movie->getCast().join("")).contains(query,Qt::CaseInsensitive)) ||
                ((movie->getDirector()).contains(query,Qt::CaseInsensitive)) ||
                (QString::number(movie->getDuration()).contains(query,Qt::CaseInsensitive)))) {

                is_filtered.push_back(true);

            }


        else if ((game = dynamic_cast<Game*>(item)) &&

                (((game->getPlatform()).contains(query,Qt::CaseInsensitive)) ||
                ((game->getPegi()).contains(query,Qt::CaseInsensitive)) ||
                (QString::number(game->getPlayers()).contains(query,Qt::CaseInsensitive)) ||
                ((game->getDev()).contains(query,Qt::CaseInsensitive)) ||
                ((game->getEngine()).contains(query,Qt::CaseInsensitive)))) {

                is_filtered.push_back(true);

            }


        else {

            is_filtered.push_back(false);

        }

    }

    return is_filtered;

}

void Library::AddItem(Item* new_item) {items.push_back(new_item);}
void Library::RemoveItem(int index) {items.removeAt(index);}
int Library::Size() const {return items.size();}

Item* Library::operator[] (int index) {

    if(index<0||index>=items.size()) return nullptr;
    else return items[index];

}

const Item* Library::operator[] (int index) const {

    if(index<0||index>=items.size()) return nullptr;
    return items[index];

}

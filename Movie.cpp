#include "Movie.h"
#include <QJsonArray>

Movie::Movie(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,
             QString s_pub,QString s_genre,int s_duration,QString s_director,QStringList s_cast) :

    Item(s_type,s_id,art,s_title,s_year,s_language,s_pub,s_genre),duration(s_duration),director(s_director),cast(s_cast) {}




int Movie::getDuration() const {return duration;}
QString Movie::getDirector() const {return director;}
QStringList Movie::getCast() const{return cast;}

void Movie::setDuration(int n) {duration=n;}
void Movie::setDirector(QString s) {director=s;}
void Movie::setCast(QStringList names) {cast=names;}

void Movie::accept(ItemVisitorInterface& visitor) const {

    visitor.visitMovie(*this);
}

QJsonObject Movie::ItemToJson() const {

    QJsonObject obj;

    obj["Type"] = type;
    obj["ID"] = id;
    obj["ArtworkPath"] = artworkpath;
    obj["Title"] = title;
    obj["Year"] = year;
    obj["Language"] = language;
    obj["Publisher"] = publisher;
    obj["Genre"] = genre;

    obj["Duration"] = duration;
    obj["Director"] = director;
    QJsonArray j_cast;

    for (const QString& member : cast) {

        j_cast.append(QJsonValue(member));
    }

    obj["Cast"] = j_cast;

    return obj;

}

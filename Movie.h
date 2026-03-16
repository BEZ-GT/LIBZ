#ifndef MOVIE_H
#define MOVIE_H

#include "Item.h"
#include <QStringList>

class Movie: public Item {

private:

    int duration;
    QString director;
    QStringList cast;

public:

    Movie(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,
          QString s_pub,QString s_genre,int s_duration,QString s_director,QStringList s_cast);

    ~Movie()= default;

    int getDuration() const;
    QString getDirector() const;
    QStringList getCast() const;

    void setDuration(int n);
    void setDirector(QString s);
    void setCast(QStringList names);

    void accept(ItemVisitorInterface& visitor) const override;
    QJsonObject ItemToJson() const override;
};

#endif // MOVIE_H

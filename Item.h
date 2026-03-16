#ifndef ITEM_H
#define ITEM_H

#include<QString>
#include<ItemVisitorInterface.h>
#include<QJsonObject>

class Item {

protected:

    const QString type;
    QString id;
    QString artworkpath;
    QString title;
    QString year;
    QString language;
    QString publisher;
    QString genre;

public:

    Item(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,QString s_pub,QString s_genre);
    virtual ~Item()= default;

    QString getID() const;
    QString getArtPath() const;
    QString getTitle() const;
    QString getYear() const;
    QString getLanguage() const;
    QString getPublisher() const;
    QString getGenre() const;
    QString getType() const;

    void setID(QString s);
    void setArtPath(QString s);
    void setTitle(QString s);
    void setYear(QString s);
    void setLanguage(QString s);
    void setPublisher(QString s);
    void setGenre(QString s);

    virtual void accept(ItemVisitorInterface& visitor) const = 0;
    virtual QJsonObject ItemToJson() const = 0;
};

#endif // ITEM_H

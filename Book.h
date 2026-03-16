#ifndef BOOK_H
#define BOOK_H

#include "Item.h"

class Book: public Item {

private:

    QString author;
    QString style;
    int pages;

public:

    Book(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,QString s_pub,QString s_genre,QString s_author,QString s_style,int n);
    virtual ~Book()= default;

    QString getAuthor() const;
    QString getStyle() const;
    int getPages() const;

    void setAuthor(QString s);
    void setStyle(QString s);
    void setPages(int n);

    void accept(ItemVisitorInterface& visitor) const override;
    QJsonObject ItemToJson() const override;
};

#endif // BOOK_H

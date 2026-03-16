#include "Book.h"

Book::Book(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,QString s_pub,QString s_genre,QString s_author,QString s_style,int n):
    Item(s_type,s_id,art,s_title,s_year,s_language,s_pub,s_genre),author(s_author),style(s_style),pages(n) {}


QString Book::getAuthor() const{return author;}
QString Book::getStyle() const{return style;}
int Book::getPages() const{return pages;}

void Book::setAuthor(QString s) {author=s;}
void Book::setStyle(QString s){style=s;}
void Book::setPages(int n){pages =n;}

void Book::accept(ItemVisitorInterface& visitor) const {

    visitor.visitBook(*this);
}

QJsonObject Book::ItemToJson() const {

    QJsonObject obj;

    obj["Type"] = type;
    obj["ID"] = id;
    obj["ArtworkPath"] = artworkpath;
    obj["Title"] = title;
    obj["Year"] = year;
    obj["Language"] = language;
    obj["Publisher"] = publisher;
    obj["Genre"] = genre;

    obj["Author"] = author;
    obj["Style"] = style;
    obj["Pages"] = pages;

    return obj;

}

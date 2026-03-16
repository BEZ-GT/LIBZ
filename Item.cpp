#include "Item.h"

Item::Item(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,QString s_pub,QString s_genre) :
    type(s_type),id(s_id),artworkpath(art),title(s_title),year(s_year),language(s_language),publisher(s_pub),genre(s_genre) {}

QString Item::getType() const {return type;}
QString Item::getArtPath() const {return artworkpath;}
QString Item::getID() const {return id;}
QString Item::getTitle() const{return title;}
QString Item::getYear() const{return year;}
QString Item::getLanguage() const{return language;}
QString Item::getPublisher() const{return publisher;}
QString Item::getGenre() const {return genre;}



void Item::setID(QString s) {id=s;}
void Item::setArtPath(QString s) {artworkpath=s;}
void Item::setTitle(QString s) {title=s;}
void Item::setYear(QString s) {year=s;}
void Item::setLanguage(QString s) {language=s;}
void Item::setPublisher(QString s) {publisher=s;}
void Item::setGenre(QString s) {genre=s;}

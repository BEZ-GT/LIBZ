#include "Game.h"

Game::Game(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,QString s_pub,QString s_genre,
           QString plat,QString pegi,int n_players,QString dev,QString s_engine):
    Item(s_type,s_id,art,s_title,s_year,s_language,s_pub,s_genre),platform(plat),pegi_r(pegi),players(n_players),developer(dev),engine(s_engine) {}

QString Game::getPlatform() const {return platform;}
QString Game::getPegi() const {return pegi_r;}
int Game::getPlayers() const {return players;}
QString Game::getDev() const {return developer;}
QString Game::getEngine() const {return engine;}

void Game::setPlatform(QString s) {platform=s;}
void Game::setPegi(QString s) {pegi_r=s;}
void Game::setPlayers(int n) {players=n;}
void Game::setDev(QString s) {developer=s;}
void Game::setEngine(QString s) {engine=s;}

void Game::accept(ItemVisitorInterface& visitor) const {

    visitor.visitGame(*this);
}

QJsonObject Game::ItemToJson() const {

    QJsonObject obj;

    obj["Type"] = type;
    obj["ID"] = id;
    obj["ArtworkPath"] = artworkpath;
    obj["Title"] = title;
    obj["Year"] = year;
    obj["Language"] = language;
    obj["Publisher"] = publisher;
    obj["Genre"] = genre;

    obj["Platform"] = platform;
    obj["Pegi"] = pegi_r;
    obj["Players"] = players;
    obj["Developer"] = developer;
    obj["Engine"] = engine;

    return obj;

}

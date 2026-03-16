#ifndef GAME_H
#define GAME_H

#include "Item.h"

class Game: public Item {

private:

    QString platform;
    QString pegi_r;
    int players;
    QString developer;
    QString engine;


public:

    Game(QString s_type,QString s_id,QString art,QString s_title,QString s_year,QString s_language,QString s_pub,QString s_genre,
        QString plat,QString pegi,int n_players,QString dev,QString s_engine);
    virtual ~Game()= default;

    QString getPlatform() const;
    QString getPegi() const;
    int getPlayers() const;
    QString getDev() const;
    QString getEngine() const;

    void setPlatform(QString s);
    void setPegi(QString s);
    void setPlayers(int n);
    void setDev(QString s);
    void setEngine(QString s);

    void accept(ItemVisitorInterface& visitor) const override;
    QJsonObject ItemToJson() const override;
};

#endif // GAME_H

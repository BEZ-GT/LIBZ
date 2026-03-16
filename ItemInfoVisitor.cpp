#include "ItemInfoVisitor.h"
#include "Book.h"
#include "Movie.h"
#include "Game.h"
#include <QLabel>
#include <QGridLayout>


QWidget* ItemInfoVisitor::getWidget() {
    return widget;
}
void ItemInfoVisitor::visitBook(const Book& book) {
    widget = new QWidget();

    QGridLayout* adv_labels = new QGridLayout(widget);

    QLabel* author_label = new QLabel("AUTHOR",widget);
    author_label->setProperty("class", "highlighted-label");
    QLabel* author = new QLabel(book.getAuthor(),widget);
    QLabel* style_label = new QLabel("STYLE",widget);
    style_label->setProperty("class", "highlighted-label");
    QLabel* style = new QLabel(book.getStyle(),widget);
    QLabel* pages_label = new QLabel("PAGES",widget);
    pages_label->setProperty("class", "highlighted-label");
    QLabel* pages = new QLabel(QString::number(book.getPages()),widget);

    adv_labels->setContentsMargins(0,0,0,0);

    adv_labels->addWidget(author_label,0,0,1,1);
    adv_labels->addWidget(author,0,1,1,1);
    adv_labels->addWidget(style_label,1,0,1,1);
    adv_labels->addWidget(style,1,1,1,1);
    adv_labels->addWidget(pages_label,2,0,1,1);
    adv_labels->addWidget(pages,2,1,1,1);
    adv_labels->setColumnMinimumWidth(0,80);
    adv_labels->setColumnMinimumWidth(1,80);

}

void ItemInfoVisitor::visitMovie(const Movie& movie){
    widget = new QWidget();

    QGridLayout* adv_labels = new QGridLayout(widget);

    QLabel* duration_label = new QLabel("DURATION",widget);
    duration_label->setProperty("class", "highlighted-label");
    QLabel* duration = new QLabel(QString::number(movie.getDuration())+" min",widget);

    QLabel* director_label = new QLabel("DIRECTOR",widget);
    director_label->setProperty("class", "highlighted-label");
    QLabel* director = new QLabel(movie.getDirector(),widget);

    QLabel* cast_label = new QLabel("CAST",widget);
    cast_label->setProperty("class", "highlighted-label");

    QString castlist;
    QStringList cast_util = movie.getCast();
    for (int i=0;i<cast_util.size();i++) {
        castlist.append((cast_util[i])+"\n");
    }
    QLabel* cast = new QLabel(castlist,widget);
    cast->setWordWrap(true);

    adv_labels->setContentsMargins(0,0,0,0);

    adv_labels->addWidget(duration_label,0,0,1,1);
    adv_labels->addWidget(duration,0,1,1,1);
    adv_labels->addWidget(director_label,1,0,1,1);
    adv_labels->addWidget(director,1,1,1,1);
    adv_labels->addWidget(cast_label,2,0,1,1);
    adv_labels->addWidget(cast,2,1,1,1);

}
void ItemInfoVisitor::visitGame(const Game& game) {
    widget = new QWidget();

    QGridLayout* adv_labels = new QGridLayout(widget);

    QLabel* platform_label = new QLabel("PLATFORM",widget);
    platform_label->setProperty("class", "highlighted-label");
    QLabel* platform = new QLabel(game.getPlatform(),widget);

    QLabel* pegi_label = new QLabel("PEGI RATING",widget);
    pegi_label->setProperty("class", "highlighted-label");
    QLabel* pegi = new QLabel(game.getPegi(),widget);

    QLabel* players_label = new QLabel("PLAYERS",widget);
    players_label->setProperty("class", "highlighted-label");
    QLabel* players = new QLabel(QString::number(game.getPlayers()),widget);

    QLabel* developer_label = new QLabel("DEVELOPER",widget);
    developer_label->setProperty("class", "highlighted-label");
    QLabel* developer = new QLabel(game.getDev(),widget);

    QLabel* engine_label = new QLabel("ENGINE",widget);
    engine_label->setProperty("class", "highlighted-label");
    QLabel* engine = new QLabel(game.getEngine(),widget);

    adv_labels->setContentsMargins(0,0,0,0);

    adv_labels->addWidget(platform_label,0,0,1,1);
    adv_labels->addWidget(platform,0,1,1,1);
    adv_labels->addWidget(pegi_label,1,0,1,1);
    adv_labels->addWidget(pegi,1,1,1,1);
    adv_labels->addWidget(players_label,2,0,1,1);
    adv_labels->addWidget(players,2,1,1,1);
    adv_labels->addWidget(developer_label,3,0,1,1);
    adv_labels->addWidget(developer,3,1,1,1);
    adv_labels->addWidget(engine_label,4,0,1,1);
    adv_labels->addWidget(engine,4,1,1,1);

}

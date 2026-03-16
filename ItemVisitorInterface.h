#ifndef ITEMVISITORINTERFACE_H
#define ITEMVISITORINTERFACE_H

class Book;
class Movie;
class Game;

class ItemVisitorInterface {

public:
    virtual ~ItemVisitorInterface()= default;
    virtual void visitBook(const Book& book) = 0;
    virtual void visitMovie(const Movie& movie) = 0;
    virtual void visitGame(const Game& game) = 0;
};


#endif // ITEMVISITORINTERFACE_H

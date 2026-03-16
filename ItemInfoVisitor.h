#ifndef ITEMINFOVISITOR_H
#define ITEMINFOVISITOR_H

#include "ItemVisitorInterface.h"
#include <QWidget>

class ItemInfoVisitor: public ItemVisitorInterface {

private:
    QWidget* widget;

public:

    QWidget* getWidget();
    virtual void visitBook(const Book& book);
    virtual void visitGame(const Game& game);
    virtual void visitMovie(const Movie& movie);
};

#endif // ITEMINFOVISITOR_H

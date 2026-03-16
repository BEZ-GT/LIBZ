#ifndef LIBMANAGEMENT_H
#define LIBMANAGEMENT_H

#include "Library.h"
#include "ItemListPreview.h"
#include "ItemView.h"
#include <QPushButton>
#include <QKeyEvent>

class LibManagement : public QWidget
{
    Q_OBJECT

private:

    Library& library;

    QPushButton* saveButton;
    QPushButton* closeButton;

    QLineEdit* searchBar;

    QPushButton* addButton;
    QPushButton* editButton;
    QPushButton* deleteButton;

    ItemListPreview* list;
    ItemView* itemview;

public:

    explicit LibManagement(Library& s_lib,QWidget *parent = nullptr);
    virtual ~LibManagement()= default;

    QPushButton* GetSaveButton();
    QPushButton* GetCloseButton();
    void saveItemsToFile();

protected:

    void keyPressEvent(QKeyEvent *event);

private slots:

    void updateItemView(int itemIndex);
    void addItem();
    void editItem();
    void deleteItem();

};

#endif // LIBMANAGEMENT_H

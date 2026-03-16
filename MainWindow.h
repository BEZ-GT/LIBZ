#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "Item.h"
#include "Startup.h"
#include "LibManagement.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QStackedWidget* tabs;
    StartUp* prompt;
    LibManagement* manager;
    Library* library;

static void loadItemsFromFile(MainWindow* window,Library& lib);

protected:

    void keyPressEvent(QKeyEvent *event);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow()= default;


};
#endif // MAINWINDOW_H

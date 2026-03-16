#include "MainWindow.h"
#include "ItemView.h"
#include "Book.h"
#include "Movie.h"
#include "Game.h"
#include "ItemPreview.h"
#include "ItemListPreview.h"
#include "LibManagement.h"
#include "AddEditItemDialog.h"
#include "JSON_Utility.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {

   setStyleSheet("QMainWindow {background-color:rgba(40, 24, 50, 255)}");

    tabs = new QStackedWidget(this);
    prompt = new StartUp(this);

    tabs->addWidget(prompt);

    connect(prompt->GetLoadButton(),&QPushButton::clicked,this,[this](){

        library = new Library();

        MainWindow::loadItemsFromFile(this,*library);

        manager = new LibManagement(*library,this);
        tabs->addWidget(manager);
        tabs->setCurrentIndex(1);

        disconnect(manager->GetSaveButton(),&QPushButton::clicked,nullptr,nullptr);
        disconnect(manager->GetCloseButton(),&QPushButton::clicked,nullptr,nullptr);

        connect(manager->GetSaveButton(),&QPushButton::clicked,this,[this](){

            if (manager) manager->saveItemsToFile();

        });

        connect(manager->GetCloseButton(),&QPushButton::clicked,this,[this](){

            int ret = QMessageBox::question(manager,"Attention","Current Library Will Be Closed.\n" "Continue?",QMessageBox::Yes | QMessageBox::Cancel,QMessageBox::Cancel);
            if (ret == QMessageBox::Yes) {

                tabs->setCurrentIndex(0);
                tabs->removeWidget(manager);
                delete manager;
            }
        });

    });

    connect(prompt->GetNewButton(),&QPushButton::clicked,this,[this](){

        library = new Library();
        manager = new LibManagement(*library,this);
        tabs->addWidget(manager);
        tabs->setCurrentIndex(1);

        disconnect(manager->GetSaveButton(),&QPushButton::clicked,nullptr,nullptr);
        disconnect(manager->GetCloseButton(),&QPushButton::clicked,nullptr,nullptr);

        connect(manager->GetSaveButton(),&QPushButton::clicked,this,[this](){

            if (manager) manager->saveItemsToFile();

        });

        connect(manager->GetCloseButton(),&QPushButton::clicked,this,[this](){

            int ret = QMessageBox::question(manager,"Attention","Current Library Will Be Closed.\n" "Continue?",QMessageBox::Yes | QMessageBox::Cancel,QMessageBox::Cancel);
            if (ret == QMessageBox::Yes) {

                tabs->setCurrentIndex(0);
                tabs->removeWidget(manager);
                delete manager;
                }

        });

    });

    this->setWindowTitle("LIBZ");
    this->setWindowIcon(QIcon(":/icons/assets/icons/window_icon.png"));

    setCentralWidget(tabs);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if (event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_O) {

        library = new Library();

        MainWindow::loadItemsFromFile(this,*library);

        manager = new LibManagement(*library,this);
        tabs->addWidget(manager);
        tabs->setCurrentIndex(1);

        disconnect(manager->GetSaveButton(),&QPushButton::clicked,nullptr,nullptr);
        disconnect(manager->GetCloseButton(),&QPushButton::clicked,nullptr,nullptr);

        connect(manager->GetSaveButton(),&QPushButton::clicked,this,[this](){

            if (manager) manager->saveItemsToFile();

        });

        connect(manager->GetCloseButton(),&QPushButton::clicked,this,[this](){

            int ret = QMessageBox::question(manager,"Attention","Current Library Will Be Closed.\n" "Continue?",QMessageBox::Yes | QMessageBox::Cancel,QMessageBox::Cancel);
            if (ret == QMessageBox::Yes) {

                tabs->setCurrentIndex(0);
                tabs->removeWidget(manager);
                delete manager;
            }
        });

    }

}

void MainWindow::loadItemsFromFile(MainWindow* window,Library& lib) {

    QString filePath = QFileDialog::getOpenFileName(window, "Load Library", "", "JSON Files (*.json)");

    if (!filePath.isEmpty()) {

    bool success = JSON_Utility::loadItems(lib,filePath);

        if (!success) {

            QMessageBox::warning(window,"Error","Unable To Open File");

        }
    }

}

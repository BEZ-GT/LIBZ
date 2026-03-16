#include "AddEditItemDialog.h"
#include "Book.h"
#include "Movie.h"
#include "Game.h"
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QSpacerItem>

AddEditItemDialog::AddEditItemDialog(QWidget *parent): QDialog(parent) {

    setStyleSheet(

        "QLabel { color:white ; background-color: purple ; border-radius: 4px ; padding: 3px ; }"
        "QLabel { font-family: 'Arial Rounded MT' ; font-size:14px ; font-weight: bold ; }"
        "QPushButton { color:white ; background-color: rgba(0,0,255,100) ; border-radius: 4px ; padding: 3px ; }"
        "QPushButton { font-family: 'Arial Rounded MT' ; font-size:18px ; font-weight: bold ; }"
        "QPushButton:hover { background-color: rgba(0,0,255,200) !important ;}"
        "QComboBox {text-align:center; font-family: 'Arial Rounded MT' ; font-size:14px ;font-weight: normal ; }"
        "QLineEdit { font-family: 'Arial Rounded MT' ; font-size:14px ;font-weight: normal ; }"
        "QSpinBox { font-family: 'Arial Rounded MT' ; font-size:14px ;font-weight: normal ; }"
        "QTextEdit { font-family: 'Arial Rounded MT' ; font-size:14px ;font-weight: normal ; }"
        "QDialog {background-color: rgba(20,20,20,255);}"
        );

    layout = new QFormLayout(this);

        typeSelector = new QComboBox(this);
        typeSelector->addItem("Book");
        typeSelector->addItem("Movie");
        typeSelector->addItem("Game");

        idEdit = new QLineEdit(this);
        titleEdit= new QLineEdit(this);
        selectArtButton = new QPushButton("SELECT ARTWORK",this);
        selectArtButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        artworkpathEdit = new QLineEdit(this);
        yearEdit= new QLineEdit(this);
        languageEdit= new QLineEdit(this);
        publisherEdit= new QLineEdit(this);
        genreEdit= new QLineEdit(this);

            QPushButton *okButton = new QPushButton("OK", this);
            okButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
            QPushButton *cancelButton = new QPushButton("CANCEL", this);
            cancelButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    layout->addRow(new QLabel("TYPE"),typeSelector);
    layout->addRow(new QLabel("ID"),idEdit);
    layout->addRow(new QLabel("TITLE"),titleEdit);
    layout->addRow(selectArtButton);
    layout->addRow(new QLabel("ARTWORK"),artworkpathEdit);
    layout->addRow(new QLabel("YEAR"),yearEdit);
    layout->addRow(new QLabel("LANGUAGE"),languageEdit);
    layout->addRow(new QLabel("PUBLISHER"),publisherEdit);
    layout->addRow(new QLabel("GENRE"),genreEdit);

    setupExtraUi(typeSelector->currentText());

    layout->addItem(new QSpacerItem(10,20));
    layout->addRow(cancelButton,okButton);

    setLayout(layout);

    connect(selectArtButton,&QPushButton::clicked,this,[this](){

    QString art_path = QFileDialog::getOpenFileName(this, "Select Artwork ", "", "Image Files (*.png *.jpg *.jpeg *.bmp )");

    if (art_path.isEmpty()) {

        artworkpathEdit->setText(":/icons/assets/icons/" + typeSelector->currentText().toLower() + "_icon.png");
        }

    else artworkpathEdit->setText(art_path);

    });
    connect(okButton, &QPushButton::clicked, this, &AddEditItemDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AddEditItemDialog::reject);
    connect(typeSelector,&QComboBox::currentTextChanged,this,[this](const QString& text) {

        this->clearUi();
        this->setupExtraUi(text);

    });
    this->setMinimumWidth(500);
}

QString AddEditItemDialog::getType() const {return typeSelector->currentText();}
QString AddEditItemDialog::getID() const {return idEdit->text();}
QString AddEditItemDialog::getArtworkPath() const {return artworkpathEdit->text();}
QString AddEditItemDialog::getTitle() const {return titleEdit->text();}
QString AddEditItemDialog::getYear() const {return yearEdit->text();}
QString AddEditItemDialog::getLanguage() const {return languageEdit->text();}
QString AddEditItemDialog::getPublisher() const {return publisherEdit->text();}
QString AddEditItemDialog::getGenre() const {return genreEdit->text();}

QString AddEditItemDialog::getAuthor() const {return authorEdit->text();}
QString AddEditItemDialog::getStyle() const {return styleEdit->text();}
int AddEditItemDialog::getPages() const {return pagesEdit->value();}

int AddEditItemDialog::getDuration() const {return durationEdit->value();}
QString AddEditItemDialog::getDirector() const {return directorEdit->text();}
QStringList AddEditItemDialog::getCast() const {

    QString temp = castEdit->toPlainText();
    QStringList list = temp.split('\n');
    return list;
}

QString AddEditItemDialog::getPlatform() const {return platformEdit->text();}
QString AddEditItemDialog::getPegi() const {return pegiEdit->text();}
int AddEditItemDialog::getPlayers() const {return playersEdit->value();}
QString AddEditItemDialog::getDeveloper() const {return developerEdit->text();}
QString AddEditItemDialog::getEngine() const {return engineEdit->text();}

void AddEditItemDialog::setType(QString type){typeSelector->setCurrentText(type);}
void AddEditItemDialog::setID(QString id){idEdit->setText(id);}
void AddEditItemDialog::setArtworkPath(QString art_path){artworkpathEdit->setText(art_path);}
void AddEditItemDialog::setTitle(QString title){titleEdit->setText(title);}
void AddEditItemDialog::setYear(QString year){yearEdit->setText(year);}
void AddEditItemDialog::setLanguage(QString language){languageEdit->setText(language);}
void AddEditItemDialog::setPublisher(QString publisher){publisherEdit->setText(publisher);}
void AddEditItemDialog::setGenre(QString genre){genreEdit->setText(genre);}

void AddEditItemDialog::setAuthor(QString author) {authorEdit->setText(author);}
void AddEditItemDialog::setStyle(QString style) {styleEdit->setText(style);}
void AddEditItemDialog::setPages(int pages){pagesEdit->setValue(pages);}

void AddEditItemDialog::setDuration(int duration){durationEdit->setValue(duration);}
void AddEditItemDialog::setDirector(QString director){directorEdit->setText(director);}
void AddEditItemDialog::setCast(QStringList cast){

    for(int i=0;i<cast.size();i++){

        castEdit->append(cast[i]);
    }

}

void AddEditItemDialog::setPlatform(QString platform){platformEdit->setText(platform);}
void AddEditItemDialog::setPegi(QString pegi){pegiEdit->setText(pegi);}
void AddEditItemDialog::setPlayers(int players){playersEdit->setValue(players);}
void AddEditItemDialog::setDeveloper(QString developer){developerEdit->setText(developer);}
void AddEditItemDialog::setEngine(QString engine){engineEdit->setText(engine);}

void AddEditItemDialog::setupExtraUi(const QString& text) {

    if( text == "Book" ) {

        artworkpathEdit->setText(":/icons/assets/icons/book_icon.png");

        authorEdit = new QLineEdit(this);
        styleEdit = new QLineEdit(this);
        pagesEdit = new QSpinBox(this);
        pagesEdit->setRange(0,9999);

        layout->insertRow(9,new QLabel("AUTHOR"),authorEdit);
        layout->insertRow(10,new QLabel("STYLE"),styleEdit);
        layout->insertRow(11,new QLabel("PAGES"),pagesEdit);

    }

    if(text == "Movie" ) {

        artworkpathEdit->setText(":/icons/assets/icons/movie_icon.png");

        durationEdit = new QSpinBox(this);
        durationEdit->setRange(0,999);
        durationEdit->setSuffix(" min");
        directorEdit = new QLineEdit(this);
        castEdit = new QTextEdit(this);

        layout->insertRow(9,new QLabel("DURATION"),durationEdit);
        layout->insertRow(10,new QLabel("DIRECTOR"),directorEdit);
        layout->insertRow(11,new QLabel("CAST"),castEdit);

    }

    if(text == "Game" ) {

        artworkpathEdit->setText(":/icons/assets/icons/game_icon.png");

        platformEdit = new QLineEdit(this);
        pegiEdit = new QLineEdit(this);
        playersEdit = new QSpinBox(this);
        developerEdit = new QLineEdit(this);
        engineEdit = new QLineEdit(this);

        layout->insertRow(9,new QLabel("PLATFORM"),platformEdit);
        layout->insertRow(10,new QLabel("PEGI"),pegiEdit);
        layout->insertRow(11,new QLabel("PLAYERS"),playersEdit);
        layout->insertRow(12,new QLabel("DEVELOPER"),developerEdit);
        layout->insertRow(13,new QLabel("ENGINE"),engineEdit);

    }

}

void AddEditItemDialog::accept() {

    if (idEdit->text().isEmpty()
        || titleEdit->text().isEmpty()
        || yearEdit->text().isEmpty()
        || languageEdit->text().isEmpty()
        || publisherEdit->text().isEmpty()
        || genreEdit->text().isEmpty()) {

        QMessageBox::warning(this,"Error","Please fill all fields");
        return;
    }

    if(typeSelector->currentText() == "Book" ){

        if (authorEdit->text().isEmpty()
            || styleEdit->text().isEmpty()
            || pagesEdit->text().isEmpty()) {

            QMessageBox::warning(this,"Error","Please fill all fields");
            return;
        }

    }

    if(typeSelector->currentText() == "Movie" ){

        if (durationEdit->text().isEmpty()
            || directorEdit->text().isEmpty()
            || castEdit->toPlainText().isEmpty()) {

            QMessageBox::warning(this,"Error","Please fill all fields");
            return;
        }

    }

    if(typeSelector->currentText() == "Game" ){

        if (platformEdit->text().isEmpty()
            || pegiEdit->text().isEmpty()
            || playersEdit->text().isEmpty()
            || developerEdit->text().isEmpty()
            || engineEdit->text().isEmpty()) {

            QMessageBox::warning(this,"Error","Please fill all fields");
            return;
        }

    }

    QDialog::accept();

}

void AddEditItemDialog::clearUi() {

    while(layout->rowCount()>11){

        layout->removeRow(9);

    }

}

QComboBox* AddEditItemDialog::GetTypeSelector(){

    return typeSelector;

}

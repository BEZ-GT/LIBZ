#ifndef ADDEDITITEMDIALOG_H
#define ADDEDITITEMDIALOG_H

#include <QFormLayout>
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QFileDialog>
#include <QTextEdit>
#include <QSpinBox>
#include "Item.h"

class AddEditItemDialog : public QDialog
{
    Q_OBJECT

private:

    QFormLayout* layout;

    QComboBox* typeSelector;
    QLineEdit* idEdit;
    QLineEdit* titleEdit;
    QPushButton* selectArtButton;
    QLineEdit* artworkpathEdit;
    QLineEdit* yearEdit;
    QLineEdit* languageEdit;
    QLineEdit* publisherEdit;
    QLineEdit* genreEdit;

    QLineEdit* authorEdit;
    QLineEdit* styleEdit;
    QSpinBox* pagesEdit;

    QSpinBox* durationEdit;
    QLineEdit* directorEdit;
    QTextEdit* castEdit;

    QLineEdit* platformEdit;
    QLineEdit* pegiEdit;
    QSpinBox* playersEdit;
    QLineEdit* developerEdit;
    QLineEdit* engineEdit;

    void clearUi();
    void setupExtraUi(const QString& text);

public:

    explicit AddEditItemDialog(QWidget *parent = nullptr);
    virtual ~AddEditItemDialog()= default;

    QString getType() const;
    QString getID() const;
    QString getArtworkPath() const;
    QString getTitle() const;
    QString getYear() const;
    QString getLanguage() const;
    QString getPublisher() const;
    QString getGenre() const;

    QString getAuthor() const;
    QString getStyle() const;
    int getPages() const;

    int getDuration() const;
    QString getDirector() const;
    QStringList getCast() const;

    QString getPlatform() const;
    QString getPegi() const;
    int getPlayers() const;
    QString getDeveloper() const;
    QString getEngine() const;

    void setType(QString type);
    void setID(QString id);
    void setArtworkPath(QString art_path);
    void setTitle(QString title);
    void setYear(QString year);
    void setLanguage(QString language);
    void setPublisher(QString publisher);
    void setGenre(QString genre);

    void setAuthor(QString author);
    void setStyle(QString style);
    void setPages(int pages);

    void setDuration(int duration);
    void setDirector(QString director);
    void setCast(QStringList cast);

    void setPlatform(QString platform);
    void setPegi(QString pegi);
    void setPlayers(int players);
    void setDeveloper(QString developer);
    void setEngine(QString engine);

    QComboBox* GetTypeSelector();

private slots:

    void accept() override;
};

#endif // ADDEDITITEMDIALOG_H

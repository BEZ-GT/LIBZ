#ifndef STARTUP_H
#define STARTUP_H

#include <QWidget>
#include <QPushButton>

class StartUp : public QWidget
{
    Q_OBJECT

private:

    QPushButton* newbutton;
    QPushButton* loadbutton;

public:

    explicit StartUp(QWidget *parent = nullptr);
    virtual ~StartUp()= default;

    QPushButton* GetNewButton();
    QPushButton* GetLoadButton();

signals:
};

#endif // STARTUP_H

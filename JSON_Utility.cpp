#include "JSON_Utility.h"
#include "Book.h"
#include "Movie.h"
#include "Game.h"
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>


namespace JSON_Utility {

bool saveItems(const Library& lib,const QString &filePath) {

    QFile out(filePath);

    if(!out.open(QIODevice::WriteOnly)) return false;

    QJsonArray jsonArr;

    for(int i=0;i<lib.Size();i++) {

        jsonArr.append(lib[i]->ItemToJson());

    }

    QJsonDocument doc(jsonArr);

    out.write(doc.toJson());
    out.close();

    return true;
}

bool loadItems(Library& lib,const QString &filePath) {

    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QByteArray res = file.readAll();
    file.close();

    QJsonDocument data = QJsonDocument::fromJson(res);

    QJsonArray jsonArr = data.array();

    for(int i = 0;i<jsonArr.size();i++) {

        QJsonObject obj = jsonArr[i].toObject();

        lib.AddItem(JSON_Utility::FromJson(obj));

    }

    return true;
}

Item* FromJson(const QJsonObject& obj) {

    Item* item = nullptr;

    if(obj["Type"] == "Book") {

        item = new Book("Book",
                        obj["ID"].toString(),
                        obj["ArtworkPath"].toString(),
                        obj["Title"].toString(),
                        obj["Year"].toString(),
                        obj["Language"].toString(),
                        obj["Publisher"].toString(),
                        obj["Genre"].toString(),

                        obj["Author"].toString(),
                        obj["Style"].toString(),
                        obj["Pages"].toInt()
                        );

    }

    if(obj["Type"] == "Movie") {

        item = new Movie("Movie",
                         obj["ID"].toString(),
                         obj["ArtworkPath"].toString(),
                         obj["Title"].toString(),
                         obj["Year"].toString(),
                         obj["Language"].toString(),
                         obj["Publisher"].toString(),
                         obj["Genre"].toString(),

                         obj["Duration"].toInt(),
                         obj["Director"].toString(),
                         obj["Cast"].toVariant().toStringList()

                         );

    }

    if(obj["Type"] == "Game") {

        item = new Game("Game",
                        obj["ID"].toString(),
                        obj["ArtworkPath"].toString(),
                        obj["Title"].toString(),
                        obj["Year"].toString(),
                        obj["Language"].toString(),
                        obj["Publisher"].toString(),
                        obj["Genre"].toString(),

                        obj["Platform"].toString(),
                        obj["Pegi"].toString(),
                        obj["Players"].toInt(),
                        obj["Developer"].toString(),
                        obj["Engine"].toString()
                        );

    }

    return item;

}

}

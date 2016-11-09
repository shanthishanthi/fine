#include "addressbookcontroller.h"
#include "sqlitedatasource.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SQLiteDataSource dSrc("cont.db", true);
    AddressBookController myBook(dSrc);
    app.setStyleSheet("QMainWindow{background-image:url(E:/gitfolder/Tulips.jpg)}");
    myBook.start();
    return app.exec();
}


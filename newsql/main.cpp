//#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection()){

        qDebug() << "Not connected!";
        return 1;
    }
    else{

        qDebug() << "Connected!";

        QSqlQuery query;
        query.exec("SELECT * FROM cont");

        while (query.next()) {
            QString firstname = query.value(1).toString();
            QString lastname = query.value(2).toString();
            QString phonenum = query.value(1).toString();
            QString  address = query.value(1).toString();
            QString city = query.value(1).toString();
            qDebug() << "first name:" << firstname;
            qDebug() << "last name:" << lastname;
            qDebug() << "phone number:" << phonenum;
            qDebug() << "address" << address;
            qDebug() << "city" << city;
        }

        return 0;
    }

    return app.exec();
}

bool createConnection(){
   QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
 //QSqlDatabase db = QSqlDatabase::addDatabase("addbook");
    db.setHostName("localhost");
    db.setDatabaseName("addbook");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open()) {
        qDebug() << "Database error occurred";
        return false;
    }
    return true;
}



#include "addpackage.h"
#include "ui_addpackage.h"
#include "databaseheader.h"

AddPackage::AddPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPackage)
{
    ui->setupUi(this);
}

AddPackage::~AddPackage()
{
    delete ui;
}

void AddPackage::on_btnSave_clicked()
{
    QString packageName = ui->txtPackageName->text();
    QString packageDescriptiuon = ui->txtDescription->toPlainText();
    QString Amount = ui->txtAmount->text();
    qDebug() << "PackageName " << packageName << "Package Description " << packageDescriptiuon << "Amount " << Amount;
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/QtConsoleApp/testgui/database/MyTouristManger.db");
    if(QFile::exists("D:/QtConsoleApp/testgui/database/MyTouristManger.db"))
        qDebug() << "Database is exists ";
    else
     {
           qDebug() << "Database file is not exist ";
           return;
    }
    if(!database.open()){
        qDebug() << "Can not open database file";
        return;
    }else{
         qDebug() << "Database opened ...";
         QSqlQuery query;
         query = QSqlQuery(database);
         query.prepare("insert into Package (PackageName, PackageDescription, Amount) values (:packageName, :packageDescription, :Amount)");
         query.bindValue(":packageName", packageName);
         query.bindValue(":packageDescription", packageDescriptiuon);
         query.bindValue(":Amount", Amount);

         if(query.exec()){

             qDebug() << "Query executed successfully ...";
         } // end if
         else{
             query.lastError();
         }
    }
///
/// closing database
///
database.close();


}


#include "findpackage.h"
#include "ui_findpackage.h"
#include "databaseheader.h"
#include <QSqlRecord>
#include <memory>
FindPackage::FindPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPackage)
{
    ui->setupUi(this);
}

FindPackage::~FindPackage()
{
    delete model;
    delete ui;
}

void FindPackage::on_btnFindPackage_clicked()
{

    QString packageName = ui->txtPackageName->text();
    qDebug() << "PackageName " << packageName ;
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

         if(packageName.isEmpty()){
              query.prepare("select * from  Package");
         }else{
             query.prepare("select * from  Package where packageName = (:packageName)");
             query.bindValue(":packageName", packageName);
         }

         if(query.exec()){
            model->setQuery(query);
            ui->tableView->setModel(model);
             qDebug() << "Query executed successfully ...";


         } // end if

    }
///
/// closing database
/// and deletion of model
///
database.close();

}


#include "findtourist.h"
#include "ui_findtourist.h"
FindTourist::FindTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindTourist)
{
    ui->setupUi(this);
}

FindTourist::~FindTourist()
{
    delete ui;
}

void FindTourist::on_btnFind_clicked()
{

    QString touristName = ui->txtTouristName->text();
    qDebug() << "tourist name: " << touristName ;
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

         if(touristName.isEmpty()){
              query.prepare("select * from  Tourist");
         }else{
             query.prepare("select * from  Tourist  where FirstName = (:touristName)");
             query.bindValue(":touristName", touristName);
         }

         if(query.exec()){
            model->setQuery(query);
            ui->tableView->setModel(model);
             qDebug() << "Query executed successfully ...";


         } // end if

    }
}


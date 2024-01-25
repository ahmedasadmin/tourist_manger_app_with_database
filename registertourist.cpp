#include "registertourist.h"
#include "ui_registertourist.h"

RegisterTourist::RegisterTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterTourist)
{
    ui->setupUi(this);
}

RegisterTourist::~RegisterTourist()
{
    delete ui;
}

void RegisterTourist::on_btnSave_clicked()
{
    QString firstName = ui->txtFirstName->text();
    QString middleName = ui->txtMiddleName_2->text();
    QString lastName = ui->txtLastName->text();
    QString passportNo = ui->txtPassportNo->text();
    QString contactNo = ui->txtContactNo->text();
    QString permenantAddress = ui->txtPermenantAddress->text();


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
         query.prepare("insert into Tourist (FirstName, MiddleName, LastName, PassportNo, ContactNo, PermenantAddress) "
                       "values (:firstName, :middleName, :lastName, :passportNo, :contactNo, :permenantAddress)");
         query.bindValue(":firstName", firstName );
         query.bindValue(":middleName", middleName);
         query.bindValue(":lastName", lastName);
         query.bindValue(":passportNo", passportNo);
         query.bindValue(":contactNo", contactNo);
         query.bindValue(":permenantAddress", permenantAddress  );


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


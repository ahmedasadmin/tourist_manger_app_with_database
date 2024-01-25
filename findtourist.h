#ifndef FindTourist_H
#define FindTourist_H

#include <QDialog>
#include "databaseheader.h"
namespace Ui {
class FindTourist;
}

class FindTourist : public QDialog
{
    Q_OBJECT

public:
    explicit FindTourist(QWidget *parent = nullptr);
    ~FindTourist();

private slots:
    void on_btnFind_clicked();

private:
    Ui::FindTourist *ui;
     QSqlQueryModel* model = new QSqlQueryModel;
};

#endif // FindTourist_H

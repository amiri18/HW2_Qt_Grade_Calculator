#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H
#include <QString>

#include <QMainWindow>

namespace Ui {
// PIC Grade Calculator:
class grade_calculator;
}

class grade_calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit grade_calculator(QWidget *parent = 0);
    ~grade_calculator();

public slots:
   // if the user wants to use grade scheme A
   void on_SchemaA_clicked();

   // if the user wants to use grade shceme B
   void on_SchemaB_clicked();

   // changes labels according to the scheme selected
   void on_comboBox_activated(const QString &arg);

private:
    Ui::grade_calculator *ui;
};

#endif // GRADE_CALCULATOR_H

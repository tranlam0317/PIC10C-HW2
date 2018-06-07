#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>
#include <QtGui>
#include <vector>

namespace Ui {
class grade_calculator;
}

class grade_calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit grade_calculator(QWidget *parent = 0); //Constructor
    ~grade_calculator(); //Destructor
    double compute_homework(int,int,int,int,int,int,int,int);

signals:

public slots:
    void update_overall();

private slots:

    void on_checkBoxA_stateChanged(int arg1);
    void on_checkBoxB_stateChanged(int arg1);

private:
    Ui::grade_calculator *ui;
};

#endif // GRADE_CALCULATOR_H

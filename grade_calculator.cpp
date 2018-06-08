#include "grade_calculator.h"
#include "ui_grade_calculator.h"
#include <iostream>
#include <QtGui>
using namespace  std;

//Default Constructor
grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);

    //Connections
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(update_overall()));
    QObject::connect(ui->checkBoxA, SIGNAL(stateChanged(int)), this, SLOT(on_checkBoxA_stateChanged(int)));
    QObject::connect(ui->checkBoxB, SIGNAL(stateChanged(int)), this, SLOT(on_checkBoxB_stateChanged(int)));

}

//Destructor
grade_calculator::~grade_calculator()
{
    delete ui;
}

double grade_calculator::compute_homework(int h1,int h2,int h3,int h4,int h5,int h6,int h7,int h8) {
    double homeworktotalscore = 0.0;

    vector<int> v = {h1,h2,h3,h4,h5,h6,h7,h8};
    sort(v.begin(), v.end());

    for (int i = 1; i < 8; i ++)
        homeworktotalscore += v[i];

    homeworktotalscore/=7;

    return homeworktotalscore;
}


void grade_calculator::update_overall(){

    int midterm;
    int finalscore;

    int hw1 = ui->doubleSpinBox->value();
    int hw2 = ui->doubleSpinBox_2->value();
    int hw3 = ui->doubleSpinBox_3->value();
    int hw4 = ui->doubleSpinBox_4->value();
    int hw5 = ui->doubleSpinBox_5->value();
    int hw6 = ui->doubleSpinBox_6->value();
    int hw7 = ui->doubleSpinBox_7->value();
    int hw8 = ui->doubleSpinBox_8->value();

    int homeworktotal = compute_homework(hw1, hw2, hw3, hw4, hw5, hw6, hw7, hw8);

    int midterm1 = ui->doubleSpinBox_9->value();
    int midterm2 = ui->doubleSpinBox_10->value();
    int finalexam = ui->doubleSpinBox_11->value();

    //Highest midterm
    if (midterm1 > midterm2){
        midterm = midterm1;
    }
    else{ // (midterm1 < midterm2)
        midterm = midterm2;
    }

    //Grading Scheme
    if (ui->checkBoxA->isChecked() == true){
        finalscore = (homeworktotal * .25) + (midterm1 * .20) + (midterm2 * .20) + (finalexam * .35);
        ui->OverallScoreLabel->setText(QString::number(finalscore));
    }

    else if (ui->checkBoxB->isChecked() == true){
        finalscore = (homeworktotal *.25) + (midterm * .30) + (finalexam * .44);
        ui->OverallScoreLabel->setText(QString::number(finalscore));
    }

    else{ //no box is checked
        ui->OverallScoreLabel->setText(("Must choose a Grading Scheme!"));
    }

}

//Disabling of check box if the other is clicked
void grade_calculator::on_checkBoxA_stateChanged(int arg1)
{
    ui->checkBoxB->setDisabled(arg1);
}

void grade_calculator::on_checkBoxB_stateChanged(int arg1)
{
    ui->checkBoxA->setDisabled(arg1);
}

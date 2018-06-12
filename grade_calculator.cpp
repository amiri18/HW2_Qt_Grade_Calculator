#include "grade_calculator.h"
#include "ui_grade_calculator.h"
#include <iostream>
#include <QString>
#include <QCoreApplication>
#include <QList>
#include <vector>

using namespace std;

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);

    // set the homework labels, midterms, final, and score labels:
    ui->label->setText("Hw 1");
    ui->label_2->setText("Hw 2");
    ui->label_3->setText("Hw 3");
    ui->label_4->setText("Hw 4");
    ui->label_5->setText("Hw 5");
    ui->label_6->setText("Hw 6");
    ui->label_7->setText("Hw 7");
    ui->label_8->setText("Hw 8");
    ui->label_9->setText("Course: ");
    ui->label_10->setText("Midterm 1");
    ui->label_11->setText("Midterm 2");
    ui->label_12->setText("Final Exam");
    ui->label_13->setText("Overall Score:     ");
    ui->label_14->setText("0.0");

    // set course labels:
    ui->comboBox->addItem("Pic 10B: Intermediate Programming.");
    ui->comboBox->addItem("Pic 10C: Advanced Programming");

    // set scheme labels:
    ui->SchemaA->setText("Schema A");
    ui->SchemaB->setText("Schema B");

    // set up numerical range for the spinBoxes/horizontalSliders:
    ui->spinBox->setRange(0, 20);
    ui->horizontalSlider->setRange(0, 20);

    ui->spinBox_2->setRange(0, 20);
    ui->horizontalSlider_2->setRange(0 ,20);

    ui->spinBox_3->setRange(0, 20);
    ui->horizontalSlider_3->setRange(0, 20);

    ui->spinBox_4->setRange(0, 20);
    ui->horizontalSlider_4->setRange(0, 20);

    ui->spinBox_5->setRange(0, 20);
    ui->horizontalSlider_5->setRange(0, 20);

    ui->spinBox_6->setRange(0 ,20);
    ui->horizontalSlider_6->setRange(0, 20);

    ui->spinBox_7->setRange(0, 20);
    ui->horizontalSlider_7->setRange(0, 20);

    ui->spinBox_8->setRange(0, 20);
    ui->horizontalSlider_8->setRange(0 ,20);

    ui->spinBox_9->setRange(0 ,100);
    ui->horizontalSlider_9->setRange(0, 100);

    ui->spinBox_10->setRange(0, 100);
    ui->horizontalSlider_10->setRange(0, 100);

    ui->spinBox_11->setRange(0, 100);
    ui->horizontalSlider_11->setRange(0 ,100);

    // connect the spinBoxes and horizontalSliders:
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));

    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_2, SLOT(setValue(int)));

    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->spinBox_3, SLOT(setValue(int)));
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->horizontalSlider_3, SLOT(setValue(int)));

    connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)), ui->spinBox_4, SLOT(setValue(int)));
    connect(ui->spinBox_4, SIGNAL(valueChanged(int)), ui->horizontalSlider_4, SLOT(setValue(int)));

    connect(ui->horizontalSlider_5, SIGNAL(valueChanged(int)), ui->spinBox_5, SLOT(setValue(int)));
    connect(ui->spinBox_5, SIGNAL(valueChanged(int)), ui->horizontalSlider_5, SLOT(setValue(int)));

    connect(ui->horizontalSlider_6, SIGNAL(valueChanged(int)), ui->spinBox_6, SLOT(setValue(int)));
    connect(ui->spinBox_6, SIGNAL(valueChanged(int)), ui->horizontalSlider_6, SLOT(setValue(int)));

    connect(ui->horizontalSlider_7, SIGNAL(valueChanged(int)), ui->spinBox_7, SLOT(setValue(int)));
    connect(ui->spinBox_7, SIGNAL(valueChanged(int)), ui->horizontalSlider_7, SLOT(setValue(int)));

    connect(ui->horizontalSlider_8, SIGNAL(valueChanged(int)), ui->spinBox_8, SLOT(setValue(int)));
    connect(ui->spinBox_8, SIGNAL(valueChanged(int)), ui->horizontalSlider_8, SLOT(setValue(int)));

    connect(ui->horizontalSlider_9, SIGNAL(valueChanged(int)), ui->spinBox_9, SLOT(setValue(int)));
    connect(ui->spinBox_9, SIGNAL(valueChanged(int)), ui->horizontalSlider_9, SLOT(setValue(int)));

    connect(ui->horizontalSlider_10, SIGNAL(valueChanged(int)), ui->spinBox_10, SLOT(setValue(int)));
    connect(ui->spinBox_10, SIGNAL(valueChanged(int)), ui->horizontalSlider_10, SLOT(setValue(int)));

    connect(ui->horizontalSlider_11, SIGNAL(valueChanged(int)), ui->spinBox_11, SLOT(setValue(int)));
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), ui->horizontalSlider_11, SLOT(setValue(int)));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

// Grading Scheme A:
void grade_calculator::on_SchemaA_clicked() {
    // store the homework scores in an std::vector
    vector<size_t> vec;
    vec.push_back(ui->spinBox->value());
    vec.push_back(ui->spinBox_2->value());
    vec.push_back(ui->spinBox_3->value());
    vec.push_back(ui->spinBox_4->value());
    vec.push_back(ui->spinBox_5->value());
    vec.push_back(ui->spinBox_6->value());
    vec.push_back(ui->spinBox_7->value());
    vec.push_back(ui->spinBox_8->value());
    // sort the scores
    sort(vec.begin(), vec.end());
    // drop the lowest one
    vec.erase(vec.begin());

    // add up the scores to get the total
    double totalHWscore = 0;
    for (size_t i = 0; i < vec.size(); ++i){
        totalHWscore = totalHWscore + vec[i];
    }

    // if the student is in PIC10B:
    if (ui->comboBox->currentText() == "Pic 10B: Intermediate Programming."){
        // calculate the homework, midterm, and final scores
        double hwPercentage = ((totalHWscore/140)*100)*0.25;
        double Midterm1Score = (ui->spinBox_9->value())*0.2;
        double Midterm2Score = (ui->spinBox_10->value())*0.2;
        double FinalScore = (ui->spinBox_11->value())*0.35;

        // calculator the overall grade
        double grade = hwPercentage + Midterm1Score + Midterm2Score + FinalScore;
        // display the grade
        ui->label_14->setNum(grade);
    }

    // if the student is in PIC10C:
    if (ui->comboBox->currentText() == "Pic 10C: Advanced Programming") {
        // calculate the homework, midterm, final, and final project scores
        double hwPercentage = ((totalHWscore/140)*100)*0.15;
        double MidtermScore = (ui->spinBox_9->value())*0.25;
        double FinalScore = (ui->spinBox_10->value())*0.3;
        double FinalProject = (ui->spinBox_11->value())*0.35;

        // calculate the overall grade
        double grade = hwPercentage + MidtermScore + FinalScore + FinalProject;
        // display the grade
        ui->label_14->setNum(grade);
    }
}

// Grading Scheme B:
void grade_calculator::on_SchemaB_clicked(){
    // store the homework scores in an std::vector
    vector<size_t> vec;
    vec.push_back(ui->spinBox->value());
    vec.push_back(ui->spinBox_2->value());
    vec.push_back(ui->spinBox_3->value());
    vec.push_back(ui->spinBox_4->value());
    vec.push_back(ui->spinBox_5->value());
    vec.push_back(ui->spinBox_6->value());
    vec.push_back(ui->spinBox_7->value());
    vec.push_back(ui->spinBox_8->value());
    // sort the scores
    sort(vec.begin(), vec.end());
    // drop the lowest one
    vec.erase(vec.begin());

    // add up the scores to get the total
    double totalHWscore = 0;
    for (size_t i = 0; i < vec.size(); ++i){
        totalHWscore = totalHWscore + vec[i];
    }

    // if the student is in PIC10B:
     if (ui->comboBox->currentText() == "Pic 10B: Intermediate Programming."){
         // calculate the homework score
         double hwPercentage = ((totalHWscore/140)*100)*0.25;
         // choose the highest midterm
         double higherMidterm = 0;
         if (ui->spinBox_9->value() > ui->spinBox_10->value()){
             higherMidterm = (ui->spinBox_9->value())*0.3;
         }
         else {
             higherMidterm = (ui->spinBox_10->value())*0.3;
         }
         // calculate the final score
         double FinalScore = (ui->spinBox_11->value())*0.45;

         // calculate the overall grade
         double grade = hwPercentage + higherMidterm + FinalScore;
         // display the grade
         ui->label_14->setNum(grade);
     }
     // if the student is in PIC10C:
     if (ui->comboBox->currentText() == "Pic 10C: Advanced Programming"){
         // calculate the homework, final, and final project score (the midterm is dropped)
         double hwPercentage = ((totalHWscore/140)*100)*0.15;
         double FinalScore = (ui->spinBox_10->value())*0.5;
         double FinalProject = (ui->spinBox_11->value())*0.35;

         // calculate the overall score
         double grade = hwPercentage + FinalProject + FinalScore;
         // display the grade
         ui->label_14->setNum(grade);
     }
}

// adjusting comboBox labels according to class
 void grade_calculator::on_comboBox_activated(const QString &arg) {
     if (arg == "Pic 10C: Advanced Programming"){
         ui->label_11->setText("Final Exam");
         ui->label_12->setText("Final Project");
     }
     if (arg == "Pic 10B: Intermediate Programming."){
         ui->label_11->setText("Midterm 2");
         ui->label_12->setText("Final Exam");
     }
 }


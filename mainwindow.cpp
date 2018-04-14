#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <GL/glu.h>

const static int FONT_SIZE = 24;
const static QString FONT = "メイリオ";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txtResult->setFont(QFont(FONT, 30));
    ui->txtMark->setFont(QFont(FONT, 20));
    ui->pushButton_0->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_1->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_2->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_3->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_4->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_5->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_6->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_7->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_8->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_9->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_plus->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_minus->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_mul->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_div->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_equal->setFont(QFont(FONT, FONT_SIZE));
    ui->pushButton_C->setFont(QFont(FONT, FONT_SIZE));
    setWindowTitle("Qt計算機");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClickNumber(QString str){
    mInputing += str;
    ui->txtResult->setText( mInputing );
}

void MainWindow::on_pushButton_0_clicked(){
    onClickNumber("0");
}
void MainWindow::on_pushButton_1_clicked(){
    onClickNumber("1");
}
void MainWindow::on_pushButton_2_clicked(){
    onClickNumber("2");
}
void MainWindow::on_pushButton_3_clicked(){
    onClickNumber("3");
}
void MainWindow::on_pushButton_4_clicked(){
    onClickNumber("4");
}
void MainWindow::on_pushButton_5_clicked(){
    onClickNumber("5");
}
void MainWindow::on_pushButton_6_clicked(){
    onClickNumber("6");
}
void MainWindow::on_pushButton_7_clicked(){
    onClickNumber("7");
}
void MainWindow::on_pushButton_8_clicked(){
    onClickNumber("8");
}
void MainWindow::on_pushButton_9_clicked(){
    onClickNumber("9");
}
void MainWindow::on_pushButton_plus_clicked(){
    calc();
    ui->txtMark->setText("+");
    mMark = eMark::ePlus;
}
void MainWindow::on_pushButton_minus_clicked(){
    calc();
    ui->txtMark->setText("-");
    mMark = eMark::eMinus;
}
void MainWindow::on_pushButton_mul_clicked(){
    calc();
    ui->txtMark->setText("×");
    mMark = eMark::eMul;
}
void MainWindow::on_pushButton_div_clicked(){
    calc();
    ui->txtMark->setText("÷");
    mMark = eMark::eDiv;
}
void MainWindow::on_pushButton_equal_clicked(){
    calc();
    if(mInputed.size()>0 && mMark!=eMark::eNone){
        ui->txtResult->setText(mInputed);
        ui->txtMark->setText("");
        mFormula += "＝";
        mFormula += mInputed;
        ui->listWidget->addItem(new QListWidgetItem(mFormula));
    }
    mInputing = "";
    mInputed = "";
    mFormula = "";
    mMark = eMark::eNone;
}
void MainWindow::on_pushButton_C_clicked(){
    mInputing = "";
    mInputed = "";
    mFormula = "";
    mMark = eMark::eNone;
    ui->txtResult->setText("");
    ui->txtMark->setText("");
}

void MainWindow::calc(){
    if(mMark!=eMark::eNone){
        if(mInputing.size()>0){
            int inputed = mInputed.toInt();
            int inputing = mInputing.toInt();
            switch(mMark){
            case ePlus:
                mInputed = QString::number(inputed+inputing);
                mFormula += "＋";
                break;
            case eMinus:
                mInputed = QString::number(inputed-inputing);
                mFormula += "－";
                break;
            case eMul:
                mInputed = QString::number(inputed*inputing);
                mFormula += "×";
                break;
            case eDiv:
                mInputed = QString::number(inputed/inputing);
                mFormula += "÷";
                break;
            }
            mFormula += mInputing;
        }
        mInputing = "";
    } else {
        if(mInputing.size()==0){
            mInputing = "0";
        }
        mInputed = mInputing;
        mFormula += mInputing;
        mInputing = "";
    }
    ui->txtResult->setText(mInputed);
}

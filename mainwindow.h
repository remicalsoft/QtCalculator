#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

enum eMark {
    ePlus,
    eMinus,
    eMul,
    eDiv,
    eNone,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_plus_clicked();

    void onClickNumber(QString num);

    void calc();

private:
    Ui::MainWindow *ui;
    QString mInputing;
    QString mInputed;
    QString mFormula;
    eMark mMark = eMark::eNone;
};

#endif // MAINWINDOW_H

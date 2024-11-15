#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <limits>

#include "../Controller/calculator_controller.h"
#include "../qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void check_zero(const QString text);

  void on_pushButton_seven_clicked();

  void on_pushButton_four_clicked();

  void on_pushButton_zero_clicked();

  void on_pushButton_one_clicked();

  void on_pushButton_two_clicked();

  void on_pushButton_three_clicked();

  void on_pushButton_five_clicked();

  void on_pushButton_six_clicked();

  void on_pushButton_eight_clicked();

  void on_pushButton_nine_clicked();

  void on_pushButton_dot_clicked();

  void on_pushButton_division_clicked();

  void on_pushButton_multiply_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_sqrt_clicked();

  void on_pushButton_pow_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_X_clicked();

  void on_pushButton_leftbracket_clicked();

  void on_pushButton_AC_clicked();

  void on_pushButton_rightbracket_clicked();

  void on_pushButton_equally_clicked();

  void on_pushButton_graphic_clicked();

 private:
  Ui::MainWindow *ui;
  double X;
  QVector<double> x, y;
};
#endif  // MAINWINDOW_H

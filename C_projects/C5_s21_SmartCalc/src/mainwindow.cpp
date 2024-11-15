#include "mainwindow.h"

#include <QString>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->x_max->setText("10");
  ui->x_min->setText("-10");
  ui->y_max->setText("10");
  ui->y_min->setText("-10");
  ui->x_value->setText("0");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::check_zero(const QString text) {
  if (text == "0") ui->input_string->setText("");
  if (text == "Input error!" || text == "Graphic values error!")
    ui->input_string->setText("");
}

void MainWindow::on_pushButton_zero_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "0");
}

void MainWindow::on_pushButton_one_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "1");
}

void MainWindow::on_pushButton_two_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "2");
}

void MainWindow::on_pushButton_three_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "3");
}

void MainWindow::on_pushButton_four_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "4");
}

void MainWindow::on_pushButton_five_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "5");
}

void MainWindow::on_pushButton_six_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "6");
}

void MainWindow::on_pushButton_seven_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "7");
}

void MainWindow::on_pushButton_eight_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "8");
}

void MainWindow::on_pushButton_nine_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "9");
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->input_string->setText(ui->input_string->text() + ".");
}

void MainWindow::on_pushButton_division_clicked() {
  ui->input_string->setText(ui->input_string->text() + "/");
}

void MainWindow::on_pushButton_multiply_clicked() {
  ui->input_string->setText(ui->input_string->text() + "*");
}

void MainWindow::on_pushButton_minus_clicked() {
  ui->input_string->setText(ui->input_string->text() + "-");
}

void MainWindow::on_pushButton_plus_clicked() {
  ui->input_string->setText(ui->input_string->text() + "+");
}

void MainWindow::on_pushButton_cos_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "cos(");
}

void MainWindow::on_pushButton_sin_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "sin(");
}

void MainWindow::on_pushButton_tan_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "tan(");
}

void MainWindow::on_pushButton_acos_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "acos(");
}

void MainWindow::on_pushButton_asin_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "asin(");
}

void MainWindow::on_pushButton_atan_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "atan(");
}

void MainWindow::on_pushButton_log_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "log(");
}

void MainWindow::on_pushButton_ln_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "ln(");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "sqrt(");
}

void MainWindow::on_pushButton_pow_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "^");
}

void MainWindow::on_pushButton_mod_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "mod");
}

void MainWindow::on_pushButton_X_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "x");
}

void MainWindow::on_pushButton_leftbracket_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + "(");
}

void MainWindow::on_pushButton_AC_clicked() { ui->input_string->setText("0"); }

void MainWindow::on_pushButton_rightbracket_clicked() {
  check_zero(ui->input_string->text());
  ui->input_string->setText(ui->input_string->text() + ")");
}

void MainWindow::on_pushButton_equally_clicked() {
  QByteArray tmp = ui->input_string->text().toLocal8Bit();
  char *src = tmp.data();
  double result = 0;

  int error = 0;
  QString x_val = ui->x_value->text();
  double x = x_val.toDouble();
  error = main_calc(src, x, &result);
  if (error) {
    ui->input_string->setText("Input error!");
  } else {
    QString res_val = QString::number((double)result);
    ui->input_string->setText(res_val);
  }
}

void MainWindow::on_pushButton_graphic_clicked() {
  ui->widget->clearGraphs();

  QString xMa = ui->x_max->text();
  double xMax = xMa.toDouble();

  QString xMi = ui->x_min->text();
  double xMin = xMi.toDouble();

  QString yMa = ui->y_max->text();
  double yMax = yMa.toDouble();

  QString yMi = ui->y_min->text();
  double yMin = yMi.toDouble();

  if (!graphic_valid(xMin, xMax, yMin, yMax)) {
    double step = (xMax - xMin) / 200;
    QString step_val = QString::number(step);
    ui->label->setText(step_val);
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);
    QByteArray tmp = ui->input_string->text().toLocal8Bit();
    char *expression = tmp.data();
    double result = 0;
    if (!main_calc(expression, 0, &result)) {
      for (X = xMin; X <= xMax; X += step) {
        x.push_back(X);
        main_calc(expression, X, &result);
        y.push_back(result);
      }
      ui->widget->addGraph();
      ui->widget->graph(0)->addData(x, y);
      ui->widget->replot();
      x.clear();
      y.clear();
    } else {
      ui->input_string->setText("Input error!");
    }
  } else {
    ui->input_string->setText("Graphic values error!");
  }
}

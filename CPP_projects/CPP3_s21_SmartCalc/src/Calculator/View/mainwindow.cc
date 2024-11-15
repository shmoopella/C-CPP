#include "mainwindow.h"

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
  std::string str = ui->input_string->text().toStdString();
  std::string x = ui->x_value->text().toStdString();
  s21::CalculatorController contr(str);
  QString output(contr.GetRes(x).c_str());
  ui->input_string->setText(output);
}

void MainWindow::on_pushButton_graphic_clicked() {
  ui->widget->clearGraphs();
  double xMax = ui->x_max->text().toDouble();
  double xMin = ui->x_min->text().toDouble();
  double yMax = ui->y_max->text().toDouble();
  double yMin = ui->y_min->text().toDouble();

  std::string str = ui->input_string->text().toStdString();
  s21::CalculatorController contr(str);

  if (contr.GraficValid(xMin, xMax, yMin, yMax)) {
    ui->input_string->setText("Graphic values error!");
  } else {
    double step = (xMax - xMin) / 200;
    ui->label->setText(QString::number(step));
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);
    if (contr.ExpressionValid()) {
      ui->input_string->setText("Input error!");
    } else {
      for (double Y, X = xMin; X <= xMax; X += step) {
        if (fabs(X) < 0.000000001) {
          X = 0.0;
        }
        Y = contr.GetDoubleRes(X);
        if (std::isnan(Y) || std::isinf(Y) || Y > yMax || Y < yMin) {
          x.push_back(X);
          y.push_back(std::numeric_limits<double>::quiet_NaN());
        } else {
          x.push_back(X);
          y.push_back(Y);
        }
      }
      ui->widget->addGraph();
      ui->widget->graph(0)->addData(x, y);
      ui->widget->replot();
      x.clear();
      y.clear();
    }
  }
}

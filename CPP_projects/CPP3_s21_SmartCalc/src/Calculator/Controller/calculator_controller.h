#include "../Model/calculator_model.h"

namespace s21 {
class CalculatorController {
 public:
  CalculatorController(std::string input_str) : string(input_str){};

  std::string GetRes(std::string x_string) {
    double x_val = 0;
    std::string result;
    double calc_res = 0;
    try {
      Model.StrValidation(this->string);
      Model.XStringValidation(x_string);
      x_val = std::strtod(x_string.c_str(), nullptr);
      calc_res = Model.GetResult(this->string, x_val);
      result = std::to_string(calc_res);
    } catch (const std::exception &e) {
      result = e.what();
      return result;
    }
    return result;
  }

  int GraficValid(double xMin, double xMax, double yMin, double yMax) {
    int error = 1;
    try {
      Model.GraphicValid(xMin, xMax, yMin, yMax);
      return 0;
    } catch (const std::exception &e) {
      return error;
    }
  }

  double GetDoubleRes(double x) { return Model.GetResult(this->string, x); }

  int ExpressionValid() {
    int error = 1;
    try {
      Model.StrValidation(this->string);
      return 0;
    } catch (const std::exception &e) {
      return error;
    }
  }

 private:
  std::string string;
  s21::CalculatorModel Model;
};
}  // namespace s21

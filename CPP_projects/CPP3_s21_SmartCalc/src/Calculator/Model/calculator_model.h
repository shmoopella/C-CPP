#include <cmath>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>

namespace s21 {
enum lexeme_type {
  t_sin,
  t_sqrt,
  t_acos,
  t_asin,
  t_atan,
  t_ln,
  t_log,
  t_tan = 't',
  t_cos = 'c',
  t_x = 'x',
  t_open_bracket = '(',
  t_close_braket = ')',
  t_plus = '+',
  t_minus = '-',
  t_mul = '*',
  t_div = '/',
  t_mod = 'm',
  t_pow = '^',
  t_number
};

typedef struct lex {
  double value;
  int priority;
  enum lexeme_type type;
} lexeme;

class CalculatorModel {
 public:
  CalculatorModel() : res(0){};
  void StrValidation(std::string &str);
  void XStringValidation(std::string x_val);
  void GraphicValid(double xMin, double xMax, double yMin, double yMax);
  double GetResult(std::string &str, double x_value);

 private:
  double res;

  void DeleteSpaces(std::string &str);
  void LenValidation(std::string &str);
  void BracketsValidation(std::string &str);
  void PointValidation(std::string &str, std::size_t i,
                       std::size_t float_point);
  int CheckOnOperator(char symbol);
  void OperatorValidation(std::string &str, std::size_t i);
  int CheckOnNumber(char symbol);
  void NumberValidation(std::string &str, std::size_t i);
  void XValidation(std::string &str, std::size_t i);
  int ValidFunction(std::string &str, std::size_t &i);
  void MicrovalidFunction(std::string &str, std::size_t i);
  int CheckOnMod(std::string &str, std::size_t i);
  void ValidMod(std::string &str, int i);

  void MakeLexemeQue(std::string &str, double x_value, std::queue<lexeme> &que);
  std::size_t NumLen(const char *str);

  void PolishNotation(std::queue<s21::lexeme> &input_que,
                      std::queue<s21::lexeme> &output_que);
  bool IsOperator(enum lexeme_type type);
  bool IsFunction(enum lexeme_type type);

  void Calculation(std::queue<s21::lexeme> &polish_que);
};
}  // namespace s21

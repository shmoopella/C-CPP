#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#define EPS 1E-7

class S21Matrix {
 private:
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
 public:
  S21Matrix();                        // Default constructor+
  S21Matrix(int rows, int cols);      // Constructor with param+
  S21Matrix(const S21Matrix& other);  // Copy constructor
  S21Matrix(S21Matrix&& other);       // Move constructor
  ~S21Matrix();                       // Destructor+

  int Get_row() { return rows_; }
  int Get_cols() { return cols_; }
  void Set_rows(int rows);
  void Set_cols(int cols);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix MatrixForMinor(int row, int col);
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& other);
  double operator()(int i, int j);

  void FillMatrix(double num);
  void FillMatrixForDeter();
  void FillMatrixForCalc();
  void PrintMatrix();
  friend void clean_memory(S21Matrix& m);
  friend void allocate_memory(S21Matrix& m);
};

#endif  // SRC_S21_MATRIX_OOP_H_
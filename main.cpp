
#include <iostream>
#include <cmath>

class Complex {
public:
  // конструктор
  Complex(double real, double imaginary) : real_(real), imaginary_(imaginary) {}
  // методы класса
  double GetReal() { return real_; }
  double GetImaginary() { return imaginary_; }
  double Module(double real, double imaginary) {
    real_ = real;
    imaginary_ = imaginary;
    return sqrt(real_ * real_ + imaginary_ * imaginary_);
  }
  void SetReal(double real) { real_ = real; }
  void SetImaginary(double imaginary) { imaginary_ = imaginary; }
  
  friend Complex operator+(Complex z1, Complex z2);
  friend Complex operator-(Complex z1, Complex z2);
  friend Complex operator*(Complex z1, Complex z2);
  friend std::ostream& operator<<(std::ostream& out, Complex z);
  friend bool operator==(Complex z1, Complex z2);
  friend bool operator!=(Complex z1, Complex z2);
  
  ~Complex() {
    real_ = 0;
    imaginary_ = 0;
  }

private:
  double real_;
  double imaginary_;
};

// перегрузка опрераторов
Complex operator+(Complex z1, Complex z2){
  double sum_real = z1.GetReal() + z2.GetReal();
  double sum_imaginary = z1.GetImaginary() + z2.GetImaginary();
  return Complex(sum_real, sum_imaginary);
}
// -
Complex operator-(Complex z1, Complex z2){
  double diff_real = z1.GetReal() - z2.GetReal();
  double diff_imaginary = z1.GetImaginary() - z2.GetImaginary();
  return Complex(diff_real, diff_imaginary);
}
// * 
Complex operator*(Complex z1, Complex z2){
  double multi_real = z1.GetReal() * z2.GetReal() -  z1.GetImaginary() * z2.GetImaginary();
  double multi_imaginary = z2.GetImaginary() * z1.GetReal() - z1.GetImaginary() * z2.GetReal();
  return Complex(multi_real, multi_imaginary);
}
// перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, Complex z){
  // разбор случаев где Re(z)!=0
  if (z.GetReal() != 0 and z.GetImaginary() > 0) {
    out << z.GetReal() << "+" << z.GetImaginary() << "i";
  } else if (z.GetReal() != 0 and z.GetImaginary() < 0) {
    out << z.GetReal() << z.GetImaginary() << "i";
  } else if (z.GetReal() != 0 and z.GetImaginary() == 0) {
    out << z.GetReal();
  }
  // разбор случаев где Re(z)==0
  if (z.GetReal() == 0 and z.GetImaginary() > 0) {
    out << z.GetImaginary() << "i";
  } else if (z.GetReal() == 0 and z.GetImaginary() < 0) {
    out << z.GetImaginary() << "i";
  } else if (z.GetReal() == 0 and z.GetImaginary() == 0) {
    out << 0;
  }
  return out;
}
// перегрузка операторов сравнения 
bool operator==(Complex z1, Complex z2){
  if(z1.GetReal() == z2.GetReal() and z1.GetImaginary() == z2.GetImaginary()) { return true; }
  else { return false; }
}

bool operator!=(Complex z1, Complex z2){
  if(z1.GetReal() == z2.GetReal() and z1.GetImaginary() == z2.GetImaginary()) { return false; }
  else { return true; }
}


int main() {
  double real_z1, imaginary_z1, real_z2, imaginary_z2;
  std::cin >> real_z1 >> imaginary_z1 >> real_z2 >> imaginary_z2;
  // создание комплесных чисел
  Complex z1(real_z1, imaginary_z1);
  Complex z2(real_z2, imaginary_z2);

  // тест прегруженных опрераторов + - * << ==
  std::cout << z1 + z2 << " " << z1 * z2 << " " << z1 - z2 << " " << (z1 == z2 ? 1 : 2);
  
  
  return 0;
}


#include <iostream>
#include <vector>
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
  // даём доступ приватным полям класса, ниже перечисленным функциям(операторы)
  friend Complex operator+(const Complex &z1, const Complex &z2);
  friend Complex operator-(const Complex &z1, const Complex &z2);
  friend Complex operator*(const Complex &z1, const Complex &z2);
  friend Complex operator/(const Complex &z1, const Complex &z2);
  // деструктор
  ~Complex() {
    real_ = 0;
    imaginary_ = 0;
  }

private:
  // приватные поля
  double real_;
  double imaginary_;
};
// перегрузка опрераторов
// оператор + является отображением то есть + : Complex * Complex -> Complex 
Complex operator+(Complex z1, Complex z2){
  double sum_real = z1.GetReal() + z2.GetReal();
  double sum_imaginary = z1.GetImaginary() + z2.GetImaginary();
  return Complex(sum_real, sum_imaginary);
}
Complex operator-(Complex z1, Complex z2){
  double diff_real = z1.GetReal() - z2.GetReal();
  double diff_imaginary = z1.GetImaginary() - z2.GetImaginary();
  return Complex(diff_real, diff_imaginary);
}
// формулу можно загуглить
Complex operator*(Complex z1, Complex z2){
  double multi_real = z1.GetReal() * z2.GetReal() -  z1.GetImaginary() * z2.GetImaginary();
  double multi_imaginary = z2.GetImaginary() * z1.GetReal() - z1.GetImaginary() * z2.GetReal();
  return Complex(multi_real, multi_imaginary);
}
Complex operator/(Complex z1, Complex z2){}



int main() {
  double real_z1, imaginary_z1, real_z2, imaginary_z2;
  std::cin >> real_z1 >> imaginary_z1 >> real_z2 >> imaginary_z2;
  Complex z1(real_z1, imaginary_z1);
  Complex z2(real_z2, imaginary_z2);
  std::cout << z1.GetReal() << " " << z2.GetReal();
  std::cout << z1.GetImaginary() << " " << z2.GetImaginary();
  z1.SetReal(10.29);
  z1.SetImaginary(194.5);
  z2.SetReal(10.9);
  z2.SetImaginary(0.29);
  
  
  return 0;
}




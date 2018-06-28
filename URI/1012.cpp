#include <cstdio>
#include <iostream>

using namespace std;

const double PI = 3.14159;

int main() {
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  printf("TRIANGULO: %.3lf\n", (a * c) / 2.0);
  printf("CIRCULO: %.3lf\n", c * c * PI);
  printf("TRAPEZIO: %.3lf\n", (a + b) * c / 2.0);
  printf("QUADRADO: %.3lf\n", b * b);
  printf("RETANGULO: %.3lf\n", a * b);  
  return 0;
}

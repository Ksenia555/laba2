#define _USE_MATH_DEFINES  // ¬ключаем макрос дл€ использовани€ M_PI
#include <cmath>
#include <iostream>
#include "../complexlib/TComplex.h"


int main()
{
	TComplex<int> N, M;
	std::cin >> M;
	std::cin >> N;
	M + N;
	std::cout << M + N;
	std::cout << M - N;
	std::cout << M * N;
	std::cout << M / N;
	N /= M;
	std::cout << N;

	TComplex<double> a(1.0, 1.0);  

	TComplex<double> result1 = a.Power(3);  
	std::cout << "(1 + i)^3 = " << result1 << std::endl;
	TComplex<double> result1_1 = a.Power(4);  
	std::cout << "(1 + i)^4 = " << result1_1 << std::endl;

	TComplex<double> d(1.0, 1.0);  

	std::cout << "Complex num: " << d << std::endl;
	std::cout << "Trig form (v gradusax): ";
	d.PrintTrigonometricForm();

	return 0;
}
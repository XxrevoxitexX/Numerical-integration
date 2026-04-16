#define _USE_MATH_DEFINES
#include "../include/Integral.h"
#include <iostream>
#include <iomanip>
using namespace std;




int main() {
    // 设置精度输出
    cout << fixed << setprecision(7);
    double eps = 1e-6;   // 精度要求


    // 定义四个被积函数对象
    Integrand1 f1;
    Integrand2 f2;
    Integrand3 f3;
    Integrand4 f4;

    cout << "f1" << endl;

    // 梯形公式 n=10, n=20
    cout << "梯形 n=10 : " << composite_trapezoidal(f1, 0, M_PI/4.0, 10) << endl;
    cout << "梯形 n=20 : " << composite_trapezoidal(f1, 0, M_PI/4.0, 20) << endl;

    // Simpson公式 n=10, n=20
    cout << "Simpson n=10 : " << composite_simpson(f1, 0, M_PI/4.0, 10) << endl;
    cout << "Simpson n=20 : " << composite_simpson(f1, 0, M_PI/4.0, 20) << endl;

    // Romberg公式 n=10, n=20
    cout << "Romberg n=10 : " << composite_romberg(f1, 0, M_PI/4.0, 10) << endl;
    cout << "Romberg n=20 : " << composite_romberg(f1, 0, M_PI/4.0, 20) << endl;

    // 变步长：自动寻找最优n
    cout << "梯形自适应 最优n=" << find_optimal_n(composite_trapezoidal, f1, 0, M_PI/4.0, eps) << " : " << adaptive_trapezoidal(f1, 0, M_PI/4.0,eps) << endl;
    cout << "Simpson自适应 最优n=" << find_optimal_n(composite_simpson, f1, 0, M_PI/4.0, eps) << " : " << adaptive_simpson(f1, 0, M_PI/4.0, eps) << endl;
    cout << "Romberg自适应 最优n=" << find_optimal_n(composite_romberg, f1, 0, M_PI/4.0, eps) << " : " << adaptive_romberg(f1, 0, M_PI/4.0, eps) << endl;






    cout << "f2" << endl;

    // 梯形公式 n=10, n=20
    cout << "梯形 n=10 : " << composite_trapezoidal(f2, 0, 1, 10) << endl;
    cout << "梯形 n=20 : " << composite_trapezoidal(f2, 0, 1, 20) << endl;

    // Simpson公式 n=10, n=20
    cout << "Simpson n=10 : " << composite_simpson(f2, 0,1, 10) << endl;
    cout << "Simpson n=20 : " << composite_simpson(f2, 0, 1, 20) << endl;

    // Romberg公式 n=10, n=20
    cout << "Romberg n=10 : " << composite_romberg(f2, 0, 1, 10) << endl;
    cout << "Romberg n=20 : " << composite_romberg(f2, 0, 1, 20) << endl;

    // 变步长：自动寻找最优n
    cout << "梯形自适应 最优n=" << find_optimal_n(composite_trapezoidal, f2, 0, 1, eps) << " : " << adaptive_trapezoidal(f2, 0, 1,eps) << endl;
    cout << "Simpson自适应 最优n=" << find_optimal_n(composite_simpson, f2, 0, 1, eps) << " : " << adaptive_simpson(f2, 0, 1, eps) << endl;
    cout << "Romberg自适应 最优n=" << find_optimal_n(composite_romberg, f2, 0, 1, eps) << " : " << adaptive_romberg(f2, 0, 1, eps) << endl;



    cout << "f3" << endl;

    // 梯形公式 n=10, n=20
    cout << "梯形 n=10 : " << composite_trapezoidal(f3, 0, 1, 10) << endl;
    cout << "梯形 n=20 : " << composite_trapezoidal(f3, 0, 1, 20) << endl;

    // Simpson公式 n=10, n=20
    cout << "Simpson n=10 : " << composite_simpson(f3, 0,1, 10) << endl;
    cout << "Simpson n=20 : " << composite_simpson(f3, 0, 1, 20) << endl;

    // Romberg公式 n=10, n=20
    cout << "Romberg n=10 : " << composite_romberg(f3, 0, 1, 10) << endl;
    cout << "Romberg n=20 : " << composite_romberg(f3, 0, 1, 20) << endl;

    // 变步长：自动寻找最优n
    cout << "梯形自适应 最优n=" << find_optimal_n(composite_trapezoidal, f3, 0, 1, eps) << " : " << adaptive_trapezoidal(f3, 0, 1,eps) << endl;
    cout << "Simpson自适应 最优n=" << find_optimal_n(composite_simpson, f3, 0, 1, eps) << " : " << adaptive_simpson(f3, 0, 1, eps) << endl;
    cout << "Romberg自适应 最优n=" << find_optimal_n(composite_romberg, f3, 0, 1, eps) << " : " << adaptive_romberg(f3, 0, 1, eps) << endl;


    cout << "f4" << endl;

    // 梯形公式 n=10, n=20
    cout << "梯形 n=10 : " << composite_trapezoidal(f4, 0, 1, 10) << endl;
    cout << "梯形 n=20 : " << composite_trapezoidal(f4, 0, 1, 20) << endl;

    // Simpson公式 n=10, n=20
    cout << "Simpson n=10 : " << composite_simpson(f4, 0,1, 10) << endl;
    cout << "Simpson n=20 : " << composite_simpson(f4, 0, 1, 20) << endl;

    // Romberg公式 n=10, n=20
    cout << "Romberg n=10 : " << composite_romberg(f4, 0, 1, 10) << endl;
    cout << "Romberg n=20 : " << composite_romberg(f4, 0, 1, 20) << endl;

    // 变步长：自动寻找最优n
    cout << "梯形自适应 最优n=" << find_optimal_n(composite_trapezoidal, f4, 0, 1, eps) << " : " << adaptive_trapezoidal(f4, 0, 1,eps) << endl;
    cout << "Simpson自适应 最优n=" << find_optimal_n(composite_simpson, f4, 0, 1, eps) << " : " << adaptive_simpson(f4, 0, 1, eps) << endl;
    cout << "Romberg自适应 最优n=" << find_optimal_n(composite_romberg, f4, 0, 1, eps) << " : " << adaptive_romberg(f4, 0, 1, eps) << endl;


    system("pause");
    return 0;
}

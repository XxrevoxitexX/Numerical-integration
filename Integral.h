#include "./Function.h"
// 复合梯形公式
double composite_trapezoidal(const Function& f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}
// 复合Simpson公式
double composite_simpson(const Function& f, double a, double b, int n) {
    double T_n   = composite_trapezoidal(f, a, b, n);      
    double T_2n  = composite_trapezoidal(f, a, b, 2 * n); 
    return (4.0 * T_2n - T_n) / 3.0;
}
// 复合 Cotes 公式 (C_n)
double composite_cotes(const Function& f, double a, double b, int n) {
    double S_n  = composite_simpson(f, a, b, n);      // 步长 h = (b-a)/(2n) 的 Simpson 值
    double S_2n = composite_simpson(f, a, b, 2 * n);  // 步长 h/2 的 Simpson 值
    return (16.0 * S_2n - S_n) / 15.0;
}

// 复合 Romberg 公式 (R_n)
double composite_romberg(const Function& f, double a, double b, int n) {
    double C_n  = composite_cotes(f, a, b, n);      // 步长 h = (b-a)/(4n) 的 Cotes 值
    double C_2n = composite_cotes(f, a, b, 2 * n);  // 步长 h/2 的 Cotes 值
    return (64.0 * C_2n - C_n) / 63.0;
}


// CompMethod 是复合积分函数的类型
template<typename CompositeMethod>
int find_optimal_n(CompositeMethod composite_method,const Function& f, double a, double b,double eps, int max_steps=20) {
    int n = 1;
    double I_old = composite_method(f, a, b, n);
    for (int step = 1; step <= max_steps; ++step) {
        n *= 2;
        double I_new = composite_method(f, a, b, n);
        if (std::abs(I_new - I_old) < eps) {
            return n;
        }
        I_old = I_new;
    }
    return n;   // 达到最大步数，返回最后的 n
}
// 自适应梯形公式
double adaptive_trapezoidal(const Function& f, double a, double b, double eps, int max_steps=20) {
    int n = find_optimal_n(composite_trapezoidal, f, a, b, eps, max_steps);
    return composite_trapezoidal(f, a, b, n);
}
// 自适应Simpson公式
double adaptive_simpson(const Function& f, double a, double b, double eps, int max_steps=20) {
    int n = find_optimal_n(composite_simpson, f, a, b, eps, max_steps);
    return composite_simpson(f, a, b, n);
}
// 自适应cotes公式
double adaptive_cotes(const Function& f, double a, double b, double eps, int max_steps=20) {
    int n = find_optimal_n(composite_cotes, f, a, b, eps, max_steps);
    return composite_cotes(f, a, b, n);
}
// 自适应romberg公式
double adaptive_romberg(const Function& f, double a, double b, double eps, int max_steps=20) {
    int n = find_optimal_n(composite_romberg, f, a, b, eps, max_steps);
    return composite_romberg(f, a, b, n);
}


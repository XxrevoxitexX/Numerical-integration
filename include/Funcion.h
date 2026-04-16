#include <cmath>
class Function {
public:
    virtual double operator()(double x) const = 0;
    virtual ~Function() {}
};
class Integrand1 : public Function {
public:
    double operator()(double x) const {
        return sqrt(4.0 - sin(x) * sin(x));    //√(4-sin^2 x)
    }
};
class Integrand2 : public Function {
public:
    double operator()(double x) const {
        if (fabs(x) < 1e-12) return 1.0;   // 处理 x=0 处的极限
        return sin(x) / x;     //sin x /x
    }
};
class Integrand3 : public Function {
public:
    double operator()(double x) const override {
        return exp(x) / (4.0 + x * x);    //e^x / (4 + x^2)
    }
};
class Integrand4 : public Function {
public:
    double operator()(double x) const override {
        return log(1.0 + x) / (1.0 + x * x);    //ln(1+x) / (1+x^2)
    }
};

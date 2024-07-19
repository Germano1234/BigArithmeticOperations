#ifndef BIG_INTEGER_ARITHMETIC_HPP
#define BIG_INTEGER_ARITHMETIC_HPP

#include "arithmetic-expression.hpp"
#include "stack.hpp"
#include <string>
#include <vector>
using namespace std;

class BigIntegerArithmetic {
    private:
    ArithmeticExpression expression;
    string result;
    Stack* firstS;
    Stack* secondS;

    string add(const string& num1, const string& num2);
    string subtract(const string& num1, const string& num2);

    public:
    BigIntegerArithmetic(const ArithmeticExpression expr);
    ~BigIntegerArithmetic();
    string getResult() const;
    int operandComp(const string& op1, const string& op2);
};

#endif









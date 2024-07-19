#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP

#include "operand.hpp"
#include <string>
using namespace std;

class ArithmeticExpression{
    private:
        Operand* op1;
        Operand* op2;
        char oper;

    public:
        ArithmeticExpression();
        ArithmeticExpression(string op11, string op22, char op);
        string getOp1Str() const;
        string getOp2Str() const;
        char getOperator() const;

        void setOp1Str(string op);
        void setOp2Str(string op);
        void setOperator(char op);

};

#endif
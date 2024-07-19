#include "arithmetic-expression.hpp"

using namespace std;

ArithmeticExpression::ArithmeticExpression()
{
    op1 = new Operand();
    op2 = new Operand();
    oper = ' ';
}

ArithmeticExpression::ArithmeticExpression(string op11, string op22, char op)
{
    op1 = new Operand(op11);
    op2 = new Operand(op22);
    oper = op;
    if (op22[0] == '-' && oper == '+')
    {
        op2->flipSign();
        oper = '-';
    }
    if (op2->getValue()[0] == '-' && oper == '-')
    {
        op2->flipSign();
        oper = '+';
    }
}

string ArithmeticExpression::getOp1Str() const{
    return op1->getValue();
}

string ArithmeticExpression::getOp2Str() const
{
    return op2->getValue();
}

char ArithmeticExpression::getOperator() const
{
    return oper;
}

void ArithmeticExpression::setOp1Str(string op) {
    op1->setValue(op);
}

void ArithmeticExpression::setOp2Str(string op) {
    op2->setValue(op);
}

void ArithmeticExpression::setOperator(char op) {
    oper = op;
}
#include "big-integer-arithmetic.hpp"
#include <algorithm>
using namespace std;

BigIntegerArithmetic::BigIntegerArithmetic(const ArithmeticExpression expr) {
    expression = expr;
    char oper = expr.getOperator();
    string op1Str = expr.getOp1Str();
    string op2Str = expr.getOp2Str();
    firstS = new Stack();
    secondS = new Stack();

    for (size_t i = 0; i< op1Str.size(); ++i)
    {
        firstS->push(op1Str[i] - '0');
    }
    for (size_t i = 0; i< op2Str.size(); ++i)
    {
        secondS->push(op2Str[i] - '0');
    }

    if (oper == '+') {
        result = add(op1Str, op2Str);
    } else if (oper == '-') {
        result = subtract(op1Str, op2Str);
    } else {
        result = "Invalid operator";
    }
}

BigIntegerArithmetic::~BigIntegerArithmetic() {
    delete firstS;
    delete secondS;
}

string BigIntegerArithmetic::getResult() const {
    return result;
}

int BigIntegerArithmetic::operandComp(const string& op1, const string& op2) {
    if (op1.size() != op2.size()) {
        return op1.size() < op2.size() ? -1 : 1;
    }
    for (size_t i = 0; i < op1.size(); ++i) {
        if (op1[i] != op2[i]) {
            return op1[i] < op2[i] ? -1 : 1;
        }
    }
    return 0;
}

/* string BigIntegerArithmetic::add(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int size1 = num1.size() - 1;
    int size2 = num2.size() - 1;
    int max_size = max(size1,size2);

    for (int i = 0; i<max_size; ++i)
    {
        int r = firstS->pop() + secondS->pop() + carry;
        result.push_back(r % 10 + '0');
        carry = r/10;
    }

    if (carry > 0)
    {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}
 */

 string BigIntegerArithmetic::add(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int size1 = num1.size();
    int size2 = num2.size();
    int max_size = max(size1, size2);

    for (int i = 0; i < max_size; ++i) {
        int digit1 = (i < size1) ? num1[size1 - 1 - i] - '0' : 0;
        int digit2 = (i < size2) ? num2[size2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry > 0) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

string BigIntegerArithmetic::subtract(const string& num1, const string& num2)
{
    string result;
    int carry = 0;
    if (operandComp(num1,num2) == 0)
    {
        return 0;
    }
    else if (operandComp(num1,num2) > 0)
    {
        for (size_t i = 0; i < num1.size(); ++i)
        {
            int r;
            if (secondS->isEmpty() == false)
            {
                if (firstS->peek() < secondS->peek())
                {
                    r = (firstS->pop() + 10 - carry) - secondS->pop();
                    carry = 1;
                }
                else{
                    r = (firstS->pop()-carry) - secondS->pop();
                    carry = 0;
                }
            }
            else{
                r = firstS->pop() - carry;
                carry = 0;
            }
            result.push_back(r + '0'); 
        }
    }
    else if (operandComp(num1,num2) < 0)
    {
        for (size_t i = 0; i < num2.size(); ++i)
        {
            int r;
            if (firstS->isEmpty() == false)
            {
                if (secondS->peek() < firstS->peek())
                {
                    r = (secondS->pop() + 10 - carry) - firstS->pop();
                    carry = 1;
                }
                else{
                    r = (secondS->pop()-carry) - firstS->pop();
                    carry = 0;
                }
            }
            else{
                r = secondS->pop() - carry;
                carry = 0;
            }
            result.push_back(r + '0'); 
        }
        result.push_back('-');
    }
    reverse(result.begin(), result.end());
    if (result[0] == '-')
    {
        if (result[1] == '0')
        {
            result = result.substr(2);
            result = '-' + result;
        }
    }
    else if (result[0] == '0')
    {
        result = result.substr(1);
    }
    return result;
}

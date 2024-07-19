#ifndef EXPRESSION_READER_HPP
#define EXPRESSION_READER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "big-integer-arithmetic.hpp"

class ExpressionReader {
private:
    std::ifstream fileStream;

public:
    ExpressionReader(const std::string& filename) {
        fileStream.open(filename);
    }

    ~ExpressionReader() {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }

    bool isEmpty() {
        std::string line;
        return !(std::getline(fileStream, line));
    }


    std::string processNextExpression() {
        std::string line;
        if (std::getline(fileStream, line)) {
            std::istringstream iss(line);
            std::string op1, op2, op, equals, result;
            iss >> op1 >> op >> op2 >> equals >> result;
            char oper = op[0];
            ArithmeticExpression ae;
            ae = ArithmeticExpression(op1,op2,oper);
		    BigIntegerArithmetic bia(ae);
            return op1 + " " + op + " " + op2 + " " + "=" + " " + bia.getResult();
        }
        return "";
    }

};

#endif 

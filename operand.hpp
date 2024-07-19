#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
using namespace std;

class Operand{
    private:
        string value;
        bool negative;

    public:
        Operand();
        Operand(const string& val);
        string getValue();
        bool isNegative();
        void setValue(const string& val);
        void flipSign();
};

#endif
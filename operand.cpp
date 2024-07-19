#include "operand.hpp"
using namespace std;

Operand::Operand(){
    value = "";
    negative = false;
}

Operand::Operand(const string& val)
{
    value = val;
    negative = (val[0] == '-');
    if (value[0]== '+')
    {
        value = value.substr(1);
    }
}

string Operand::getValue(){
    return value;
}

bool Operand::isNegative()
{
    return negative;
}

void Operand::setValue(const string& val)
{
    value = val;
    negative = (val[0] == '-');
}

void Operand::flipSign()
{
    if(!negative && value[0]!='-')
    {
        value = "-" + value;
        negative = true;
    } else if (negative && value[0] == '-'){
        value = value.substr(1);
        negative = false;
    }
}
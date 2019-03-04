#include "Equation.h"


Equation::Equation(EnergyFunction* e, SourceFunction* s) :
    energyfct(e), sourcefct(s)
{
}

Equation::~Equation()
{
    delete energyfct;
    delete sourcefct;
}
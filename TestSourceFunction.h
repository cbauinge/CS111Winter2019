#ifndef TESTSOURCEFUNCTION_H
#define TESTSOURCEFUNCITON_H

#include "SourceFunction.h"

class TestSourceFunction : public SourceFunction
{
public:
    TestSourceFunction(/* args */);

    virtual ~TestSourceFunction();

    virtual double Eval(const Node& x) const;

private:
    /* data */
};



#endif /* TESTSOURCEFUNCTION_H */
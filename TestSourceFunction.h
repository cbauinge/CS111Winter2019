#ifndef TESTSOURCEFUNCTION_H
#define TESTSOURCEFUNCITON_H

#include "SourceFunction.h"


/*! \brief Specific implementation of a source function for tests.
 *
 *  Derived class from SourceFunction.
 */
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
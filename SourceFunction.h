#ifndef SOURCEFUNCTION_H
#define SOURCEFUNCTION_H

#include "Node.h"

/*!Class representing the rhs in the pde. I.e. the source term.
*Every specfific source function is a derived class from this class
*Later, the user could add new source functions using runtime compilation and dynamical linking.
*/
class SourceFunction
{
public:
    SourceFunction();

    virtual ~SourceFunction();

    virtual double Eval(const Node& x) const = 0;
private:

};


#endif /* SOURCEFUNCTION_H */
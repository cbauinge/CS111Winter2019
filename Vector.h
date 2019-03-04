#ifndef VECTOR_H
#define VECTOR_H

#include <map>

template <typename T>
class Vector
{
public:
    Vector(int m = 0) : dim(m) {}
    virtual ~Vector() {}

    virtual T& operator[](const int& i)
    {
        if (i >= dim)
            throw std::out_of_range("In Vector class");

        return values[i];    
    }

    virtual const T& operator[](const int& i) const
    {
        if (i >= dim)
            throw std::out_of_range("In Vector class");

        return values.at(i);    
    }

    Vector<T> operator*(const double& rhs) const
    {
        Vector<T> val = *this;
        for (auto iter = val.GetValues().begin(); iter != val.GetValues().end(); iter++)
        {
            iter->second *= rhs;
        }
        
        return val;
    }

    Vector<T>& operator*=(const double& rhs)
    {
        for (auto iter = values.begin(); iter != values.end(); iter++)
        {
            iter->second *= rhs;
        }
        
        return *this;
    }

    int GetDimension() const {return dim;}
    std::map<int, T>& GetValues() {return values;}
    bool Exists(int i) const
    {
        return values.find(i) != values.end();
    }

    static T Dot(Vector& lhs, Vector& rhs) 
    {
        T sum = 0.0;
        if (lhs.GetDimension() != rhs.GetDimension())
            throw std::invalid_argument("Trying to use Dot product on two vectors of different length");

        for (int i = 0; i < rhs.GetDimension(); i++) {
            sum += lhs[i]*rhs[i];
        }

        return sum;
    }

protected:
    int dim;
    std::map<int, T> values;
};



#endif /* VECTOR_H */
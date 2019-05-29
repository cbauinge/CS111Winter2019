#ifndef VECTOR_H
#define VECTOR_H

#include <map>
#include <ostream>


/*! \brief Vector class. Used in the matrix class.
 *
 *  Uses map to allow for sparse. Doesn't work in multithreaded applications.
 */
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

        if (values.find(i) == values.end())
            throw std::invalid_argument("In Vector class");

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


template <typename T>
std::ofstream& operator<<(std::ofstream& ofs, const Vector<T>& v)
{
    for (int i = 0; i < v.GetDimension(); i++) {
        if (v.Exists(i))
            ofs << v[i] << ", ";
        else
        {
            ofs << 0 << ", ";
        }
        
    }

    return ofs;
}



#endif /* VECTOR_H */
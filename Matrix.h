#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <map>
#include "Vector.h"
#include <ostream>

/*! \brief MAtrix class.
 *
 *  Template class with basic linear algebra properties.
 */
template <typename T>
class Matrix
{
public:
    Matrix(int m, int n) : dimrows(m), dimcols(n) {}

    virtual ~Matrix() {}

    virtual Vector<T>& operator[](const int& i) 
    {
        if (i >= dimrows) 
            throw std::out_of_range("Index out of bounds in Matrix class");
        
        if (values.find(i) == values.end())
            values.insert(std::pair<int, Vector<T> >(i, Vector<T>(dimcols)));

        return values[i];
    }

    virtual const Vector<T>& operator[](const int& i) const
    {
        if (i >= dimrows) 
            throw std::out_of_range("Index out of bounds in Matrix class");
        
        if (values.find(i) == values.end())
            throw std::invalid_argument("Element doesn't exist in Matrix class");

        return values.at(i);
    }

    Matrix<T>& operator=(const Matrix<T>& rhs)
    {
        if(&rhs == this)
            return *this;

        values = rhs.GetValues();
        dimrows = rhs.GetDimensionRows();
        dimcols = rhs.GetDimensionCols();

        return *this;
    }

    Vector<T> operator*(const Vector<T>& rhs) const
    {
        if (rhs.GetDimension() != dimcols)
            throw std::invalid_argument("Trying to multiply matrix and vector with different dimensions.");

        Vector<T> v(dimrows);
        for (int i = 0; i < dimrows; i++)
        {
            v[i] = 0;
            for (int j = 0; j < dimcols; j++) {
                if (Exists(i, j))
                    v[i] += rhs[j]*operator[](i)[j];
            }
        }
        return v;
    }

    int GetDimensionRows() const {return dimrows;}
    int GetDimensionCols() const {return dimcols;}
    const std::map<int, Vector<T> >& GetValues() const {return values;}


    bool Exists(int i, int j) const
    {
        if (values.find(i) != values.end())
        {
            return values.at(i).Exists(j);
        }
        return false;
    }

    bool Exists(int i) const
    {
        return values.find(i) != values.end();
    }
    
    Matrix<T> operator*(const double& rhs) const 
    {
        Matrix<T> val(this->GetDimensionRows(), this->GetDimensionCols());
        for (auto iter = values.begin(); iter != values.end(); iter++)
        {
            val[iter->first] = iter->second*rhs;
        }
        return val;
    }


    static Matrix<T> Inverse(const Matrix<T>& M) 
    {
        if (M.GetDimensionCols() != M.GetDimensionRows())
            throw std::logic_error("Attempting to invert non-square matrix in Matrix::Inverse");

        if (M.GetDimensionCols() != 2)
            throw std::invalid_argument("didn't implement Inverse funciton for more than 2 dimensions yet");


        Matrix<T> inv(M.GetDimensionRows(), M.GetDimensionCols());

        double det = Determinant(M);
        if (det == 0)
            throw std::logic_error("Attempting to invert singular Matrix");

        inv[0][0] = M[1][1]/det;
        inv[0][1] = -M[0][1]/det;
        inv[1][0] = -M[1][0]/det;
        inv[1][1] = M[0][0]/det;

        return inv;        
    }

    static double Determinant(const Matrix<T>& M)
    {
        if (M.GetDimensionCols() != M.GetDimensionRows())
            throw std::logic_error("Attempting to compute determinant of non-square matrix in Matrix::Determinant");

        if (M.GetDimensionCols() != 2)
            throw std::invalid_argument("didn't implement Determinant function for more than 2 dimensions yet");

        
        return M[0][0]*M[1][1] - M[0][1]*M[1][0];
    } 

    static Matrix<T> Transpose(const Matrix<T>& M)
    {
        Matrix<T> V(M.GetDimensionCols(), M.GetDimensionRows());

        for (int i = 0; i < M.GetDimensionRows(); i++)
        {
            for (int j = 0; j < M.GetDimensionCols(); j++)
            {
                V[j][i] = M[i][j];
            }
        }
        return V;
    }

protected:
    int dimrows;
    int dimcols;
    std::map<int, Vector<T> > values;
};

template <typename T>
std::ofstream& operator<<(std::ofstream& ofs, const Matrix<T>& M)
{
    for (int i = 0; i < M.GetDimensionRows(); i++)
    {
        if (M.Exists(i))
            ofs << M[i];
        else
        {
            for (int j = 0; j < M.GetDimensionCols(); j++)
            {
                ofs << 0 << ", ";
            }
        }
        ofs << std::endl;            
    }
    return ofs;
}


#endif /* MATRIX_H */
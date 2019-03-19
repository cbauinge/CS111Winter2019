#ifndef MULTIINDEX_H
#define MULTIINDEX_H

#include <vector>
#include <ostream>

/*! \brief Class representing a multiindex.
 *
 */
class Multiindex
{
public:
    Multiindex(std::vector<int>& vals) : values(vals) {}
    
    /*! \brief Get the modulus of the multiindex.
    *
    *  Sum over all the indices
    */
    int abs() const;
    int& operator[] (unsigned index);
    int operator[] (unsigned index) const;
    /*! \brief Get the dimensio, i.e. the number of indices in it.
    */
    int size() const {return values.size();}
    /*! \brief comparison operator.
    */
    bool operator <  (const Multiindex& m) const;
    
    
private:
    std::vector<int> values;
    
    
};

std::ostream& operator<<(std::ostream& ofs, const Multiindex& m);

#endif /*MULTIINDEX_H*/

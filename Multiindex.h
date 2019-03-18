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
    
    int abs() const;
    int& operator[] (unsigned index);
    int operator[] (unsigned index) const;
    int size() const {return values.size();}
    bool operator <  (const Multiindex& m) const;
    
    
private:
    std::vector<int> values;
    
    
};

std::ostream& operator<<(std::ostream& ofs, const Multiindex& m);

#endif /*MULTIINDEX_H*/

#ifndef MULTIINDEX_H
#define MULTIINDEX_H

#include <vector>


class Multiindex
{
public:
    Multiindex(int deg, std::vector<int>& vals) : d(deg), values(vals) {}
    
    int abs() const;
    int& operator[] (unsigned index);
    
    
private:
    int d;
    std::vector<int> values;
    
    
};

#endif /*MULTIINDEX_H*/

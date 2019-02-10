#ifndef SIMPLEX_H
#define SIMPLEX_H

#include<vector>
#include <ostream>

class Simplex
{
public:
    Simplex(std::vector<int> pts, std::vector<int> edges, double area = 0) : pts_(pts), edges_(edges), area_(area) {}
    
    
    int GetPoint(int id) const {return pts_[id]; }
    int GetEdge(int id) const {return edges_[id]; }
    double GetArea() const {return area_;}
    
    //friend std::ostream& operator<<(std::ostream& os, const Simplex& s);
    
private:
    std::vector<int> pts_;
    std::vector<int> edges_;
    double area_;
    
};

std::ostream& operator<<(std::ostream& os, const Simplex& s);


#endif /* SIMPLEX_H */

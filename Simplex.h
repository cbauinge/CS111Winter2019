#ifndef SIMPLEX_H
#define SIMPLEX_H

#include<vector>

class Simplex
{
public:
    Simplex(std::vector<int> pts, std::vector<int> edges, double area = 0) : pts_(pts), edges_(edges), area_(area) {}
    
    
    int GetPoint(int id) const {return pts_[id]; }
    int GetEdge(int id) const {return edges_[id]; }
    double GetArea() const {return area_;}
    
private:
    std::vector<int> pts_;
    std::vector<int> edges_;
    double area_;
    
};


#endif /* SIMPLEX_H */

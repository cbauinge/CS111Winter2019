#ifndef NODE_H
#define NODE_H

#include <fstream>
#include <ostream>

class Node
{
public:
    Node(double x, double y) : x_(x), y_(y) {}
    Node() : Node(0, 0) {}
    
    double GetX() const {return x_;}
    double GetY() const {return y_;}
    double& operator[](int idx) {return idx == 0 ? x_ : y_;}
    const double& operator[] (int idx) const {return idx == 0 ? x_ : y_;}
    int Dimension() const {return 2;}
    
    Node operator+(const Node& rhs) const;
    Node& operator+=(const Node& rhs);
    Node operator/(double rhs) const;
    Node& operator/=(double rhs);
    bool operator==(const Node& rhs) const;
    bool operator!= (const Node& rhs) const;
    
private:
    double x_, y_;
    
};

std::ostream& operator<<(std::ostream& os, const Node& n);



#endif /* NODE_H */

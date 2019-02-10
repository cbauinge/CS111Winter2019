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
    
    //friend std::ostream& operator<<(std::ostream& os, const Node& n);
    
private:
    double x_, y_;
    
};

std::ostream& operator<<(std::ostream& os, const Node& n);



#endif /* NODE_H */

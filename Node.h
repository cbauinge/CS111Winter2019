#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(double x, double y) : x_(x), y_(y) {}
    Node() : Node(0, 0) {}
    double GetX() const {return x_;}
    double GetY() const {return y_;}
    
private:
    double x_, y_;
    
};

#endif /* NODE_H */

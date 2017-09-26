//
//  polygon.hpp
//  Polygon
//
//  Created by Sumitha on 11/19/16.
//  Copyright © 2016 Sumitha. All rights reserved.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <iostream>
using namespace std;

//Point class
class Point
{
private:
    int x;
    int y;
    
public:
    Point(){ x = 0.0; y = 0.0; }
    Point(double x_val, double y_val){ x = x_val; y = y_val; }
    int getX() const;
    int getY() const;
    void setX(const int new_x);
    void setY(const int new_y);
    
};

// Point Array Class
class PointArray
{
private:
    Point* pArray;
    int size;
    void resize(int n);
    
public:
    int getSize() const { return size;}
    Point * getPoints() const;
    
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray &pv);
    ~PointArray();
    
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    void clear();
    const Point *get(const int pos) const;
    //void printPointArray(const PointArray* pa);
    
};

// Implement a class for a convex polygon called Polygon.
// Polygon will be an abstract class.

class Polygon {
    
protected:
    PointArray pArray;
    static int count;
    
public:
    Polygon(const Point pa[], const int length);
    Polygon(const PointArray &pa);
    ~Polygon() { count--; }
    
    virtual double area() = 0;
    static int getNumPolygons() { return count; }
    int getNumSides() const {return pArray.getSize();}
    const PointArray *getPoints() const {return &pArray;}
    void printPointArray(const PointArray* pa);
    };


//Subclass of Polygon called Rectangle that models a rectangle.
class Rectangle : public Polygon
{
    public:
    Rectangle(const Point &pt_1, const Point &pt_2);
    Rectangle(const int a, const int b, const int c, const int d);
    virtual double area() override;
};

//Subclass of Polygon called Triangle that models a triangle.
class Triangle : public Polygon
{
    public:
    Triangle(const Point &pt_1, const Point &pt_2, const Point &pt_3);
    virtual double area() override;
};

void printAttributes(Polygon *p);

#endif /* polygon_hpp */

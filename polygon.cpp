//
//  polygon.cpp
//  Polygon
//
//  Created by Sumitha on 11/19/16.
//  Copyright © 2016 Sumitha. All rights reserved.
//

#include "polygon.hpp"
#include <cmath>
using namespace std;

/* Point Class Member function Definitions */
int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(const int new_x)
{
    x = new_x;
    cout << "new x coordinate : " << x << endl;
}

void Point::setY(const int new_y)
{
    y = new_y;
    cout << "new y coordinate : " << y << endl;
}


/* Point Class Member function Definitions */

Point* PointArray :: getPoints() const
{
    return pArray;
}

//Default constructor
PointArray :: PointArray()
{
    size = 0;
    Point* pArray = new Point [size];
    pArray = {};
}

//Constructor that takes a points Array called points[] and it's size as parameters
PointArray :: PointArray(const Point points[], const int size)
{
    pArray = new Point[size];
    for (int i = 0; i < size; i++)
    {
        pArray[i] = points[i];
    }
    resize(size);
}

//Copy constructor that creates a copy of a given Point Array
PointArray :: PointArray(const PointArray &pv)
{
    size = getSize();
    pArray = new Point[size];
    for(int i = 0; i < size; i++)
    {
        pArray[i] = pv.getPoints()[i];
    }
    
}

PointArray :: ~PointArray()
{
    delete[] pArray;
}


void PointArray::resize(int n)
{
    Point* new_pArray = new Point[n];
    
    // copy the first min(previous array size, n) existing elements
    for (int i = 0; i < (size < n ? size : n); i++)
        new_pArray[i] = pArray[i];
    size = n;
}

//Add a Point to the end of the array
void PointArray:: push_back(const Point &p)
{
    resize(size + 1);
    pArray[size -1] = p;
    cout << "Added Point (" << p.getX() <<","<< p.getY() << ") at the end of the array." << endl;
}

void PointArray::insert(const int position, const Point &p)
{
    // increase array size
    resize(size + 1);
    
    // Shifting Array elements to the right after the insertion point
    for (int i = size - 1; i > position; i--)
        pArray[i] = pArray[i-1];
    
    // insert p
    pArray[position] = p;
    
    cout<< "Inserted a Point (" << p.getX() <<","<< p.getY() << ") to  PointArray at index : "<< position <<endl;
}

void PointArray::remove(const int pos)
{
    // Remove the Point at pos, shifting the remaining elements to the left
    for (int i = pos; i < size ; i++)
    {
        Point x;
        if(i == pos)
        {
            x = pArray[i];
        }
        pArray[i] = pArray[i+1];
        // resize array
        resize(size - 1);
        cout << "Removed Point (" << x.getX() <<","<< x.getY() << ") from PointArray at index : "<< pos << endl;
    }
    
}
// Remove everything from the array and sets its size to 0
void PointArray::clear()
{
    resize(0);
}

//Get a pointer to the element at some arbitrary position

const Point* PointArray::get(const int position) const
{
    return pArray + position;
}

void Polygon::printPointArray(const PointArray* pa)
{
    cout << "Point objects : " << endl;
    for(int i = 0; i<pa->getSize();i++)
    {
        cout << "(" << pa->getPoints()[i].getX()<<"," << pa->getPoints()[i].getY() << ")" <<endl;
        
    }
    
}

/* Polygon Class Member function Definitions */

// Implement a constructor that creates a Polygon from two arguments: an array of
// Points and the length of that array.
Polygon::Polygon(const Point pa[], const int length) : pArray(pa, length)
{
    count++;
}

//Implement a constructor that creates a polygon using the points in an existing
//PointArray that is passed as an argument.
Polygon::Polygon(const PointArray &pa) : pArray(pa)
{
    count++;
}


/* Rectangle Class Member function Definitions */

//Global array that we update each time we want to make a new array of Points for constructing a Polygon.

Point constructorPoints[4];
Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3,
                               const Point &p4 = Point(0,0)) {
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

// Allow constructing a Rectangle from two Points (the lower left coordinate and
// the upper right coordinate)

Rectangle::Rectangle(const Point &lowerLeft, const Point &upperRight)
: Polygon(updateConstructorPoints(lowerLeft,Point(upperRight.getX(), lowerLeft.getY()),upperRight, Point(lowerLeft.getX(), upperRight.getY())), 4) {
    }

//Allow construct a Rectangle from four ints

Rectangle::Rectangle(const int llx, const int lly, const int urx, const int ury)
: Polygon(updateConstructorPoints(Point(llx, lly), Point(llx, ury),
                                  Point(urx, ury), Point(urx, lly)), 4) {}

//Override the Polygon::area’s behavior such that the rectangle’s area is calculated
//by multiplying its length by its width, but still return the area as a double.

double Rectangle::area()
{
    int length = pArray.get(1)->getX() - pArray.get(0)->getX();
    int width = pArray.get(3)->getY() - pArray.get(0)->getY();
    return abs((double)length * width);
}

/* Triangle Class Member function Definitions */

//Construct a Triangle from three Points
Triangle::Triangle(const Point &pt_1, const Point &pt_2, const Point &pt_3)
: Polygon(updateConstructorPoints(pt_1, pt_2, pt_3), 3) {
    
}


//Override the area function such that it calculates the area using Heron’s formula.
double Triangle::area() 
{
    
    int x0 = pArray.get(0)->getX();
    int y0 = pArray.get(0)->getY();
    
    int x1 = pArray.get(1)->getX();
    int y1 = pArray.get(1)->getY();
    
    int x2 = pArray.get(2)->getX();
    int y2 = pArray.get(2)->getY();
    
    double a = sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
    double b = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    double c = sqrt((x2-x0)*(x2-x0) + (y2-y0)*(y2-y0));
    
    double s = (a + b + c) / 2;
    return sqrt( s * (s-a) * (s-b) * (s-c) );
    

}











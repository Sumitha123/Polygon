//
//  main.cpp
//  Polygon
//
//  Created by Sumitha on 11/19/16.
//  Copyright © 2016 Sumitha. All rights reserved.
//

#include <iostream>
#include "polygon.hpp"

void printAttributes(Polygon *p)
{
    cout << "Polygon's area : " << p->area() << endl;
    cout << "Polygon's points are :\n";
    const PointArray* pl = p->getPoints();    
    for(int i = 0; i < pl->getSize();i++)
    {
        cout << "(" << pl->get(i)->getX() << ", " << pl->get(i)-> getY() << ")\n";
    }
}

int Polygon :: count=0;
int main()
{
    int lowerLeft_x, lowerLeft_y, upperRight_x, upperRight_y;

    cout << "Enter the lower left and upper right coordinates of rectangle as integers separated by space : ";
    
    cin>>lowerLeft_x>>lowerLeft_y>>upperRight_x>>upperRight_y;
    
    Point lowerLeft(lowerLeft_x, lowerLeft_y);
    Point upperRight(upperRight_x,upperRight_y);
    
    Rectangle rect(lowerLeft, upperRight);
    printAttributes(&rect);
    
    cout << "Enter the three coordinates of triangle as integers separated by space : ";
    int x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);
    Triangle tri(a, b, c);
    printAttributes(&tri);
   
}

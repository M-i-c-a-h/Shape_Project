/**
G++ SYSTEM
COURSE: CS251 DATA STRUCTURES- FALL 2022/2023
        University of Illinois Chicago
PROJECT TITLE: SEARCH ENGINE
STARTER CODE BY: Prof Adam Koehler
EDITED BY: MICAH OREOLUWA OLUGBAMILA
DATE:  14TH OCTOBER 2023
 * */

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual string printShape() const;
        Shape(const Shape* copyShape);
};


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual string printShape() const;
        Circle(const Circle* copyCircle);
};


class Rect : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rect();
        Rect(int w, int h);
        Rect(int x, int y, int w, int h);
        
        virtual ~Rect();
        virtual Rect* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual string printShape() const;
        Rect(const Rect* copyRect);
};

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual string printShape() const;
        RightTriangle(const RightTriangle* copyTri);
};


// DO NOT REMOVE - USED BY AUTOGRADER
#include "moreshapes.h"
// DO NOT REMOVE - USED BY AUTOGRADER
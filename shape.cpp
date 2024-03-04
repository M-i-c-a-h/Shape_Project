/**
G++ SYSTEM
COURSE: CS251 DATA STRUCTURES- FALL 2022/2023
        University of Illinois Chicago
PROJECT TITLE: SEARCH ENGINE
EDITED BY: MICAH OREOLUWA OLUGBAMILA
DATE:  14TH OCTOBER 2023
 * */

#include "shape.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////           SHAPE CLASS FUNCTION DEFINITION            /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// default constructor Shapes
/// function takes in no parameter and returns no parameter
/// function sets data members x and y to default value 0
Shape :: Shape() {
    x = 0;
    y = 0;
}

/// constructor Shapes is overloaded to accept parameters
/// function takes in 2 int  parameter and returns no parameter
/// function sets data members x and y to value passed in constructor argument
Shape :: Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

///Function is an empty destructor but needed to implement derived class destructors
Shape :: ~Shape(){

}

/// Function is a copy constructor that creates a deep copy of implicitly provided Shape object
/// Function takes in a const pointer to a shape object
/// Function has no return type
Shape :: Shape(const Shape* copyShape){
    this->x = copyShape->x;
    this->y = copyShape->y;
}

/// Function returns a newly created copy of the implicitly provided shape object that has its own memory location,
/// (***has all the same properties as the implicitly provided original object.)
/// Function calls copy constructor
Shape* Shape :: copy(){
    Shape* newShape = new Shape(this);
    return newShape;
}

/// Function returns an int which is the value of data member X of Shape class
/// Function is a const signifying inability to make modifications to class Shape
int Shape :: getX() const {
    return x;
}

/// Function returns an int which is the value of data member Y of Shape class
/// Function is a const signifying inability to make modifications to class Shape
int Shape :: getY() const {
    return y;
}

/// Function  takes in an int data and has no return type
/// Function explicitly sets value of X
void Shape :: setX(int x) {
    this->x =  x;
}

/// Function  takes in an int data and has no return type
/// Function explicitly sets value of Y
void Shape :: setY(int y) {
    this->y =  y;
}

/// Function has no parameters and returns a string of the Shape class data members
/// Function is a const signifying inability to make modifications to class Shape
string Shape :: printShape() const {
    return "It's a Shape at x: " + to_string(getX()) + ", y: " + to_string(getY());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////           SHAPE CLASS FUNCTION DEFINITION            /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////           CIRCLE CLASS FUNCTION DEFINITION           /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// default constructor Circle
/// function takes in no parameter and returns no parameter
/// function sets data member Radius to default value 0
Circle :: Circle() {
    radius = 0;
}


/// Constructor Circle is overloaded to accept parameter
/// Function takes in 1 int  parameter and returns no parameter
/// Function sets data member Radius to value passed in constructor argument
Circle :: Circle(int r) {
    radius =  r;
}

/// Constructor Circle is overloaded to accept parameters (constructor passes x and y values to base class Shape)
/// Function takes in 3 int parameter (x, y, r) and returns no parameter
/// Function sets data member Radius to value passed in constructor argument
Circle :: Circle(int x, int y, int r)  : Shape(x, y){
    radius = r;
}


/// Function is the destructor for Circle class
/// Function has no parameters and no return type
Circle :: ~Circle(){

}


/// Function is a copy constructor that creates a deep copy of implicitly provided Circle object
/// Function takes in a const pointer to a Circle object
/// Function has no return type
Circle :: Circle(const Circle* copyCircle) : Shape(copyCircle){
    this->radius = copyCircle->radius;
}

/// Function returns a newly created copy of the implicitly provided Circle object that has its own memory location,
/// (***has all the same properties as the implicitly provided original object.)
/// Function calls copy constructor
Circle* Circle :: copy(){
    Circle* newCircle = new Circle(this);
    return newCircle;
}


/// Function has no parameters and returns a string of the Circle class data members with its inherited Shape data members
/// Function is a const signifying inability to make modifications to class Shape
string Circle :: printShape() const {
    return "It's a Circle at x: " + to_string(getX()) + ", y: " + to_string(getY()) +
            ", radius: "+ to_string(radius);
}


/// Function returns an int which is the Radius of Circle class
/// Function is a const signifying inability to make modifications to class Shape
int Circle :: getRadius() const {
    return radius;
}

/// Function takes in an int data and has no return type
/// Function explicitly sets value of Radius
void Circle :: setRadius(int radius) {
    this->radius = radius;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////           CIRCLE CLASS FUNCTION DEFINITION           /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////         RECTANGLE CLASS FUNCTION DEFINITION          /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// default constructor Rectangle
/// function takes in no parameter and returns no parameter
/// function sets data member width and height to default value 0
Rect :: Rect() {
    width = 0;
    height = 0;
}


/// Constructor Rectangle is overloaded to accept parameter
/// Function takes in 2 int  parameter and returns no parameter
/// Function sets data members width & height to value passed in constructor argument
Rect ::Rect (int w, int h) {
    width = w;
    height = h;
}

/// Constructor Rectangle is overloaded to accept parameters (constructor passes x and y values to base class Shape)
/// Function takes in 4 int parameter (x, y, w,h) and returns no parameter
/// Function sets data members to value passed in constructor argument
Rect :: Rect (int x, int y, int w, int h)  : Shape(x, y){
    width = w;
    height = h;
}


/// Function is the destructor for Rectangle class
/// Function has no parameters and no return type
Rect :: ~Rect(){

}


/// Function is a copy constructor that creates a deep copy of implicitly provided Rectangle object
/// Function takes in a const pointer to a Rectangle object
/// Function has no return type
Rect :: Rect(const Rect* copyRect) : Shape(copyRect){
    this->width = copyRect->width;
    this->height = copyRect->height;
}

/// Function returns a newly created copy of the implicitly provided Rectangle object that has its own memory location,
/// (***has all the same properties as the implicitly provided original object.)
/// Function calls copy constructor
Rect* Rect :: copy(){
    Rect* newRect = new Rect(this);
    return newRect;
}


/// Function has no parameters and returns a string of the Rectangle class data members with its inherited Shape data members
/// Function is a const signifying inability to make modifications to class Shape
string Rect :: printShape() const {
    return "It's a Rectangle at x: " + to_string(getX()) + ", y: " + to_string(getY()) +
           " with width: " + to_string(width) + " and height: " + to_string(height);
}


/// Function returns an int which is the width of Rectangle class
/// Function is a const signifying inability to make modifications to class Shape
int Rect :: getWidth() const {
    return width;
}

/// Function returns an int which is the height of Rectangle class
/// Function is a const signifying inability to make modifications to class Shape
int Rect :: getHeight() const {
    return height;
}

/// Function takes in an int data and has no return type
/// Function explicitly sets value of Rectangle's width
void Rect :: setWidth(int width) {
    this->width = width;
}

/// Function takes in an int data and has no return type
/// Function explicitly sets value of Rectangle's width
void Rect :: setHeight(int height) {
    this->height = height;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////         RECTANGLE CLASS FUNCTION DEFINITION          /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////       RightTriangle CLASS FUNCTION DEFINITION        /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// default constructor Rectangle
/// function takes in no parameter and returns no parameter
/// function sets data member base and height to default value 0
RightTriangle :: RightTriangle() {
    base = 0;
    height = 0;
}


/// Constructor RightTriangle is overloaded to accept parameter
/// Function takes in 2 int  parameter and returns no parameter
/// Function sets data members to value passed in constructor argument
RightTriangle ::RightTriangle (int b, int h) {
    base = b;
    height = h;
}

/// Constructor RightTriangle is overloaded to accept parameters (constructor passes x and y values to base class Shape)
/// Function takes in 4 int parameter (x, y, b,h) and returns no parameter
/// Function sets data members to value passed in constructor argument
RightTriangle :: RightTriangle (int x, int y, int b, int h)  : Shape(x, y){
    base = b;
    height = h;
}


/// Function is the destructor for RightTriangle class
/// Function has no parameters and no return type
RightTriangle :: ~RightTriangle(){

}


/// Function is a copy constructor that creates a deep copy of implicitly provided RightTriangle object
/// Function takes in a const pointer to a RightTriangle object
/// Function has no return type
RightTriangle :: RightTriangle(const RightTriangle* copyTri) : Shape(copyTri){
    this->base = copyTri->base;
    this->height = copyTri->height;
}

/// Function returns a newly created copy of the implicitly provided RightTriangle object that has its own memory location,
/// (***has all the same properties as the implicitly provided original object.)
/// Function calls copy constructor
RightTriangle* RightTriangle :: copy(){
    RightTriangle* newTri = new RightTriangle(this);
    return newTri;
}


/// Function has no parameters and returns a string of the RightTriangle class data members with its inherited Shape data members
/// Function is a const signifying inability to make modifications to class Shape
string RightTriangle :: printShape() const {
    return "It's a Right Triangle at x: " + to_string(getX()) + ", y: " + to_string(getY()) +
           " with base: " + to_string(base) + " and height: " + to_string(height);
}


/// Function returns an int which is the width of Rectangle class
/// Function is a const signifying inability to make modifications to class Shape
int RightTriangle :: getBase() const {
    return base;
}

/// Function returns an int which is the height of Rectangle class
/// Function is a const signifying inability to make modifications to class Shape
int RightTriangle :: getHeight() const {
    return height;
}

/// Function takes in an int data and has no return type
/// Function explicitly sets value of Rectangle's width
void RightTriangle :: setBase(int base) {
    this->base = base;
}

/// Function takes in an int data and has no return type
/// Function explicitly sets value of Rectangle's width
void RightTriangle :: setHeight(int height) {
    this->height = height;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////       RightTriangle CLASS FUNCTION DEFINITION        /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
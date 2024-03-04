/**
G++ SYSTEM
COURSE: CS251 DATA STRUCTURES- FALL 2022/2023
        University of Illinois Chicago
PROJECT TITLE: Shapes and CanvasList
EDITED BY: MICAH OREOLUWA OLUGBAMILA
DATE:  14TH OCTOBER 2023
 * */

#include <iostream>
#include "canvaslist.h"
#include "shape.h"

using namespace std;

int main()
{
     CanvasList myCanvas;
     cout << "List size: " << myCanvas.size() << endl;
     cout << "Front: " << myCanvas.front() << endl;

     cout << endl << endl << "Adding Shape to the front" << endl;
     Shape *s = new Shape(1, 3);
     myCanvas.push_front(s);
     cout << "List size: " << myCanvas.size() << endl;
     myCanvas.draw();

     cout << endl << endl << "Adding Shape to the front" << endl;
     Shape *p = new Shape(4, 6);
     myCanvas.push_front(p);
     cout << "List size: " << myCanvas.size() << endl;
     myCanvas.draw();


     cout << endl << endl << "Adding Shape to the back" << endl;
     Shape *b = new Shape(4, 6);
     myCanvas.push_back(b);
     cout << "List size: " << myCanvas.size() << endl;
     myCanvas.draw();


     // comment out the circle, rectangle, and right triangle calls
     // until you have those classes implemented
     cout << endl << endl << "Adding Circle to the front" << endl;
     s = new Circle(2, 4, 3);
     myCanvas.push_front(s);
     cout << "List size: " << myCanvas.size() << endl;
     myCanvas.draw();

     cout << endl << endl << "Adding Rectangle to the back" << endl;
     s = new Rect(0, 10);
     myCanvas.push_back(s);
     cout << "List size: " << myCanvas.size() << endl;
     myCanvas.draw();

     cout << endl << endl << "Adding Right Triangle to the front" << endl;
     s = new RightTriangle(1, 2, 3, 4);
     myCanvas.push_front(s);
     cout << "List size: " << myCanvas.size() << endl;
     myCanvas.draw();



     cout << endl << endl << "Deleting last element" << endl;
     delete myCanvas.pop_back();
     cout << "List size: " << myCanvas.size() << endl;
     myCanvas.draw();

     cout << endl << endl << "Inserting Shape after index 1" << endl;
     cout << "Original:" << endl;
     myCanvas.draw();
     myCanvas.insertAfter(1, new Shape(3,4));
     cout << "Updated Original:" << endl;
     myCanvas.draw();


     cout << endl << endl;
     cout << "Addresses:" << endl;
     myCanvas.printAddresses();




    return 0;
}
void CanvasTest(){
    CanvasList myCanvas;

    Shape *a = new Shape();
    Shape *b = new Shape(1,2);

    Shape *c = new Circle(4);
    Shape *d = new Circle(1,2,3);

    Shape *e = new Rect();
    Shape *f = new Rect(4,5);
    Shape *g = new Rect(-1,-3,-4,-5);

    Shape *h = new RightTriangle();
    Shape *i = new RightTriangle(2,22);
    Shape *j = new RightTriangle(12,11,13,14);


    myCanvas.push_front(a);
    cout << endl  << endl;
    cout  << "canvas has " << myCanvas.size() << " shapes\n";
    myCanvas.draw();

    myCanvas.push_front(b);
    cout << endl  << endl;
    cout  << "canvas has " << myCanvas.size() << " shapes\n";
    myCanvas.draw();

    myCanvas.push_back(c);
//    myCanvas.push_front(d);
//    myCanvas.push_front(e);
//    myCanvas.push_front(f);
    myCanvas.push_back(g);
//    myCanvas.push_front(h);
//    myCanvas.push_front(i);
    myCanvas.push_back(j);


    cout << endl  << endl;
    cout  << "canvas has " << myCanvas.size() << " shapes\n";
    myCanvas.draw();

    //myCanvas.insertAfter(2, i);
    //myCanvas.pop_back();

    cout << endl  << endl;
    cout  << "canvas has " << myCanvas.size() << " shapes\n";
    myCanvas.draw();
    //myCanvas.pop_back();
    //myCanvas.pop_back();
    //myCanvas.pop_back();
    //myCanvas.pop_back();
    //myCanvas.pop_front();
    //myCanvas.removeAt(-3);

    myCanvas.removeEveryOther();

    cout << endl  << endl;
    cout  << "canvas has " << myCanvas.size() << " shapes\n";
    myCanvas.draw();
}
void run(){
    //    Shape shape;
//    cout << "shape x is " << shape.getX() << " Y is " << shape.getY() << endl;
//
//    shape.setX(4);   shape.setY(5);
//    cout << "shape x is " << shape.getX() << " Y is " << shape.getY() << endl;
//
//    shape.setX(11);   shape.setY(12);
//    cout << "shape x is " << shape.getX() << " Y is " << shape.getY() << endl;
//
//    Shape shape1 = shape;
//    cout << "shape1 x is " << shape1.getX() << " Y is " << shape1.getY() << endl;
//    cout << &shape << endl << &shape1 << endl ;
//
//    Shape* shape2;
//    shape2 = shape1.copy();
//    cout << "shape2 x is " << shape2->getX() << " Y is " << shape2->getY() << endl;
//    cout << &shape << endl << &shape1 << endl  << shape2 << endl;
//
//
//    shape2->setX(20);  shape2->setY(22);
//    cout << shape2->printShape();
//    cout << "shape2 x is " << shape2->getX() << " Y is " << shape2->getY() << endl;


//    Shape* testShape = new Circle(1,2,3);
//    cout << testShape->printShape() << "\n";
//
//    Circle *myCircle = new Circle();


//    cout << myCircle->printShape() << "\n";
//
//    myCircle->setX(2);
//    myCircle->setY(3);
//    myCircle->setRadius(4);
//
//    cout << myCircle->printShape() << "\n";

//    Shape* testShape = new Rect(1,2,3,4);
//    cout << testShape->printShape() << "\n";
//
//    Rect *myRect = new Rect();
//
//
//    cout << myRect->printShape() << "\n";
//
//    myRect->setX(2);
//    myRect->setY(3);
//    myRect->setWidth(4);
//    myRect->setHeight(5);
//
//    cout << myRect->printShape() << "\n";

//    Shape* testShape = new RightTriangle(1,2,3,4);
//    cout << testShape->printShape() << "\n";
//
//    RightTriangle *myTri = new RightTriangle();
//
//
//    cout << myTri->printShape() << "\n";
//
//    myTri->setX(2);
//    myTri->setY(3);
//    myTri->setBase(4);
//    myTri->setHeight(5);
//
//    cout << myTri->printShape() << "\n";


//     CanvasList myCanvas;
//     int pass = 0, fail = 0;
//     nullptr == myCanvas.front() ? ++pass : ++fail;
//
//     cout << "Checking canvas sets nullptr with default constructor\n";
//     cout << "\n\n" << pass << "  " << fail << endl;
//
//     cout << "Checking new shape is pushed front\n";
//     myCanvas.push_front(shape2);
//     cout << "Checking new shape2 is pushed front\n";
//     myCanvas.push_front(&shape);
//
//     11 == myCanvas.front()->value->getX() ? ++pass : ++fail;
//     cout << "Checking if last pushed shape is pushed front\n";
//     cout << "\n\n" << pass << "  " << fail << endl;
//
//     cout << "Checking copy constructor \n";
//     CanvasList canvasList1(myCanvas);
//
//     canvasList1.front()->value == myCanvas.front()->value ? ++pass : ++fail;
//     cout << "\n\n" << pass << "  " << fail << endl;

//     cout << "Checking copy assignment operator && address is diff \n";
//     CanvasList testCopy = myCanvas;
//     testCopy.front()->value == myCanvas.front()->value ? ++pass : ++fail;
//     &testCopy != &myCanvas ? ++pass : ++fail;
//     cout << "\n\n" << pass << "  " << fail << endl;
//
//    cout << "Checking swap \n";
//
//    canvasList1.push_front(&shape1);
//    myCanvas.front()->value->setX(10);
//    cout << myCanvas.front()->value->getX() << endl;
//    swap(canvasList1,myCanvas);
//    11 == myCanvas.front()->value->getX() ? ++pass : ++fail;
//    cout << "\n\n" << pass << "  " << fail << endl;
//
//    cout << "Checking clear and delete \n";
//    myCanvas.clear();
//
//    nullptr == myCanvas.front() ? ++pass : ++fail;
//    0 == myCanvas.size() ? ++pass : ++fail;
//    cout << "\n\n" << pass << "  " << fail << endl;
//
//
//    cout << "Checking push_back \n";
//    myCanvas.push_back(&shape1);
//    myCanvas.push_back(&shape);
//
//    &shape == myCanvas.back()->value ? ++pass : ++fail;
//    cout << "\n\n" << pass << "  " << fail << endl;

//	 cout << "List size: " << myCanvas.size() << endl;
//	 cout << "Front: " << myCanvas.front() << endl;
//
//	 cout << endl << endl << "Adding Shape to the front" << endl;
//	 Shape *s = new Shape(1, 3);
//	 myCanvas.push_front(s);
//	 cout << "List size: " << myCanvas.size() << endl;
//	 myCanvas.draw();
//
//	 cout << endl << endl << "Adding Shape to the front" << endl;
//	 Shape *p = new Shape(4, 6);
//	 myCanvas.push_front(p);
//	 cout << "List size: " << myCanvas.size() << endl;
//	 myCanvas.draw();
//
//
//	 cout << endl << endl << "Adding Shape to the back" << endl;
//	 Shape *b = new Shape(4, 6);
//	 myCanvas.push_back(b);
//	 cout << "List size: " << myCanvas.size() << endl;
//	 myCanvas.draw();
//     //delete myCanvas.pop_front();


    // // comment out the circle, rectangle, and right triangle calls
    // // until you have those classes implemented
    // cout << endl << endl << "Adding Circle to the front" << endl;
    // s = new Circle(2, 4, 3);
    // myCanvas.push_front(s);
    // cout << "List size: " << myCanvas.size() << endl;
    // myCanvas.draw();

    // cout << endl << endl << "Adding Rectangle to the back" << endl;
    // s = new Rect(0, 10);
    // myCanvas.push_back(s);
    // cout << "List size: " << myCanvas.size() << endl;
    // myCanvas.draw();

    // cout << endl << endl << "Adding Right Triangle to the front" << endl;
    // s = new RightTriangle(1, 2, 3, 4);
    // myCanvas.push_front(s);
    // cout << "List size: " << myCanvas.size() << endl;
    // myCanvas.draw();


//
//	 cout << endl << endl << "Deleting last element" << endl;
//	 delete myCanvas.pop_back();
//     myCanvas.draw();
//
//	 cout << "List size: " << myCanvas.size() << endl;
//	 myCanvas.draw();
//
//	 cout << endl << endl << "Inserting Shape after index 1" << endl;
//	 cout << "Original:" << endl;
//	 myCanvas.draw();
//	 myCanvas.insertAfter(-1, new Shape(3,4));
//	 cout << "Updated Original:" << endl;
//	 myCanvas.draw();
//
//
//	 cout << endl << endl;
//	 cout << "Addresses:" << endl;
//	 myCanvas.printAddresses();
}
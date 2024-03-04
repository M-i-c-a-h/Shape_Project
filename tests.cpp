/**
G++ SYSTEM
COURSE: CS251 DATA STRUCTURES- FALL 2022/2023
        University of Illinois Chicago
PROJECT TITLE: Shapes and CanvasList
STARTER CODE BY: Prof Adam Koehler
Author: MICAH OREOLUWA OLUGBAMILA
DATE:  14TH OCTOBER 2023
 * */

// The tutorial for Catch 1.x can be found at:
// https://github.com/catchorg/Catch2/blob/Catch1.x/docs/tutorial.md

// This tells Catch to provide a main() - do not remove
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "canvaslist.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////           SHAPES CLASS TEST CASES              ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("TEST_1 -CLASS SHAPES")
{

    Shape myShape;   // an instance of a shape object

    /// Section1 tests that default constructor accurately sets shapes x and y values to 0
    SECTION("Section 1--"
            "CREATE A SHAPE OBJECT WITH DEFAULT CONSTRUCTOR") {

        REQUIRE(myShape.getX() == 0);
        REQUIRE(myShape.getY() == 0);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section2 tests that an overloaded constructor that takes in two int parameters for x and y respectively
    /// Frame work assess that constructor accurately sets shapes x and y values arguments passed
    SECTION("Section 2--"
            "CREATE A SHAPE OBJECT WITH OVERLOADED CONSTRUCTOR") {

        Shape shape1(3, 5);  // call to overloaded constructor

        REQUIRE(shape1.getX() == 3);
        REQUIRE(shape1.getY() == 5);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section3 tests that copy () accurately sets shapes x and y values to match R.H.S object
    SECTION("Section 3--"
            "CREATE A SHAPE OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        Shape shape1(3, 5);
        Shape copyShape1;

        copyShape1 = shape1;      // copy data of shape1 to copyShape1

        REQUIRE(shape1.getX() == copyShape1.getX());
        REQUIRE(shape1.getY() == copyShape1.getY());
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section4 tests that copy() accurately returns a pointer to a newly created copy of the implicitly provided shape
    /// object which has identical members but different memory to the shape object copied
    SECTION("Section 4--"
            "CREATE A SHAPE OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        Shape shape1(3, 5);
        Shape *copyShape1;  // a ptr toa shape object

        copyShape1 = shape1.copy();    // copy data of shape1 to copyShape1

        REQUIRE(shape1.getX() == copyShape1->getX());
        REQUIRE(shape1.getY() == copyShape1->getY());
        REQUIRE(&shape1 != copyShape1);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section5 tests getX() and getY() accurately returns value of shape x and y respectively
    SECTION("Section 5--TEST getX()  && getY()") {
        Shape shape1(3, 5);

        REQUIRE(shape1.getX() == 3);
        REQUIRE(shape1.getY() == 5);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section6 tests setX() and setY() accurately returns value of shape x and y respectively
    SECTION("Section 6--TEST setX()  && setY() AFTER CONSTRUCTION") {
        Shape shape1(3, 5);  //constructed x and y value

        //adjusted x and y value
        shape1.setX(44);
        shape1.setY(55);


        REQUIRE(shape1.getX() != 3);
        REQUIRE(shape1.getY() != 5);

        REQUIRE(shape1.getX() == 44);
        REQUIRE(shape1.getY() == 55);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section7 tests printShape() accurately returns a string description of shape with expected x and y values
    SECTION("Section 7--TEST string printShape()") {
        Shape shape1(3, 5);  //constructed x and y value


        REQUIRE(shape1.printShape() == "It's a Shape at x: 3, y: 5");
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////           CIRCLE CLASS TEST CASES              ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("TEST_2 -CIRCLE CLASS")
{

    Circle myCircle;   // an instance of a Circle object

    /// Section1 tests that default constructor accurately sets Circle x, y, and radius values to 0
    SECTION("Section 1--"
            "CREATE A Circle OBJECT WITH DEFAULT CONSTRUCTOR") {

        REQUIRE(myCircle.getX() == 0);
        REQUIRE(myCircle.getY() == 0);
        REQUIRE(myCircle.getRadius() == 0);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section2 tests that an overloaded constructor that takes in 1 int parameters for  radius
    /// Frame work assess that constructor accurately sets circle radius value arguments passed
    SECTION("Section 2--"
            "CREATE A circle OBJECT WITH OVERLOADED CONSTRUCTOR") {

        Circle myCircle(7);  // call to overloaded constructor

        REQUIRE(myCircle.getRadius() == 7);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section3 tests that an overloaded constructor that takes in 3 int parameters for x, y , and radius respectively
    /// Frame work assess that constructor accurately sets circle x , y and radius values arguments passed
    SECTION("Section 3--"
            "CREATE A circle OBJECT WITH OVERLOADED CONSTRUCTOR") {

        Circle myCircle(3, 5,7);  // call to overloaded constructor

        REQUIRE(myCircle.getX() == 3);
        REQUIRE(myCircle.getY() == 5);
        REQUIRE(myCircle.getRadius() == 7);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section4 tests that copy () accurately sets circle x and y values to match R.H.S object
    SECTION("Section 4--"
            "CREATE A CIRCLE OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        Circle circle(3, 5,8);
        Circle copyCircle;

        copyCircle = circle;      // copy data of shape1 to copyShape1

        REQUIRE(circle.getX() == copyCircle.getX());
        REQUIRE(circle.getY() == copyCircle.getY());
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section5 tests that copy() accurately returns a pointer to a newly created copy of the implicitly provided shape
    /// object which has identical members but different memory to the shape object copied
    SECTION("Section 5--"
            "CREATE A SHAPE OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        Circle shape1(3, 5,7);
        Circle *copyShape1;  // a ptr to a circle object

        copyShape1 = shape1.copy();    // copy data of shape1 to copyShape1

        REQUIRE(shape1.getX() == copyShape1->getX());
        REQUIRE(shape1.getY() == copyShape1->getY());
        REQUIRE(shape1.getRadius() == copyShape1->getRadius());
        REQUIRE(&shape1 != copyShape1);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section6 tests getX(), getY() and getRadius() accurately returns value of shape x, y and Radius respectively
    SECTION("Section 6--TEST getX(), getY() && getRadius()") {
        Circle shape1(3, 5,9);

        REQUIRE(shape1.getX() == 3);
        REQUIRE(shape1.getY() == 5);
        REQUIRE(shape1.getRadius() == 9);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section7 tests setX(), setY() and setRadius()accurately
    SECTION("Section 7--TEST setX()  && setY() AFTER CONSTRUCTION") {
        Circle shape1(3, 5,6);  //constructed x and y value

        //adjusted x and y value
        shape1.setX(44);
        shape1.setY(55);
        shape1.setRadius(66);

        REQUIRE(shape1.getX() != 3);
        REQUIRE(shape1.getY() != 5);
        REQUIRE(shape1.getRadius() != 6);


        REQUIRE(shape1.getX() == 44);
        REQUIRE(shape1.getY() == 55);
        REQUIRE(shape1.getRadius() == 66);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section8 tests printShape() accurately returns a string description of Circle with expected x, y and radius
    SECTION("Section 8--TEST string printShape()") {
        Circle shape1(3,5, 5);  //constructed x and y value


        REQUIRE(shape1.printShape() == "It's a Circle at x: 3, y: 5, radius: 5");
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////           CIRCLE CLASS TEST CASES              ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////           REC CLASS TEST CASES              ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("TEST_3 -REC CLASS")
{

    Rect myRec;   // an instance of a RECTANGLE object

    /// Section1 tests that default constructor accurately sets rectangle x, y, width and height values to 0
    SECTION("Section 1--"
            "CREATE A RECTANGLE OBJECT WITH DEFAULT CONSTRUCTOR") {

        REQUIRE(myRec.getX() == 0);
        REQUIRE(myRec.getY() == 0);
        REQUIRE(myRec.getWidth() == 0);
        REQUIRE(myRec.getHeight() == 0);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section2 tests that an overloaded constructor that takes in 2 int parameters for  width and height
    /// Frame work assess that constructor accurately sets RECTANGLE width and height values arguments passed
    SECTION("Section 2--"
            "CREATE A RECTANGLE OBJECT WITH OVERLOADED CONSTRUCTOR") {

        Rect myRec(7,5);  // call to overloaded constructor

        REQUIRE(myRec.getWidth() == 7);
        REQUIRE(myRec.getHeight() == 5);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section3 tests that an overloaded constructor that takes in 4 int parameters for x, y , width and height resp.
    /// Frame work assess that constructor accurately sets RECTANGLE x , y and radius values arguments passed
    SECTION("Section 3--"
            "CREATE A RECTANGLE OBJECT WITH OVERLOADED CONSTRUCTOR") {

        Rect myRec(3, 5,7, 8);  // call to overloaded constructor

        REQUIRE(myRec.getX() == 3);
        REQUIRE(myRec.getY() == 5);
        REQUIRE(myRec.getWidth() == 7);
        REQUIRE(myRec.getHeight() == 8);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section4 tests that copy () accurately sets RECTANGLE x, y, width and height  values to match R.H.S object
    SECTION("Section 4--"
            "CREATE A RECTANGLE OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        Rect myRec(3, 5,8,10);
        Rect copyRec;

        copyRec = myRec;      // copy data of myRec to copyRec

        REQUIRE(copyRec.getX() == myRec.getX());
        REQUIRE(copyRec.getY() == myRec.getY());
        REQUIRE(copyRec.getWidth() == myRec.getWidth());
        REQUIRE(copyRec.getHeight() == myRec.getHeight());

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section5 tests that copy() accurately returns a pointer to a newly created copy of the implicitly provided shape
    /// object which has identical members but different memory to the shape object copied
    SECTION("Section 5--"
            "CREATE A RECTANGLE OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        Rect shape1(3, 5,7,6);
        Rect *copyShape1;  // a ptr to a circle object

        copyShape1 = shape1.copy();    // copy data of shape1 to copyShape1

        REQUIRE(shape1.getX() == copyShape1->getX());
        REQUIRE(shape1.getY() == copyShape1->getY());
        REQUIRE(shape1.getWidth() == copyShape1->getWidth());
        REQUIRE(shape1.getHeight() == copyShape1->getHeight());

        REQUIRE(&shape1 != copyShape1);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section6 tests getX(), getY(), getWidth() and getHeight() accurately returns value of RECTANGLE x, y,w ,h resp.
    SECTION("Section 6--TEST getX(), getY(), getWidth() and getHeight()") {
        Rect shape1(3, 5,9, 16);

        REQUIRE(shape1.getX() == 3);
        REQUIRE(shape1.getY() == 5);
        REQUIRE(shape1.getWidth() == 9);
        REQUIRE(shape1.getHeight() == 16);


    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section7 tests setX(), setY() getWidth() and getHeight() accurately
    SECTION("Section 7--TEST setX(), setY(),  getWidth() and getHeight()AFTER CONSTRUCTION") {
        Rect shape1(3, 5,6, 7);  //constructed x and y value

        //adjusted x and y value
        shape1.setX(44);
        shape1.setY(55);
        shape1.setWidth(66);
        shape1.setHeight(77);


        REQUIRE(shape1.getX() != 3);
        REQUIRE(shape1.getY() != 5);
        REQUIRE(shape1.getWidth() != 6);
        REQUIRE(shape1.getHeight() != 7);


        REQUIRE(shape1.getX() == 44);
        REQUIRE(shape1.getY() == 55);
        REQUIRE(shape1.getWidth() == 66);
        REQUIRE(shape1.getHeight() == 77);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section8 tests printShape() accurately returns a string description of RECTANGLE with expected x, y,w and h
    SECTION("Section 8--TEST string printShape()") {
        Rect shape1(3,5, 10,5);  //constructed shape


        REQUIRE(shape1.printShape() == "It's a Rectangle at x: 3, y: 5 with width: 10 and height: 5");
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////           REC CLASS TEST CASES            /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////         Right Triangle CLASS TEST CASES CLASS TEST CASES       //////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("TEST_4 -Right Triangle CLASS")
{

    RightTriangle myTri;   // an instance of a RightTriangle object

    /// Section1 tests that default constructor accurately sets RightTriangle x, y, base and height values to 0
    SECTION("Section 1--"
            "CREATE A RightTriangle OBJECT WITH DEFAULT CONSTRUCTOR") {

        REQUIRE(myTri.getX() == 0);
        REQUIRE(myTri.getY() == 0);
        REQUIRE(myTri.getBase() == 0);
        REQUIRE(myTri.getHeight() == 0);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section2 tests that an overloaded constructor that takes in 2 int parameters for  base and height
    /// Frame work assess that constructor accurately sets RightTriangle width and height values arguments passed
    SECTION("Section 2--"
            "CREATE A RightTriangle OBJECT WITH OVERLOADED CONSTRUCTOR") {

        RightTriangle myTri(7,5);  // call to overloaded constructor

        REQUIRE(myTri.getBase() == 7);
        REQUIRE(myTri.getHeight() == 5);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section3 tests that an overloaded constructor that takes in 4 int parameters for x, y , base and height resp.
    /// Frame work assess that constructor accurately sets RightTriangle x , y and radius values arguments passed
    SECTION("Section 3--"
            "CREATE A RECTANGLE OBJECT WITH OVERLOADED CONSTRUCTOR") {

        RightTriangle myTri(3, 5,7, 8);  // call to overloaded constructor

        REQUIRE(myTri.getX() == 3);
        REQUIRE(myTri.getY() == 5);
        REQUIRE(myTri.getBase() == 7);
        REQUIRE(myTri.getHeight() == 8);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section4 tests that copy () accurately sets RightTriangle x, y, base and height  values to match R.H.S object
    SECTION("Section 4--"
            "CREATE A RightTriangle OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        RightTriangle myTri(3, 5,8,10);
        RightTriangle copyTri;

        copyTri = myTri;      // copy data of myTri to copyTri

        REQUIRE(copyTri.getX() == myTri.getX());
        REQUIRE(copyTri.getY() == myTri.getY());
        REQUIRE(copyTri.getBase() == myTri.getBase());
        REQUIRE(copyTri.getHeight() == myTri.getHeight());

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section5 tests that copy() accurately returns a pointer to a newly created copy of the implicitly provided shape
    /// object which has identical members but different memory to the shape object copied
    SECTION("Section 5--"
            "CREATE A RightTriangle OBJECT WITH COPY ASSIGNMENT OPERATOR") {
        RightTriangle shape1(3, 5,7,6);
        RightTriangle *copyShape1;  // a ptr to a circle object

        copyShape1 = shape1.copy();    // copy data of shape1 to copyShape1

        REQUIRE(shape1.getX() == copyShape1->getX());
        REQUIRE(shape1.getY() == copyShape1->getY());
        REQUIRE(shape1.getBase() == copyShape1->getBase());
        REQUIRE(shape1.getHeight() == copyShape1->getHeight());

        REQUIRE(&shape1 != copyShape1);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section6 tests getX(), getY(), getBase() and getHeight() accurately returns value of RECTANGLE x, y,w ,h resp.
    SECTION("Section 6--TEST getX(), getY(), getaBase() and getHeight()") {
        RightTriangle shape1(3, 5,9, 16);

        REQUIRE(shape1.getX() == 3);
        REQUIRE(shape1.getY() == 5);
        REQUIRE(shape1.getBase() == 9);
        REQUIRE(shape1.getHeight() == 16);


    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section7 tests setX(), setY() getBase() and getHeight() accurately
    SECTION("Section 7--TEST setX(), setY(),  getBase() and getHeight() AFTER CONSTRUCTION") {
        RightTriangle shape1(3, 5,6, 7);  //constructed x and y value

        //adjusted x and y value
        shape1.setX(44);
        shape1.setY(55);
        shape1.setBase(66);
        shape1.setHeight(77);


        REQUIRE(shape1.getX() != 3);
        REQUIRE(shape1.getY() != 5);
        REQUIRE(shape1.getBase() != 6);
        REQUIRE(shape1.getHeight() != 7);


        REQUIRE(shape1.getX() == 44);
        REQUIRE(shape1.getY() == 55);
        REQUIRE(shape1.getBase() == 66);
        REQUIRE(shape1.getHeight() == 77);

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section8 tests printShape() accurately returns a string description of RightTriangle with expected x, y,w && h
    SECTION("Section 8--TEST string printShape()") {
        RightTriangle shape1(3,5, 10,5);  //constructed shape


        REQUIRE(shape1.printShape() == "It's a Right Triangle at x: 3, y: 5 with base: 10 and height: 5");
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////      Right Triangle CLASS TEST CASES      /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////             CANVAS CLASS TEST CASES              /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("TEST_5 -CANVASLIST CLASS")
{
    CanvasList myCanvas;   // an instance of a CanvasList object

    Shape *a = new Shape();
    Shape *b = new Shape(1,2);

    Shape *c = new Circle(4);
    Shape *d = new Circle(1,2,3);

    Shape *e = new Rect();



    /// Section1 tests default constructor accurately sets listFront && listTail to nullptr and listSize to 0
    SECTION("Section 1--"
            "CREATE A CLASS OBJECT WITH DEFAULT CONSTRUCTOR"){

        REQUIRE(myCanvas.front() == nullptr);
        REQUIRE(myCanvas.back() == nullptr);
        REQUIRE(myCanvas.size() == 0);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section2 tests the push_front() accurately sets newShape to front of an empty CanvasList,
    /// listFront points to newShapeNode and listSize is incremented
    SECTION("Section 2--"
            "TEST THAT NEW SHAPE IS ADDED TO FRONT OF EMPTY LIST"){
        Shape* shapeG = new Shape(10,5); //newShape
        myCanvas.push_front(shapeG);

        REQUIRE(myCanvas.front() != nullptr);   //verify that canvas is no longer empty
        REQUIRE(myCanvas.front()->value == shapeG); //verify that canvas has new shape at front of list
        REQUIRE(myCanvas.size() == 1);  //verify that canvas size was incremented

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section3 tests the push_front() accurately sets newShape to front of the CanvasList,
    /// listFront points to newShapeNode and listSize is incremented
    SECTION("Section 3--"
            "TEST THAT NEW SHAPE IS ADDED TO FRONT OF NON_EMPTY LIST"){

        myCanvas.push_front(a);     //newShape in canvas

        myCanvas.push_front(b);  //newShape in canvas

        REQUIRE(myCanvas.front()->value != a);   //verify that canvas is no longer empty
        REQUIRE(myCanvas.front()->value == b); //verify that canvas has new shape at front of list
        REQUIRE(myCanvas.size() == 2);  //verify that canvas size was incremented

        // clear canvas
        myCanvas.clear();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section4 tests  the push_back() accurately sets newShape to end of empty CanvasList,
    /// listTail points to newShapeNode and listSize is incremented
    SECTION("Section 4--"
            "TEST THAT NEW SHAPE IS ADDED TO END OF EMPTY LIST"){

        myCanvas.push_back(a);  //push shape a to end of list

        REQUIRE(myCanvas.back()->value != nullptr);   //verify that canvas is no longer empty
        REQUIRE(myCanvas.back()->value == a); //verify that canvas has new shape at end of list
        REQUIRE(myCanvas.size() == 1);  //verify that canvas size was incremented

        // clear canvas
        myCanvas.clear();
    }

    /// Section5 tests  the push_back() accurately sets newShape to end of the CanvasList,
    /// listTail points to newShapeNode and listSize is incremented
    SECTION("Section 5--"
            "TEST THAT NEW SHAPE IS ADDED TO FRONT OF NON_EMPTY LIST"){

        myCanvas.push_back(a);  //push shape a to end of list

        myCanvas.push_back(b);  //push shape b to end of list

        REQUIRE(myCanvas.back()->value != a);   //verify that canvas is no longer empty
        REQUIRE(myCanvas.back()->value == b); //verify that canvas has new shape at end of list
        REQUIRE(myCanvas.size() == 2);  //verify that canvas size was incremented

        // clear canvas
        myCanvas.clear();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section6 tests the pop_front() accurately deletes shapeNode from a one list CanvasList,
    /// CanvasList size should become 0, and data members pointers are nullptr
    SECTION("Section 6--"
            "TEST CHECKS POP_FRONT() ON A ONE LIST CanvasList"){

        myCanvas.push_back(a);  //push shape a to end of list

        delete myCanvas.pop_front(); // delete only node in list (delete pointer to shape to avoid memory loss)

        REQUIRE(myCanvas.front() == nullptr);   //verify that canvas is no longer empty
        REQUIRE(myCanvas.back() == nullptr); //verify that canvas has new shape at end of list
        REQUIRE(myCanvas.size() == 0);  //verify that canvas size was incremented

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section7 tests the pop_front() accurately deletes shapeNode from a 2 list CanvasList,
    /// CanvasList size should become 1, and data members pointers are nullptr
    SECTION("Section 7--"
            "TEST CHECKS POP_FRONT() ON A CanvasList WITH MORE THAN ONE ShapeNode (2 NODES)"){

        myCanvas.push_back(a);      // push shape a to end of list ---size = 1
        myCanvas.push_back(b);      // push shape a to end of list ---size = 2

        myCanvas.pop_front();       // delete only node at front in list

        REQUIRE(myCanvas.front() != nullptr);   // verify that canvas is no not empty
        REQUIRE(myCanvas.back() != nullptr);    // verify that canvas is no not empty
        REQUIRE(myCanvas.size() == 1);          // verify that canvas size was is decreased by 1

        //clear list
        myCanvas.clear();

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section8 tests the pop_back() accurately deletes shapeNode from a one list CanvasList,
    /// CanvasList size should become 0, and data members pointers are nullptr
    SECTION("Section 8--"
            "TEST CHECKS POP_BACK() ON A ONE LIST CanvasList"){

        myCanvas.push_back(a);  //push shape a to end of list

        delete myCanvas.pop_back(); // delete only node in list (delete pointer to shape to avoid memory loss)

        REQUIRE(myCanvas.front() == nullptr);    //  verify that canvas is empty
        REQUIRE(myCanvas.back() == nullptr);    //  verify that canvas end of list is empty
        REQUIRE(myCanvas.size() == 0);          // verify that canvas size was decremented

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section9 tests the pop_back() accurately deletes shapeNode from a 2 list CanvasList,
    /// CanvasList size should become 1, and data members pointers are nullptr
    SECTION("Section 9--"
            "TEST CHECKS POP_FRONT() ON A 2 LIST CanvasList"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape a to end of list

        myCanvas.pop_back(); // delete only node in list (delete pointer to shape to avoid memory loss)

        REQUIRE(myCanvas.front() != nullptr);    //  verify that canvas is empty
        REQUIRE(myCanvas.back()->value == a);    //  verify that canvas end of list is empty
        REQUIRE(myCanvas.size() == 1);          // verify that canvas size was decremented


        //clear list
        myCanvas.clear();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section10 tests the DELETEALLNODE() accurately deletes all shapeNode from CanvasList,
    /// CanvasList size should become 0, and data members pointers are nullptr
    /// Function is used by CLEAR() &&  CLEAR() is called by the destructor in CanvasList Class
    SECTION("Section 10--"
            "TEST CLEAR() ON  CanvasList WITH SIZE GREATER THAN 1"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape a to end of list
        myCanvas.push_back(c);  //push shape a to end of list
        myCanvas.push_back(d);  //push shape a to end of list

        myCanvas.clear();       //clear list

        REQUIRE(myCanvas.front() == nullptr);    //  verify that canvas is empty
        REQUIRE(myCanvas.back() == nullptr);    //  verify that canvas end of list is empty
        REQUIRE(myCanvas.size() == 0);          // verify that canvas size was decremented

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section11 tests the clear() accurately deletes all shapeNode from CanvasList,
    /// CanvasList size should become 0, and data members pointers are nullptr
    /// clear() is called by the destructor in CanvasList Class
    ///    -Function calls the DELETEALLNODES()
    SECTION("Section 11--"
            "TEST CLEAR() ON 1 LIST CanvasList"){

        myCanvas.push_back(a);  //push shape a to end of list

        myCanvas.clear();       //clear list

        REQUIRE(myCanvas.front() == nullptr);    //  verify that canvas is empty
        REQUIRE(myCanvas.back() == nullptr);    //  verify that canvas end of list is empty
        REQUIRE(myCanvas.size() == 0);          // verify that canvas size was decremented

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section12 tests the clear() accurately deletes all shapeNode from CanvasList,
    /// CanvasList size should become 0, and data members pointers are nullptr
    /// clear() is called by the destructor in CanvasList Class
    ///    -Function calls the DELETEALLNODES()
    SECTION("Section 12--"
            "TEST CLEAR() ON  CanvasList WITH SIZE GREATER THAN 1 (SIZE 2)"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape a to end of list

        myCanvas.clear();       //clear list

        REQUIRE(myCanvas.front() == nullptr);    //  verify that canvas is empty
        REQUIRE(myCanvas.back() == nullptr);    //  verify that canvas end of list is empty
        REQUIRE(myCanvas.size() == 0);          // verify that canvas size was decremented

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section13 tests the clear() accurately deletes all shapeNode from CanvasList,
    /// CanvasList size should become 0, and data members pointers are nullptr
    /// clear() is called by the destructor in CanvasList Class
    ///    -Function calls the DELETEALLNODES()
    SECTION("Section 13--"
            "TEST CLEAR() ON  CanvasList WITH SIZE GREATER THAN 1"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        myCanvas.clear();       //clear list

        REQUIRE(myCanvas.front() == nullptr);    //  verify that canvas is empty
        REQUIRE(myCanvas.back() == nullptr);    //  verify that canvas end of list is empty
        REQUIRE(myCanvas.size() == 0);          // verify that canvas size was decremented

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section14 tests the FRONT() accurately returns a pointer to the shape at the front of a CanvasList
    SECTION("Section 14--"
            "TEST FRONT() ON CanvasList WITH SIZE > 1"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list


        REQUIRE(myCanvas.front()->value == a);    //  verify that canvas is empty
        myCanvas.clear();       //clear list
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section15 tests the BACK() accurately returns a pointer to the shape at the end of a CanvasList
    SECTION("Section 15--"
            "TEST BACK() ON CanvasList WITH SIZE > 1"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        REQUIRE(myCanvas.back()->value == d);    //  verify that canvas end of list is empty

        myCanvas.clear();       //clear list
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section16 tests the CanvasList(const CanvasList &) accurately creates a deep copy of Canvas object
    SECTION("Section 16--"
            "TEST CanvasList(const CanvasList &) ON  CanvasList WITH SIZE GREATER THAN 1"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        CanvasList *copyThis = new CanvasList(myCanvas);

        REQUIRE(myCanvas.front() != copyThis->front());   //  verify that copyThis has a different pointer from myCanvas

        //  verify both canvas have the same shape*
        REQUIRE(myCanvas.back()->value->printShape() == copyThis->back()->value->printShape());
        REQUIRE(myCanvas.size() == copyThis->size());          // verify that canvas size == copyThis size

        myCanvas.clear();       //clear list
        copyThis->clear();

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section17 tests insertAfter(int, Shape *) accurately a shapeNode with shape* after specified index
    SECTION("Section 17--"
            "TEST insertAfter(int, Shape *) ON CanvasList WITH SIZE GREATER THAN 1"){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        myCanvas.insertAfter(2,e);  // insert shape e at index 3 (after 2, and pushing former shape at index 3 right)

        REQUIRE(myCanvas.shapeAt(3)->printShape() == e->printShape());  //verify newShape is inserted at index 2

        myCanvas.clear();       //clear list

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section18 tests bool isempty() accurately if a CanvasList is empty
    SECTION("Section 18--TEST bool isempty() "){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        CanvasList emptyCanvas;     // an empty canvas


        REQUIRE(emptyCanvas.isempty() == 1);
        REQUIRE(myCanvas.isempty() == 0);

        myCanvas.clear();       //clear list

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section19 tests int size() accurately returns CanvasList current size
    SECTION("Section 19--TEST int size() "){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        CanvasList emptyCanvas;     // an empty canvas


        REQUIRE(emptyCanvas.size() == 0);
        REQUIRE(myCanvas.size() == 4);

        myCanvas.clear();       //clear list

    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section20 tests int find(x,y) accurately returns the index of the first shape with matching x and y
    /// if shape is non-existence returns -1
    /// Function returns a the index to the shape in the CanvasList if found or a -1 is search is unsuccessful
    SECTION("Section 20--TEST  int find(x,y) "){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list


        REQUIRE(myCanvas.find(1,2) == 1);
        REQUIRE(myCanvas.find(10,22) == -1);

        myCanvas.clear();       //clear list

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section21 tests draw() accurately prints CanvasList shapes descriptions as a string
    /// function calls the printShape() of the shapes in the list
    SECTION("Section 21--TEST draw() "){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        ///*****FUNCTION IS A VOID_(NO REQUIRED TEST_CASE)
        ///***OUTPUT WAS VALIDATED BY DIRECT INSPECTION ON CONSOLE

        myCanvas.clear();       //clear list

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section22 tests PrintAddresses() accurately prints CanvasList Node addresses and Shape* addresses
    SECTION("Section 22--TEST PrintAddresses "){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        ///*****FUNCTION IS A VOID_(NO REQUIRED TEST_CASE)
        ///***OUTPUT WAS VALIDATED BY DIRECT INSPECTION ON CONSOLE

        myCanvas.clear();       //clear list

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// Section23 tests swap() accurately modifies the std::swap() to swap 2 CanvasList objects contents
    SECTION("Section 23--TEST swap() "){

        myCanvas.push_back(a);  //push shape a to end of list
        myCanvas.push_back(b);  //push shape b to end of list
        myCanvas.push_back(c);  //push shape c to end of list
        myCanvas.push_back(d);  //push shape d to end of list

        CanvasList emptyCanvas;     // an empty canvas

        swap(emptyCanvas, myCanvas);  //swap objects data member

        REQUIRE(emptyCanvas.size() == 4);
        REQUIRE(myCanvas.size() == 0);

        REQUIRE(emptyCanvas.shapeAt(1)->printShape() == "It's a Shape at x: 1, y: 2");
        REQUIRE(myCanvas.front() == nullptr);

        REQUIRE(emptyCanvas.back()->value->printShape() == "It's a Circle at x: 1, y: 2, radius: 3");
        REQUIRE(myCanvas.back() == nullptr);

        //clear list
        myCanvas.clear();
        emptyCanvas.clear();
    }

    myCanvas.clear();


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////             CANVAS CLASS TEST CASES              /////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

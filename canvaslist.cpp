/**
G++ SYSTEM
COURSE: CS251 DATA STRUCTURES- FALL 2022/2023
        University of Illinois Chicago
PROJECT TITLE: Shapes and CanvasList
Author: MICAH OREOLUWA OLUGBAMILA

DATE:  14TH OCTOBER 2023
 * */
#include "canvaslist.h"

/// default constructor -sets listSize to 0, listFront to points to NULL and
/// listTail to points to NULL. Constructor takes in no arguments and has no
/// return type
CanvasList ::CanvasList() {
    listSize = 0;
    listFront = nullptr;
    listTail = nullptr;
}

/// Function is a copy constructor that creates a deep copy of implicitly
/// provided Canvas object Function takes in a const reference to a canvas
/// object, allocates memory for listFront and listTail Function has no return type
CanvasList ::CanvasList(const CanvasList &copyCanvas) {

    // initialise listFront && listTail to nullptr && listSize to 0
    this->listFront = nullptr;
    this->listTail = nullptr;
    this->listSize = 0;
    // check if Canvas List has at least one ShapeNode*
    if (!copyCanvas.listFront) {
        return;
    }

    // create temp variable to traverse through list && another to save next node
    ShapeNode *curr = copyCanvas.listFront;
    // iterate while curr is not NULL
    while (curr) {
        ShapeNode *newNode = new ShapeNode; // allocate memory for new ShapeNode
        newNode->value = curr->value->copy();       // copy value
        newNode->next = nullptr;            // assume no next ptr

        // if listFront has not been set, initialize
        if (!this->listFront) {
            this->listFront = newNode;
        }

        // if we had a previous node, its next is the curr node now
        if (this->listTail) {
            this->listTail->next = newNode;
        }

        // update listTail to curr node
        this->listTail = newNode;

        // update loop iterator
        curr = curr->next;
    }

    this->listSize = copyCanvas.listSize; // copyOver listSize
}

/// Function is a copy assignment operator that creates a deep copy of a Canvas
/// object passed as a const parameter Function takes in a const reference to a
/// canvas object, allocates memory for listFront and listTail Function has
/// returns the address of the object copied
CanvasList &CanvasList ::operator=(const CanvasList &copyCanvas) {
    // do not self-assign
    if (this != &copyCanvas) {
        this->clear();

        CanvasList temp(copyCanvas); // calls the CanvasList copy constructor

        swap(*this,temp); // uses a modified version of the swap function in std::swap

        temp.clear();
    }
    return *this;
}

/// Makes swap between two CanvasList objects
void CanvasList ::swap(CanvasList &swapThis, CanvasList &withThis) {
    using std ::swap; // Import the std::swap function

    // Swap the listFront pointers
    swap(swapThis.listFront, withThis.listFront);

    // Swap the listTail pointers
    swap(swapThis.listTail, withThis.listTail);

    // Swap the listSize values
    swap(swapThis.listSize, withThis.listSize);
}

/// Function deletes a linkedList starting from the head
void CanvasList ::deleteAllNodes(ShapeNode *del) {

    while (del) {
        ShapeNode *next = del->next;

        delete del->value;
        delete del;

        del = next;
    }
}

/// Function releases all allocations of memory (all Nodes and their internal
/// Shapes) Function has no parameter and has no return type
void CanvasList ::clear() {

    deleteAllNodes(this->listFront); // function call to deleteNode
    this->listFront = nullptr;
    this->listTail = nullptr;
    this->listSize = 0;
}

/// CanvasList destructor
CanvasList ::~CanvasList() {
    clear();
}

/// Function returns an int which is the size of the CanvasList
/// Function has no parameter
int CanvasList ::size() const { return listSize; }

/// Function creates a new ShapeNode and adds it to the front of the List
/// Function has one Shape ptr object and has no return type
void CanvasList ::push_front(Shape *newShape) {

    // create newNode
    ShapeNode *newNode = new ShapeNode; // static memory of a newNode
    newNode->value = newShape;
    newNode->next = nullptr;

    // if CanvasList is empty add newNode to listFront
    if (!listFront) {
        // adjust private members accordingly
        listFront = newNode;
        listTail = newNode;

    }
        // if list has a listFront, add newNode before listFront
    else {
        newNode->next = listFront; // newNode now point to previous listFront

        listFront = newNode; // update listFront
    }

    listSize++; // increase canvasList size
}

/// Function creates a new ShapeNode and adds it to the back of the List
/// Function has one Shape ptr object and has no return type
void CanvasList ::push_back(Shape *newShape) {

    // create newNode
    ShapeNode *newNode = new ShapeNode; // static memory of a newNode
    newNode->value = newShape;
    newNode->next = nullptr;

    // if CanvasList is empty, add newNode to listFront
    if (!listFront) {
        // adjust private members accordingly
        listFront = newNode;
        listTail = newNode;

    }
        // if list has a listFront, add newNode before listFront
    else {

        listTail->next = newNode; // previous tail now points to newly added node

        listTail = newNode; // listTail is updated to point to newNode
    }

    listSize++; // increase canvasList size
}

/// Function inserts a new ShapeNode to the CanvasList and does nothing to the
/// list when the index is out of range Function has one int (index)  and a
/// Shape object ptr  (*newShape)parameters and has no return type Index is the
/// index position before the new ShapeNode, newShape is a pointer to the shape
/// object being added
void CanvasList ::insertAfter(int index, Shape *newShape) {
    // return without making modification if index is out of range
    if (index < 0 || index > (this->listSize - 1) || !listFront) {
        return;
    }

    // if newShape is being added after all present shapeNodes, push_back newShape
    if (index == (this->listSize - 1)) {
        this->push_back(newShape);
    }
        // add shape after user specified index
    else {
        // create a ShapeNode for new shape
        ShapeNode *newNode = new ShapeNode; // newNode of newShape
        newNode->value = newShape;          // newNode now points to newShape
        newNode->next = nullptr; // newNode next is assumed to point to null

        ShapeNode *curr = listFront; // node to traverse the list
        int count = 0;               // keeps track of index

        // traverse list until curr point to index
        while (curr && count < index) {
            curr = curr->next;
            count++;
        }

        ShapeNode *temp = curr->next; // save currentNode next
        curr->next = newNode;         // update curr next to point to newNode
        newNode->next = temp; // newNode next now points to curr previous next

        this->listSize++;
    }
}

/// Function removes the ShapeNode at the front  of the CanvasList if one exists
/// Function takes in no argument and returns either a nullptr or a pointer to
/// the shape being popped If node exists, it is released from memory but not
/// shape's memory is left untouched.
Shape *CanvasList ::pop_front() {
    // if list is empty, return a nullptr
    if (!listFront) {
        return nullptr;
    }

    ShapeNode *newFront = listFront->next; // save new listFront
    Shape *poppedShape = listFront->value; // save pointer to shape of node popped

    if(listSize == 1){

        delete listFront; // delete listFront

        listFront = nullptr;  // set listFront to nullptr
        listTail = nullptr;  // set listFront to nullptr
        listSize--; // reduce listSize

        return poppedShape;
    }

    delete listFront; // delete listFront

    listFront = newFront; // define new listFront

    listSize--; // reduce listSize
    return poppedShape;
}

/// Function removes the ShapeNode at the end of the CanvasList if one exists
/// Function takes in no argument and returns either a nullptr or a pointer to
/// the shape being popped If node exists, it is released from memory but not
/// shape's memory is left untouched.
Shape *CanvasList ::pop_back() {
    // if list is empty, return a nullptr
    if (!listFront) {
        return nullptr;
    }
    // handle case for one list item
    if (listFront == listTail) {
        Shape *poppedShape = listFront->value; // pointer to shape of node popped

        delete listFront;

        listFront = nullptr;
        listTail = nullptr;
        listSize = 0;

        return poppedShape;
    }

    Shape *poppedShape = listTail->value; // pointer to shape of node popped

    // Find new listTail
    //  to pop from behind, an iteration to end of the list is required
    ShapeNode *curr = listFront; // node to traverse through list
    ShapeNode *prev = nullptr;   // node before curr

    // set prev to node before end of list
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }

    delete listTail; // delete listTail

    listTail = prev;          // define new listTail
    listTail->next = nullptr; // set next to null

    listSize--; // reduce listSize
    return poppedShape;
}

/// Function removes a ShapeNode at user specified index
/// Function takes in an int parameter (index of node to be removed) and has no
/// return type Function makes calls to pop_front nad pop_back if index fits
/// function's description
void CanvasList ::removeAt(int index) {
    // if index is out of range return
    if (index > (listSize - 1) || index < 0 || !listFront) {
        return;
    }
        // if index is at front of list, call pop_front()
    else if (index == 0) {
         delete this->pop_front();
    }
        // if index is at end of list, call pop_back()
    else if (index == (listSize - 1)) {
        delete this->pop_back();
    }
        // iterate to specified index and remove node
    else {

        ShapeNode *curr = listFront; // node to traverse through list
        ShapeNode *prev = nullptr;   // node before curr
        int count = 0;               // keep track of index

        // find prev node to be deleted
        while (curr && count < index) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next; // point prev next one pass curr next

        delete curr->value;
        delete curr; // delete currNode

        listSize--; // reduce listSize
    }
}

/// Function removes nodes at every other index (odd index) with first removal
/// being index 1 Function has parameter and no return type Function makes call
/// to removeAt() with index to be removed
void CanvasList ::removeEveryOther() {
    // if list is empty  or if list has no other node return
    if (!listFront || listSize == 1) {
        return;
    }

    ShapeNode *curr = listFront; // node to traverse list
    int index = 1; // assuming a 1-based index for the nodes in the list
    int count = 1; // specifies if iteration is even or odd

    // iterate to end of list
    while (curr) {

        // Remove the node at index when count is even
        if (count % 2 == 0) {
            ShapeNode *next = curr->next; // save next node

            removeAt(index - 1); // call removeAt() with other index

            curr = next; // continue list iteration after deleted node
        }
            // if a node was not deleted
        else {
            curr = curr->next;
            index++;
        }

        count++;
    }
}

/// Function has no parameter and returns the private data member that points to the front of the list.
/// Function is a const referencing the inability to modify CanvasList structure
ShapeNode *CanvasList ::front() const {
    return listFront;
}


/// Function has no parameter and returns the private data member that points to
/// the front of the list. Function is a const referencing the inability to
/// modify CanvasList structure
ShapeNode *CanvasList ::back() const {
    return listTail;
}


/// Function searches through list to find the first shape with matching x and y
/// values Function has two int parameters (x and y ) and returns an int (index)
/// Function must return -1 for an unsuccessful finding
int CanvasList ::find(int x, int y) const {
    // if list is empty return -1
    if (!listFront) {
        return -1;
    }

    ShapeNode *curr = listFront; // ShapeNode to traverse CanvasList
    int index = 0;               // index of CanvasList

    // iterate to end of list
    while (curr) {
        // return index of shape if X and Y are identical
        if (curr->value->getX() == x && curr->value->getY() == y) {
            return index;
        }
        index++;
        curr = curr->next; // move to next node
    }

    return -1; // return -1 for unsuccessful find()
}

/// Function shapeAt() returns nullptr or a pointer to the shape at the given
/// linked list index.
Shape *CanvasList ::shapeAt(int index) const {
    // if list is empty or if index is out of range return
    if (!listFront || index > (listSize - 1) || index < 0) {
        return nullptr;
    }
        // if index is at front of list, call pop_front()
    else if (index == 0) {
        return listFront->value;
    }
        // if index is at end of list, call pop_back()
    else if (index == (listSize - 1)) {
        return listTail->value;
    }

    // iterate to specified index
    ShapeNode *curr = listFront; // ShapeNode to traverse CanvasList
    int count = 0;               // tracks index

    while (curr && count < index) {
        count++;
        curr = curr->next;
    }

    return curr->value;
}

/// Function returns a boolean of the CanvasList empty state
/// Function has no parameter and returns a bool
bool CanvasList ::isempty() const { return listFront == nullptr; }

/// Function prints the details of the shapes within the linked list
/// Function has no parameter and no return type
/// Function is a const indicating inability to modify CanvasList
void CanvasList ::draw() const {

    ShapeNode *curr = listFront; // ShapeNode to traverse CanvasList

    // iterate to end of list
    // shapes are accessed by shape* and are printed by calling necessary helper
    // functions
    while (curr) {
        cout << curr->value->printShape() << endl;
        curr = curr->next; // move to next node
    }
}

/// Function prints out the memory addresses of the ShapeNode as well as the
/// address of internal Shape Function has no parameter and no return type
/// Function is a const indicating inability to modify CanvasList
void CanvasList ::printAddresses() const {

    ShapeNode *curr = listFront; // ShapeNode to traverse CanvasList

    // iterate to end of list
    while (curr) {
        cout << "Node Address: " << curr << "\tShape Address: " << &(curr->value)
             << endl;
        curr = curr->next; // move to next node
    }
}

/**
G++ SYSTEM
COURSE: CS251 DATA STRUCTURES- FALL 2022/2023
        University of Illinois Chicago
PROJECT TITLE: SEARCH ENGINE
EDITED BY: MICAH OREOLUWA OLUGBAMILA
DATE:  14TH OCTOBER 2023
 * */


#pragma once

#include "shape.h"

using namespace std;

// ShapeNode class used as nodes in linked list
// implemented akin to a struct as all data is public
class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

// The CanvasList class implements the functionality of a linked list.
// This linked list can contain all types of Shape and its derived classes.
class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;
        ShapeNode *listTail;   // points to end of list



    public:
        CanvasList();
        CanvasList(const CanvasList &);
        CanvasList& operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();
        
        void insertAfter(int, Shape *);
        void push_front(Shape *);
        void push_back(Shape *);
        
        void removeAt(int);
        void removeEveryOther();
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const;
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const;
        
        void draw() const;
        void printAddresses() const;

        void swap(CanvasList &, CanvasList &);
        void deleteAllNodes(ShapeNode*);
        ShapeNode* back() const;
};

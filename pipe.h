// pipe.h
// Brian Cariddi

#include<cstdlib>
#include<iostream>
#include<time.h>
#include"gfx.h"

const int WD = 600;
const int HT = 400;
const int PIPEWD = 40; // width of the pipe
const int SPEED = 3; // speed that the pipe moves to the left

class Pipe{
    public:
        Pipe(); // default constructor
        ~Pipe(); // destructor
        void show(); // draws pipe
        void drawRect(int, int, int, int); // draws a rectangle
        void update(); // updates location of pipe
        int getX(); // returns location of the front edge of the pipe
        bool checkhit(int); // sees if the bird hit the pipe
    private:
        int x;
        int top; // y location of the edge of the top pipe
        int bottom; // y location of the edge of the bottom pipe
};
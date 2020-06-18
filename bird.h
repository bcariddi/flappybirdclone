// bird.h
// Brian Cariddi

#include<iostream>

const int WIDTH = 600; // width of screen
const int HEIGHT = 400; // height of screen
const int GRAVITY = 1; // force of gravity
const int R = 10; // radius of bird

class Bird{
    public:
        Bird(); // default constructor
        ~Bird(); // destructor
        int getX(); // returns x location
        int getY(); // returns y location
        double getVel(); // returns velocity
        void move(); // updates bird position
        void click(); // updates y acceleration and y velocity in response to click
    private:
        int xPosition;
        int yPosition;
        double yVelocity;
        double yAcceleration;
};
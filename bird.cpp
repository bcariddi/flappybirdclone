// bird.cpp
// Brian Cariddi

#include"bird.h"
#include"gfx.h"
#include<unistd.h>
using namespace std;

Bird::Bird(){
    xPosition = WIDTH / 3;
    yPosition = HEIGHT / 2;
    yVelocity = 0;
    yAcceleration = 0;
}

Bird::~Bird(){}

int Bird::getX() { return xPosition; }

int Bird::getY() { return yPosition; }

double Bird::getVel() {return yVelocity; }

void Bird::click(){
    yAcceleration = 0;
    yVelocity = -10*GRAVITY/2; // boosts the bird upwards
    gfx_flush();
}

void Bird::move(){
    usleep(4000);
    yAcceleration += GRAVITY/100.0;

    if(yAcceleration >= GRAVITY) yAcceleration = GRAVITY;

    yVelocity += yAcceleration;
    yPosition += yVelocity;
    
    if(yPosition >= HEIGHT - R){
        yPosition = HEIGHT - R;
        yVelocity = 0;
    }
    if(yPosition <= R){
        yPosition = R;
        yVelocity = 0;
    }

    gfx_flush();
}
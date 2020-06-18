// pipe.cpp
// Brian Cariddi

#include"pipe.h"
using namespace std;

Pipe::Pipe(){
    srand(time(0));
    top = rand() % HT / 2; // random value from 0 to half of height
    bottom = rand() % HT / 2 + (HT / 2); // random value from half of height height
    x = WD; // starts the pipe at the right edge of the screen
}


Pipe::~Pipe(){}

void Pipe::show(){
    gfx_color(24,63,192);
    drawRect(x, 0, x, top);
    drawRect(x, bottom, x, HT);
}

void Pipe::drawRect(int topleftx, int toplefty, int bottomleftx, int bottomlefty){
    gfx_line(topleftx, toplefty, bottomleftx, bottomlefty); // left edge
    gfx_line(topleftx, toplefty, topleftx + PIPEWD, toplefty); // top edge
    gfx_line(bottomleftx, bottomlefty, bottomleftx + PIPEWD, bottomlefty); // bottom edge
    gfx_line(topleftx + PIPEWD, toplefty, bottomleftx + PIPEWD, bottomlefty); // right
}

void Pipe::update(){
    x -= SPEED;
    show();
}

int Pipe::getX(){
    return x;
}

bool Pipe::checkhit(int birdY) { 
    // if the bird is higher than or equal to the height of the top edge, or
    // if the bird is lower than or equal to the height of the bottom edge, it has hit the pipe
    if(birdY - 10 <= top || birdY + 10 >= bottom) return true;
    return false;
}
// program.cpp
// Brian Cariddi
// Lab 13 - Flappy Bird

#include<iostream>
#include"gfx.h"
#include"bird.h"
#include"pipe.h"
#include<unistd.h>
using namespace std;

void showDeathScreen(Bird, Pipe, Pipe);

int main(){
    bool done = false; // keeps the game running
    bool start = false; // tells whether to go or not
    char c; // handles user input
    bool event = false; 
    bool kill = false; // if the bird has hit the floor, ceiling, or a pipe

    // opens window and clears to make it white
    gfx_open(WIDTH, HEIGHT, "Flappy Bird");
    gfx_clear_color(255,255,255);
    gfx_clear();

    // creates bird object and the two pipes (there are only ever two pipes)
    Bird bird = Bird();
    Pipe pipe1 = Pipe();
    Pipe pipe2 = Pipe();

    // runs until bird dies
    while(!done){
        gfx_clear();

        // draws bird
        gfx_color(0,0,0);
        gfx_circle(bird.getX(), bird.getY(), R);

        // generates a new pipe 2 when pipe 1 gets far enough down the screen, and pipe 2 is already off the screen
        if(pipe1.getX() == 2*WIDTH / 5){
            pipe2 = Pipe();
        }

        // generates a new pipe 1 when pipe 2 gets far enough down the screen, and pipe 1 is already off the screen
        if(pipe2.getX() == 2*WIDTH / 5){
            pipe1 = Pipe();
        }

        // draws pipes
        pipe1.show();
        pipe2.show();

        // lets game run update while waiting for a click
        if(gfx_event_waiting()){
            c = gfx_wait();
            if(c == 1)
                event = true;
        }

        if(event) { // if the user clicks, then execute click function and if the game hasn't started, tell it to start
            bird.click();
            start = true;
            event = false;
        }
        
        // if the user has started the game with a click
        if(start){
            // update the y location of the bird with gravity, velocity (x never changes)
            bird.move();

            // moves pipe 1 to the left
            pipe1.update();

            // checks if the bird should die when the bird is within the range of the pipe
            if(pipe1.getX() >= bird.getX() - R && pipe1.getX() <= bird.getX() + R){ // this checks the "front half"
                kill = pipe1.checkhit(bird.getY());
            }
            if(pipe1.getX() + PIPEWD >= bird.getX() - R && pipe1.getX() + PIPEWD <= bird.getX() + R){ // this checks the "back half"
                kill = pipe1.checkhit(bird.getY());
            }

            // moves pipe 2 
            pipe2.update();

            // checks if the bird should die when the bird is within the range of the pipe
            if(pipe2.getX() >= bird.getX() - R && pipe2.getX() <= bird.getX() + R){ // this checks the "front half"
                kill = pipe2.checkhit(bird.getY());
            }
            if(pipe2.getX() + PIPEWD >= bird.getX() - R && pipe2.getX() + PIPEWD <= bird.getX() + R){ // this checks the "back half"
                kill = pipe2.checkhit(bird.getY());
            }

            // if the bird hits the ceiling or the floor, kill it
            if(bird.getY() == HEIGHT - R || bird.getY() == R)
                kill = true;
            
            // if the bird should be killed, show the death screen
            if(kill){
                gfx_clear();
                showDeathScreen(bird, pipe1, pipe2);
                done = true;
            }
        }

        usleep(1000);
    }

    return 0;
}

void showDeathScreen(Bird bird, Pipe pipe1, Pipe pipe2){
    bool show = true; // infinite for loop

    // draws the death screen infinitely
    while(show){
        // draw dead bird
        gfx_color(0,0,0);
        gfx_circle(bird.getX(), bird.getY(), R);

        // draw stationary pipe 1
        pipe2.show();

        // draw stationary pipe 2 if it exists
        pipe1.show();

        // show death message
        gfx_color(256,0,0);
        gfx_text(WIDTH/2, HEIGHT/2, "YOU LOSE");
    }
}

#include "headers/ant.h"
Ant::Ant(int X, int Y) {
    x = X;
    y = Y;
    dir = 0;
}

void Ant::move(bool state) {
    if (state == false) {
        turnLeft();
    } else {
        turnRight();
    }
    if (dir == 0) {
        y -= 4;
    }
    if (dir == 1) {
        x += 4;
    }
    if (dir == 2) {
	y += 4;
    }
    if (dir == 3) {
	x -= 4;
    }
}

void Ant::turnLeft(void) {
    dir --;
    if (dir < 0) {
        dir = 3;
    }
}

void Ant::turnRight(void) {
    dir ++;
    if (dir > 3) {
        dir = 0;
    }
}

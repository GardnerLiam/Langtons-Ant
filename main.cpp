#include <SFML/Graphics.hpp>

#include "headers/ant.h"
#include "headers/pixelArray.h"
#include "headers/application.h"

int main() {

    int width = 640;
    int height = 480;
    int FPS = 30;

    Application window(width, height, "Langton's Ant");
    window.limitFPS(FPS);

    PixelArray pixelArray(width, height);

    Ant ant(width/2, height/2);

    while (window.isRunning) {

        window.checkCloseState();

        bool curState = false;

        int index = ant.y * width + ant.x;

        if (pixelArray.pixels[index] == 0) {
            curState = true;
        }

        ant.move(curState);

        if (pixelArray.pixels[index] == 0) {
            pixelArray.pixels[index] = 255;
            pixelArray.pixels[index+1] = 255;
            pixelArray.pixels[index+2] = 255;
            pixelArray.pixels[index+3] = 255;
            pixelArray.update();
        } else {
            pixelArray.pixels[index] = 255;

            pixelArray.pixels[index] = 0;
            pixelArray.pixels[index+1] = 0;
            pixelArray.pixels[index+2] = 0;
            pixelArray.pixels[index+3] = 255;
            pixelArray.update();
        }

        window.update(pixelArray.sprite);
    }

    window.terminate();

    return 0;
}

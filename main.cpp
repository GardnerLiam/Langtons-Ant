#include <SFML/Graphics.hpp>
#include "headers/ant.h"
#include "headers/pixelArray.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(400,400), "Langton's Ant");

    PixelArray pixelArray(400,400);

    Ant ant(120,120);

    window.setFramerateLimit(30);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        bool curState = false;

        int index = ant.y * 400 + ant.x;

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

        window.clear();
        window.draw(pixelArray.sprite);
        window.display();
    }
    return 0;
}

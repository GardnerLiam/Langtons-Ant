#include "headers/pixelArray.h"
PixelArray::PixelArray(int w, int h) {
    width = w;
    height = h;
    pixels = new sf::Uint8[width*height*4];
    texture.create(width, height);
    sprite.setTexture(texture);

    for (int i = 0; i < width*height*4; i+=4) {
        pixels[i] = 255;
        pixels[i+1] = 255;
        pixels[i+2] = 255;
        pixels[i+3] = 255;
    }
    texture.update(pixels);
}
void PixelArray::update(void){
	texture.update(pixels);
}

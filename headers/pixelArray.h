#include <SFML/Graphics.hpp>

class PixelArray {
public:
	int width;
	int height;
	sf::Uint8* pixels;
	sf::Texture texture;
	sf::Sprite sprite;

	PixelArray(int w, int h);
	void update(void);
};

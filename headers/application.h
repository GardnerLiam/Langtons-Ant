#include <SFML/Graphics.hpp>
#include <iostream>
class Application {
public:
    int width;
    int height;
    std::string title;
    bool isRunning;
    int fps;

    sf::RenderWindow window;

    Application(int w, int h, std::string t);
    void checkCloseState();
    void update(sf::Sprite sprite);
    void limitFPS(int limit);
    void terminate();
};

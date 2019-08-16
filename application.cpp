#include "headers/application.h"
Application::Application(int w, int h, std::string t) {
    width = w;
    height = h;
    title = t;
    window.create(sf::VideoMode(w, h), t);

    isRunning = true;
}


void Application::checkCloseState() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;


        }
    }

}

void Application::limitFPS(int limit) {
    fps = limit;
    window.setFramerateLimit(fps);
}

void Application::update(sf::Sprite sprite) {
    window.clear();
    window.draw(sprite);
    window.display();
}

void Application::terminate() {
    window.close();
}

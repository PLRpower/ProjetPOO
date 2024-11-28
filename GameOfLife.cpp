#include "GameOfLife.h"

GameOfLife::GameOfLife() : window(VideoMode(Grid::getWindowWidth(), Grid::getWindowHeight()), "Jeu de la vie") {
    window.setFramerateLimit(60);
}

void GameOfLife::run() {
    while(window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void GameOfLife::handleEvents() {
    Event event;
    while(window.pollEvent(event)) {
        if(event.type == Event::Closed)
            window.close();
    }
}

void GameOfLife::update() {
    if(clock.getElapsedTime().asMilliseconds() >= 100) {
        grid.update();
        clock.restart();
    }
}

void GameOfLife::render() {
    window.clear(Color::Black);
    grid.render(window);
    window.display();
}
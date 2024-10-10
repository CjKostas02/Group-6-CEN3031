#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Application {
private:
    // login window
    sf::RenderWindow* window;
    sf::Font font;
    std::map<std::string, sf::Sprite>* textures;

public:
    // main driver
    void run();

    // helper function for updating loginWindow
    void updateLoginWindow();
    void loadTextures();

    // default constructor
    Application();
};



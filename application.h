#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class TextBox{
private:
    // text variable and rectangle object
    std::string boxText = "";
    sf::RectangleShape rect;

public:
    // button selected boolean
    bool selected = false;

    // setter
    void setPosition(float x, float y);
    void setColor(sf::Color color);

    // getter
    sf::RectangleShape getRect();

    // default constructor
    TextBox();
};


class Application {
private:
    // fonts
    sf::Font titleFont;
    sf::Font textFont;

    // application state: 0 for login screen, 1 for main application, 2 for create account
    int applicationState = 0;
    sf::RenderWindow* window;
    std::map<std::string, sf::Sprite>* textures;
    std::map<std::string, TextBox*> textBoxes;

public:
    // main driver prototype
    void run();

    // helper function prototypes for updating loginWindow
    void renderLoginWindow();
    void loadItems();

    // default constructor
    Application();
};





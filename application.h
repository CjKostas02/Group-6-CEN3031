#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

class Button{
private:
    // variables
    std::string buttonText;
    sf::Text buttonRenderText;
    sf::RectangleShape hitBox;

public:
    // setter function prototypes
    void setPosition(float x, float y);
    void setHitbox(sf::RectangleShape inputHitbox);

    // getter function prototypes
    std::string getText();
    sf::Text getRenderText();
    sf::RectangleShape getHitbox();

    // constructor
    Button(sf::Text inputText);
};


class TextBox{
private:
    // variables
    std::string boxText;
    sf::Text boxRenderText;
    sf::RectangleShape rect;

public:
    // button selected boolean
    bool selected = false;

    // setter function prototypes
    void setPosition(float x, float y);
    void setColor(sf::Color color);
    void addChar(char character);
    void backspace();

    // getter function prototypes
    sf::Text getRenderText();
    std::string getText();
    sf::RectangleShape getRect();

    // constructor
    TextBox(sf::Text inputRenderText);
};


class Application {
private:
    // fonts
    sf::Font titleFont;
    sf::Font textFont;

    // application state: 0 for login screen, 1 for main application, 2 for create account
    int applicationState = 0;
    sf::RenderWindow* window;
    std::map<std::string, std::map<std::string, Button*>> buttons;
    std::map<std::string, std::map<std::string, TextBox*>> textBoxes;

    std::vector<char> characters;

public:
    // window driver prototypes
    void runLogin();
    void runCreateAcc();

    // function prototypes for updating loginWindow
    void renderLoginWindow();
    void renderCreateAccWindow();
    void loadItems();

    // constructor
    Application();
};

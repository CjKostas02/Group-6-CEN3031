#pragma once
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

class Button{
private:
    // variables
    std::string buttonText;
    sf::RectangleShape hitBox;
    sf::Text buttonRenderText;

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
    std::string type;
    std::string boxText;
    sf::Text boxRenderText;
    sf::RectangleShape hitbox;

public:
    // button selected boolean
    bool selected = false;

    // setter function prototypes
    void reset();
    void backspace();
    void addChar(char character);
    void setColor(sf::Color color);
    void setPosition(float x, float y);

    // getter function prototypes
    std::string getText();
    sf::Text getRenderText();
    sf::RectangleShape getRect();

    // constructor
    TextBox(sf::Text inputRenderText, const std::string& type);
};


class Application {
private:
    // fonts
    sf::Font titleFont;
    sf::Font textFont;

    sf::RenderWindow* window;
    std::vector<char> characters;
    std::string applicationState = "Login";
    std::map<std::string, std::map<std::string, Button*>> buttons;
    std::map<std::string, std::map<std::string, TextBox*>> textBoxes;


public:
    mongocxx::uri uri;
    mongocxx::client conn;
    mongocxx::instance inst{};

    // window driver prototypes
    void runLogin();
    void runCreateAcc();
    void verifyLogin(const std::string& username, const std::string& password);
    bool createAccount(const std::string& username, const std::string& password);

    // function prototypes
    void loadItems();
    void renderLoginWindow();
    void renderCreateAccWindow();
    void interpretKey(sf::Keyboard::Key keyCode);

    // constructor
    Application();
};

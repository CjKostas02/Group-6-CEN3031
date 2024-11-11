#pragma once
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>


class Button{
private:
    // variables
    std::string buttonText;
    sf::RectangleShape hitBox;
    sf::Text buttonRenderText;

public:
    // setter function prototypes
    void setHitbox(sf::RectangleShape inputHitbox);

    // getter function prototypes
    std::string getText();
    sf::Text getRenderText();
    sf::RectangleShape getHitbox();

    // constructor
    Button(sf::Text inputText);
};

struct Listing{
    std::string name;
    std::string price;
    std::string ownerID;
    std::string ownerName;
    std::string description;
    std::vector<Button> buttons;
    sf::RectangleShape background;

    Listing(const std::string& name, const std::string& price,
            const std::string& description,
            const std::string& ownerID,
            const std::string& ownerName,
            sf::Font& textFont);
};

struct Eatery{
    std::string name;
    std::string userID;
    sf::Text renderName;
    sf::RectangleShape background;

    Eatery(const std::string& name, const std::string& userID, sf::Font& textFont);
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
    std::string getType();
    sf::Text getRenderText();
    sf::RectangleShape getRect();

    // constructor
    TextBox(sf::Text& inputRenderText, const std::string& type, const float& width = 250);
};


class Application {
private:
    // fonts
    sf::Font textFont;
    sf::Font headerFont;

    int loginErr;
    int accountErr;
    int newPassErr;
    int newUserErr;
    std::string userID;
    std::string currentUser;
    sf::RenderWindow* window;
    std::vector<char> characters;
    std::string applicationState;
    std::vector<Eatery> eateries;
    std::map<std::string, std::vector<Listing>> listings;
    std::map<std::string, std::map<std::string, Button*>> buttons;
    std::map<std::string, std::map<std::string, TextBox*>> textBoxes;

public:
    mongocxx::uri uri;
    mongocxx::client conn;
    mongocxx::instance inst{};

    // function prototypes
    void run();
    void loadItems();
    void loadListings();
    void changePassword();
    void changeUsername();
    void interpretKey(sf::Keyboard::Key keyCode);
    void verifyLogin(const std::string& username, const std::string& password);
    bool createAccount(const std::string& username, const std::string& password);
    bool createListing(const std::string& name, const std::string& price, const std::string& description);

    // render function prototypes
    void renderLoginWindow();
    void renderOrderWindow();
    void renderMyAccountWindow();
    void renderCreateAccWindow();
    void renderCreateListingWindow();

    // constructor
    Application();
};

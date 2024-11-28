#pragma once
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
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
    // member variables
    std::string buttonText;
    sf::RectangleShape* hitBox;
    sf::Text buttonRenderText;

public:
    // setter function prototypes
    void setHitbox(sf::RectangleShape* inputHitbox);

    // getter function prototypes
    std::string getText() const;
    sf::Text getRenderText() const;
    sf::RectangleShape getHitbox() const;

    // constructor
    explicit Button(const sf::Text& inputText);
};

struct Listing{
    // member variables
    std::string name;
    std::string price;
    sf::Text renderName;
    sf::Text renderPrice;
    std::string ownerID;
    std::string ownerName;
    std::string description;
    sf::RectangleShape shadow;
    std::vector<Button> buttons;
    sf::RectangleShape* background;

    // default constructor
    Listing();

    // parameterized constructor
    Listing(const std::string& name, const std::string& price,
            const std::string& description,
            const std::string& ownerID,
            const std::string& ownerName,
            sf::Font& textFont);
};

struct Eatery{
    // member variables
    std::string name;
    std::string userID;
    sf::Text renderName;
    sf::RectangleShape shadow;
    sf::RectangleShape* background;

    // constructor
    Eatery(const std::string& name, const std::string& userID, sf::Font& textFont);
};

class TextBox{
private:
    // member variables
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
    std::string getText() const;
    std::string getType() const;
    sf::Text getRenderText() const;
    sf::RectangleShape getRect() const;

    // constructor
    TextBox(sf::Text& inputRenderText, const std::string& type, const float& width = 250);
};

class Application {
private:
    // fonts
    sf::Font textFont;
    sf::Font headerFont;

    // member variables
    int loginErr;
    int accountErr;
    int newPassErr;
    int newUserErr;
    int eateryPage;
    int listingPage;

    /* Application states
     * Login: log in functionality
     * CreateAccount: Create account functionality
     * Ordering: Eatery selection window functionality
     * MyAccount: Account credential modification functionality
     * SelectListing: Listing selection screen functionality
     * CreateListing: Listing creation functionality
     * ViewListing: Listing details functionality */
    std::string applicationState;

    // member variables
    std::string userID;
    std::string currentUser;
    sf::RenderWindow* window;
    std::string selectedEatery;
    Listing selectedListing;
    std::vector<char> characters;
    std::vector<Eatery> eateries;
    std::map<std::string, std::vector<Listing>> listings;
    std::map<std::string, std::map<std::string, Button*>> buttons;
    std::map<std::string, std::map<std::string, TextBox*>> textBoxes;

public:
    // MongoDB class variables
    mongocxx::uri* uri;
    mongocxx::client* conn;
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
    void renderMyAccountWindow();
    void renderCreateAccWindow();
    void renderViewListingWindow();
    void renderSelectEateryWindow();
    void renderSelectListingWindow();
    void renderCreateListingWindow();

    // constructor
    Application();
};

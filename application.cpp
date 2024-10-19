#include <iostream>
#include "application.h"
#include <map>
#include <sstream>

void Application::loadItems(){
    // load fonts from folder
    titleFont.loadFromFile("../fonts/Open_Sans/static/OpenSans-ExtraBold.ttf");
    textFont.loadFromFile("../fonts/Open_Sans/static/OpenSans-Regular.ttf");

    // keyboard characters in array form
    characters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
                  '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                  'U', 'V', 'W', 'X', 'Y', 'Z', ')', '!', '@', '#', '$', '%', '^', '&',
                  '*', '(', '[', ']', ';', ',', '.', '\'', '/', '\\', '`', '=', '-', '{',
                   '}', ':', '<', '>', '\"', '?', '|', '~', '+', '_'};

    // text object for username textbox
    sf::Text usernameText;
    usernameText.setFont(textFont);
    usernameText.setFillColor(sf::Color::Black);
    usernameText.setCharacterSize(15);
    usernameText.setPosition(400, 400);

    // create text box for entering username
    TextBox* usernameBox = new TextBox(usernameText, "Username");
    usernameBox->setPosition(400, 400);
    textBoxes["Login"]["Username"] = usernameBox;    // load into map for easy access

    // text object for password box
    sf::Text passwordText;
    passwordText.setFont(textFont);
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setCharacterSize(15);
    passwordText.setPosition(400, 460);

    // create text box for entering password
    TextBox* passwordBox = new TextBox(passwordText, "Password");
    passwordBox->setPosition(400, 460);
    textBoxes["Login"]["Password"] = passwordBox;    // load into map for easy access

    // text object for create username textbox
    sf::Text createUserText;
    createUserText.setFont(textFont);
    createUserText.setFillColor(sf::Color::Black);
    createUserText.setCharacterSize(15);
    createUserText.setPosition(400, 400);

    // create text box for creating username
    TextBox* createUserBox = new TextBox(createUserText, "Username");
    createUserBox->setPosition(400, 400);
    textBoxes["CreateAccount"]["CreateUser"] = createUserBox;    // load into map for easy access

    // text object for create password textbox
    sf::Text createPassText;
    createPassText.setFont(textFont);
    createPassText.setFillColor(sf::Color::Black);
    createPassText.setCharacterSize(15);
    createPassText.setPosition(400, 460);

    // create text box for creating password
    TextBox* createPassBox = new TextBox(createPassText, "Password");
    createPassBox->setPosition(400, 460);
    textBoxes["CreateAccount"]["CreatePass"] = createPassBox;    // load into map for easy access

    // text object for create account button
    sf::Text createAccText;
    createAccText.setFont(textFont);
    createAccText.setFillColor({98, 115, 255});
    createAccText.setCharacterSize(17);
    createAccText.setString("Create Account");
    createAccText.setPosition(465, 555);

    // create-account button clickable area
    sf::RectangleShape createAccHitbox({120,20});
    createAccHitbox.setPosition(465,555);
    createAccHitbox.setFillColor({223, 226, 255});

    // create-account button object
    Button* createAccButton = new Button(createAccText);
    createAccButton->setHitbox(createAccHitbox);

    // add create-account button to map of buttons for easy access
    buttons["Login"]["CreateAccount"] = createAccButton;

    // text object for log in button
    sf::Text loginText;
    loginText.setFont(textFont);
    loginText.setFillColor({223, 226, 255});
    loginText.setCharacterSize(20);
    loginText.setString("Log in");
    loginText.setPosition(495, 500);

    // create-account button clickable area
    sf::RectangleShape loginHitbox({250,28});
    loginHitbox.setPosition(400,500);
    loginHitbox.setFillColor({98,115,255});

    // create-account button object
    Button* loginButton = new Button(loginText);
    loginButton->setHitbox(loginHitbox);

    // add log in button to map of buttons for easy access
    buttons["Login"]["Login"] = loginButton;

    // text object for create account button
    sf::Text completeCreateText;
    completeCreateText.setFont(textFont);
    completeCreateText.setFillColor({223, 226, 255});
    completeCreateText.setCharacterSize(20);
    completeCreateText.setString("Create Account");
    completeCreateText.setPosition(455, 500);

    // create-account button clickable area
    sf::RectangleShape completeCreateHitbox({250,28});
    completeCreateHitbox.setPosition(400,500);
    completeCreateHitbox.setFillColor({98,115,255});

    // create-account button object
    Button* confirmCreateButton = new Button(completeCreateText);
    confirmCreateButton->setHitbox(completeCreateHitbox);

    // add log in button to map of buttons for easy access
    buttons["CreateAccount"]["Create Account"] = confirmCreateButton;

    // text object for back-button
    sf::Text backText;
    backText.setFont(textFont);
    backText.setFillColor({98, 115, 255});
    backText.setCharacterSize(20);
    backText.setString("Back");
    backText.setPosition(20, 20);

    // clickable area for back-button
    sf::RectangleShape backHitbox({45,25});
    backHitbox.setPosition(20,20);
    backHitbox.setFillColor({223, 226, 255});

    // button object for back-button
    Button* backButton = new Button(backText);
    backButton->setHitbox(backHitbox);

    // add back-button to map of buttons for easy access
    buttons["CreateAccount"]["Back"] = backButton;
}

void Application::interpretKey(sf::Keyboard::Key keyCode){
    // if a valid key is pressed
    if(keyCode >= 0 && keyCode <= 35) {
        // if user is pressing shift
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            // add alternate character to selected text box
            for(auto iter: textBoxes[applicationState]) {
                if (iter.second->selected){
                    iter.second->addChar(characters[keyCode + 36]);
                }
            }
        }
        else{
            // add character to selected text box
            for(auto iter: textBoxes[applicationState]) {
                if(iter.second->selected){
                    iter.second->addChar(characters[keyCode]);
                }
            }
        }
    }
    // other valid keys
    else if(keyCode >= 46 && keyCode <= 56){
        // if user is pressing shift
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            // add alternate character to selected textbox
            for (auto iter: textBoxes[applicationState]){
                if(iter.second->selected){
                    iter.second->addChar(characters[keyCode + 37]);
                }
            }
        }
        else{
            // add character to selected text box
            for(auto iter: textBoxes[applicationState]){
                if(iter.second->selected){
                    iter.second->addChar(characters[keyCode + 26]);
                }
            }
        }

    }
    // if the user pressed backspace
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
        // delete the last character from selected text box
        for(auto iter : textBoxes[applicationState]){
            if(iter.second->selected && iter.second->getText().size() > 0){
                iter.second->backspace();
            }
        }
    }
}

/*------------------------------------------------------------------------*/
/*-------------------Create-Account Window Functionality------------------*/
/*------------------------------------------------------------------------*/

bool Application::createAccount(const std::string& username, const std::string& password){
    // TODO: Add comments

    if(username.size() > 0){
        auto db = conn["user_data"];
        auto collection = db["users"];

        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", username)));

        if(resultUserSearch){
            std::cout << "Error: Account with that name already exists" << std::endl;
            return false;
        }
        if(password.size() > 0 && username.size() > 0){
            auto db = conn["user_data"];
            auto collection = db["users"];

            bsoncxx::builder::basic::document document{};
            document.append(bsoncxx::builder::basic::kvp("Username", username));
            document.append(bsoncxx::builder::basic::kvp("Password", password));

            collection.insert_one(document.view());

            return true;
        }
        else{
            std::cout << "Empty entry" << std::endl;
            return false;
        }
    }
}

void Application::renderCreateAccWindow(){
    // title text
    sf::Text title;
    title.setFont(titleFont);
    title.setFillColor({98, 115, 255});
    title.setString("Create Account");
    title.setPosition(265, 50);
    title.setCharacterSize(65);

    // set window background color
    window->clear({223, 226, 255});

    // draw the buttons and text boxes on render window
    for(auto iter : buttons["CreateAccount"]){
        window->draw(iter.second->getHitbox());
        window->draw(iter.second->getRenderText());
    }
    for(auto iter : textBoxes["CreateAccount"]){
        window->draw(iter.second->getRect());
        window->draw(iter.second->getRenderText());
    }

    sf::Text createUsername;
    createUsername.setFont(textFont);
    createUsername.setFillColor({98, 115, 255});
    createUsername.setString("Create Username:");
    createUsername.setPosition(400, 375);
    createUsername.setCharacterSize(20);

    sf::Text createPassword;
    createPassword.setFont(textFont);
    createPassword.setFillColor({98, 115, 255});
    createPassword.setString("Create Password:");
    createPassword.setPosition(400, 435);
    createPassword.setCharacterSize(20);


    window->draw(title);
    window->draw(createUsername);
    window->draw(createPassword);

    // render window
    window->display();
}

void Application::runCreateAcc(){
    float mouseX;
    float mouseY;

    while(window->isOpen()){
        renderCreateAccWindow();

        sf::Event event;
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                return;
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                mouseX = sf::Mouse::getPosition(*window).x;
                mouseY = sf::Mouse::getPosition(*window).y;

                for (auto iter: textBoxes["CreateAccount"]) {
                    if (iter.second->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                        for (auto iter2: textBoxes["CreateAccount"]) {
                            iter2.second->selected = false;
                            iter2.second->setColor(sf::Color::White);
                        }
                        iter.second->selected = true;
                        iter.second->setColor({240, 240, 255});
                    }
                }
                for(auto iter: buttons["CreateAccount"]) {
                    if (iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                        if(iter.second->getText() == "Back"){
                            for(auto iter : textBoxes["CreateAccount"]){
                                iter.second->reset();
                            }

                            applicationState = "Login";
                            return;
                        }
                        else if(iter.second->getText() == "Create Account"){
                            if(createAccount(textBoxes["CreateAccount"]["CreateUser"]->getText(),
                                          textBoxes["CreateAccount"]["CreatePass"]->getText())){
                                for(auto iter : textBoxes["CreateAccount"]){
                                    iter.second->reset();
                                }

                                applicationState = "Login";
                                return;
                            }
                        }
                    }
                }
            }
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Key::Enter){
                    if(createAccount(textBoxes["CreateAccount"]["CreateUser"]->getText(),
                                  textBoxes["CreateAccount"]["CreatePass"]->getText())){
                        for(auto iter : textBoxes["CreateAccount"]){
                            iter.second->reset();
                        }

                        applicationState = "Login";
                        return;
                    }
                }
                else{
                    interpretKey(event.key.code);
                }
            }

            renderCreateAccWindow();
        }
    }
}

/*------------------------------------------------------------------------*/
/*-----------------------Login Window Functionality-----------------------*/
/*------------------------------------------------------------------------*/

void Application::verifyLogin(const std::string& username, const std::string& password){
    // TODO: Add comments

    if(username.size() > 0 && password.size() > 0){
        auto db = conn["user_data"];
        auto collection= db["users"];

        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", username)));

        try{
            std::string input = bsoncxx::to_json(*resultUserSearch);

            if(input.size() > 3){
                bsoncxx::document::view getPass = resultUserSearch->view();
                std::string passResult = getPass["Password"].get_utf8().value.to_string();

                if(passResult == password){
                    std::cout << "Login success" << std::endl;
                }
                else{
                    std::cout << "Invalid login" << std::endl;
                }
            }
            else{
                std::cout << "Invalid login" << std::endl;
            }
        }
        catch(const std::exception& e){
            std::cout << "Invalid login" << std::endl;
        }
    }
    else{
        std::cout << "Invalid login" << std::endl;
    }
}

void Application::renderLoginWindow(){
    // title text
    sf::Text title;
    title.setFont(titleFont);
    title.setFillColor({98, 115, 255});
    title.setString("Campus Central Food");
    title.setPosition(175, 50);
    title.setCharacterSize(65);

    sf::Text username;
    username.setFont(textFont);
    username.setFillColor({98, 115, 255});
    username.setString("Username:");
    username.setPosition(400, 375);
    username.setCharacterSize(20);

    sf::Text password;
    password.setFont(textFont);
    password.setFillColor({98, 115, 255});
    password.setString("Password:");
    password.setPosition(400, 435);
    password.setCharacterSize(20);

    // set window background color
    window->clear({223, 226, 255});

    // draw title, buttons and text boxes
    window->draw(title);
    for(auto iter : buttons["Login"]){
        window->draw(iter.second->getHitbox());
        window->draw(iter.second->getRenderText());
    }
    for(auto iter : textBoxes["Login"]){
        window->draw(iter.second->getRect());
        window->draw(iter.second->getRenderText());
    }
    window->draw(username);
    window->draw(password);

    // render window
    window->display();
}

void Application::runLogin(){
    loadItems();
    float mouseX;
    float mouseY;

    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
                return;
            }

            if(event.type == sf::Event::MouseButtonReleased){
                mouseX = sf::Mouse::getPosition(*window).x;
                mouseY = sf::Mouse::getPosition(*window).y;

                for(auto iter : textBoxes["Login"]){
                    if(iter.second->getRect().getGlobalBounds().contains(mouseX, mouseY)){
                        for(auto iter2 : textBoxes["Login"]){
                            iter2.second->selected = false;
                            iter2.second->setColor(sf::Color::White);
                        }
                        iter.second->selected = true;
                        iter.second->setColor({240, 240, 255});
                    }
                }
                for(auto iter : buttons["Login"]){
                    if(iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                        if(iter.second->getText() == "Create Account"){
                            for(auto iter : textBoxes["Login"]){
                                iter.second->reset();
                            }

                            applicationState = "CreateAccount";
                            runCreateAcc();
                        }
                        else{
                            verifyLogin(textBoxes["Login"]["Username"]->getText(), textBoxes["Login"]["Password"]->getText());
                        }
                    }
                }
            }
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Key::Enter){
                    verifyLogin(textBoxes["Login"]["Username"]->getText(), textBoxes["Login"]["Password"]->getText());
                }
                else{
                    interpretKey(event.key.code);
                }
            }

            renderLoginWindow();
        }
    }
}

Application::Application(){
    // create the application window
    window = new sf::RenderWindow(sf::VideoMode(1050, 600), "Campus Central Food");

    // Create an instance.
    uri = mongocxx::uri{"mongodb+srv://default_user:defaultPassword@group6ccf.ka8iy.mongodb.net/?retryWrites=true&w=majority&appName=Group6CCF"};
    conn = mongocxx::client{uri};
}

/*------------------------------------------------------------------------*/
/*----------------------------Button Functions----------------------------*/
/*------------------------------------------------------------------------*/

sf::Text Button::getRenderText(){
    return buttonRenderText;
}

Button::Button(sf::Text inputText){
    buttonRenderText = inputText;
    buttonText = inputText.getString();
}

void Button::setHitbox(sf::RectangleShape inputHitbox){
    hitBox = inputHitbox;
}

sf::RectangleShape Button::getHitbox(){
    return hitBox;
}

std::string Button::getText(){
    return buttonText;
}

/*------------------------------------------------------------------------*/
/*---------------------------TextBox Functions----------------------------*/
/*------------------------------------------------------------------------*/

void TextBox::setPosition(float x, float y){
    hitbox.setPosition({x, y});
}

void TextBox::setColor(sf::Color color){
    hitbox.setFillColor(color);
}

sf::RectangleShape TextBox::getRect(){
    return hitbox;
}

void TextBox::addChar(char character){
    boxText += character;

    if(type == "Username"){
        boxRenderText.setString(boxText);
    }
    else if(type == "Password"){
        std::string hideText;
        for(int i = 0; i < boxText.size() - 1; i++){
            hideText += '*';
        }
        boxRenderText.setString(hideText + character);
    }
}

std::string TextBox::getText(){
    return boxText;
}

sf::Text TextBox::getRenderText(){
    return boxRenderText;
}

void TextBox::backspace(){
    boxText.erase(boxText.end() - 1);

    if(type == "Username"){
        boxRenderText.setString(boxText);
    }
    else if(type == "Password"){
        std::string hideText;
        for(char i : boxText){
            hideText += '*';
        }
        boxRenderText.setString(hideText);

    }
}

void TextBox::reset(){
    boxText = "";
    selected = false;
    boxRenderText.setString("");
    hitbox.setFillColor(sf::Color::White);
}

TextBox::TextBox(sf::Text inputRenderText, const std::string& type){
    this->type = type;

    boxText = "";
    boxRenderText = inputRenderText;
    hitbox.setSize({250, 25});
    hitbox.setOutlineColor(sf::Color::Black);
    hitbox.setOutlineThickness(2);
}

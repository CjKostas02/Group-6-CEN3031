#include <iostream>
#include "application.h"
#include <map>

void Application::loadItems(){
    // load fonts from folder
    titleFont.loadFromFile("../fonts/Open_Sans/static/OpenSans-ExtraBold.ttf");
    textFont.loadFromFile("../fonts/Open_Sans/static/OpenSans-Regular.ttf");

    // keyboard characters in array form
    characters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
                  '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                  'U', 'V', 'W', 'X', 'Y', 'Z'};

    // text object for username textbox
    sf::Text usernameText;
    usernameText.setFont(textFont);
    usernameText.setFillColor(sf::Color::Black);
    usernameText.setCharacterSize(15);
    usernameText.setPosition(400, 400);

    // create text box for entering username
    TextBox* usernameBox = new TextBox(usernameText);
    usernameBox->setPosition(400, 400);
    textBoxes["Login"]["Username"] = usernameBox;    // load into map for easy access

    sf::Text passwordText;
    passwordText.setFont(textFont);
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setCharacterSize(15);
    passwordText.setPosition(400, 450);

    // create text box for entering password
    TextBox* passwordBox = new TextBox(passwordText);
    passwordBox->setPosition(400, 450);
    textBoxes["Login"]["Password"] = passwordBox;    // load into map for easy access

    // text object for create account button
    sf::Text createAccText;
    createAccText.setFont(textFont);
    createAccText.setFillColor({98, 115, 255});
    createAccText.setCharacterSize(20);
    createAccText.setString("Create Account");
    createAccText.setPosition(455, 525);

    // create-account button clickable area
    sf::RectangleShape createAccHitbox({140,25});
    createAccHitbox.setPosition(455,525);

    // create-account button object
    Button* createAccButton = new Button(createAccText);
    createAccButton->setHitbox(createAccHitbox);

    // add create-account button to map of buttons for easy access
    buttons["Login"]["CreateAccount"] = createAccButton;

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

    // button object for back-button
    Button* backButton = new Button(backText);
    backButton->setHitbox(backHitbox);

    // add back-button to map of buttons for easy access
    buttons["CreateAccount"]["Back"] = backButton;
}

/*------------------------------------------------------------------------*/
/*-------------------Create-Account Window Functionality------------------*/
/*------------------------------------------------------------------------*/

void Application::renderCreateAccWindow(){
    // set window background color
    window->clear({223, 226, 255});

    // draw the buttons and text boxes on render window
    for(auto iter : buttons["CreateAccount"]){
        //window->draw(iter.second->getHitbox());
        window->draw(iter.second->getRenderText());
    }
    for(auto iter : textBoxes["CreateAccount"]){
        window->draw(iter.second->getRect());
    }

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

                for (auto iter: textBoxes["Login"]) {
                    if (iter.second->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                        for (auto iter2: textBoxes["Login"]) {
                            iter2.second->selected = false;
                            iter2.second->setColor(sf::Color::White);
                        }
                        iter.second->selected = true;
                        iter.second->setColor({240, 240, 255});
                    }
                }
                for (auto iter: buttons["CreateAccount"]) {
                    if (iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                        std::cout << iter.second->getText() << " Pressed" << std::endl;
                        if(iter.second->getText() == "Back"){
                            return;
                        }
                    }
                }
            }

            renderCreateAccWindow();
        }
    }
}

/*------------------------------------------------------------------------*/
/*-----------------------Login Window Functionality-----------------------*/
/*------------------------------------------------------------------------*/

void Application::renderLoginWindow(){
    // title text
    sf::Text title;
    title.setFont(titleFont);
    title.setFillColor({98, 115, 255});
    title.setString("Campus Central Food");
    title.setPosition(175, 50);
    title.setCharacterSize(65);

    // set window background color
    window->clear({223, 226, 255});

    // draw title, buttons and text boxes
    window->draw(title);
    for(auto iter : buttons["Login"]){
        window->draw(iter.second->getRenderText());
    }
    for(auto iter : textBoxes["Login"]){
        window->draw(iter.second->getRect());
        window->draw(iter.second->getRenderText());
    }

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
                    else{
                        //iter.second.getRect().setFillColor(sf::Color::White);
                    }
                }
                for(auto iter : buttons["Login"]){
                    if(iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                        std::cout << iter.second->getText() << " Pressed" << std::endl;
                        runCreateAcc();
                    }
                }
            }
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code >= 0 && event.key.code <= 35) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && event.key.code <= 25) {
                        std::cout << characters[event.key.code + 36] << std::endl;\

                        for (auto iter: textBoxes["Login"]) {
                            if (iter.second->selected) {
                                iter.second->addChar(characters[event.key.code + 36]);
                            }
                        }
                    } else {
                        std::cout << characters[event.key.code] << std::endl;

                        for (auto iter: textBoxes["Login"]) {
                            if(iter.second->selected){
                                iter.second->addChar(characters[event.key.code]);
                            }
                        }
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
                    for(auto iter : textBoxes["Login"]){
                        if(iter.second->selected && iter.second->getText().size() > 0){
                            iter.second->backspace();
                            std::cout << "Backspace" << std::endl;
                        }
                    }
                }
            }

            renderLoginWindow();
        }
    }
}

Application::Application(){
    // create the application window
    window = new sf::RenderWindow(sf::VideoMode(1050, 600), "Campus Central Food");
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
    rect.setPosition({x, y});
}

void TextBox::setColor(sf::Color color){
    this->rect.setFillColor(color);
}

TextBox::TextBox(sf::Text inputRenderText){
    boxText = "";
    boxRenderText = inputRenderText;
    rect.setSize({250, 25});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(2);
}

sf::RectangleShape TextBox::getRect(){
    return rect;
}

void TextBox::addChar(char character){
    boxText += character;
    std::cout << boxText << std::endl;
    boxRenderText.setString(boxText);
}

std::string TextBox::getText(){
    return boxText;
}

sf::Text TextBox::getRenderText(){
    return boxRenderText;
}

void TextBox::backspace(){
    boxText.erase(boxText.end() - 1);
    boxRenderText.setString(boxText);
}

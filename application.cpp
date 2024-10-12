#include <iostream>
#include "application.h"
#include <map>

void Application::renderLoginWindow(){
    // title text
    sf::Text title;
    title.setFont(titleFont);
    title.setFillColor({98, 115, 255});
    title.setString("Campus Central Food");
    title.setPosition(175, 50);
    title.setCharacterSize(65);

    // create account hitbox
    sf::RectangleShape createAccRect({140,25});
    //createAccRect.setFillColor(sf::Color::White);
    //createAccRect.setOutlineThickness(2);
    //createAccRect.setOutlineColor({98, 115, 255});
    createAccRect.setPosition(455,525);

    // text for create account button
    sf::Text createAccText;
    createAccText.setFont(textFont);
    createAccText.setFillColor({98, 115, 255});
    createAccText.setCharacterSize(20);
    createAccText.setString("Create Account");
    createAccText.setPosition(455, 525);

    window->clear({223, 226, 255});
    window->draw(title);
    window->draw(createAccText);
    window->draw(textBoxes["Username"]->getRect());
    window->draw(textBoxes["Password"]->getRect());
    window->display();
}

void Application::loadItems(){
    // load fonts from folder
    titleFont.loadFromFile("../fonts/Open_Sans/static/OpenSans-ExtraBold.ttf");
    textFont.loadFromFile("../fonts/Open_Sans/static/OpenSans-Regular.ttf");

    // create text box for entering username
    TextBox* usernameBox = new TextBox;
    usernameBox->setPosition(455, 400);
    textBoxes["Username"] = usernameBox;    // load into map for easy access

    // create text box for entering password
    TextBox* passwordBox = new TextBox;
    passwordBox->setPosition(455, 450);
    textBoxes["Password"] = passwordBox;    // load into map for easy access
}

void Application::run(){
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

            if(applicationState == 0){

                if(event.type == sf::Event::MouseButtonReleased){
                    mouseX = sf::Mouse::getPosition(*window).x;
                    mouseY = sf::Mouse::getPosition(*window).y;

                    for(auto iter : textBoxes){
                        if(iter.second->getRect().getGlobalBounds().contains(mouseX, mouseY)){
                            for(auto iter2 : textBoxes){
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
                }


                renderLoginWindow();
            }
            else if(applicationState == 1){
                // TODO: Add main application functionality
            }
            else if(applicationState == 2){
                // TODO: Add account creation functionality
            }
        }
    }
}

Application::Application(){
    // create the application window
    window = new sf::RenderWindow(sf::VideoMode(1050, 600), "Campus Central Food");
}

sf::RectangleShape TextBox::getRect(){
    return rect;
}

void TextBox::setPosition(float x, float y){
    rect.setPosition({x, y});
}

void TextBox::setColor(sf::Color color){
    this->rect.setFillColor(color);
}

TextBox::TextBox(){
    rect.setSize({140, 25});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(2);
}
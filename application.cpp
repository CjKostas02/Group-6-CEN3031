#include "application.h"
#include <map>

void Application::updateLoginWindow(){
    sf::Text title;
    title.setFont(font);
    title.setFillColor({98, 115, 255});
    title.setString("Campus Central Food");
    title.setPosition(175, 50);
    title.setScale(2,2);

    window->clear({223, 226, 255});
    window->draw(title);
    window->display();
}

void Application::loadTextures(){
    font.loadFromFile("../fonts/Open_Sans/static/OpenSans-ExtraBold.ttf");
}

void Application::run(){
    loadTextures();

    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
                return;
            }
            updateLoginWindow();
        }
    }
}

Application::Application(){
    window = new sf::RenderWindow(sf::VideoMode(1050, 600), "Campus Central Food");
}
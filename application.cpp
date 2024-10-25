#include <sstream>
#include <iostream>
#include "application.h"


void Application::loadItems(){
    // TODO: Organize by section

    // load fonts from folder
    headerFont.loadFromFile("../fonts/Open_Sans/static/OpenSans-ExtraBold.ttf");
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
    usernameText.setPosition(400, 402);

    // create text box for entering username
    TextBox* usernameBox = new TextBox(usernameText, "Username");
    usernameBox->setPosition(400, 400);
    textBoxes["Login"]["Username"] = usernameBox;    // load into map for easy access

    // text object for password box
    sf::Text passwordText;
    passwordText.setFont(textFont);
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setCharacterSize(15);
    passwordText.setPosition(400, 462);

    // create text box for entering password
    TextBox* passwordBox = new TextBox(passwordText, "Password");
    passwordBox->setPosition(400, 460);
    textBoxes["Login"]["Password"] = passwordBox;    // load into map for easy access

    // text object for create username textbox
    sf::Text createUserText;
    createUserText.setFont(textFont);
    createUserText.setFillColor(sf::Color::Black);
    createUserText.setCharacterSize(15);
    createUserText.setPosition(400, 402);

    // create text box for creating username
    TextBox* createUserBox = new TextBox(createUserText, "Username");
    createUserBox->setPosition(400, 400);
    textBoxes["CreateAccount"]["CreateUser"] = createUserBox;    // load into map for easy access

    // text object for create password textbox
    sf::Text createPassText;
    createPassText.setFont(textFont);
    createPassText.setFillColor(sf::Color::Black);
    createPassText.setCharacterSize(15);
    createPassText.setPosition(400, 462);

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

    // create account button clickable area
    sf::RectangleShape createAccHitbox({120,20});
    createAccHitbox.setPosition(465,555);
    createAccHitbox.setFillColor({223, 226, 255});

    // create account button object
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

    // log in button clickable area
    sf::RectangleShape loginHitbox({250,28});
    loginHitbox.setPosition(400,500);
    loginHitbox.setFillColor({98,115,255});

    // log in button object
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

    // create account button clickable area
    sf::RectangleShape completeCreateHitbox({250,28});
    completeCreateHitbox.setPosition(400,500);
    completeCreateHitbox.setFillColor({98,115,255});

    // create account button object
    Button* confirmCreateButton = new Button(completeCreateText);
    confirmCreateButton->setHitbox(completeCreateHitbox);

    // add create account button to map of buttons for easy access
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

    // add back button to map of buttons for easy access
    buttons["CreateAccount"]["Back"] = backButton;

    // move back button for my-account screen
    backText.setPosition(20, 60);
    backHitbox.setPosition(20,60);

    // add modified back button to my account button map for easy access
    backButton = new Button(backText);
    backButton->setHitbox(backHitbox);
    buttons["MyAccount"]["Back"] = backButton;

    // text object for my-account button
    sf::Text viewAccText;
    viewAccText.setFont(textFont);
    viewAccText.setFillColor({98, 115, 255});
    viewAccText.setCharacterSize(20);
    viewAccText.setString("My Account");
    viewAccText.setPosition(900, 0);

    // my account button clickable area
    sf::RectangleShape viewAccHitbox({110,25});
    viewAccHitbox.setPosition(900,0);
    viewAccHitbox.setFillColor({200, 200, 255});

    // my account button object
    Button* viewAccButton = new Button(viewAccText);
    viewAccButton->setHitbox(viewAccHitbox);

    // add My Account button to map of buttons for easy access
    buttons["Ordering"]["ViewAccount"] = viewAccButton;

    // text object for log out button
    sf::Text logoutText;
    logoutText.setFont(textFont);
    logoutText.setFillColor({98, 115, 255});
    logoutText.setCharacterSize(15);
    logoutText.setString("Log Out");
    logoutText.setPosition(925, 28);

    // log out button clickable area
    sf::RectangleShape logoutHitbox({55,20});
    logoutHitbox.setPosition(925,28);
    logoutHitbox.setFillColor({200, 200, 255});

    // log out button object
    Button* logoutButton = new Button(logoutText);
    logoutButton->setHitbox(logoutHitbox);

    // add log out button to map of buttons for easy access
    buttons["Ordering"]["Logout"] = logoutButton;

    // text object for current password textbox
    sf::Text currentPassText;
    currentPassText.setFont(textFont);
    currentPassText.setFillColor(sf::Color::Black);
    currentPassText.setCharacterSize(15);
    currentPassText.setPosition(200, 342);

    // create text box for entering current password
    TextBox* currentPassBox = new TextBox(currentPassText, "Password");
    currentPassBox->setPosition(200, 340);
    textBoxes["MyAccount"]["CurrentPassword"] = currentPassBox;    // load into map for easy access

    // text object for new password textbox
    sf::Text newPassText;
    newPassText.setFont(textFont);
    newPassText.setFillColor(sf::Color::Black);
    newPassText.setCharacterSize(15);
    newPassText.setPosition(200, 402);

    // create text box for entering new password
    TextBox* newPassBox = new TextBox(newPassText, "Password");
    newPassBox->setPosition(200, 400);
    textBoxes["MyAccount"]["NewPassword"] = newPassBox;    // load into map for easy access

    // text object for confirming new password textbox
    sf::Text confirmNewPassText;
    confirmNewPassText.setFont(textFont);
    confirmNewPassText.setFillColor(sf::Color::Black);
    confirmNewPassText.setCharacterSize(15);
    confirmNewPassText.setPosition(200, 462);

    // create text box for confirming new password
    TextBox* confirmNewPassBox = new TextBox(confirmNewPassText, "Password");
    confirmNewPassBox->setPosition(200, 460);
    textBoxes["MyAccount"]["ConfirmNewPassword"] = confirmNewPassBox;    // load into map for easy access

    // text object for change password button
    sf::Text changePassText;
    changePassText.setFont(textFont);
    changePassText.setFillColor({223, 226, 255});
    changePassText.setCharacterSize(20);
    changePassText.setString("Change Password");
    changePassText.setPosition(240, 500);

    // change password button clickable area
    sf::RectangleShape changePassHitbox({250,28});
    changePassHitbox.setPosition(200,500);
    changePassHitbox.setFillColor({98,115,255});

    // change password button object
    Button* changePassButton = new Button(changePassText);
    changePassButton->setHitbox(changePassHitbox);

    // load into map for easy access
    buttons["MyAccount"]["ChangePassword"] = changePassButton;

    // text object for new username textbox
    sf::Text newUserText;
    newUserText.setFont(textFont);
    newUserText.setFillColor(sf::Color::Black);
    newUserText.setCharacterSize(15);
    newUserText.setPosition(600, 342);

    // create text box for entering new username
    TextBox* newUserBox = new TextBox(newUserText, "Username");
    newUserBox->setPosition(600, 340);
    textBoxes["MyAccount"]["NewUsername"] = newUserBox;    // load into map for easy access

    // text object for change username button
    sf::Text changeUserText;
    changeUserText.setFont(textFont);
    changeUserText.setFillColor({223, 226, 255});
    changeUserText.setCharacterSize(20);
    changeUserText.setString("Change Username");
    changeUserText.setPosition(640, 500);

    // change username button clickable area
    sf::RectangleShape changeUserHitbox({250,28});
    changeUserHitbox.setPosition(600,500);
    changeUserHitbox.setFillColor({98,115,255});

    // change username button object
    Button* changeUserButton = new Button(changeUserText);
    changeUserButton->setHitbox(changeUserHitbox);

    // load into map for easy access
    buttons["MyAccount"]["ChangeUsername"] = changeUserButton;
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
/*---------------------My Account Window Functionality--------------------*/
/*------------------------------------------------------------------------*/

// TODO: Change format of changeUsername and changePassword to be similar to
//  createAccount and verifyLogin to reduce map traversals
void Application::changeUsername(){
    // TODO: Add comments

    if(textBoxes["MyAccount"]["NewUsername"]->getText() == currentUser){
        newUserErr = 2;
        return;
    }
    else if(textBoxes["MyAccount"]["NewUsername"]->getText().size() == 0){
        newUserErr = 3;
        return;
    }
    else{
        auto database = conn["user_data"];
        auto collection = database["users"];

        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(
                        "Username", textBoxes["MyAccount"]["NewUsername"]->getText())));

        if(resultUserSearch){
            newUserErr = 1;
        }
        else{
            bsoncxx::builder::stream::document getDoc;
            getDoc << "Username" << currentUser;

            bsoncxx::builder::stream::document modifyDoc;

            modifyDoc << "$set" << bsoncxx::builder::stream::open_document
                      << "Username" << textBoxes["MyAccount"]["NewUsername"]->getText()
                      << bsoncxx::builder::stream::close_document;

            collection.update_one(getDoc.view(), modifyDoc.view());

            currentUser = textBoxes["MyAccount"]["NewUsername"]->getText();

            for(auto iter : textBoxes["MyAccount"]){
                iter.second->reset();
            }
        }
    }
}

void Application::changePassword(){
    // TODO: Add comments

    auto database = conn["user_data"];
    auto collection= database["users"];

    auto resultUserSearch = collection.find_one(
            bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", currentUser)));

    std::string input = bsoncxx::to_json(*resultUserSearch);


    bsoncxx::document::view getPass = resultUserSearch->view();
    std::string currentPass = getPass["Password"].get_utf8().value.to_string();

    if(currentPass == textBoxes["MyAccount"]["CurrentPassword"]->getText()){
        if(textBoxes["MyAccount"]["NewPassword"]->getText().size() > 0
           && textBoxes["MyAccount"]["ConfirmNewPassword"]->getText().size() > 0){
            if(currentPass != textBoxes["MyAccount"]["NewPassword"]->getText()){
                if(textBoxes["MyAccount"]["NewPassword"]->getText() == textBoxes["MyAccount"]["ConfirmNewPassword"]->getText()){
                    bsoncxx::builder::stream::document getDoc;
                    getDoc << "Username" << currentUser;

                    bsoncxx::builder::stream::document modifyDoc;

                    modifyDoc << "$set" << bsoncxx::builder::stream::open_document
                    << "Password" << textBoxes["MyAccount"]["NewPassword"]->getText()
                    << bsoncxx::builder::stream::close_document;

                    collection.update_one(getDoc.view(), modifyDoc.view());

                    for(auto iter : textBoxes["MyAccount"]){
                        iter.second->reset();
                    }
                }
                else{
                    newPassErr = 1;
                }
            }
            else{
                newPassErr = 2;
            }
        }
        else{
            newPassErr = 3;
        }
    }
    else{
        newPassErr = 4;
    }
}

void Application::renderMyAccountWindow(){
    // TODO: Add comments
    // TODO: Organize

    // set window background color
    window->clear({223, 226, 255});

    // window header
    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});
    window->draw(windowHeader);

    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Modify Account");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);
    window->draw(headerText);

    // draw the buttons and text boxes on render window
    for(auto iter : buttons["MyAccount"]){
        window->draw(iter.second->getHitbox());
        window->draw(iter.second->getRenderText());
    }
    for(auto iter : textBoxes["MyAccount"]){
        window->draw(iter.second->getRect());
        window->draw(iter.second->getRenderText());
    }

    sf::Text currentPass;
    currentPass.setFont(textFont);
    currentPass.setFillColor({98, 115, 255});
    currentPass.setString("Current Password:");
    currentPass.setPosition(200, 315);
    currentPass.setCharacterSize(20);

    sf::Text newPass;
    newPass.setFont(textFont);
    newPass.setFillColor({98, 115, 255});
    newPass.setString("New Password:");
    newPass.setPosition(200, 375);
    newPass.setCharacterSize(20);

    sf::Text confirmNewPass;
    confirmNewPass.setFont(textFont);
    confirmNewPass.setFillColor({98, 115, 255});
    confirmNewPass.setString("Confirm New Password:");
    confirmNewPass.setPosition(200, 435);
    confirmNewPass.setCharacterSize(20);

    sf::Text newUserErrorText;
    newUserErrorText.setFont(textFont);
    newUserErrorText.setCharacterSize(20);
    newUserErrorText.setFillColor(sf::Color::Red);

    if(newUserErr == 1){
        newUserErrorText.setString("Account with that username already exists.");
        newUserErrorText.setPosition(525, 250);
    }
    if(newUserErr == 2){
        newUserErrorText.setString("New username cannot be the same as current username.");
        newUserErrorText.setPosition(460, 250);
    }
    else if(newUserErr == 3){
        newUserErrorText.setString("Please enter a valid username.");
        newUserErrorText.setPosition(580, 250);
    }


    sf::Text newPassErrorText;
    newPassErrorText.setFont(textFont);
    newPassErrorText.setCharacterSize(20);
    newPassErrorText.setFillColor(sf::Color::Red);

    // print error depending on context
    if(newPassErr == 1){
        newPassErrorText.setString("Passwords do not match.");
        newPassErrorText.setPosition(205, 250);
    }
    else if(newPassErr == 2){
        newPassErrorText.setString("New password cannot be the same as current password.");
        newPassErrorText.setPosition(90, 250);
    }
    else if(newPassErr == 3){
        newPassErrorText.setString("Please enter a valid password.");
        newPassErrorText.setPosition(185, 250);
    }
    else if(newPassErr == 4){
        newPassErrorText.setString("Incorrect password.");
        newPassErrorText.setPosition(230, 250);
    }

    sf::Text newUser;
    newUser.setFont(textFont);
    newUser.setFillColor({98, 115, 255});
    newUser.setString("New Username:");
    newUser.setPosition(600, 315);
    newUser.setCharacterSize(20);

    window->draw(newPassErrorText);
    window->draw(newUserErrorText);
    window->draw(confirmNewPass);
    window->draw(currentPass);
    window->draw(newPass);
    window->draw(newUser);

    // render window
    window->display();
}

void Application::runMyAccount(){
    // TODO: Add comments

    float mouseX;
    float mouseY;

    while(window->isOpen()){
        renderMyAccountWindow();

        sf::Event event;
        while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window->close();
                return;
            }

            if(event.type == sf::Event::MouseButtonReleased) {
                mouseX = sf::Mouse::getPosition(*window).x;
                mouseY = sf::Mouse::getPosition(*window).y;

                for(auto iter: textBoxes["MyAccount"]) {
                    if(iter.second->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                        for(auto iter2: textBoxes["MyAccount"]){
                            iter2.second->selected = false;
                            iter2.second->setColor(sf::Color::White);

                            newPassErr = 0;
                            newUserErr = 0;
                        }
                        iter.second->selected = true;
                        iter.second->setColor({240, 240, 255});

                        if(iter.second->getType() == "Password"){
                            for(auto iter : textBoxes["MyAccount"]){
                                if(iter.second->getType() == "Username"){
                                    iter.second->reset();
                                }
                            }
                        }
                        else if(iter.second->getType() == "Username"){
                            for(auto iter : textBoxes["MyAccount"]){
                                if(iter.second->getType() == "Password"){
                                    iter.second->reset();
                                }
                            }
                        }
                    }
                }
                for(auto iter: buttons["MyAccount"]) {
                    if(iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                        if(iter.second->getText() == "Back"){
                            for(auto iter : textBoxes["MyAccount"]){
                                iter.second->reset();
                            }

                            newUserErr = 0;
                            newPassErr = 0;

                            applicationState = "Ordering";
                            return;
                        }
                        else if(iter.second->getText() == "Change Password"){
                            newUserErr = 0;
                            for(auto iter : textBoxes["MyAccount"]){
                                if(iter.second->getType() == "Username"){
                                    iter.second->reset();
                                }
                            }
                            changePassword();
                        }
                        else if(iter.second->getText() == "Change Username"){
                            for(auto iter : textBoxes["MyAccount"]){
                                if(iter.second->getType() == "Password"){
                                    iter.second->reset();
                                }
                            }
                            newPassErr = 0;
                            changeUsername();
                        }
                    }
                }
            }
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Key::Enter){
                    for(auto iter : textBoxes["MyAccount"]){
                        if(iter.second->selected && iter.second->getType() == "Password"){
                            changePassword();
                        }
                        else if(iter.second->selected && iter.second->getType() == "Username"){
                            changeUsername();
                        }
                    }
                }
                else{
                    newPassErr = 0;
                    newUserErr = 0;
                    interpretKey(event.key.code);
                }
            }

            renderMyAccountWindow();
        }
    }
}


/*------------------------------------------------------------------------*/
/*----------------------Ordering Window Functionality---------------------*/
/*------------------------------------------------------------------------*/

void Application::renderOrderWindow(){
    // TODO: Add comments

    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Welcome " + currentUser + "!");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);

    // set window background color
    window->clear({223, 226, 255});

    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});

    window->draw(windowHeader);
    window->draw(headerText);

    // draw the buttons and text boxes on render window
    for(auto iter : buttons["Ordering"]){
        window->draw(iter.second->getHitbox());
        window->draw(iter.second->getRenderText());
    }
    for(auto iter : textBoxes["Ordering"]){
        window->draw(iter.second->getRect());
        window->draw(iter.second->getRenderText());
    }

    // render window
    window->display();
}

void Application::runOrdering(){
    float mouseX;
    float mouseY;

    while(window->isOpen()){
        renderOrderWindow();

        sf::Event event;
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                return;
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                mouseX = sf::Mouse::getPosition(*window).x;
                mouseY = sf::Mouse::getPosition(*window).y;

                for (auto iter: textBoxes["Ordering"]) {
                    if (iter.second->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                        for (auto iter2: textBoxes["Ordering"]) {
                            iter2.second->selected = false;
                            iter2.second->setColor(sf::Color::White);
                        }
                        iter.second->selected = true;
                        iter.second->setColor({240, 240, 255});
                    }
                }
                for(auto iter: buttons["Ordering"]) {
                    if(iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                        if(iter.second->getText() == "Log Out"){
                            currentUser = "";
                            applicationState = "Login";
                            return;
                        }
                        else if(iter.second->getText() == "My Account"){
                            applicationState = "MyAccount";
                            runMyAccount();
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

            renderOrderWindow();
        }
    }
}


/*------------------------------------------------------------------------*/
/*-------------------Create-Account Window Functionality------------------*/
/*------------------------------------------------------------------------*/

bool Application::createAccount(const std::string& username, const std::string& password){
    // TODO: Add comments

    if(username.size() > 0 && password.size() > 0){
        auto database = conn["user_data"];
        auto collection = database["users"];

        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", username)));

        if(resultUserSearch){
            accountErr = 2;
            return false;
        }
        else{
            bsoncxx::builder::basic::document document{};
            document.append(bsoncxx::builder::basic::kvp("Username", username));
            document.append(bsoncxx::builder::basic::kvp("Password", password));

            collection.insert_one(document.view());

            return true;
        }
    }
    else{
        accountErr = 1;
        return false;
    }
}

void Application::renderCreateAccWindow(){
    // header text
    sf::Text header;
    header.setFont(headerFont);
    header.setFillColor({98, 115, 255});
    header.setString("Create Account");
    header.setPosition(265, 50);
    header.setCharacterSize(65);

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

    window->draw(header);
    window->draw(createUsername);
    window->draw(createPassword);

    sf::Text accountErrText;
    accountErrText.setFont(textFont);
    accountErrText.setCharacterSize(20);
    accountErrText.setFillColor(sf::Color::Red);

    // print error depending on context
    if(accountErr == 1){
        accountErrText.setString("Please enter a valid username and password.");
        accountErrText.setPosition(315, 250);
    }
    else if(accountErr == 2){
        accountErrText.setString("Account with that username already exists.");
        accountErrText.setPosition(335, 250);
    }

    window->draw(accountErrText);

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

                        accountErr = 0;
                    }
                }
                for(auto iter: buttons["CreateAccount"]) {
                    if (iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                        if(iter.second->getText() == "Back"){
                            for(auto iter : textBoxes["CreateAccount"]){
                                iter.second->reset();
                            }

                            accountErr = 0;

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
                    accountErr = 0;

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
        auto database = conn["user_data"];
        auto collection= database["users"];

        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", username)));

        try{
            std::string input = bsoncxx::to_json(*resultUserSearch);

            if(input.size() > 3){
                bsoncxx::document::view getPass = resultUserSearch->view();
                std::string passResult = getPass["Password"].get_utf8().value.to_string();

                // login success
                if(passResult == password){
                    for(auto iter : textBoxes["Login"]){
                        iter.second->reset();
                    }

                    currentUser = username;
                    runOrdering();
                }
                else{
                    loginErr = 2;
                }
            }
            else{
                loginErr = 2;
            }
        }
        catch(const std::exception& e){
            std::cout << "Login error" << std::endl;
        }
    }
    else{
        loginErr = 1;
    }
}

void Application::renderLoginWindow(){
    // header text
    sf::Text header;
    header.setFont(headerFont);
    header.setFillColor({98, 115, 255});
    header.setString("Campus Central Food");
    header.setPosition(175, 50);
    header.setCharacterSize(65);

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

    // draw header text, buttons and text boxes
    window->draw(header);

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

    sf::Text loginErrText;
    loginErrText.setFont(textFont);
    loginErrText.setCharacterSize(20);
    loginErrText.setFillColor(sf::Color::Red);

    // print error depending on context
    if(loginErr == 1){
        loginErrText.setString("Please enter a valid username and password.");
        loginErrText.setPosition(315, 250);
    }
    else if(loginErr == 2){
        loginErrText.setString("Incorrect username or password.");
        loginErrText.setPosition(370, 250);
    }

    window->draw(loginErrText);

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
                        loginErr = 0;
                    }
                }
                for(auto iter : buttons["Login"]){
                    if(iter.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                        if(iter.second->getText() == "Create Account"){
                            for(auto iter : textBoxes["Login"]){
                                iter.second->reset();
                            }

                            loginErr = 0;
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
                    loginErr = 0;
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

    // set the default application state to "Login"
    applicationState = "Login";

    // set the login and createAcc result
    loginErr = 0;
    accountErr = 0;
    newPassErr = 0;
    newUserErr = 0;

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

void Button::setHitbox(sf::RectangleShape inputHitbox){
    hitBox = inputHitbox;
}

sf::RectangleShape Button::getHitbox(){
    return hitBox;
}

std::string Button::getText(){
    return buttonText;
}

Button::Button(sf::Text inputText){
    buttonRenderText = inputText;
    buttonText = inputText.getString();
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
    if(boxText.size() < 18){
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

std::string TextBox::getType(){
    return type;
}

TextBox::TextBox(sf::Text inputRenderText, const std::string& type){
    this->type = type;

    boxText = "";
    boxRenderText = inputRenderText;
    hitbox.setSize({250, 25});
    hitbox.setOutlineColor(sf::Color::Black);
    hitbox.setOutlineThickness(2);
}

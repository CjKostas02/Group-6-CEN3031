#include "application.h"


void Application::loadItems(){
    // TODO: Organize by section

    loadListings();

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
    auto* usernameBox = new TextBox(usernameText, "Username");
    usernameBox->setPosition(400, 400);
    textBoxes["Login"]["Username"] = usernameBox;    // load into map for easy access

    // text object for password box
    sf::Text passwordText;
    passwordText.setFont(textFont);
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setCharacterSize(15);
    passwordText.setPosition(400, 462);

    // create text box for entering password
    auto* passwordBox = new TextBox(passwordText, "Password");
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
    auto* createPassBox = new TextBox(createPassText, "Password");
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
    auto* createAccButton = new Button(createAccText);
    createAccButton->setHitbox(createAccHitbox);

    // add create-account button to map of buttons for easy access
    buttons["Login"]["CreateAccount"] = createAccButton;

    // text object for log in button
    sf::Text loginText;
    loginText.setFont(textFont);
    loginText.setFillColor({223, 226, 255});
    loginText.setCharacterSize(20);
    loginText.setString("Log In");
    loginText.setPosition(495, 500);

    // log in button clickable area
    sf::RectangleShape loginHitbox({250,28});
    loginHitbox.setPosition(400,500);
    loginHitbox.setFillColor({98,115,255});

    // log in button object
    auto* loginButton = new Button(loginText);
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
    auto* confirmCreateButton = new Button(completeCreateText);
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
    auto* backButton = new Button(backText);
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
    buttons["CreateListing"]["Back"] = backButton;
    buttons["SelectListing"]["Back"] = backButton;


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
    auto* viewAccButton = new Button(viewAccText);
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
    auto* logoutButton = new Button(logoutText);
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
    auto* currentPassBox = new TextBox(currentPassText, "Password");
    currentPassBox->setPosition(200, 340);
    textBoxes["MyAccount"]["CurrentPassword"] = currentPassBox;    // load into map for easy access

    // text object for new password textbox
    sf::Text newPassText;
    newPassText.setFont(textFont);
    newPassText.setFillColor(sf::Color::Black);
    newPassText.setCharacterSize(15);
    newPassText.setPosition(200, 402);

    // create text box for entering new password
    auto* newPassBox = new TextBox(newPassText, "Password");
    newPassBox->setPosition(200, 400);
    textBoxes["MyAccount"]["NewPassword"] = newPassBox;    // load into map for easy access

    // text object for confirming new password textbox
    sf::Text confirmNewPassText;
    confirmNewPassText.setFont(textFont);
    confirmNewPassText.setFillColor(sf::Color::Black);
    confirmNewPassText.setCharacterSize(15);
    confirmNewPassText.setPosition(200, 462);

    // create text box for confirming new password
    auto* confirmNewPassBox = new TextBox(confirmNewPassText, "Password");
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
    auto* changePassButton = new Button(changePassText);
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
    auto* newUserBox = new TextBox(newUserText, "Username");
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
    auto* changeUserButton = new Button(changeUserText);
    changeUserButton->setHitbox(changeUserHitbox);

    // load into map for easy access
    buttons["MyAccount"]["ChangeUsername"] = changeUserButton;
    
    // text object for listing creation button
    sf::Text createListingText;
    createListingText.setFont(headerFont);
    createListingText.setFillColor({223, 226, 255});
    createListingText.setCharacterSize(30);
    createListingText.setString("+");
    createListingText.setPosition(989, 528);

    // create listing button clickable area
    sf::RectangleShape createListingHitbox({35,35});
    createListingHitbox.setPosition(980,530);
    createListingHitbox.setFillColor({98,115,255});

    // create listing button object
    auto* createListingButton = new Button(createListingText);
    createListingButton->setHitbox(createListingHitbox);

    // load into map for easy access
    buttons["Ordering"]["CreateListing"] = createListingButton;

    // text object for confirming listing button
    sf::Text confirmListingText;
    confirmListingText.setFont(textFont);
    confirmListingText.setFillColor({223, 226, 255});
    confirmListingText.setCharacterSize(20);
    confirmListingText.setString("Create Listing");
    confirmListingText.setPosition(820, 530);

    // confirming listing button clickable area
    sf::RectangleShape confirmListingHitbox({250,28});
    confirmListingHitbox.setPosition(760,530);
    confirmListingHitbox.setFillColor({98,115,255});

    // confirming listing button object
    auto* confirmListingButton = new Button(confirmListingText);
    confirmListingButton->setHitbox(confirmListingHitbox);

    // load into map for easy access
    buttons["CreateListing"]["ConfirmListing"] = confirmListingButton;

    // text object for listing name textbox
    sf::Text listingNameText;
    listingNameText.setFont(textFont);
    listingNameText.setFillColor(sf::Color::Black);
    listingNameText.setCharacterSize(15);
    listingNameText.setPosition(35, 282);

    // create text box for entering listing name
    auto* listingNameBox = new TextBox(listingNameText, "Name", 389);
    listingNameBox->setPosition(35, 280);
    textBoxes["CreateListing"]["ListingName"] = listingNameBox;    // load into map for easy access

    // text object for listing price textbox
    sf::Text listingPriceText;
    listingPriceText.setFont(textFont);
    listingPriceText.setFillColor(sf::Color::Black);
    listingPriceText.setCharacterSize(15);
    listingPriceText.setPosition(525, 282);

    // create text box for entering listing price
    auto* listingPriceBox = new TextBox(listingPriceText, "Price", 70);
    listingPriceBox->setPosition(525, 280);
    textBoxes["CreateListing"]["ListingPrice"] = listingPriceBox;    // load into map for easy access

    // text object for listing description textbox
    sf::Text listingDescriptionText;
    listingDescriptionText.setFont(textFont);
    listingDescriptionText.setFillColor(sf::Color::Black);
    listingDescriptionText.setCharacterSize(15);
    listingDescriptionText.setPosition(35, 342);

    // create text box for entering listing description
    auto* listingDescriptionBox = new TextBox(listingDescriptionText, "Description", 980);
    listingDescriptionBox->setPosition(35, 340);
    textBoxes["CreateListing"]["ListingDescription"] = listingDescriptionBox;    // load into map for easy access

    // text object for next page button
    sf::Text nextPageText;
    nextPageText.setFont(textFont);
    nextPageText.setFillColor({223, 226, 255});
    nextPageText.setCharacterSize(20);
    nextPageText.setString("Next >");
    nextPageText.setPosition(222, 550);

    // next page button clickable area
    sf::RectangleShape nextPageHitbox({102,28});
    nextPageHitbox.setPosition(200,550);
    nextPageHitbox.setFillColor({98,115,255});

    // next page button object
    auto* nextPageButton = new Button(nextPageText);
    nextPageButton->setHitbox(nextPageHitbox);

    // load into map for easy access
    buttons["SelectListing"]["NextPage"] = nextPageButton;

    // text object for previous page button
    sf::Text previousPageText;
    previousPageText.setFont(textFont);
    previousPageText.setFillColor({223, 226, 255});
    previousPageText.setCharacterSize(20);
    previousPageText.setString("< Previous");
    previousPageText.setPosition(52, 550);

    // previous page button clickable area
    sf::RectangleShape previousPageHitbox({102,28});
    previousPageHitbox.setPosition(50,550);
    previousPageHitbox.setFillColor({98,115,255});

    // previous page button object
    auto* previousPageButton = new Button(previousPageText);
    previousPageButton->setHitbox(previousPageHitbox);

    // load into map for easy access
    buttons["SelectListing"]["PreviousPage"] = previousPageButton;
}

void Application::interpretKey(sf::Keyboard::Key keyCode){
    if(keyCode == 57){
        for (auto& [key, box] : textBoxes["CreateListing"]) {
            if (box->selected) {
                box->addChar(' ');
            }
        }
    }

    // if a valid key is pressed
    if(keyCode >= 0 && keyCode <= 35) {
        // if user is pressing shift
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            // add alternate character to selected text box
            for (auto& [key, box] : textBoxes[applicationState]) {
                if (box->selected) {
                    box->addChar(characters[keyCode + 36]);
                }
            }
        }
        else{
            // add character to selected text box
            for (auto& [key, box] : textBoxes[applicationState]) {
                if (box->selected) {
                    box->addChar(characters[keyCode]);
                }
            }
        }
    }
    // other valid keys
    else if(keyCode >= 46 && keyCode <= 56){
        // if user is pressing shift
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            // add alternate character to selected textbox
            for (auto& [key, box] : textBoxes[applicationState]) {
                if (box->selected) {
                    box->addChar(characters[keyCode + 37]);
                }
            }
        }
        else{
            // add character to selected text box
            for (auto& [key, box] : textBoxes[applicationState]) {
                if (box->selected) {
                    box->addChar(characters[keyCode + 26]);
                }
            }
        }
    }
    // if the user pressed backspace
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
        // delete the last character from selected text box
        for (auto& [key, box] : textBoxes[applicationState]) {
            if (box->selected && box->getText().size() > 0) {
                box->backspace();
            }
        }
    }
}

void Application::loadListings(){
    listings = {};
    eateries = {};

    auto database = (*conn)["user_data"];
    auto userCollection = database["users"];
    auto listingCollection = database["listings"];


    auto items = listingCollection.find({});

    for(auto document : items){
        auto user = userCollection.find_one(
                bsoncxx::builder::basic::make_document(
                        bsoncxx::builder::basic::kvp("_id",
                                                     bsoncxx::oid{document["OwnerID"].get_utf8().value.to_string()})));
        auto userConvert = user->view();

        Listing listing(document["Name"].get_utf8().value.to_string(),
                        document["Price"].get_utf8().value.to_string(),
                        document["Description"].get_utf8().value.to_string(),
                        document["OwnerID"].get_utf8().value.to_string(),
                        userConvert["Username"].get_utf8().value.to_string(),
                        textFont);
        listings[document["OwnerID"].get_utf8().value.to_string()].push_back(listing);
    }

    for (auto& [key, users] : listings) {
        Eatery eatery(users[0].ownerName, users[0].ownerID, headerFont);
        eateries.push_back(eatery);
    }
}

/*------------------------------------------------------------------------*/
/*-------------------Create Listing Window Functionality------------------*/
/*------------------------------------------------------------------------*/
bool Application::createListing(const std::string& name, const std::string& price, const std::string& description){
    auto database = (*conn)["user_data"];
    auto collection = database["listings"];

    bsoncxx::builder::basic::document document{};
    document.append(bsoncxx::builder::basic::kvp("Name", name));
    document.append(bsoncxx::builder::basic::kvp("OwnerID", userID));
    document.append(bsoncxx::builder::basic::kvp("Price", price));
    document.append(bsoncxx::builder::basic::kvp("Description", description));

    collection.insert_one(document.view());

    return true;
}

void Application::renderCreateListingWindow(){
    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Create a food listing");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);

    // set window background color
    window->clear({223, 226, 255});

    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});

    sf::Text listingName;
    listingName.setFont(textFont);
    listingName.setFillColor({98, 115, 255});
    listingName.setString("Listing Name:");
    listingName.setPosition(35, 252);
    listingName.setCharacterSize(20);

    sf::Text listingPrice;
    listingPrice.setFont(textFont);
    listingPrice.setFillColor({98, 115, 255});
    listingPrice.setString("Price:");
    listingPrice.setPosition(525, 252);
    listingPrice.setCharacterSize(20);

    sf::Text listingDescription;
    listingDescription.setFont(textFont);
    listingDescription.setFillColor({98, 115, 255});
    listingDescription.setString("Listing Description:");
    listingDescription.setPosition(35, 312);
    listingDescription.setCharacterSize(20);


    window->draw(listingName);
    window->draw(listingPrice);
    window->draw(listingDescription);
    window->draw(windowHeader);
    window->draw(headerText);

    // draw the buttons and text boxes on render window
    for (auto& [key, button] : buttons["CreateListing"]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }
    for (auto& [key, textBox] : textBoxes["CreateListing"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
    }

    // render window
    window->display();
}


/*------------------------------------------------------------------------*/
/*---------------------My Account Window Functionality--------------------*/
/*------------------------------------------------------------------------*/
void Application::changeUsername(){
    // TODO: Add comments, change format of changeUsername
    //  and changePassword to be similar to createAccount
    //  and verifyLogin to reduce map traversals
    if(textBoxes["MyAccount"]["NewUsername"]->getText() == currentUser){
        newUserErr = 2;
        return;
    }
    else if(textBoxes["MyAccount"]["NewUsername"]->getText().size() == 0){
        newUserErr = 3;
        return;
    }
    else{
        auto database = (*conn)["user_data"];
        auto collection = database["users"];

        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(
                        "Username", textBoxes["MyAccount"]["NewUsername"]->getText())));

        if(resultUserSearch){
            newUserErr = 1;
        }
        else{
            newUserErr = 4;

            bsoncxx::builder::stream::document getDoc;
            getDoc << "Username" << currentUser;

            bsoncxx::builder::stream::document modifyDoc;

            modifyDoc << "$set" << bsoncxx::builder::stream::open_document
                      << "Username" << textBoxes["MyAccount"]["NewUsername"]->getText()
                      << bsoncxx::builder::stream::close_document;

            collection.update_one(getDoc.view(), modifyDoc.view());

            currentUser = textBoxes["MyAccount"]["NewUsername"]->getText();

            for (auto& [key, textBox] : textBoxes["MyAccount"]) {
                textBox->reset();
            }
        }
    }
}

void Application::changePassword(){
    // TODO: Add comments

    auto database = (*conn)["user_data"];
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
                    newPassErr = 5;

                    bsoncxx::builder::stream::document getDoc;
                    getDoc << "Username" << currentUser;

                    bsoncxx::builder::stream::document modifyDoc;

                    modifyDoc << "$set" << bsoncxx::builder::stream::open_document
                    << "Password" << textBoxes["MyAccount"]["NewPassword"]->getText()
                    << bsoncxx::builder::stream::close_document;

                    collection.update_one(getDoc.view(), modifyDoc.view());

                    for (auto& [key, textBox] : textBoxes["MyAccount"]) {
                        textBox->reset();
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
    for (auto& [key, button] : buttons["MyAccount"]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }
    for (auto& [key, textBox] : textBoxes["MyAccount"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
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
    else if(newUserErr == 4){
        newUserErrorText.setFillColor({98, 115, 255});
        newUserErrorText.setString("Username changed successfully!");
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
    else if(newPassErr == 5){
        newPassErrorText.setFillColor({98, 115, 255});
        newPassErrorText.setString("Password changed successfully!");
        newPassErrorText.setPosition(185, 250);
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


/*------------------------------------------------------------------------*/
/*----------------------Ordering Window Functionality---------------------*/
/*------------------------------------------------------------------------*/
void Application::renderSelectEateryWindow(){
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
    for (auto& [key, button] : buttons["Ordering"]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }
    for (auto& [key, textBox] : textBoxes["Ordering"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
    }

    float column = 0;
    float row = 0;

    for(auto eatery : eateries){
        if(eatery.userID == userID) {
            eatery.background->setPosition({20 + (column * 220), 70 + (row * 220)});
            //eatery.moveBackground(20 + (column * 220), 70 + (row * 220));
            eatery.renderName.setPosition({119 + (column * 220), 82 + (row * 220)});

            eatery.background->setOutlineThickness(2);
            eatery.background->setOutlineColor(sf::Color::Black);

            window->draw(*(eatery.background));
            window->draw(eatery.renderName);

            if (column < 3) {
                column++;
            } else {
                row++;
                column = 0;
            }
            break;
        }
    }

    for(auto eatery : eateries){
        if(eatery.userID != userID){
            eatery.background->setPosition({20 + (column * 220), 70 + (row * 220)});
            //eatery.moveBackground(20 + (column * 220), 70 + (row * 220));
            eatery.renderName.setPosition({119 + (column * 220), 82 + (row * 220)});

            eatery.background->setOutlineThickness(2);
            eatery.background->setOutlineColor(sf::Color::Black);

            window->draw(*(eatery.background));
            window->draw(eatery.renderName);

            if(column < 3){
                column++;
            }
            else{
                row++;
                column = 0;
            }
        }
    }

    // render window
    window->display();
}

void Application::renderSelectListingWindow(){
    // TODO: Add comments

    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Select your order");
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
    for(auto iter : buttons["SelectListing"]){
        window->draw(iter.second->getHitbox());
        window->draw(iter.second->getRenderText());
    }
    for(auto iter : textBoxes["SelectListing"]){
        window->draw(iter.second->getRect());
        window->draw(iter.second->getRenderText());
    }

    float column = 0;
    float row = 0;

    for(Listing listing : listings[selectedEatery]){
        listing.background->setPosition({5000, 5000});
    }

    for(int i = 6 * listingPage; i < listings[selectedEatery].size(); i++){
        if(row < 2){
            listings[selectedEatery][i].background->setPosition({20 + (column * 345), 95 + (row * 220)});
            listings[selectedEatery][i].shadow.setPosition({25 + (column * 345), 100 + (row * 220)});
            listings[selectedEatery][i].renderName.setPosition({177 + (column * 345), 107 + (row * 220)});
            listings[selectedEatery][i].background->setOutlineColor(sf::Color::Black);

            window->draw(listings[selectedEatery][i].shadow);
            window->draw(*listings[selectedEatery][i].background);
            window->draw(listings[selectedEatery][i].renderName);

            if(column < 2){
                column++;
            }
            else{
                row++;
                column = 0;
            }
        }
    }


    /*for(auto listing : listings[selectedEatery]){
        listing.background.setPosition({20 + (column * 220), 95 + (row * 220)});
        listing.renderName.setPosition({119 + (column * 220), 107 + (row * 220)});

        listing.background.setOutlineThickness(2);
        listing.background.setOutlineColor(sf::Color::Black);

        window->draw(listing.background);
        window->draw(listing.renderName);

        if(column < 3){
            column++;
        }
        else{
            row++;
            column = 0;
        }
    }*/

    // render window
    window->display();
}


/*------------------------------------------------------------------------*/
/*-------------------Create-Account Window Functionality------------------*/
/*------------------------------------------------------------------------*/
bool Application::createAccount(const std::string& username, const std::string& password){
    // TODO: Add comments

    if(username.size() > 0 && password.size() > 0){
        auto database = (*conn)["user_data"];
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
    for (auto& [key, button] : buttons["CreateAccount"]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }
    for (auto& [key, textBox] : textBoxes["CreateAccount"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
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


/*------------------------------------------------------------------------*/
/*-----------------------Login Window Functionality-----------------------*/
/*------------------------------------------------------------------------*/
void Application::verifyLogin(const std::string& username, const std::string& password){
    // TODO: Add comments

    if(username.size() > 0 && password.size() > 0){
        auto database = (*conn)["user_data"];
        auto collection= database["users"];

        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", username)));

        if(!resultUserSearch){
            loginErr = 2;
        }
        else{
            try{
                std::string input = bsoncxx::to_json(*resultUserSearch);

                if(input.size() > 3){
                    bsoncxx::document::view getUser = resultUserSearch->view();
                    std::string passResult = getUser["Password"].get_utf8().value.to_string();
                    // login success
                    if(passResult == password){
                        for(auto iter : textBoxes["Login"]){
                            iter.second->reset();
                        }
                        userID = getUser["_id"].get_oid().value.to_string();
                        currentUser = username;
                        applicationState = "Ordering";
                        loadListings();
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
                loginErr = 1;
            }
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

    for (auto& [key, button] : buttons["Login"]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }
    for (auto& [key, textBox] : textBoxes["Login"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
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


/*------------------------------------------------------------------------*/
/*------------------------Main Application Driver-------------------------*/
/*------------------------------------------------------------------------*/
void Application::run(){
    float mouseX;
    float mouseY;

    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                return;
            }
            if(event.type == sf::Event::MouseButtonReleased) {
                mouseX = sf::Mouse::getPosition(*window).x;
                mouseY = sf::Mouse::getPosition(*window).y;

                if(applicationState == "Login"){
                    for(auto& [key, textBox] : textBoxes[applicationState]) {
                        if(textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                            for (auto iter2: textBoxes[applicationState]) {
                                iter2.second->selected = false;
                                iter2.second->setColor(sf::Color::White);
                            }
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});

                            loginErr = 0;
                        }
                    }
                    for(auto button: buttons[applicationState]) {
                        if (button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                            if (button.second->getText() == "Log In") {
                                verifyLogin(textBoxes["Login"]["Username"]->getText(),
                                            textBoxes["Login"]["Password"]->getText());
                            } else if (button.second->getText() == "Create Account") {
                                for (auto textBox: textBoxes[applicationState]) {
                                    textBox.second->reset();
                                }
                                loginErr = 0;
                                applicationState = "CreateAccount";
                            }
                        }
                    }
                }
                else if(applicationState == "CreateAccount"){
                    for(auto& [key, textBox] : textBoxes[applicationState]) {
                        if (textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                            for (auto iter2: textBoxes[applicationState]) {
                                iter2.second->selected = false;
                                iter2.second->setColor(sf::Color::White);
                            }
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});

                            accountErr = 0;
                        }
                    }
                    for(auto button: buttons[applicationState]){
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            if(button.second->getText() == "Create Account") {
                                if(createAccount(textBoxes["CreateAccount"]["CreateUser"]->getText(),
                                                  textBoxes["CreateAccount"]["CreatePass"]->getText())){
                                    for(auto textBox: textBoxes["CreateAccount"]){
                                        textBox.second->reset();
                                    }

                                    applicationState = "Login";
                                }
                            }
                            if(button.second->getText() == "Back") {
                                for (auto textBox: textBoxes[applicationState]) {
                                    textBox.second->reset();
                                }
                                applicationState = "Login";
                                accountErr = 0;
                            }
                        }
                    }
                }
                else if(applicationState == "Ordering"){
                    for(auto button: buttons[applicationState]) {
                        if (button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                            if(button.second->getText() == "Log Out") {
                                currentUser = "";
                                userID = "";
                                applicationState = "Login";
                            }
                            else if(button.second->getText() == "My Account"){
                                applicationState = "MyAccount";
                            }
                            else if(button.second->getText() == "+"){
                                applicationState = "CreateListing";
                            }
                        }
                    }
                    for(Eatery eatery: eateries){
                        if(eatery.background->getGlobalBounds().contains(mouseX, mouseY)){
                            selectedEatery = eatery.userID;
                            applicationState = "SelectListing";
                        }
                    }
                }
                else if(applicationState == "MyAccount"){
                    for(auto& [key, textBox] : textBoxes[applicationState]) {
                        if(textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                            for (auto& [key, innerTextBox] : textBoxes[applicationState]) {
                                innerTextBox->selected = false;
                                innerTextBox->setColor(sf::Color::White);
                            }
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});

                            newPassErr = 0;
                            newUserErr = 0;

                            if (textBox->getType() == "Password") {
                                for (auto iter: textBoxes["MyAccount"]) {
                                    if (iter.second->getType() == "Username") {
                                        iter.second->reset();
                                    }
                                }
                            }
                            else if (textBox->getType() == "Username") {
                                for (auto iter: textBoxes["MyAccount"]) {
                                    if (iter.second->getType() == "Password") {
                                        iter.second->reset();
                                    }
                                }
                            }
                        }
                    }
                    for(auto button: buttons[applicationState]) {
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            if(button.second->getText() == "Back") {
                                for(auto textBox: textBoxes[applicationState]){
                                    textBox.second->reset();
                                }
                                newUserErr = 0;
                                newPassErr = 0;
                                applicationState = "Ordering";
                            }
                            else if(button.second->getText() == "Change Password"){
                                newUserErr = 0;
                                for(auto textBox: textBoxes[applicationState]){
                                    if(textBox.second->getType() == "Username"){
                                        textBox.second->reset();
                                    }
                                }
                                changePassword();
                            }
                            else if(button.second->getText() == "Change Username"){
                                for(auto textBox: textBoxes[applicationState]){
                                    if(textBox.second->getType() == "Password"){
                                        textBox.second->reset();
                                    }
                                }
                                newPassErr = 0;
                                changeUsername();
                            }
                        }
                    }
                }
                else if(applicationState == "CreateListing"){
                    for (auto& [key, textBox] : textBoxes[applicationState]) {
                        if (textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)) {
                            for (auto& [key, innerTextBox] : textBoxes[applicationState]) {
                                innerTextBox->selected = false;
                                innerTextBox->setColor(sf::Color::White);
                            }
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});
                        }
                    }
                    for(auto button: buttons[applicationState]){
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            if(button.second->getText() == "Back") {
                                for (auto textBox: textBoxes[applicationState]) {
                                    textBox.second->reset();
                                }
                                applicationState = "Ordering";
                            }
                            else if(button.second->getText() == "Create Listing"){
                                if(createListing(textBoxes["CreateListing"]["ListingName"]->getText(),
                                                 textBoxes["CreateListing"]["ListingPrice"]->getText(),
                                                 textBoxes["CreateListing"]["ListingDescription"]->getText())){
                                    for(auto textBox: textBoxes[applicationState]){
                                        textBox.second->reset();
                                    }
                                    applicationState = "Ordering";
                                    loadListings();
                                }
                            }
                        }
                    }
                }
                else if(applicationState == "SelectListing"){
                    for(auto button: buttons[applicationState]) {
                        if (button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                            if(button.second->getText() == "Back"){
                                listingPage = 0;
                                applicationState = "Ordering";
                            }
                            else if(button.second->getText() == "Next >"){
                                if(8 * (listingPage + 1) < listings[selectedEatery].size()){
                                    listingPage++;
                                }
                            }
                            else if(button.second->getText() == "< Previous"){
                                if(listingPage > 0){
                                    listingPage--;
                                }
                            }
                        }
                    }
                    for(Listing listing : listings[selectedEatery]){
                        if(listing.background->getGlobalBounds().contains(mouseX, mouseY)){
                            std::cout << listing.name << std::endl;
                        }
                    }
                }
            }
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Key::Enter){
                    if(applicationState == "Login"){
                        verifyLogin(textBoxes["Login"]["Username"]->getText(),
                                    textBoxes["Login"]["Password"]->getText());
                    }
                    else if(applicationState == "CreateAccount"){
                        if(createAccount(textBoxes["CreateAccount"]["CreateUser"]->getText(),
                                          textBoxes["CreateAccount"]["CreatePass"]->getText())){
                            for(auto iter: textBoxes["CreateAccount"]){
                                iter.second->reset();
                            }
                            applicationState = "Login";
                        }
                    }
                    else if(applicationState == "MyAccount"){
                        for(auto textBox: textBoxes["MyAccount"]){
                            if (textBox.second->selected && textBox.second->getType() == "Password"){
                                changePassword();
                            }
                            else if(textBox.second->selected && textBox.second->getType() == "Username"){
                                changeUsername();
                            }
                        }
                    }
                    else if (applicationState == "CreateListing") {
                        if (createListing(textBoxes["CreateListing"]["ListingName"]->getText(),
                                          textBoxes["CreateListing"]["ListingPrice"]->getText(),
                                          textBoxes["CreateListing"]["ListingDescription"]->getText())){
                            for (auto& [key, textBox] : textBoxes[applicationState]){
                                textBox->reset();
                            }
                            applicationState = "Ordering";
                            loadListings();
                        }
                    }
                }
                else{
                    accountErr = 0;
                    loginErr = 0;
                    interpretKey(event.key.code);
                }
            }

            if(applicationState == "Login"){
                renderLoginWindow();
            }
            else if(applicationState == "CreateAccount"){
                renderCreateAccWindow();
            }
            else if(applicationState == "Ordering"){
                renderSelectEateryWindow();
            }
            else if(applicationState == "MyAccount"){
                renderMyAccountWindow();
            }
            else if(applicationState == "CreateListing"){
                renderCreateListingWindow();
            }
            else if(applicationState == "SelectListing"){
                renderSelectListingWindow();
            }
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
    eateryPage = 0;
    listingPage = 0;

    // Create an instance.
    uri = new mongocxx::uri{"mongodb+srv://default_user:defaultPassword@group6ccf.ka8iy.mongodb.net/?retryWrites=true&w=majority&appName=Group6CCF"};
    conn = new mongocxx::client{*uri};

    // load all items into the program
    loadItems();
}


/*------------------------------------------------------------------------*/
/*----------------------------Button Functions----------------------------*/
/*------------------------------------------------------------------------*/
sf::Text Button::getRenderText() const {
    return buttonRenderText;
}

void Button::setHitbox(const sf::RectangleShape& inputHitbox) {
    hitBox = inputHitbox;
}

sf::RectangleShape Button::getHitbox() const {
    return hitBox;
}

std::string Button::getText() const {
    return buttonText;
}

Button::Button(const sf::Text& inputText) {
    buttonRenderText = inputText;
    buttonText = inputText.getString();
}


/*------------------------------------------------------------------------*/
/*-----------------------Listing/Eatery Constructors----------------------*/
/*------------------------------------------------------------------------*/
Listing::Listing(const std::string& name, const std::string& price, const std::string& description,
                 const std::string& ownerID, const std::string& ownerName, sf::Font& textFont){
    this->name = name;
    this->price = price;
    this->ownerID = ownerID;
    this->ownerName = ownerName;
    this->description = description;

    background = new sf::RectangleShape({315,200});
    background->setFillColor(sf::Color::White);
    background->setOutlineThickness(1);

    shadow.setSize({315,200});
    shadow.setFillColor({203, 206, 235});

    renderName.setString(name);
    renderName.setFont(textFont);
    renderName.setFillColor(sf::Color::Black);
    renderName.setCharacterSize(12);
    renderName.setOrigin({renderName.getGlobalBounds().getSize().x / 2, renderName.getGlobalBounds().getSize().y / 2});
}

Eatery::Eatery(const std::string& name, const std::string& userID, sf::Font& textFont){
    this->name = name;
    this->userID = userID;

    background = new sf::RectangleShape;

    background->setFillColor(sf::Color::White);
    background->setSize({200,200});

    renderName.setString(name);
    renderName.setFont(textFont);
    renderName.setFillColor(sf::Color::Black);
    renderName.setCharacterSize(12);
    renderName.setOrigin({renderName.getGlobalBounds().getSize().x / 2, renderName.getGlobalBounds().getSize().y / 2});
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

sf::RectangleShape TextBox::getRect() const {
    return hitbox;
}

void TextBox::addChar(char character){
    if(type == "Password"){
        std::string hideText;
        for(int i = 0; i < boxText.size(); i++){
            hideText += '*';
        }
        sf::Text tempRenderText = boxRenderText;
        tempRenderText.setString(hideText + character);
        if(tempRenderText.getGlobalBounds().getSize().x < hitbox.getSize().x){
            boxText += character;
            boxRenderText.setString(hideText + character);
        }
    }
    else{
        if(type != "Price" || (type == "Price" && (isdigit(character) || character == '.' || character == ','))){
            sf::Text tempRenderText = boxRenderText;
            tempRenderText.setString(boxText + character);

            if(tempRenderText.getGlobalBounds().getSize().x < hitbox.getSize().x){
                boxText += character;
                boxRenderText.setString(boxText);
            }
        }
    }
}

std::string TextBox::getText() const {
    return boxText;
}

sf::Text TextBox::getRenderText() const {
    return boxRenderText;
}

void TextBox::backspace(){
    boxText.erase(boxText.end() - 1);

    if(type == "Password"){
        std::string hideText;
        for(char i : boxText){
            hideText += '*';
        }
        boxRenderText.setString(hideText);
    }
    else{
        boxRenderText.setString(boxText);
    }
}

void TextBox::reset(){
    boxText = "";
    selected = false;
    boxRenderText.setString("");
    hitbox.setFillColor(sf::Color::White);
}

std::string TextBox::getType() const {
    return type;
}

TextBox::TextBox(sf::Text& inputRenderText, const std::string& type, const float& width){
    this->type = type;

    boxText = "";
    boxRenderText = inputRenderText;
    hitbox.setSize({width, 25});
    hitbox.setOutlineColor(sf::Color::Black);
    hitbox.setOutlineThickness(2);
}

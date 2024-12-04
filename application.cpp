#include "application.h"


void Application::loadItems(){
    loadListings();

    // load Open Sans font: https://fonts.google.com/specimen/Open+Sans
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
    sf::RectangleShape* createAccHitbox = new sf::RectangleShape({120,20});
    createAccHitbox->setPosition(465,555);
    createAccHitbox->setFillColor({223, 226, 255});

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
    sf::RectangleShape* loginHitbox = new sf::RectangleShape({250,28});
    loginHitbox->setPosition(400,500);
    loginHitbox->setFillColor({98,115,255});

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
    sf::RectangleShape* completeCreateHitbox = new sf::RectangleShape({250,28});
    completeCreateHitbox->setPosition(400,500);
    completeCreateHitbox->setFillColor({98,115,255});

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
    backText.setPosition(20, 60);

    // clickable area for back-button
    sf::RectangleShape* backHitbox = new sf::RectangleShape({45,25});
    backHitbox->setPosition(20,60);
    backHitbox->setFillColor({223, 226, 255});

    // button object for back-button
    auto* backButton = new Button(backText);
    backButton->setHitbox(backHitbox);

    // add back button to map of buttons for easy access
    buttons["CreateAccount"]["Back"] = backButton;
    buttons["MyAccount"]["Back"] = backButton;
    buttons["CreateListing"]["Back"] = backButton;
    buttons["SelectListing"]["Back"] = backButton;
    buttons["ViewListing"]["Back"] = backButton;

    // text object for my account button
    sf::Text viewAccText;
    viewAccText.setFont(textFont);
    viewAccText.setFillColor({98, 115, 255});
    viewAccText.setCharacterSize(20);
    viewAccText.setString("My Account");
    viewAccText.setPosition(900, 0);

    // my account button clickable area
    sf::RectangleShape* viewAccHitbox = new sf::RectangleShape({110,25});
    viewAccHitbox->setPosition(900,0);
    viewAccHitbox->setFillColor({200, 200, 255});

    // my account button object
    auto* viewAccButton = new Button(viewAccText);
    viewAccButton->setHitbox(viewAccHitbox);

    // add my account button to map of buttons for easy access
    buttons["Ordering"]["ViewAccount"] = viewAccButton;

    // text object for log out button
    sf::Text logoutText;
    logoutText.setFont(textFont);
    logoutText.setFillColor({98, 115, 255});
    logoutText.setCharacterSize(15);
    logoutText.setString("Log Out");
    logoutText.setPosition(925, 28);

    // log out button clickable area
    sf::RectangleShape* logoutHitbox = new sf::RectangleShape({55,20});
    logoutHitbox->setPosition(925,28);
    logoutHitbox->setFillColor({200, 200, 255});

    // log out button object
    auto* logoutButton = new Button(logoutText);
    logoutButton->setHitbox(logoutHitbox);

    // add log out button to map of buttons for easy access
    buttons["Ordering"]["Logout"] = logoutButton;


    // text for purchase button
    sf::Text purchaseText;
    purchaseText.setFont(textFont);
    purchaseText.setString("Purchase");
    purchaseText.setFillColor({223, 226, 255});
    purchaseText.setCharacterSize(20);
    purchaseText.setPosition(20, 490);

    auto* purchaseButton = new Button(purchaseText);

    // purchase button hitbox
    sf::RectangleShape* purchaseHitbox = new sf::RectangleShape({90,28});
    purchaseHitbox->setPosition(20, 490);
    purchaseHitbox->setFillColor({98,115,255});
    purchaseButton->setHitbox(purchaseHitbox);

    buttons["ViewListing"]["Purchase"] = purchaseButton;

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
    sf::RectangleShape* changePassHitbox = new sf::RectangleShape({250,28});
    changePassHitbox->setPosition(200,500);
    changePassHitbox->setFillColor({98,115,255});

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
    sf::RectangleShape* changeUserHitbox = new sf::RectangleShape({250,28});
    changeUserHitbox->setPosition(600,500);
    changeUserHitbox->setFillColor({98,115,255});

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
    createListingText.setPosition(959, 428);

    // create listing button clickable area
    sf::RectangleShape* createListingHitbox = new sf::RectangleShape({35,35});
    createListingHitbox->setPosition(950,430);
    createListingHitbox->setFillColor({98,115,255});

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
    sf::RectangleShape* confirmListingHitbox = new sf::RectangleShape({250,28});
    confirmListingHitbox->setPosition(760,530);
    confirmListingHitbox->setFillColor({98,115,255});

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
    nextPageText.setPosition(918, 550);

    // next page button clickable area
    sf::RectangleShape* nextPageHitbox = new sf::RectangleShape({102,28});
    nextPageHitbox->setPosition(898,550);
    nextPageHitbox->setFillColor({98,115,255});

    // next page button object
    auto* nextPageButton = new Button(nextPageText);
    nextPageButton->setHitbox(nextPageHitbox);

    // load into map for easy access
    buttons["SelectListing"]["NextPage"] = nextPageButton;
    buttons["Ordering"]["NextPage"] = nextPageButton;

    // text object for previous page button
    sf::Text previousPageText;
    previousPageText.setFont(textFont);
    previousPageText.setFillColor({223, 226, 255});
    previousPageText.setCharacterSize(20);
    previousPageText.setString("< Previous");
    previousPageText.setPosition(52, 550);

    // previous page button clickable area
    sf::RectangleShape* previousPageHitbox = new sf::RectangleShape({102,28});
    previousPageHitbox->setPosition(50,550);
    previousPageHitbox->setFillColor({98,115,255});

    // previous page button object
    auto* previousPageButton = new Button(previousPageText);
    previousPageButton->setHitbox(previousPageHitbox);

    // load into map for easy access
    buttons["SelectListing"]["PreviousPage"] = previousPageButton;
    buttons["Ordering"]["PreviousPage"] = previousPageButton;

    // text object for refresh button
    sf::Text refreshText;
    refreshText.setFont(textFont);
    refreshText.setFillColor({98,115,255});
    refreshText.setCharacterSize(20);
    refreshText.setString("Refresh");
    refreshText.setPosition(922, 70);

    // refresh button clickable area
    sf::RectangleShape* refreshHitbox = new sf::RectangleShape({72,28});
    refreshHitbox->setFillColor({223, 226, 255});
    refreshHitbox->setPosition(920,70);

    // refresh button object
    auto* refreshButton = new Button(refreshText);
    refreshButton->setHitbox(refreshHitbox);

    // load into map for easy access
    buttons["Ordering"]["Refresh"] = refreshButton;
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
    // clear/initialize listings and eatery vectors
    listings = {};
    eateries = {};

    // initialize MongoDB database and collection
    auto database = (*conn)["user_data"];
    auto userCollection = database["users"];
    auto listingCollection = database["listings"];

    // get all listings from MongoDB collection
    auto items = listingCollection.find({});

    // loop through listings
    for(auto document : items){
        // get the UserID of listing owner
        auto user = userCollection.find_one(
                bsoncxx::builder::basic::make_document(
                        bsoncxx::builder::basic::kvp("_id",
                                                     bsoncxx::oid{document["OwnerID"].get_utf8().value.to_string()})));
        auto userConvert = user->view();

        // create listing object with values from MongoDB collection
        Listing listing(document["Name"].get_utf8().value.to_string(),
                        document["Price"].get_utf8().value.to_string(),
                        document["Description"].get_utf8().value.to_string(),
                        document["OwnerID"].get_utf8().value.to_string(),
                        userConvert["Username"].get_utf8().value.to_string(),
                        textFont);

        // store listing in application class variable
        listings[document["OwnerID"].get_utf8().value.to_string()].push_back(listing);
    }

    // load eateries from listings
    for (auto& [key, users] : listings) {
        Eatery eatery(users[0].ownerName, users[0].ownerID, headerFont);
        eateries.push_back(eatery);
    }
}


/*------------------------------------------------------------------------*/
/*-------------------Create Listing Window Functionality------------------*/
/*------------------------------------------------------------------------*/
bool Application::createListing(const std::string& name, const std::string& price, const std::string& description){
    if(name.length() == 0 || price.length() == 0 || description.length() == 0){
        newListingErr = 1;
    }
    else{
        // initialize MongoDB database and collection
        auto database = (*conn)["user_data"];
        auto collection = database["listings"];

        // create listing entry
        bsoncxx::builder::basic::document document{};
        document.append(bsoncxx::builder::basic::kvp("Name", name));
        document.append(bsoncxx::builder::basic::kvp("OwnerID", userID));
        document.append(bsoncxx::builder::basic::kvp("Price", price));
        document.append(bsoncxx::builder::basic::kvp("Description", description));

        // store listing in MongoDB collection
        collection.insert_one(document.view());

        return true;
    }
    return false;
}

void Application::renderCreateListingWindow(){
    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Create a food listing");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);

    // window header rectangle
    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});

    // text object for listing name
    sf::Text listingName;
    listingName.setFont(textFont);
    listingName.setFillColor({98, 115, 255});
    listingName.setString("Listing Name:");
    listingName.setPosition(35, 252);
    listingName.setCharacterSize(20);

    // text object for listing price
    sf::Text listingPrice;
    listingPrice.setFont(textFont);
    listingPrice.setFillColor({98, 115, 255});
    listingPrice.setString("Price:");
    listingPrice.setPosition(525, 252);
    listingPrice.setCharacterSize(20);

    // text object for listing description
    sf::Text listingDescription;
    listingDescription.setFont(textFont);
    listingDescription.setFillColor({98, 115, 255});
    listingDescription.setString("Listing Description:");
    listingDescription.setPosition(35, 312);
    listingDescription.setCharacterSize(20);

    // success/error message object for changing username
    sf::Text listingErrorText;
    listingErrorText.setFont(textFont);
    listingErrorText.setCharacterSize(20);
    listingErrorText.setFillColor(sf::Color::Red);
    listingErrorText.setPosition(425, 150);

    // set message depending on context
    if(newListingErr == 1){
        listingErrorText.setString("Please fill out each entry.");
    }

    // set window background color
    window->clear({223, 226, 255});

    // draw all listing text objects and window header
    window->draw(listingName);
    window->draw(listingPrice);
    window->draw(listingDescription);
    window->draw(windowHeader);
    window->draw(headerText);
    window->draw(listingErrorText);

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
    // get new username from textbox
    std::string newUsername = textBoxes["MyAccount"]["NewUsername"]->getText();

    // if the user attempts to change username to current username
    if(newUsername == currentUser){
        // throw error
        newUserErr = 2;
        return;
    }
    // if the user attempts to change username to an invalid value
    if(newUsername.size() == 0){
        // throw error
        newUserErr = 3;
        return;
    }

    // initialize MongoDB database and collection
    auto database = (*conn)["user_data"];
    auto collection = database["users"];

    // determine username availability
    auto resultUserSearch = collection.find_one(
            bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(
                    "Username", newUsername)));

    // if desired username is already taken
    if(resultUserSearch){
        // throw error
        newUserErr = 1;
    }
    else{
        // success message
        newUserErr = 4;

        // get current user object to modify
        bsoncxx::builder::stream::document getDoc;
        getDoc << "Username" << currentUser;

        // create modified user object
        bsoncxx::builder::stream::document modifyDoc;

        // set new credentials
        modifyDoc << "$set" << bsoncxx::builder::stream::open_document
                  << "Username" << newUsername
                  << bsoncxx::builder::stream::close_document;

        // update the database
        collection.update_one(getDoc.view(), modifyDoc.view());

        // update the class member variable to reflect changes
        currentUser = newUsername;

        // clear textboxes
        for (auto& [key, textBox] : textBoxes["MyAccount"]) {
            textBox->reset();
        }

        loadListings();
    }

}

void Application::changePassword(){
    // initialize MongoDB database and collection
    auto database = (*conn)["user_data"];
    auto collection= database["users"];

    // get current user object from collection
    auto resultUserSearch = collection.find_one(
            bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", currentUser)));

    std::string input = bsoncxx::to_json(*resultUserSearch);

    // read current password from user object
    bsoncxx::document::view getPass = resultUserSearch->view();
    std::string currentPass = getPass["Password"].get_utf8().value.to_string();

    // verify that user correctly entered current password and entered valid new password
    if(currentPass == textBoxes["MyAccount"]["CurrentPassword"]->getText()){
        if(textBoxes["MyAccount"]["NewPassword"]->getText().size() > 0
           && textBoxes["MyAccount"]["ConfirmNewPassword"]->getText().size() > 0){
            if(currentPass != textBoxes["MyAccount"]["NewPassword"]->getText()){
                if(textBoxes["MyAccount"]["NewPassword"]->getText() == textBoxes["MyAccount"]["ConfirmNewPassword"]->getText()){
                    // success message
                    newPassErr = 5;

                    // get the current user object
                    bsoncxx::builder::stream::document getDoc;
                    getDoc << "Username" << currentUser;

                    // new object to store modifications
                    bsoncxx::builder::stream::document modifyDoc;

                    // modify object
                    modifyDoc << "$set" << bsoncxx::builder::stream::open_document
                    << "Password" << textBoxes["MyAccount"]["NewPassword"]->getText()
                    << bsoncxx::builder::stream::close_document;

                    // update current user object with modified password
                    collection.update_one(getDoc.view(), modifyDoc.view());

                    // clear textboxes
                    for (auto& [key, textBox] : textBoxes["MyAccount"]) {
                        textBox->reset();
                    }
                }
                else{
                    // user incorrectly confirms password
                    newPassErr = 1;
                }
            }
            else{
                // user tries to change password to current password
                newPassErr = 2;
            }
        }
        else{
            // user enters invalid new password
            newPassErr = 3;
        }
    }
    else{
        // user enters incorrect password
        newPassErr = 4;
    }
}

void Application::renderMyAccountWindow(){
    // window header
    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});

    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Modify Account");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);

    // current password text object
    sf::Text currentPass;
    currentPass.setFont(textFont);
    currentPass.setFillColor({98, 115, 255});
    currentPass.setString("Current Password:");
    currentPass.setPosition(200, 315);
    currentPass.setCharacterSize(20);

    // new password text object
    sf::Text newPass;
    newPass.setFont(textFont);
    newPass.setFillColor({98, 115, 255});
    newPass.setString("New Password:");
    newPass.setPosition(200, 375);
    newPass.setCharacterSize(20);

    // new password confirmation text object
    sf::Text confirmNewPass;
    confirmNewPass.setFont(textFont);
    confirmNewPass.setFillColor({98, 115, 255});
    confirmNewPass.setString("Confirm New Password:");
    confirmNewPass.setPosition(200, 435);
    confirmNewPass.setCharacterSize(20);

    // success/error message object for changing username
    sf::Text newUserErrorText;
    newUserErrorText.setFont(textFont);
    newUserErrorText.setCharacterSize(20);
    newUserErrorText.setFillColor(sf::Color::Red);

    // set message depending on context
    if(newUserErr == 1){
        newUserErrorText.setString("Account with that username already exists.");
        newUserErrorText.setPosition(525, 250);
    }
    else if(newUserErr == 2){
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

    // success/error message object for changing password
    sf::Text newPassErrorText;
    newPassErrorText.setFont(textFont);
    newPassErrorText.setCharacterSize(20);
    newPassErrorText.setFillColor(sf::Color::Red);

    // set message depending on context
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

    // new username text object
    sf::Text newUser;
    newUser.setFont(textFont);
    newUser.setFillColor({98, 115, 255});
    newUser.setString("New Username:");
    newUser.setPosition(600, 315);
    newUser.setCharacterSize(20);

    // set window background color
    window->clear({223, 226, 255});

    // draw the buttons and text boxes on render window
    for (auto& [key, button] : buttons["MyAccount"]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }
    for (auto& [key, textBox] : textBoxes["MyAccount"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
    }

    // draw text objects and messages if applicable
    window->draw(windowHeader);
    window->draw(headerText);
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
    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Welcome " + currentUser + "!");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);

    // window header rectangle
    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});

    // set window background color
    window->clear({223, 226, 255});

    // draw window header
    window->draw(windowHeader);
    window->draw(headerText);

    // draw the buttons and text boxes on render window
    for(auto& [key, button] : buttons["Ordering"]){
        // if user has scrolled to another page of eateries, display the "Previous" button
        if(button->getText() == "< Previous"){
            if(eateryPage > 0){
                window->draw(button->getHitbox());
                window->draw(button->getRenderText());
            }
        }
        // if there are multiple pages of eateries, draw "Next" button
        else if(button->getText() == "Next >"){
            if(8 * (eateryPage + 1) < eateries.size()){
                window->draw(button->getHitbox());
                window->draw(button->getRenderText());
            }
        }
        else{
            window->draw(button->getHitbox());
            window->draw(button->getRenderText());
        }
    }
    for (auto& [key, textBox] : textBoxes["Ordering"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
    }

    // column and row variables for displaying eateries
    float column = 0;
    float row = 0;

    // move un-rendered listings off the screen
    for(Eatery eatery : eateries){
        eatery.background->setPosition({5000, 5000});
    }

    if(eateryPage == 0){
        // search for current user in eateries
        for(auto eatery : eateries){
            // if current user has created listings, display current user card first
            if(eatery.userID == userID) {
                // render eatery in top left position
                eatery.background->setPosition({20, 70});
                eatery.shadow.setPosition({25,75});
                eatery.renderName.setPosition({119, 82});

                // draw eatery text and background
                window->draw(eatery.shadow);
                window->draw(*(eatery.background));
                window->draw(eatery.renderName);

                // adjust column
                column++;
                break;
            }
        }
    }

    // read through eateries
    for(int i = 8 * eateryPage; i < eateries.size(); i++){
        if(row < 2){
            // ignore current user
            if(eateries[i].userID != userID){
                // move eatery card to position depending on rows and columns
                eateries[i].background->setPosition({20 + (column * 220), 70 + (row * 220)});
                eateries[i].shadow.setPosition({25 + (column * 220), 75 + (row * 220)});
                eateries[i].renderName.setPosition({119 + (column * 220), 82 + (row * 220)});

                // draw the eatery text and background
                window->draw(eateries[i].shadow);
                window->draw(*(eateries[i].background));
                window->draw(eateries[i].renderName);

                // adjust the rows and columns
                if(column < 3){
                    column++;
                }
                else{
                    // if end of column reached, add a row
                    row++;
                    column = 0;
                }
            }
        }
    }

    // render window
    window->display();
}

void Application::renderSelectListingWindow(){
    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Select Your Order");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);

    // window header rectangle
    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});

    // set window background color
    window->clear({223, 226, 255});

    // draw window header
    window->draw(windowHeader);
    window->draw(headerText);

    // draw the buttons and text boxes on render window
    for(auto button : buttons["SelectListing"]){
        // if user has scrolled to another page of listings, display the "Previous" button
        if(button.second->getText() == "< Previous"){
            if(listingPage > 0){
                window->draw(button.second->getHitbox());
                window->draw(button.second->getRenderText());
            }
        }
        // if there are multiple pages of listings, draw "Next" button
        else if(button.second->getText() == "Next >"){
            if(6 * (listingPage + 1) < listings[selectedEatery].size()){
                window->draw(button.second->getHitbox());
                window->draw(button.second->getRenderText());
            }
        }
        else{
            // draw buttons
            window->draw(button.second->getHitbox());
            window->draw(button.second->getRenderText());
        }
    }
    for(auto iter : textBoxes["SelectListing"]){
        window->draw(iter.second->getRect());
        window->draw(iter.second->getRenderText());
    }

    // row and column values
    float column = 0;
    float row = 0;

    // move un-rendered listings off the screen
    for(Listing listing : listings[selectedEatery]){
        listing.background->setPosition({5000, 5000});
    }

    // read listings according to current page
    for(int i = 6 * listingPage; i < listings[selectedEatery].size(); i++){
        // only allow 2 rows of listings to be rendered at a time
        if(row < 2){
            // render listing background, shadow and text according to row and column values
            listings[selectedEatery][i].background->setPosition({20 + (column * 345), 95 + (row * 220)});
            listings[selectedEatery][i].shadow.setPosition({25 + (column * 345), 100 + (row * 220)});
            listings[selectedEatery][i].renderName.setPosition({177 + (column * 345), 157 + (row * 220)});
            listings[selectedEatery][i].renderPrice.setPosition({177 + (column * 345), 177 + (row * 220)});


            // draw listing
            window->draw(listings[selectedEatery][i].shadow);
            window->draw(*listings[selectedEatery][i].background);
            window->draw(listings[selectedEatery][i].renderName);
            window->draw(listings[selectedEatery][i].renderPrice);


            // adjust rows and columns
            if(column < 2){
                column++;
            }
            else{
                // if end of column reached, add a row
                row++;
                column = 0;
            }
        }
    }

    // render window
    window->display();
}

void Application::renderViewListingWindow(){
    // header text
    sf::Text headerText;
    headerText.setFont(headerFont);
    headerText.setFillColor({98, 115, 255});
    headerText.setString("Order Details");
    headerText.setPosition(2, 0);
    headerText.setCharacterSize(40);

    // header rectangle
    sf::RectangleShape windowHeader(sf::Vector2f(1050 , 50));
    windowHeader.setPosition(0,0);
    windowHeader.setFillColor({200, 200, 255});

    // listing name text object
    sf::Text nameText;
    nameText.setFont(textFont);
    nameText.setString("Food item: " + selectedListing.name);
    nameText.setFillColor({98, 115, 255});
    nameText.setCharacterSize(20);
    nameText.setPosition({50, 100});

    // listing price text object
    sf::Text priceText;
    priceText.setFont(textFont);
    priceText.setString("Price: $" + selectedListing.price);
    priceText.setFillColor({98, 115, 255});
    priceText.setCharacterSize(20);
    priceText.setPosition({50, 150});

    // listing description text object
    sf::Text descriptionText;
    descriptionText.setFont(textFont);
    descriptionText.setString("Description: ");
    descriptionText.setFillColor({98, 115, 255});
    descriptionText.setCharacterSize(20);
    descriptionText.setPosition({50, 200});

    // variables to hold description words
    std::vector<std::string> split;
    std::string value;
    std::istringstream stream(selectedListing.description);

    // break up the description into words
    while(std::getline(stream, value, ' ')){
        // add words into vector
        split.push_back(value);
    }

    // read the description
    for(std::string value : split){
        // temporary text object
        sf::Text tempText = descriptionText;
        tempText.setString(descriptionText.getString() + " " + value);
        // if the current word fits within the description boundaries
        if(tempText.getGlobalBounds().width < 500){
            // add word to the render text
            descriptionText.setString(descriptionText.getString() + " " + value);
        }
        else{
            // if word does not fit in the description boundaries, add a new line and add there instead
            tempText.setString(descriptionText.getString() + "\n" + value);

            // if adding the word to a new line still does not fit within the description boundaries
            if(tempText.getGlobalBounds().width >= 500){
                descriptionText.setString(descriptionText.getString() + "\n");

                std::string parsedVal;
                std::string tempVal;

                // break the word up into characters, move all non-fitting characters to new line
                for(char i : value){
                    tempVal = parsedVal + i + "-";
                    tempText.setString(descriptionText.getString() + tempVal);
                    if(tempText.getGlobalBounds().width >= 500){
                        parsedVal += "-\n";
                        parsedVal += i;
                    }
                    else{
                        parsedVal += i;
                    }
                }
                // add modified word to render text
                descriptionText.setString(descriptionText.getString() + parsedVal);
            }
            else{
                // add word to render text
                descriptionText.setString(descriptionText.getString() + "\n" + value);
            }
        }
    }

    // set window background
    window->clear({223, 226, 255});

    // draw header and text objects
    window->draw(windowHeader);
    window->draw(headerText);
    window->draw(nameText);
    window->draw(priceText);
    window->draw(descriptionText);

    // draw buttons
    for (auto& [key, button] : buttons[applicationState]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }

    // render window
    window->display();
}


/*------------------------------------------------------------------------*/
/*-------------------Create-Account Window Functionality------------------*/
/*------------------------------------------------------------------------*/
bool Application::createAccount(const std::string& username, const std::string& password){
    // if the user entered a valid username and password
    if(username.size() > 0 && password.size() > 0){
        // initialize MongoDB database and collection
        auto database = (*conn)["user_data"];
        auto collection = database["users"];

        // search for username availability
        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", username)));

        // if user with desired username exists
        if(resultUserSearch){
            // set error message
            accountErr = 2;
            return false;
        }
        else{
            // create new user object with desired username and password
            bsoncxx::builder::basic::document document{};
            document.append(bsoncxx::builder::basic::kvp("Username", username));
            document.append(bsoncxx::builder::basic::kvp("Password", password));

            // insert into MongoDB user data collection
            collection.insert_one(document.view());

            return true;
        }
    }
    else{
        // if user entered invalid username or password, set error message
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

    // create username text object
    sf::Text createUsername;
    createUsername.setFont(textFont);
    createUsername.setFillColor({98, 115, 255});
    createUsername.setString("Create Username:");
    createUsername.setPosition(400, 375);
    createUsername.setCharacterSize(20);

    // create password text object
    sf::Text createPassword;
    createPassword.setFont(textFont);
    createPassword.setFillColor({98, 115, 255});
    createPassword.setString("Create Password:");
    createPassword.setPosition(400, 435);
    createPassword.setCharacterSize(20);

    // message text object
    sf::Text accountErrText;
    accountErrText.setFont(textFont);
    accountErrText.setCharacterSize(20);
    accountErrText.setFillColor(sf::Color::Red);

    // set error depending on context
    if(accountErr == 1){
        accountErrText.setString("Please enter a valid username and password.");
        accountErrText.setPosition(315, 250);
    }
    else if(accountErr == 2){
        accountErrText.setString("Account with that username already exists.");
        accountErrText.setPosition(335, 250);
    }

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

    // draw header and text, message if applicable
    window->draw(header);
    window->draw(createUsername);
    window->draw(createPassword);
    window->draw(accountErrText);

    // render window
    window->display();
}


/*------------------------------------------------------------------------*/
/*-----------------------Login Window Functionality-----------------------*/
/*------------------------------------------------------------------------*/
void Application::verifyLogin(const std::string& username, const std::string& password){
    // if user entered a valid username and password
    if(username.size() > 0 && password.size() > 0){
        // initialize MongoDB database and collection
        auto database = (*conn)["user_data"];
        auto collection= database["users"];

        // search for user in database
        auto resultUserSearch = collection.find_one(
                bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("Username", username)));

        // if user does not exist
        if(!resultUserSearch){
            // set error message
            loginErr = 2;
        }
        else{
            try{
                std::string input = bsoncxx::to_json(*resultUserSearch);

                // if returned result is valid
                if(input.size() > 3){
                    bsoncxx::document::view getUser = resultUserSearch->view();
                    std::string passResult = getUser["Password"].get_utf8().value.to_string();
                    // login success
                    if(passResult == password){
                        // reset text boxes
                        for(auto iter : textBoxes["Login"]){
                            iter.second->reset();
                        }
                        // set the userID, username, application state member variables
                        userID = getUser["_id"].get_oid().value.to_string();
                        currentUser = username;
                        applicationState = "Ordering";

                        // call loadListings function
                        loadListings();
                    }
                    else{
                        // user enters incorrect password, set error message
                        loginErr = 2;
                    }
                }
                else{
                    // set error message for incorrect username or password
                    loginErr = 2;
                }
            }
            // catch invalid input
            catch(const std::exception& e){
                // set error message
                loginErr = 1;
            }
        }
    }
    else{
        // set error message for invalid input
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

    // username text object
    sf::Text username;
    username.setFont(textFont);
    username.setFillColor({98, 115, 255});
    username.setString("Username:");
    username.setPosition(400, 375);
    username.setCharacterSize(20);

    // password text object
    sf::Text password;
    password.setFont(textFont);
    password.setFillColor({98, 115, 255});
    password.setString("Password:");
    password.setPosition(400, 435);
    password.setCharacterSize(20);

    // message text object
    sf::Text loginErrText;
    loginErrText.setFont(textFont);
    loginErrText.setCharacterSize(20);
    loginErrText.setFillColor(sf::Color::Red);

    // set error depending on context
    if(loginErr == 1){
        loginErrText.setString("Please enter a valid username and password.");
        loginErrText.setPosition(315, 250);
    }
    else if(loginErr == 2){
        loginErrText.setString("Incorrect username or password.");
        loginErrText.setPosition(370, 250);
    }

    // set window background color
    window->clear({223, 226, 255});

    // draw header text
    window->draw(header);

    // draw buttons and text boxes
    for (auto& [key, button] : buttons["Login"]) {
        window->draw(button->getHitbox());
        window->draw(button->getRenderText());
    }
    for (auto& [key, textBox] : textBoxes["Login"]) {
        window->draw(textBox->getRect());
        window->draw(textBox->getRenderText());
    }

    // draw username, password and message text if applicable
    window->draw(username);
    window->draw(password);
    window->draw(loginErrText);

    // render window
    window->display();
}


/*------------------------------------------------------------------------*/
/*------------------------Main Application Driver-------------------------*/
/*------------------------------------------------------------------------*/
void Application::run(){
    // variables to store mouse location
    float mouseX;
    float mouseY;

    // render the login window
    renderLoginWindow();

    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)) {
            // if user closes window
            if(event.type == sf::Event::Closed){
                window->close();
                return;
            }
            // user clicks
            if(event.type == sf::Event::MouseButtonReleased) {
                // get mouse location
                mouseX = sf::Mouse::getPosition(*window).x;
                mouseY = sf::Mouse::getPosition(*window).y;

                // functionality for Log In screen
                if(applicationState == "Login"){
                    // if user clicked a textbox
                    for(auto& [key, textBox] : textBoxes[applicationState]){
                        if(textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)){
                            // de-select other textboxes
                            for(auto iter2: textBoxes[applicationState]){
                                iter2.second->selected = false;
                                iter2.second->setColor(sf::Color::White);
                            }
                            // set clicked textbox as selected, change color for visual cue
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});

                            // clear message
                            loginErr = 0;
                        }
                    }
                    // if user clicked a button
                    for(auto button: buttons[applicationState]){
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            // if user clicked log in
                            if(button.second->getText() == "Log In"){
                                // verify if credentials entered are correct
                                verifyLogin(textBoxes["Login"]["Username"]->getText(),
                                            textBoxes["Login"]["Password"]->getText());
                            }
                            // if user clicked create account
                            else if(button.second->getText() == "Create Account") {
                                // clear text boxes
                                for(auto textBox: textBoxes[applicationState]){
                                    textBox.second->reset();
                                }

                                // change application state to CreateAccount and clear message
                                applicationState = "CreateAccount";
                                loginErr = 0;
                            }
                        }
                    }
                }
                // functionality for Create Account screen
                else if(applicationState == "CreateAccount"){
                    // if user clicked a textbox
                    for(auto& [key, textBox] : textBoxes[applicationState]){
                        if(textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)){
                            // de-select other textboxess
                            for(auto iter2: textBoxes[applicationState]){
                                iter2.second->selected = false;
                                iter2.second->setColor(sf::Color::White);
                            }
                            // set clicked textbox as selected, change color for visual cue
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});

                            // clear message
                            accountErr = 0;
                        }
                    }
                    // if user clicked a button
                    for(auto button: buttons[applicationState]){
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            // if user clicked Create Account
                            if(button.second->getText() == "Create Account") {
                                // if account creation was successful
                                if(createAccount(textBoxes["CreateAccount"]["CreateUser"]->getText(),
                                                  textBoxes["CreateAccount"]["CreatePass"]->getText())){
                                    // reset text boxes
                                    for(auto textBox: textBoxes["CreateAccount"]){
                                        textBox.second->reset();
                                    }

                                    // set application state to Log In
                                    applicationState = "Login";
                                }
                            }
                            // if user clicked the Back button
                            else if(button.second->getText() == "Back"){
                                // reset text boxes
                                for(auto textBox: textBoxes[applicationState]){
                                    textBox.second->reset();
                                }

                                // set application state to Log In and clear message
                                applicationState = "Login";
                                accountErr = 0;
                            }
                        }
                    }
                }
                // eatery selection screen functionality
                else if(applicationState == "Ordering"){
                    // if user clicked a button
                    for(auto button: buttons[applicationState]){
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            // if user clicked Log Out
                            if(button.second->getText() == "Log Out") {
                                // clear account member variables
                                currentUser = "";
                                userID = "";
                                eateryPage = 0;

                                // set application state to Log In
                                applicationState = "Login";
                            }
                            // if user clicked My Account
                            else if(button.second->getText() == "My Account"){
                                // set application state to My Account
                                applicationState = "MyAccount";
                            }
                            // if user clicked Create Listing
                            else if(button.second->getText() == "+"){
                                // set application state to Create Listing
                                applicationState = "CreateListing";
                            }
                            // if user clicked the Next button
                            else if(button.second->getText() == "Next >"){
                                // if user is not on the last page of eateries
                                if(8 * (eateryPage + 1) < eateries.size()){
                                    // go forward a page
                                    eateryPage++;
                                }
                            }
                            // if user clicks the Previous button
                            else if(button.second->getText() == "< Previous"){
                                // if user is not on the first page of eateries
                                if(eateryPage > 0){
                                    // go back a page
                                    eateryPage--;
                                }
                            }
                            // if user clicks refresh button
                            else if(button.second->getText() == "Refresh"){
                                // reload the listings and set page back to 0
                                loadListings();
                                eateryPage = 0;
                            }
                        }
                    }
                    // if user clicked an eatery card
                    for(Eatery eatery: eateries){
                        if(eatery.background->getGlobalBounds().contains(mouseX, mouseY)){
                            // set selected eatery and change application state to Select Listing
                            selectedEatery = eatery.userID;
                            applicationState = "SelectListing";
                        }
                    }
                }
                // account modification screen functionality
                else if(applicationState == "MyAccount"){
                    // if user clicked a textbox
                    for(auto& [key, textBox] : textBoxes[applicationState]){
                        if(textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)){
                            // de-select other textboxes
                            for(auto& [key, innerTextBox] : textBoxes[applicationState]){
                                innerTextBox->selected = false;
                                innerTextBox->setColor(sf::Color::White);
                            }

                            // set clicked textbox as selected, change color as visual cue
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});

                            // reset messages
                            newPassErr = 0;
                            newUserErr = 0;

                            // if user clicks into Change Password section
                            if(textBox->getType() == "Password"){
                                // reset username textboxes
                                for(auto iter: textBoxes["MyAccount"]){
                                    if(iter.second->getType() == "Username"){
                                        iter.second->reset();
                                    }
                                }
                            }
                            // if user clicks into Change Username section
                            else if(textBox->getType() == "Username"){
                                // reset password textbox
                                for(auto iter: textBoxes["MyAccount"]){
                                    if(iter.second->getType() == "Password"){
                                        iter.second->reset();
                                    }
                                }
                            }
                        }
                    }
                    // if user clicked a button
                    for(auto button: buttons[applicationState]) {
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            // if user clicked the Back button
                            if(button.second->getText() == "Back") {
                                // reset textboxes
                                for(auto textBox: textBoxes[applicationState]){
                                    textBox.second->reset();
                                }

                                // clear messages
                                newUserErr = 0;
                                newPassErr = 0;

                                // set application state to Ordering
                                applicationState = "Ordering";
                            }
                            // if user clicked Change Password
                            else if(button.second->getText() == "Change Password"){
                                // clear username-related message
                                newUserErr = 0;

                                // reset username textboxes
                                for(auto textBox: textBoxes[applicationState]){
                                    if(textBox.second->getType() == "Username"){
                                        textBox.second->reset();
                                    }
                                }
                                // call changePassword
                                changePassword();
                            }
                            // if user clicked Change Username
                            else if(button.second->getText() == "Change Username"){
                                // clear password textboxes
                                for(auto textBox: textBoxes[applicationState]){
                                    if(textBox.second->getType() == "Password"){
                                        textBox.second->reset();
                                    }
                                }

                                // clear password-related message
                                newPassErr = 0;

                                // change username
                                changeUsername();
                            }
                        }
                    }
                }
                // listing creation screen functionality
                else if(applicationState == "CreateListing"){
                    // if user clicks a textbox
                    for(auto& [key, textBox] : textBoxes[applicationState]){
                        if(textBox->getRect().getGlobalBounds().contains(mouseX, mouseY)){
                            // de-select other textboxes
                            for(auto& [key, innerTextBox] : textBoxes[applicationState]){
                                innerTextBox->selected = false;
                                innerTextBox->setColor(sf::Color::White);
                            }

                            // set clicked textbot as selected, change color as visual cue
                            textBox->selected = true;
                            textBox->setColor({240, 240, 255});

                            // reset message
                            newListingErr = 0;
                        }
                    }
                    // if user clicked a button
                    for(auto button: buttons[applicationState]){
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            // if user clicked Back button
                            if(button.second->getText() == "Back") {
                                // reset textboxes
                                for (auto textBox: textBoxes[applicationState]) {
                                    textBox.second->reset();
                                }

                                // change application state to Ordering
                                applicationState = "Ordering";

                                // reset message
                                newListingErr = 0;
                            }
                            // if user clicked Create Listing
                            else if(button.second->getText() == "Create Listing"){
                                // if listing creation successful
                                if(createListing(textBoxes["CreateListing"]["ListingName"]->getText(),
                                                 textBoxes["CreateListing"]["ListingPrice"]->getText(),
                                                 textBoxes["CreateListing"]["ListingDescription"]->getText())){
                                    // reset textboxes
                                    for(auto textBox: textBoxes[applicationState]){
                                        textBox.second->reset();
                                    }

                                    // set application state to Ordering
                                    applicationState = "Ordering";

                                    // load listings from MongoDB
                                    loadListings();
                                }
                            }
                        }
                    }
                }
                // listing selection screen functionality
                else if(applicationState == "SelectListing"){
                    for(auto button: buttons[applicationState]){
                        // if user clicked a button
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)) {
                            // if user clicked Back button
                            if(button.second->getText() == "Back"){
                                // reset current page of listings
                                listingPage = 0;

                                // set application state to Ordering
                                applicationState = "Ordering";
                            }
                            // if user clicked the Next button
                            else if(button.second->getText() == "Next >"){
                                // if user is not on the last page of listings
                                if(6 * (listingPage + 1) < listings[selectedEatery].size()){
                                    // go forward a page
                                    listingPage++;
                                }
                            }
                            // if user clicks the Previous button
                            else if(button.second->getText() == "< Previous"){
                                // if user is not on the first page of listings
                                if(listingPage > 0){
                                    // go back a page
                                    listingPage--;
                                }
                            }
                        }
                    }
                    // if user clicked a listing
                    for(Listing listing : listings[selectedEatery]){
                        if(listing.background->getGlobalBounds().contains(mouseX, mouseY)){
                            // set selected listing and change application state
                            selectedListing = listing;
                            applicationState = "ViewListing";
                        }
                    }
                }
                // listing details screen functionality
                else if(applicationState == "ViewListing"){
                    // if user clicked a button
                    for(auto button: buttons[applicationState]) {
                        if(button.second->getHitbox().getGlobalBounds().contains(mouseX, mouseY)){
                            // if user clicked Back button
                            if(button.second->getText() == "Back"){
                                // reset selected listing and change application state
                                selectedListing = Listing();
                                applicationState = "SelectListing";
                            }
                        }
                    }
                }

                // render window depending on current application state
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
                else if(applicationState == "ViewListing"){
                    renderViewListingWindow();
                }

            }
            // if user pressed a key
            else if(event.type == sf::Event::KeyPressed){
                // enter key
                if(event.key.code == sf::Keyboard::Key::Enter){
                    // log in screen functionality
                    if(applicationState == "Login"){
                        // verify user credentials
                        verifyLogin(textBoxes["Login"]["Username"]->getText(),
                                    textBoxes["Login"]["Password"]->getText());
                    }
                    // create account screen functionality
                    else if(applicationState == "CreateAccount"){
                        // verify new account credentials
                        if(createAccount(textBoxes["CreateAccount"]["CreateUser"]->getText(),
                                          textBoxes["CreateAccount"]["CreatePass"]->getText())){
                            // reset textboxes
                            for(auto iter: textBoxes["CreateAccount"]){
                                iter.second->reset();
                            }

                            // set application state to log in
                            applicationState = "Login";
                        }
                    }
                    // account credentials modification screen functionality
                    else if(applicationState == "MyAccount"){
                        for(auto textBox: textBoxes["MyAccount"]){
                            // if user has a password box selected
                            if (textBox.second->selected && textBox.second->getType() == "Password"){
                                // change password
                                changePassword();
                            }
                            // if user has a username box selected
                            else if(textBox.second->selected && textBox.second->getType() == "Username"){
                                // change username
                                changeUsername();
                            }
                        }
                    }
                    // listing creation screen functionality
                    else if (applicationState == "CreateListing") {
                        // verify listing creation
                        if(createListing(textBoxes["CreateListing"]["ListingName"]->getText(),
                                          textBoxes["CreateListing"]["ListingPrice"]->getText(),
                                          textBoxes["CreateListing"]["ListingDescription"]->getText())){
                            // reset textboxes
                            for(auto& [key, textBox] : textBoxes[applicationState]){
                                textBox->reset();
                            }

                            // set application state to Ordering and load listings from MongoDB
                            applicationState = "Ordering";
                            loadListings();
                        }
                    }
                }
                // user pressed a letter/number/symbol
                else{
                    // clear messages
                    accountErr = 0;
                    loginErr = 0;
                    newListingErr = 0;

                    // perform key operation
                    interpretKey(event.key.code);
                }

                // render window depending on current application state
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
                else if(applicationState == "ViewListing"){
                    renderViewListingWindow();
                }
            }
        }
    }
}

Application::Application(){
    // create the application window
    window = new sf::RenderWindow(sf::VideoMode(1050, 600), "Campus Central Food");

    // set the default application state to "Login"
    applicationState = "Login";

    // initialize member variables
    loginErr = 0;
    accountErr = 0;
    newPassErr = 0;
    newUserErr = 0;
    newListingErr = 0;
    eateryPage = 0;
    listingPage = 0;

    // Create a MongoDB instance
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

void Button::setHitbox(sf::RectangleShape* inputHitbox) {
    hitBox = inputHitbox;
}

sf::RectangleShape Button::getHitbox() const {
    return *hitBox;
}

std::string Button::getText() const {
    return buttonText;
}

Button::Button(const sf::Text& inputText) {
    // initialize button text object and text member variable
    buttonRenderText = inputText;
    buttonText = inputText.getString();
}


/*------------------------------------------------------------------------*/
/*-----------------------Listing/Eatery Constructors----------------------*/
/*------------------------------------------------------------------------*/
Listing::Listing(){
    // default constructor- initialize member variables
    name = "";
    price = "";
    description = "";
    ownerID = "";
    ownerName = "";
}

Listing::Listing(const std::string& name, const std::string& price, const std::string& description,
                 const std::string& ownerID, const std::string& ownerName, sf::Font& textFont){
    // set member variables for listing
    this->name = name;
    this->price = price;
    this->ownerID = ownerID;
    this->ownerName = ownerName;
    this->description = description;

    // create background rectangle
    background = new sf::RectangleShape({315,200});
    background->setFillColor(sf::Color::White);
    background->setOutlineThickness(1);
    background->setOutlineColor(sf::Color::Black);

    // create shadow
    shadow.setSize({315,200});
    shadow.setFillColor({203, 206, 235});

    // set name render text object
    renderName.setString(name);
    renderName.setFont(textFont);
    renderName.setFillColor(sf::Color::Black);
    renderName.setCharacterSize(12);
    renderName.setOrigin({renderName.getGlobalBounds().getSize().x / 2, renderName.getGlobalBounds().getSize().y / 2});

    // set price render text object
    renderPrice.setString("$" + price);
    renderPrice.setFont(textFont);
    renderPrice.setFillColor(sf::Color::Black);
    renderPrice.setCharacterSize(12);
    renderPrice.setOrigin({renderPrice.getGlobalBounds().getSize().x / 2, renderPrice.getGlobalBounds().getSize().y / 2});
}

Eatery::Eatery(const std::string& name, const std::string& userID, sf::Font& textFont){
    // set member variables
    this->name = name;
    this->userID = userID;

    // create background rectangle object
    background = new sf::RectangleShape({200,200});
    background->setFillColor(sf::Color::White);
    background->setOutlineThickness(1);
    background->setOutlineColor(sf::Color::Black);

    // create shadow
    shadow.setSize({200,200});
    shadow.setFillColor({203, 206, 235});

    // set name render text object
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
    // set textbox location
    hitbox.setPosition({x, y});
}

void TextBox::setColor(sf::Color color){
    hitbox.setFillColor(color);
}

sf::RectangleShape TextBox::getRect() const {
    return hitbox;
}

void TextBox::addChar(char character){
    // if the textbox is a password box
    if(type == "Password"){
        // hide the text as user types password
        std::string hideText;
        for(int i = 0; i < boxText.size(); i++){
            hideText += '*';
        }

        // temporary text object
        sf::Text tempRenderText = boxRenderText;
        tempRenderText.setString(hideText + character);

        // if character fits in textbox
        if(tempRenderText.getGlobalBounds().getSize().x < hitbox.getSize().x){
            // add character to textbox
            boxText += character;
            boxRenderText.setString(hideText + character);
        }
    }
    else{
        // prevent user from typing letters or characters other than ',' and '.' into a price box
        if(type != "Price" || (type == "Price" && (isdigit(character) || character == '.' || character == ','))){
            // temporary text object
            sf::Text tempRenderText = boxRenderText;
            tempRenderText.setString(boxText + character);

            // if character fits in textbox
            if(tempRenderText.getGlobalBounds().getSize().x < hitbox.getSize().x){
                // add character to textbox
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
    // remove last character from selected textbox
    boxText.erase(boxText.end() - 1);

    // hide characters if textbox is a password box
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
    // clear textbox member variables and reset fill colo
    boxText = "";
    selected = false;
    boxRenderText.setString("");
    hitbox.setFillColor(sf::Color::White);
}

std::string TextBox::getType() const {
    return type;
}

TextBox::TextBox(sf::Text& inputRenderText, const std::string& type, const float& width){
    // parameterized constructor- set member variables
    this->type = type;

    // text object and member variable
    boxText = "";
    boxRenderText = inputRenderText;

    // hitbox object
    hitbox.setSize({width, 25});
    hitbox.setOutlineColor(sf::Color::Black);
    hitbox.setOutlineThickness(2);
}

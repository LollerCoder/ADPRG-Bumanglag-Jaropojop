#include "Game.h"
#include <iostream>


Game::Game() : mWindow(sf::VideoMode(640,480), "SFML Application"){
    sf::Texture mTexture;

    primaryTextFont.loadFromFile("../Media/Font/Sansation.ttf");
    mTexture.loadFromFile("../Media/Textures/Eagle.png");

    mSampleEntity.setTexture(mTexture);

    mSampleEntity.getSprite()->setPosition(100.f, 100.f);
    mSampleEntity.getSprite()->setOrigin(24.f, 0.f);


    //assignment
    fpsCounter.setFont(primaryTextFont);

    timePerUpdateCounter.setFont(primaryTextFont);
    timePerUpdateCounter.setPosition(0.f, 30.f);

    

}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    //assignment
    sf::Time oneSecondTracker = sf::Time::Zero;
    float frameTrack = 0.f;

    bool onFirstDraw = true;
   

    while (mWindow.isOpen())
    {
        processEvents();
        sf::Time deltaTime = clock.restart();
        
        timeSinceLastUpdate += deltaTime;
        //assignment
        oneSecondTracker += deltaTime;
       
        //everything update is here so for the assignment place everything here and remove for the next module
        while (timeSinceLastUpdate > TimePerFrame) {
            frameTrack++;
            timePerUpdateCounter.setString("Time / Update = " + std::to_string(timeSinceLastUpdate.asMicroseconds()) + "us");
            //to make sure it draws before 1 seconds happens.
            if (onFirstDraw) {
                fpsCounter.setString("Frames / Second = 0 ");
                onFirstDraw = false;
            }
            //after one second post how many frames was done.
            if (oneSecondTracker >= sf::seconds(1.f)) {
                fpsCounter.setString("Frames / Second = " + std::to_string(frameTrack));

                frameTrack = 0;
                oneSecondTracker = sf::Time::Zero;

            }
            
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
            
          
            


            
            
            
        }
        
        
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::MouseButtonPressed:
            handleMouseInput(event.mouseButton.button, true);
            break;
        case sf::Event::MouseButtonReleased:
            handleMouseInput(event.mouseButton.button, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
        
    }
}

void Game::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f);
    float rotation = 0.f;

    if (!mMouseMovement) {//if we're using WASD
        if (mIsMovingUp) {
            movement.y -= playerSpeed;
        }

        if (mIsMovingDown) {
            movement.y += playerSpeed;
        }

        if (mIsMovingLeft) {
            movement.x -= playerSpeed;
        }

        if (mIsMovingRight) {
            movement.x += playerSpeed;
        }
        //rotation
        if (movement.y != 0 || movement.x != 0) {

            if (movement.x > 0) {
                rotation += 90;

                if (movement.y > 0) rotation += 45;
                if (movement.y < 0) rotation -= 45;

            }
            else if (movement.x < 0) {
                rotation += 270;
                if (movement.y > 0) rotation -= 45;
                if (movement.y < 0) rotation += 45;
            }

            else if (movement.y > 0) {
                rotation = 180;
            }
            mSampleEntity.getSprite()->setRotation(rotation);
        }
    }
    else {//if we're using MOUSE MOVEMENxT
       
        float rotateToMouse = atan2(mSampleEntity.getSprite()->getPosition().x - sf::Mouse::getPosition(mWindow).x, 
            mSampleEntity.getSprite()->getPosition().y - sf::Mouse::getPosition(mWindow).y);

        float const PI = 3.14159;

        rotateToMouse = -rotateToMouse * (180 / PI);
        
        sf::Vector2f moveTo(sf::Mouse::getPosition(mWindow).x - mSampleEntity.getSprite()->getPosition().x,
            sf::Mouse::getPosition(mWindow).y - mSampleEntity.getSprite()->getPosition().y);

        float magnitude = sqrt(moveTo.x * moveTo.x + moveTo.y * moveTo.y);

        moveTo = moveTo / magnitude;

        movement += moveTo * playerSpeed;

        

        mSampleEntity.getSprite()->setRotation(rotateToMouse);
    }
    
 
    
    mSampleEntity.getSprite()->move(movement * deltaTime.asSeconds());

    
}
void Game::render() {

    mWindow.clear();
    mWindow.draw(*mSampleEntity.getSprite());
    mWindow.draw(fpsCounter);
    mWindow.draw(timePerUpdateCounter);
    mWindow.display();

}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    switch (key) {
    case sf::Keyboard::W:
        mIsMovingUp = isPressed;
        break;
    case sf::Keyboard::S:
        mIsMovingDown = isPressed;
        break;
    case sf::Keyboard::A:
        mIsMovingLeft = isPressed;
        break;
    case sf::Keyboard::D:
        mIsMovingRight = isPressed;
        break;
    }
}

void Game::handleMouseInput(sf::Mouse::Button mouseButton, bool isPressed) {
    switch (mouseButton) {
    case sf::Mouse::Left:
        /*std::cout << "Left click!" << std::endl;
        std::cout << sf::Mouse::getPosition(mWindow).x << std::endl;
        std::cout << sf::Mouse::getPosition(mWindow).y << std::endl;*/
        mMouseMovement = isPressed;
        break;
    }
    
}

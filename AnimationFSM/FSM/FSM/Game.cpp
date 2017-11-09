//Patryk Wysocki
//9/11/17
//Simple FSM.

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false}, //when true game will exit
	m_jumping{ false }, //when true jumping sprite will appear
	m_climbing{ false },//when true climbing sprite will appear
	m_hammering{ false },//when true hammering sprite will appear
	m_shoveling{ false },//when true shoveling sprite will appear
	m_swordsmanship{ false },//when true swordmanship sprite will appear
	m_walking{ false },//when true walking sprite will appear
	m_idle{ true }
{
	setupFontAndText(); // load font 
	setUpSprites(); // load texture
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Up == event.key.code)
			{

				m_climbing = true;
				m_idle = false;
				timer = 20;
				fsm.climbing();
			}
			if (sf::Keyboard::Space == event.key.code)
			{
				m_jumping = true;
				m_idle = false;
				timer = 20;
				fsm.jumping();
			}
			if (sf::Keyboard::H == event.key.code)
			{
				m_hammering = true;
				m_idle = false;
				timer = 20;
				fsm.hammering();
			}
			if (sf::Keyboard::S == event.key.code)
			{
				m_shoveling = true;
				m_idle = false;
				timer = 20;
				fsm.shoveling();
			}
			if (sf::Keyboard::W == event.key.code)
			{
				m_swordsmanship = true;
				m_idle = false;
				timer = 20;
				fsm.swordmanship();
			}
			if (sf::Keyboard::Left == event.key.code)
			{
				m_walking = true;
				m_idle = false;
				timer = 20;
				fsm.walking();
			}
			if (sf::Keyboard::Right == event.key.code)
			{
				m_walking = true;
				m_idle = false;
				timer = 20;
				fsm.walking();
			}
			if (sf::Keyboard::Down == event.key.code)
			{

				fsm.idle();
			}
		}

	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (timer > 0)
	{
		timer--;
	}
	if (timer == 0)
	{
		m_jumping = false;
		m_climbing = false;
		m_shoveling = false;
		m_swordsmanship = false;
		m_hammering = false;
		m_walking = false;
		m_idle = true;
	}
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the sprite and text
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	if (m_jumping == true)
	{
		m_window.draw(m_jumpingText);
		m_window.draw(m_spriteJumping);
	}
	if (m_climbing == true)
	{
		m_window.draw(m_climbingText);
		m_window.draw(m_spriteClimbing);
	}
	if (m_shoveling == true)
	{
		m_window.draw(m_shovelingText);
		m_window.draw(m_spriteShoveling);
	}
	if (m_swordsmanship == true)
	{
		m_window.draw(m_swordmanshipText);
		m_window.draw(m_spriteSwordmanship);
	}
	if (m_hammering == true)
	{
		m_window.draw(m_hammeringText);
		m_window.draw(m_spriteHammering);
	}
	if (m_walking == true)
	{
		m_window.draw(m_walkingText);
		m_window.draw(m_spriteWalkingRight);
	}
	if (m_idle == true)
	{
		m_window.draw(m_idleText);
		m_window.draw(m_spriteIdle);
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text for state of finite state machine 
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_jumpingText.setFont(m_ArialBlackfont);
	m_jumpingText.setCharacterSize(40);
	m_jumpingText.setString("JUMPING");
	m_jumpingText.setFillColor(sf::Color::Black);
	m_jumpingText.setPosition(300, 100);

	m_climbingText.setFont(m_ArialBlackfont);
	m_climbingText.setCharacterSize(40);
	m_climbingText.setString("CLIMBING");
	m_climbingText.setFillColor(sf::Color::Black);
	m_climbingText.setPosition(300, 100);

	m_hammeringText.setFont(m_ArialBlackfont);
	m_hammeringText.setCharacterSize(40);
	m_hammeringText.setString("HAMMERING");
	m_hammeringText.setFillColor(sf::Color::Black);
	m_hammeringText.setPosition(300, 100);

	m_shovelingText.setFont(m_ArialBlackfont);
	m_shovelingText.setCharacterSize(40);
	m_shovelingText.setString("SHOVELING");
	m_shovelingText.setFillColor(sf::Color::Black);
	m_shovelingText.setPosition(300, 100);

	m_swordmanshipText.setFont(m_ArialBlackfont);
	m_swordmanshipText.setCharacterSize(40);
	m_swordmanshipText.setString("SWORDMANSHIP");
	m_swordmanshipText.setFillColor(sf::Color::Black);
	m_swordmanshipText.setPosition(300, 100);

	m_walkingText.setFont(m_ArialBlackfont);
	m_walkingText.setCharacterSize(40);
	m_walkingText.setString("WALKING");
	m_walkingText.setFillColor(sf::Color::Black);
	m_walkingText.setPosition(300, 100);

	m_idleText.setFont(m_ArialBlackfont);
	m_idleText.setCharacterSize(40);
	m_idleText.setString("IDLE");
	m_idleText.setFillColor(sf::Color::Black);
	m_idleText.setPosition(300, 100);

}

/// <summary>
/// load the texture and setup the sprite for the animations
/// </summary>
void Game::setUpSprites()
{
	m_spriteIdle.setPosition(100, 100);
	m_spriteWalkingLeft.setPosition(100, 100);
	m_spriteWalkingRight.setPosition(100, 100);
	m_spriteClimbing.setPosition(100, 100);
	m_spriteJumping.setPosition(100, 100);
	m_spriteHammering.setPosition(100, 100);
	m_spriteShoveling.setPosition(100, 100);
	m_spriteSwordmanship.setPosition(100, 100);
	if (!m_climbingTexture.loadFromFile("ASSETS\\IMAGES\\climbing.png"))
	{
		std::cout << "ERROR LOADING CLIMBING IMAGE" << std::endl;
	}
	if (!m_hammeringTexture.loadFromFile("ASSETS\\IMAGES\\hammering.png"))
	{
		std::cout << "ERROR LOADING HAMMERING IMAGE" << std::endl;
	}
	if (!m_idleTexture.loadFromFile("ASSETS\\IMAGES\\idle.png"))
	{
		std::cout << "ERROR LOADING IDLE IMAGE" << std::endl;
	}
	if (!m_jumpingTexture.loadFromFile("ASSETS\\IMAGES\\jumping.png"))
	{
		std::cout << "ERROR LOADING JUMPING IMAGE" << std::endl;
	}
	if (!m_shovelingTexture.loadFromFile("ASSETS\\IMAGES\\shoveling.png"))
	{
		std::cout << "ERROR LOADING SHOVELING IMAGE" << std::endl;
	}
	if (!m_swordmanshipTexture.loadFromFile("ASSETS\\IMAGES\\swordmanship.png"))
	{
		std::cout << "ERROR LOADING SWORDMANSHIP IMAGE" << std::endl;
	}
	if (!m_walkingRightTexture.loadFromFile("ASSETS\\IMAGES\\walkingRight.png"))
	{
		std::cout << "ERROR LOADING WALKING RIGHT IMAGE" << std::endl;
	}
	m_spriteIdle.setTexture(m_idleTexture);
	m_spriteWalkingRight.setTexture(m_walkingRightTexture);
	m_spriteClimbing.setTexture(m_climbingTexture);
	m_spriteJumping.setTexture(m_jumpingTexture);
	m_spriteHammering.setTexture(m_hammeringTexture);
	m_spriteShoveling.setTexture(m_shovelingTexture);
	m_spriteSwordmanship.setTexture(m_swordmanshipTexture);

}




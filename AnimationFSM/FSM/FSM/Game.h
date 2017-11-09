//Patryk Wysocki
//9/11/17
//Simple FSM.

#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	Animation fsm;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setUpSprites();
	int timer;

	sf::Sprite m_spriteIdle;
	sf::Texture m_idleTexture;

	sf::Sprite m_spriteWalkingLeft;
	sf::Texture m_walkingLeftTexture;

	sf::Sprite m_spriteWalkingRight;
	sf::Texture m_walkingRightTexture;

	sf::Sprite m_spriteClimbing;
	sf::Texture m_climbingTexture;

	sf::Sprite m_spriteJumping;
	sf::Texture m_jumpingTexture;

	sf::Sprite m_spriteHammering;
	sf::Texture m_hammeringTexture;

	sf::Sprite m_spriteShoveling;
	sf::Texture m_shovelingTexture;

	sf::Sprite m_spriteSwordmanship;
	sf::Texture m_swordmanshipTexture;

	sf::Text m_jumpingText;
	sf::Text m_walkingText;
	sf::Text m_climbingText;
	sf::Text m_hammeringText;
	sf::Text m_shovelingText;
	sf::Text m_swordmanshipText;
	sf::Text m_idleText;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message

	bool m_jumping;
	bool m_climbing;
	bool m_hammering;
	bool m_shoveling;
	bool m_swordsmanship;
	bool m_idle;
	bool m_walking;

	bool m_exitGame; // control exiting game

};

#endif // !GAME


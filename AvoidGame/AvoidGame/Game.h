#pragma once
#include <vector>
#include <sstream>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class Game
{
private:
	RenderWindow* Window;
	Event Event;

	//player
	CircleShape Player;

	//Enemy
	RectangleShape Enemy;
	vector<RectangleShape> EnemyArray;

	int EnemyMax;
	float IntervalMax;
	float IntervalStart;

	//Point
	int Point;

	// Font
	Font Font;

	// Text
	Text PointText;
	Text GameOverText;

	bool GameOverState;

public:
	Game();
	
	void InitWindowPointer();
	void InitWindow();
	
	// Update
	const bool Running() const;
	void EventHandler();
	void Update();

	// Render
	void Render();

	// Shut Down
	~Game();
	void DeleteWindow();

	//player
	void InitPlayer();
	void UpdatePlayer();

	// Enemy
	void InitEnemy();
	void InitSpawn();
	void SpawnEnemy();
	void UpdateEnemy();
	
	// Collision Check
	void CollisionCheck();

	// Font
	void InitFont();

	// Text
	void InitPointText();
	void UpdatePointText();

	void InitGameOverText();
	void PrintGameOverText();
};
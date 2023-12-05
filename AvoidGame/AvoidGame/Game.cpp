#include "Game.h"

Game::Game()
{
	// ������ �ʱ�ȭ �� ����
	this->InitWindowPointer();
	this->InitWindow();

	// Player �ʱ�ȭ
	this->InitPlayer();

	// Enemy �ʱ�ȭ
	this->InitEnemy();
	this->InitSpawn();

	// point �ʱ�ȭ
	this->Point = 0;
	
	//Font �ʱ�ȭ
	this->InitFont();

	this->InitPointText();

	this->InitGameOverText();

	// Game Over State �ʱ�ȭ
	this->GameOverState = false;
}

void Game::InitWindowPointer()
{
	// ������ ���� �ʱ�ȭ
	this->Window = nullptr;
}

void Game::InitWindow()
{
	// ������ ���� ����
	this->Window = new RenderWindow (VideoMode(1280, 720), "Avoid Game", Style::Titlebar | Style::Close);
	
	// �����ϰ� �ݺ� ����
	this->Window->setFramerateLimit(60);
}

// Update
const bool Game::Running() const
{
	return this->Window->isOpen();
}

void Game::EventHandler()
{
	while (this->Window->pollEvent(Event)) {

		switch (Event.type) {

		case Event::Closed:
			// ����
			this->Window->close();
			break;
		case Event::KeyPressed:
			if (Event.key.code == Keyboard::Escape) this->Window->close();
			break;
		}
	}
}

void Game::Update()
{
	this->EventHandler();

	if (!this->GameOverState)
	{		
		this->UpdatePlayer();
		this->UpdateEnemy();
		this->CollisionCheck();
		this->UpdatePointText();
	}
}

// Render
void Game::Render()
{
	this->Window->clear(Color::Green); // ȭ���
	this->Window->draw(this->Player);
	
	for (int i = 0; i < this->EnemyArray.size(); i++)
	{
		this->Window->draw(this->EnemyArray[i]);
	}

	// Draw Text
	this->Window->draw(this->PointText);
	this->Window->draw(this->GameOverText);

	this->Window->display();
}

// Shut Down
Game::~Game()
{
	this->DeleteWindow();
}

void Game::DeleteWindow()
{
	// ������ �޸𸮿��� ����
	delete this->Window;
}

// player
void Game::InitPlayer()
{
	this->Player.setRadius(20.0f);
	this->Player.setFillColor(Color::Blue);
	this->Player.setPosition(
		float(this->Window->getSize().x / 2) - 30.0f,
		float(this->Window->getSize().y / 2) - 30.0f);
}

void Game::UpdatePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->Player.move(-3.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->Player.move(3.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->Player.move(0.0f, -3.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->Player.move(0.0f, 3.0f);
	}
}

// Enemy
void Game::InitEnemy()
{
	this->Enemy.setSize(Vector2f(60.0f,60.0f));
	this->Enemy.setFillColor(Color::Red);
	this->Enemy.setPosition(100, 100);
}

void Game::InitSpawn()
{
	this->EnemyMax = 20;
	this->IntervalMax = 10.0f;
	this->IntervalStart = 0.0f;
}

void Game::SpawnEnemy()
{
	this->Enemy.setPosition(static_cast<float>(rand() % 1200), 0.0f);
	this->EnemyArray.push_back(this->Enemy);
}

void Game::UpdateEnemy()
{
	if (this->EnemyArray.size() < this->EnemyMax)
	{
		if (this->IntervalMax <= this->IntervalStart)
		{
			this->SpawnEnemy();
			this->IntervalStart = 0.0f;
		}
		else
		{
			this->IntervalStart += 1.0f;
		}
	}
	for (int i = 0; i < this->EnemyArray.size(); i++)
	{
		this->EnemyArray[i].move(0.0f, 4.0f);
	}
	//������ ������ ����� enemy ����
	for (int i = 0; i < this->EnemyArray.size(); i++)
	{
		if (this->EnemyArray[i].getPosition().y >= this->Window->getSize().y)
		{
			this->EnemyArray.erase(this->EnemyArray.begin() + i);
			Point++;
		}
	}
}

// Collision Check
void Game::CollisionCheck()
{
	for (int i = 0; i < EnemyArray.size(); i++)
	{
		if (this->Player.getGlobalBounds().intersects(this->EnemyArray[i].getGlobalBounds())){
			
		// �浹 : true
		// ���� ����
		this->GameOverState=true;
		this->PrintGameOverText();
		}
	}
}

// Font
void Game::InitFont()
{
	if(this->Font.loadFromFile("Font/NanumGothic.ttf"))
	{
		cout << "Load Complete" << endl;
	}
	else
	{
		cout << "Load Fail" << endl;
	}
}

// Text
void Game::InitPointText()
{
	this->PointText.setFont(this->Font);
	this->PointText.setCharacterSize(30);
	this->PointText.setFillColor(Color::Black);
	this->PointText.setPosition(100, 100);
}

void Game::UpdatePointText()
{
	stringstream pt;

	pt << "Point : " << Point;

	this->PointText.setString(pt.str());
}

void Game::InitGameOverText()
{
	this->GameOverText.setFont(this->Font);
	this->GameOverText.setCharacterSize(100);
	this->GameOverText.setFillColor(Color::Black);
	this->GameOverText.setPosition(100, 100);
}

void Game::PrintGameOverText()
{
	stringstream pt;

	pt << "Game Over";

	this->GameOverText.setString(pt.str());
}
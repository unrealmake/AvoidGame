#include "Game.h"

Game::Game()
{
	// 윈도우 초기화 및 생성
	this->InitWindowPointer();
	this->InitWindow();

	// Player 초기화
	this->InitPlayer();
}

Game::~Game()
{
	this->DeleteWindow();
}

void Game::InitWindowPointer()
{
	// 포인터 변수 초기화
	this->Window = nullptr;
}

void Game::InitWindow()
{
	// 윈도우 동적 생성
	this->Window = new RenderWindow (VideoMode(1280, 720), "Avoid Game", Style::Titlebar | Style::Close);
}

void Game::DeleteWindow()
{
	// 윈도우 메모리에서 제거
	delete this->Window;
}

const bool Game::Running() const
{
	return this->Window->isOpen();
}

void Game::EventHandler()
{
	while (this->Window->pollEvent(Event)) {

		switch (Event.type) {

		case Event::Closed:
			// 동작
			this->Window->close();
			break;
		case Event::KeyPressed:
			if (Event.key.code == Keyboard::Escape) this->Window->close();
			break;
		}
	}
}

void Game::Render()
{
	this->Window->clear(Color::Green); // 화면색
	this->Window->draw(this->Player);
	this->Window->display();
}

// player
void Game::InitPlayer()
{
	this->Player.setRadius(100.0f);
	this->Player.setFillColor(Color::Blue);
	this->Player.setPosition(100, 100);
}
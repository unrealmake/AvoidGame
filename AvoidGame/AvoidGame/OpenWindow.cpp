#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

void OpenWindow()
{
	RenderWindow Window(VideoMode(1280, 720), "Avoid Game", Style::Titlebar | Style::Close);

	Event Event;

	// ������ â�� ������ �� ���α׷� ���� ���� �ʵ���
	while(Window.isOpen())
	{
		// �̺�Ʈ ����
		while (Window.pollEvent(Event)) {

			// clear
			Window.clear(Color::Green); // ȭ���
			// draw
			Window.display(); // ����

			switch (Event.type) {

			case Event::Closed:
				// ����
				Window.close();
				break;
			case Event::KeyPressed:
				if(Event.key.code == Keyboard::Escape) Window.close();
					break;
			}
	}
		
		
	}
}

/*
	�̺�Ʈ(Event) : (�߻���) ���
	=> ����Ʈ����, ���ø����̼��� ���� ��ȭ : �����

	- Interface ��ġ�� ���õ� �̺�Ʈ : Ű����, ���콺, ��ġ��ũ��
		- Ű���� �̺�Ʈ : Ű �Է�(Press), ������ Ű ������ if�� ����
		- ���콺 �̺�Ʈ : Ŭ��(Press / Release), �� ��ũ��, ���� Ŭ��, ������, �巡�� (Press + Move)
		- ��ġ ��ũ�� : ��ġ, ��������, ��ġ
	- Interface ��ġ�� ���þ��� �̺�Ʈ
		- �ε� �̺�Ʈ : �����ͳ� ����Ʈ������ ȭ�� ���� ��Ұ� ��� ȭ�鿡 ������� �߻��Ǵ� �̺�Ʈ

	�̺�Ʈ �߻��� �̺�Ʈ ���� => �ش� �̺�Ʈ�� ������ ����

	Event Listening : �̺�Ʈ ����
	Event Handling : ������ �̺�Ʈ�� ���ؼ� ������ ����

*/
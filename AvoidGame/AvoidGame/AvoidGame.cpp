#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Game.h"

int main()
{
    //������ ��� ����
    // time�� ��� : ������ �� ���� �ʱⰪ�� �ٸ������� ���
    srand(time(NULL));

    // start up
    Game Avoid;

    // ���� ����
    while (Avoid.Running())
    {

    Avoid.EventHandler();
    Avoid.Update();
    Avoid.Render();
    }
}
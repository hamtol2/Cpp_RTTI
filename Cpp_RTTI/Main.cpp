#include <iostream>
#include "Actor/Player.h"

int main()
{
	TSubclassOf<Player> objectType = Player::StaticClass();
	auto object = SpawnActor<Player>(objectType);

	if (object->Is<Player>())
	{
		// Player 타입.
		std::cout << "object is Player type.\n";
	}
	if (object->Is<Actor>())
	{
		// Actor 타입.
		std::cout << "object is Actor type.\n";
	}
}
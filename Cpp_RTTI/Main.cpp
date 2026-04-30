#include <iostream>
#include "Actor/Player.h"

int main()
{
	std::shared_ptr<CraftObject> object = std::make_shared<Player>();

	if (object->Is(Player::TypeId()))
	{
		// Player 타입.
		std::cout << "object is Player type.\n";
	}
	if (object->Is(Actor::TypeId()))
	{
		// Actor 타입.
		std::cout << "object is Actor type.\n";
	}
}
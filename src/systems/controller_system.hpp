#pragma once

#include <dawn/ecs/system.hpp>


namespace game
{
	class game;
	class controller_system : public dawn::system
	{
	public:
		controller_system(game& game);

	protected:
		void update_entity(dawn::entity& entity);
	};
}
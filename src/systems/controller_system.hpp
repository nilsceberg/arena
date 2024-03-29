#pragma once

#include "factories/projectile_factory.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>
#include <dawn/ecs/system.hpp>
#include <dawn/time.hpp>



namespace game
{
	class game;
	class controller_system : public dawn::system
	{
	public:
		controller_system(game& game, dawn::entity_list& entities);

	protected:
		void update_entity(dawn::entity::ptr entity);
		void pre_update();

	private:
		game& m_game;
		dawn::entity_list& m_entities;

		projectile_factory m_projectile_factory;
	};
}

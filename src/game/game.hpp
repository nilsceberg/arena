#pragma once

#include "assets/asset_loader.hpp"
#include "factories/player_factory.hpp"
#include "systems/render_system.hpp"
#include "systems/controller_system.hpp"
#include "systems/movement_system.hpp"
#include "systems/debug_info_system.hpp"

#include <dawn/events/event_dispatcher.hpp>
#include <dawn/tasks/scheduler.hpp>
#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class application;
	class game
	{
	public:
		game(application& app);
		~game();

		dawn::event_dispatcher& get_event_dispatcher();
		dawn::scheduler& get_scheduler();

		application& get_application();

		asset_loader& get_asset_loader();

		void update();
		void render();

	private:
		application& m_app;

		asset_loader m_loader;

		player_factory m_player_factory;

		std::vector<dawn::entity::ptr> m_entities;

		controller_system m_controller_system;
		debug_info_system m_debug_info_system;
		movement_system m_movement_system;
		render_system m_renderer;
	};
}

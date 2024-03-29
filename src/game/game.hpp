#pragma once

#include "state_stack.hpp"
#include "assets/asset_loader.hpp"

#include <dawn/events/event_dispatcher.hpp>
#include <dawn/tasks/scheduler.hpp>
#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/system.hpp>
#include <dawn/time.hpp>


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
		state_stack& get_state_stack();

		void update();
		void render();


		float get_delta() const;

	private:
		void update_delta();

		application& m_app;

		asset_loader m_loader;

		state_stack m_state_stack;

		dawn::time::time_point m_last_update;
		float m_delta;
	};
}

#pragma once

#include "particles/particle_emitter.hpp"

#include <dawn/ecs/component.hpp>


namespace game
{
	class particle_emitter_component : public dawn::component
	{
	public:
		particle_emitter_component(
			const glm::vec3& color_start,
			const glm::vec3& color_end,
			const glm::vec3& target_color,
			float size_start, float size_end,
			float frequency,
			float cone_size,
			const glm::vec2& direction,
			float speed,
			float friction,
			dawn::time::duration lifetime,
			dawn::entity::ptr follow = nullptr
		) :
		emitter(
			color_start, color_end,
			target_color,
			size_start, size_end,
			frequency,
			cone_size,
			direction,
			speed,
			friction,
			lifetime,
			follow
		)
		{}

		particle_emitter_component(
			const particle_emitter& emitter
		)
		: emitter(emitter)
		{}

		particle_emitter emitter;
	};
}

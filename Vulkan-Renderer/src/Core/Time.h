#pragma once

namespace VulkanRenderer
{
	class Time
	{
	public:
		Time() = default;
		Time(float deltatime) : m_DeltaTime(deltatime) {}

		operator float() const { return m_DeltaTime; }

		inline const float GetDeltaTime() const { return m_DeltaTime; }
		inline const float GetDeltaTimeMillis() const { return m_DeltaTime * 1000; }
	private:
		float m_DeltaTime = 0;
	};

	inline Time DeltaTime;
}
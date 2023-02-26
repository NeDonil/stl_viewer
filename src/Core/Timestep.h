#pragma once

namespace Viewer
{
	class Timestep
	{
	public:
		Timestep(float time) :
			m_Time(time)
		{
		}

		operator float() const { return m_Time; }

		float GetSecond() const { return m_Time; }
		float GetMilisecond() const { return m_Time * 1000.0f; }
	private:
		float m_Time = 0.0f;
	};
}
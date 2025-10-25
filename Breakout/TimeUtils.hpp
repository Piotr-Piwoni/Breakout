#pragma once

class TimeUtils
{
public:
	static float GetDefaultTimeScale();

	static float GetTimeScale();
	static void SetTimeScale(float value);

private:
	static float m_TimeScale;
};

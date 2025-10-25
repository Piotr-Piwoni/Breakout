#include "TimeUtils.hpp"

float TimeUtils::m_TimeScale = 1.0f;

float TimeUtils::GetDefaultTimeScale()
{
	return 1.0f;
}

float TimeUtils::GetTimeScale()
{
	return m_TimeScale;
}

void TimeUtils::SetTimeScale(const float value)
{
	m_TimeScale = value;
}

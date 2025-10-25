#include "SlowMoUltimate.hpp"
#include "TimeUtils.hpp"

void SlowMoUltimate::ApplyEffect()
{
	UltimateBase::ApplyEffect();

	TimeUtils::SetTimeScale(0.3f);
}

void SlowMoUltimate::StopEffect()
{
	UltimateBase::StopEffect();

	TimeUtils::SetTimeScale(TimeUtils::GetDefaultTimeScale());
}

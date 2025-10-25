#pragma once
#include "UltimateBase.hpp"

class SlowMoUltimate : public UltimateBase
{
public:
	void ApplyEffect() override;
	void StopEffect() override;

private:
};

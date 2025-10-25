#include "UltimateBase.hpp"

void UltimateBase::Update(const float dt)
{
	// Only work when active.
	if (!m_IsActive)
		return;

	// Increment time.
	m_Time -= dt;

	if (m_Time <= 0.0f)
		StopEffect();
}

void UltimateBase::ApplyEffect()
{
	m_Time = m_MaxDuration;
	m_IsActive = true;
}

void UltimateBase::StopEffect()
{
	m_Time = 0.0f;
	m_IsActive = false;
}

float UltimateBase::GetMaxDuration() const
{
	return m_MaxDuration;
}

void UltimateBase::SetMaxDuration(const float seconds)
{
	m_MaxDuration = seconds;
}

bool UltimateBase::IsActive() const
{
	return m_IsActive;
}

void UltimateBase::SetActive(const bool b)
{
	m_IsActive = b;
}

#pragma once

class UltimateBase
{
public:
	virtual ~UltimateBase() = default;

	void Update(float dt);

	virtual void ApplyEffect();
	virtual void StopEffect();

	float GetMaxDuration() const;
	void SetMaxDuration(float seconds);

	bool IsActive() const;
	void SetActive(bool b);

protected:
	float m_Time{};
	float m_MaxDuration{5.0f};
	bool m_IsActive{false};
};

#include "ProgressBar.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

ProgressBar::ProgressBar()
{
	m_Background.setSize(m_Size);
	m_Background.setFillColor({50, 50, 50, 200});

	m_FillBar.setSize({m_Size.x * m_Progress, m_Size.y});
	m_FillBar.setFillColor(sf::Color::Red);

	m_Angle = m_Background.getRotation();
}

void ProgressBar::Render(sf::RenderWindow& window)
{
	if (!m_IsVisible)
		return;

	window.draw(m_Background);
	window.draw(m_FillBar);
}

bool ProgressBar::IsVisible() const
{
	return m_IsVisible;
}

void ProgressBar::SetVisible(const bool b)
{
	m_IsVisible = b;
}

float ProgressBar::GetProgress() const
{
	return m_Progress;
}

void ProgressBar::SetProgress(const float val)
{
	m_Progress = val;
	UpdateFillBar();
}

sf::Color ProgressBar::GetBarColour() const
{
	return m_FillBar.getFillColor();
}

void ProgressBar::SetBarColour(const sf::Color color)
{
	m_FillBar.setFillColor(color);
}

sf::Vector2f ProgressBar::GetPosition() const
{
	return m_Position;
}

void ProgressBar::SetPosition(const sf::Vector2f pos)
{
	m_Position = pos;
	m_Background.setPosition(m_Position);
	m_FillBar.setPosition(m_Position);
}

sf::Vector2f ProgressBar::GetSize() const
{
	return m_Size;
}

void ProgressBar::SetSize(const sf::Vector2f size)
{
	m_Size = size;
	m_Background.setSize(m_Size);
	UpdateFillBar();
}

float ProgressBar::GetRotation() const
{
	return m_Angle;
}

void ProgressBar::SetRotation(const float degrees)
{
	m_Angle = degrees;
	m_Background.setRotation(m_Angle);
	m_FillBar.setRotation(m_Angle);
}

void ProgressBar::UpdateFillBar()
{
	m_FillBar.setSize({m_Size.x * m_Progress, m_Size.y});
}

#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

namespace sf
{
class RenderWindow;
}

class ProgressBar
{
public:
	ProgressBar();

	void Render(sf::RenderWindow& window);

	bool IsVisible() const;
	void SetVisible(bool b);

	float GetProgress() const;
	void SetProgress(float val);

	sf::Color GetBarColour() const;
	void SetBarColour(sf::Color color);

	sf::Vector2f GetPosition() const;
	void SetPosition(sf::Vector2f pos);

	sf::Vector2f GetSize() const;
	void SetSize(sf::Vector2f size);

	float GetRotation() const;
	void SetRotation(float degrees);

private:
	void UpdateFillBar();

private:
	sf::RectangleShape m_Background{};
	sf::RectangleShape m_FillBar{};
	bool m_IsVisible{true};
	float m_Progress{0.0f};

	sf::Vector2f m_Position{};
	sf::Vector2f m_Size{100.0f, 10.0f};
	float m_Angle{};
};

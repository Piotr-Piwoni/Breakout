#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

class ProgressBar
{
public:
	ProgressBar();

	bool IsVisible() const;
	void SetVisible(bool b);

	float GetProgress() const;
	void SetProgress(float val);

	sf::Vector2f GetPosition() const;
	void SetPosition(sf::Vector2f pos);

	sf::Vector2f GetSize() const;
	void SetSize(sf::Vector2f size);

private:
	sf::RectangleShape _background{};
	sf::RectangleShape _fillBar{};
	bool _isVisible{false};
	float _progress{0.0f};

	sf::Vector2f _position{};
	sf::Vector2f _size{};
};

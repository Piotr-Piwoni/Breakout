#include "ProgressBar.hpp"

ProgressBar::ProgressBar()
{
	_background.setSize({100.0f, 10.0f});
	_background.setFillColor({50, 50, 50, 200});

	_fillBar.setSize({100.0f * _progress, 10.0f});
	_fillBar.setFillColor(sf::Color::Red);
}

bool ProgressBar::IsVisible() const
{
	return _isVisible;
}

void ProgressBar::SetVisible(const bool b)
{
	_isVisible = b;
}

float ProgressBar::GetProgress() const
{
	return _progress;
}

void ProgressBar::SetProgress(const float val)
{
	_progress = val;
}

sf::Vector2f ProgressBar::GetPosition() const
{
	return _position;
}

void ProgressBar::SetPosition(const sf::Vector2f pos)
{
	_position = pos;
	_background.setPosition(_position);
	_fillBar.setPosition(_position);
}

sf::Vector2f ProgressBar::GetSize() const
{
	return _size;
}

void ProgressBar::SetSize(sf::Vector2f size)
{
	_size = size;
	_background.setSize(_size);
	_fillBar.setSize({_size.x * _progress, _size.y});
}

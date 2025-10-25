#include "UI.h"
#include <iomanip>
#include <sstream>
#include "GameManager.h"

UI::UI(sf::RenderWindow* window, int lives, GameManager* gameManager) :
	_gameManager(gameManager), _window(window)
{
	for (int i = lives; i > 0; --i)
	{
		sf::CircleShape newLife;
		newLife.setFillColor(sf::Color::Red);
		newLife.setOutlineColor(sf::Color::Cyan);
		newLife.setOutlineThickness(4.0f);
		newLife.setRadius(LIFE_RADIUS);
		newLife.setPosition((LIFE_RADIUS * 2 + LIFE_PADDING) * i, LIFE_PADDING);
		_lives.push_back(newLife);
	}
	_powerupText.setCharacterSize(30);
	_powerupText.setPosition(800, 10);
	_powerupText.setFillColor(sf::Color::Cyan);
	_font.loadFromFile("font/montS.ttf");
	_powerupText.setFont(_font);

	_powerupIcon.setPosition({750.0f, 10.0f});
	_powerupIcon.setFillColor(sf::Color::Cyan);

	// Vertically align the progress bar and the powerup icon.
	constexpr float spacing = 25.0f;
	const float iconCenterY = _powerupIcon.getPosition().y +
							  _powerupIcon.getRadius();
	_progressBar.SetSize({150.0f, 35.0f});
	_progressBar.SetPosition({
		_powerupIcon.getPosition().x + 2.0f *
		_powerupIcon.getRadius() + spacing,
		iconCenterY - _progressBar.GetSize().y / 2.0f
	});
	_progressBar.SetVisible(false);

	// Ultimate Bar.
	_ultimateBar.SetRotation(-90.0f);
	_ultimateBar.SetBarColour(sf::Color::Yellow);
	_ultimateBar.SetSize({170.0f, 20.0f});

	const auto winSize = static_cast<sf::Vector2f>(_window->getSize());
	const sf::Vector2f ultOffset = {50.0f, _ultimateBar.GetSize().x / 2.0f};
	_ultimateBar.SetPosition({
		winSize.x - ultOffset.x,
		winSize.y / 2.0f + ultOffset.y
	});
}

UI::~UI()
{}


void UI::updatePowerupText(std::pair<POWERUPS, sf::Vector2f> powerup)
{
	std::ostringstream oss;

	const float time = powerup.second.y;
	switch (powerup.first)
	{
	case bigPaddle:
		oss << std::fixed << std::setprecision(2) << time;
		_powerupText.setString("big " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		break;
	case smallPaddle:
		oss << std::fixed << std::setprecision(2) << time;
		_powerupText.setString("small " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		break;
	case slowBall:
		oss << std::fixed << std::setprecision(2) << time;
		_powerupText.setString("slow " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		break;
	case fastBall:
		oss << std::fixed << std::setprecision(2) << time;
		_powerupText.setString("fast " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		break;
	case fireBall:
		oss << std::fixed << std::setprecision(2) << time;
		_powerupText.setString("fire " + oss.str());
		_powerupText.setFillColor(extraBallEffectsColour);
		break;
	case none:
		_powerupText.setString("");

		break;
	}
}

void UI::updatePowerupBar(std::pair<POWERUPS, sf::Vector2f> powerup)
{
	const float time = powerup.second.y;
	const float maxDuration = powerup.second.x;
	// Calculate the remaining percentage.
	const float progress = std::clamp(time / maxDuration, 0.0f, 1.0f);
	_progressBar.SetProgress(progress);

	switch (powerup.first)
	{
	case bigPaddle:
		_progressBar.SetVisible(true);
		_powerupIcon.setFillColor(paddleEffectsColour);
		break;
	case smallPaddle:
		_progressBar.SetVisible(true);
		_powerupIcon.setFillColor(paddleEffectsColour);
		break;
	case slowBall:
		_progressBar.SetVisible(true);
		_powerupIcon.setFillColor(ballEffectsColour);
		break;
	case fastBall:
		_progressBar.SetVisible(true);
		_powerupIcon.setFillColor(ballEffectsColour);
		break;
	case fireBall:
		_progressBar.SetVisible(true);
		_powerupIcon.setFillColor(extraBallEffectsColour);
		break;
	case none:
		_progressBar.SetVisible(false);
		break;
	}
}

void UI::updateUltimateBar(const float amount)
{
	// Check for reset value.
	if (amount <= 0.0f)
	{
		_ultimateBar.SetProgress(0.0f);
		return;
	}

	// Convert into a full value.
	float currentProgress = _ultimateBar.GetProgress() * 100.0f;
	currentProgress += amount;
	// Calculate the remaining percentage.
	const float newProgress = std::clamp(currentProgress / 100.0f, 0.0f, 1.0f);
	_ultimateBar.SetProgress(newProgress);
}

bool UI::IsUltimateReady() const
{
	return _ultimateBar.GetProgress() >= 1.0f;
}

void UI::lifeLost(int lives)
{
	_lives[_lives.size() - 1 - lives].setFillColor(sf::Color::Transparent);
}

void UI::render()
{
	//_window->draw(_powerupText);

	for (sf::CircleShape life : _lives)
		_window->draw(life);

	// Render te progress bar with a icon.
	_progressBar.Render(*_window);
	if (_progressBar.IsVisible())
		_window->draw(_powerupIcon);

	_ultimateBar.Render(*_window);
}

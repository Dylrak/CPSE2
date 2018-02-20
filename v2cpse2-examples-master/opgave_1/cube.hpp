
#include "drawable.hpp"

class cube : public drawable
{
private:
	sf::Vector2f position;
	float size;
	sf::Color color;
	sf::RectangleShape rectangle;
public:

	cube(sf::Vector2f position, float size = 60.0, sf::Color color = sf::Color::Red);

	void draw(sf::RenderWindow & window) override;
	sf::FloatRect getAABB() override;
	void move(sf::Vector2f delta);
};


#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include "drawable.hpp"
//#include "operators.hpp"

class picture : public drawable
{
private:
	static std::string name;
	std::string path;
	sf::Texture image;
	sf::RectangleShape shape;
public:
	picture(sf::Vector2f position, std::string filename);
	std::string print() override;
};

#endif //_PICTURE_HPP

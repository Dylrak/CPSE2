#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "circle.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include <iostream>
#include <fstream>

class factory
{
private:
	std::string filename;
	std::vector<drawable*> drawables;
	drawable * read_drawable(std::ifstream & input);
public:
	factory(std::string filename);
	bool read_drawables();
	std::vector<drawable*> get_drawables();
	void set_drawables(std::vector<drawable*> drawables);
};

#endif

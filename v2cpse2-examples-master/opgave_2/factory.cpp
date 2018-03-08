#include "factory.hpp"

factory::factory()
{
}
class unknown_color : public std::exception {
private:
	std::string s;
public:
	unknown_color(const std::string & name) :
		s{ std::string{ "unknown color [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
};

class unknown_shape : public std::exception {
private:
	std::string s;
public:
	unknown_shape(const std::string & name) :
		s{ std::string{ "unknown shape [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
};

class invalid_position : public std::exception {
private:
	std::string s;
public:
	invalid_position(const char & c) : 
		s{ std::string {"invalid character [" } +c + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
};

class invalid_filename : public std::exception {
private:
	std::string s;
public:
	invalid_filename(const std::string & name) :
		s{ std::string{ "invalid filename [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
};

class end_of_file : public std::exception {
};

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) { throw end_of_file(); }
	if (c != '(') { throw invalid_position(c); }

	if (!(input >> rhs.x)) {  }
	if (!(input >> c)) { }
	
	if (!(input >> rhs.y)) { }

	if (!(input >> c)) { }
	if (c != ')') { throw invalid_position(c); }

	return input;
}

std::ifstream & operator>>(std::ifstream & input, sf::Color & rhs) {
	std::string s;
	input >> s;
	const struct { const char * name; sf::Color color; } colors[]{
		{ "YELLOW", sf::Color::Yellow },
		{ "RED",    sf::Color::Red },
		{ "GREEN",    sf::Color::Green },
		{ "BLUE",    sf::Color::Blue }
	};
	for (auto const & color : colors) {
		if (color.name == s) {
			rhs = color.color;
			return input;
		}
	}
	if (s == "") {
		throw end_of_file();
	}
	throw unknown_color(s);
}

std::ifstream & operator>>(std::ifstream & input, sf::Texture & rhs) {
	std::string s;
	input >> s;
	if (!rhs.loadFromFile(s)) {
		throw invalid_filename(s);
	}
	return input;
}

drawable * read_drawable(std::ifstream & input) {
	sf::Vector2f position;
	std::string name;
	input >> position >> name;

	if (name == "circle") {
		sf::Color fill_color;
		int radius;
		input >> fill_color;
		input >> radius;
		return new circle(position, fill_color, radius);
	}
	else if (name == "rectangle") {
		sf::Color fill_color;
		sf::Vector2f size;
		input >> size >> fill_color;
		return new rectangle(position, fill_color, size);
	}
	else if (name == "picture") {
		sf::Texture image;
		input >> image;
		return new picture(position, image);
	}
	else if (name == "line") {
		sf::Color fill_color;
		sf::Vector2f size;
		input >> size >> fill_color;
		return new line(position, fill_color, size);
	}
	else if (name == "") {
		throw end_of_file();
	}

	throw unknown_shape(name);
}

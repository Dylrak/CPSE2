#include "factory.hpp"

factory::factory(std::string filename):
	filename (filename)
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

class invalid_character : public std::exception {
private:
	std::string s;
public:
	invalid_character(const char & c) : 
		s{ std::string {"invalid character [" } +c + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
};

class invalid_syntax : public std::exception {
private:
	std::string s;
public:
	invalid_syntax(const std::string & name) :
		s{ std::string{ "invalid syntax [" } + name + "]" }
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
	if (!(input >> c)) { throw invalid_syntax("Unexpected EOF at vector"); }
	if (c != '(') { throw invalid_character(c); }

	if (!(input >> rhs.x)) { throw invalid_syntax("Unexpected X-value for vector"); }
	if (!(input >> c)) { throw invalid_syntax("Unexpected EOF at vector"); }
	if (c != ',') { throw invalid_character(c); }
	
	if (!(input >> rhs.y)) { throw invalid_syntax("Unexpected Y-value for vector"); }

	if (!(input >> c)) { throw invalid_syntax("Unexpected EOF at vector"); }
	if (c != ')') { throw invalid_character(c); }

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
		throw invalid_syntax("Unexpected EOF at color");
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
drawable * factory::read_drawable(std::ifstream & input) {
	sf::Vector2f position;
	std::string name;
	input >> name;
	if (name == "") {
		throw end_of_file();
	}
	input >> position;

	if (name == "picture") {
		std::string filename;
		input >> filename;
		return new picture(position, filename);
	} 
	else if (name == "circle") {
		sf::Color fill_color;
		float radius;
		input >> fill_color >> radius;
		return new circle(position, fill_color, radius);
	}
	else if (name == "rectangle") {
		sf::Color fill_color;
		sf::Vector2f size;
		input >> fill_color >> size;
		return new rectangle(position, fill_color, size);
	}
	else if (name == "line") {
		sf::Color fill_color;
		sf::Vector2f size;
		input >> fill_color >> size;
		return new line(position, fill_color, size);
	}

	throw unknown_shape(name);
}

bool factory::read_drawables() {
	std::ifstream input(filename);
	try {
		for (;;) {
			drawables.push_back(read_drawable(input));
		}
	}
	catch (end_of_file) {
		return true;
	}
	catch (std::exception & problem) {
		std::cerr << problem.what() << '\n';
		return false;
	}
}
std::vector<drawable*> factory::get_drawables() {
	return drawables;
}

void factory::set_drawables(std::vector<drawable*> drawables) {
	std::ofstream output(filename, std::ofstream::trunc);
	try {
		for (auto drawable : drawables) {
			output << drawable->print();
		}
	}
	catch (std::exception & problem) {
		std::cerr << problem.what() << '\n';
	}
}
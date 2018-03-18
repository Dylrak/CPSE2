#include <iostream>
#include <fstream>
#include <functional>
#include <array>
#include <set>
#include <SFML/Graphics.hpp>

std::vector<char> get_characters(std::string filename) {
	std::vector<char> characters;
	std::ifstream file(filename);
	char current;
	//Filling vector with chars
	while (file.get(current)) {
		characters.push_back(current);
	}
	return characters;
}

int get_line_amount(const std::vector<char> & characters) {
	int line_amount = 0; //We assume the document ends with a newline. If there is just one line, trailed by one '\n' then we count just a single line in the file.
	for (char c : characters) {
		if (c == '\n') {
			line_amount++;
		}
	}
	return line_amount;
}

int get_alphabetic_char_amount(const std::vector<char> & characters) {
	int alpha_char_amount = 0; //We assume the document ends with a newline. If there is just one line, trailed by one '\n' then we count just a single line in the file.
	for (char c : characters) {
		if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z')) {
			alpha_char_amount++;
		}
	}
	return alpha_char_amount;
}

std::map<char, int> get_character_amounts(const std::vector<char> & characters) {
	std::map<char, int> character_amounts;
	for (char c : characters) {
		if (c > 'a' && c < 'z') { character_amounts[c]++; }
	}
	return character_amounts;
}

std::ostream & operator<< (std::ostream & lhs, std::map<char, int> char_amounts_alphabetic) {
	lhs << "Amounts of characters are as following: \n";
	for (auto char_amount : char_amounts_alphabetic) {
		lhs << char_amount.first << ": " << char_amount.second << '\n';
	}
	return lhs;
}

std::map<int, char> swap_key_value(const std::map<char, int> char_amounts_alphabetic) {
	// Declaring the type of Predicate that accepts 2 pairs and return a bool
	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
		[](std::pair<char, int> elem1, std::pair<char, int> elem2)
	{
		return elem1.second < elem2.second;
	};

	// Declaring a set that will store the pairs using above comparision logic
	std::set<std::pair<std::string, int>, Comparator> char_amounts_by_amount(
		char_amounts_alphabetic.begin(),char_amounts_alphabetic.end(), compFunctor);
}
void uppercase_to_lowercase(std::vector<char> & characters) {
	for (char c : characters) {
		if (c > 'A' && c < 'Z') c -= 'a' - 'A'; //Subtract the difference between upper- and lowercase from the character to get its lowercase counterpart.
	}
}

int main() {
	//Declaration
	std::vector<char> characters = get_characters("bible.txt");
	std::map<char, int> char_amounts_alphabetic;
	std::map<int, char> char_amounts_by_amount;
	std::cout << "Amount of characters in file: " << characters.max_size() << '\n';
	std::cout << "Amount of newlines in file: " << get_line_amount(characters) << '\n';
	uppercase_to_lowercase(characters);
	std::cout << "Changed all uppercase characters to lowercase.\n";
	char_amounts_alphabetic = get_character_amounts(characters);

	std::cout << char_amounts_alphabetic; //print the amounts of all lowercase characters
	return 0;
}
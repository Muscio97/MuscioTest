#include <iostream>
#include <cctype>
#include <fstream>  
#include <vector>
#include <map>
#include <stdlib.h>
#include <algorithm>

int main() {

	char character;
	int alphabet = 0;
	int upper = 0;
	int temp = 0;
	std::string word;
	std::vector<int> list;
	std::map <int, char> count;
	std::map <std::string, int> words;
	std::map <int, std::string> sort_words;
	std::ifstream file("temp.txt");

	std::cout << "Het is gestart......\nGeloof me.\n";

	if (file.is_open())
		while (file.get(character)) {
			list.push_back(character);
			if (std::isalpha(character)) {
				character = std::tolower(character);
			}
			if (std::isalpha(character)) {
				word += character;
			}
			else {
				if (word != "") {
					words[word]++;
					word = "";
				}
			}
		}

	int lines = std::count(list.begin(), list.end(), '\n');

	for (int i = 'A'; i <= 'z'; i++) {
		temp = std::count(list.begin(), list.end(), i);
		alphabet = alphabet + temp;
	}

	for (auto &character : list) { character = std::tolower(character); } //ONELINER !!!!!

	for (int i = 'A'; i <= 'Z'; i++) {
		temp = std::count(list.begin(), list.end(), i);
		upper = upper + temp;
	}

	for (int i = 'a'; i <= 'z'; i++) {
		temp = std::count(list.begin(), list.end(), i);
		count[temp] = i;
	}

	std::cout << "Size vector: " << list.size() <<
		"\nNumber of lines: " << lines <<
		"\nNumber of alphabet letters: " << alphabet <<
		"\nNumber of uppercase letters: " << upper << "\n";

	for (auto const &character : count) {
		std::cout << character.second << "\t" << character.first << "\n";
	}

	for (auto const &word : words) {
		sort_words[word.second] = word.first;
	}

	std::cout << "\n\n";

	auto end = sort_words.rbegin();

	for (int i = 0; i < 10; i++){
		std::advance(end, i);
		std::cout << i << ". " << end->second.c_str() << "\t" << end->first << "\n";
	}
	
	while (true) {}
	return 69;

}











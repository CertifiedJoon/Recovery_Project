#include <string>
#include <map>
#include <fstream>
#include <iostream>

int main () {
	std::multimap<std::string, std::string> author_to_book;
	std::ifstream fin ("books.txt");
	std::string author, book;
	
	while(fin >> author >> book)
		multimap.insert(make_pair(book, author));

	std::cout << "which book would you like to erase? ";
	std::cin >> book >> author;
}
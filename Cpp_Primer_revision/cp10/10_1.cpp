#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

int main () {
	std::list<std::string> v {"word", "word", "words", "wjhat"};
	std::cout << count(v.begin(), v.end(), string("word")) << std::endl;
}
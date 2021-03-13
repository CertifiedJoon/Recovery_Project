#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
int main () {
	std::ifstream fin ("test.txt");
	std::istream_iterator<std::string> ist_it(fin), eof;
	std::ostream_iterator<std::string> ost_it(std::cout, " ");
	std::vector<std::string> v (ist_it, eof);
	
	copy(v.cbegin(), v.cend(), ost_it);
	std::cout << std::endl;
}
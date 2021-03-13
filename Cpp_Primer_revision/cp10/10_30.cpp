#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main () {
	std::istream_iterator<int> ist_it(std::cin), eof;
	std::ostream_iterator<int> ost_it(std::cout, " ");
	std::vector<int> v(ist_it, eof);
	
	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), ost_it);
	std::cout << std::endl;
}
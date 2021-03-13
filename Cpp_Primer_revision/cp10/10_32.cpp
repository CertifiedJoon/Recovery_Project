#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>


int main() {
	std::ifstream fin("test.txt");
	std::ofstream oddOut("odd.txt");
	std::ofstream evenOut("even.txt");
	
	std::istream_iterator<int> ist_it(fin), eof;
	std::ostream_iterator<int> odd_it(oddOut, " ");
	std::ostream_iterator<int> even_it(evenOut, "\n");
	
	std::vector<int> v (ist_it, eof);
	
	copy_if(v.cbegin(), v.cend(), even_it, [](int i) {return (i % 2 == 0);});
	copy_if(v.cbegin(), v.cend(), odd_it, [](int i) {return (i%2 != 0);});
}


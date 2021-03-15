#include "strblob.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::string line;
	std::ifstream fin(argv[1]);
	StrBlob sb;
	while (getline(fin, line)) {
		sb.push_back(line);
	}
	
	for (StrBlobPtr it = sb.begin(); it != sb.end(); it.incr())
		std::cout << it.deref() << std::endl;
	
	return 0;
}
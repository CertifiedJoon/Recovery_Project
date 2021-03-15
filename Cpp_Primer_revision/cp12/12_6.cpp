#include <memory>
#include <vector>
#include <iostream>

void read(std::vector<int> *);
void print(std::vector<int> *);
std::vector<int>* dynamic();

int main () {
	std::vector<int> *vp = dynamic();
	read(vp);
	print(vp);
	delete vp;
}

void read(std::vector<int> *vp) {
	int s;
	
	while(std::cin >> s) 
		vp->push_back(s);
}

void print(std::vector<int> *vp) {
	for (auto i : *vp)
		std::cout << i << std::endl;
}

std::vector<int>* dynamic(){
	return new std::vector<int>();
}

#include <memory>
#include <vector>
#include <iostream>

void read(std::shared_ptr<std::vector<int>>);
void print(std::shared_ptr<std::vector<int>>);
std::shared_ptr<std::vector<int>>
	dynamic();

int main() {
	std::shared_ptr<std::vector<int>> vsp = dynamic();
	read(vsp);
	print(vsp);
}

void read(std::shared_ptr<std::vector<int>> vsp) {
	int i;
	while(std::cin >> i)
		vsp->push_back(i);
}

void print(std::shared_ptr<std::vector<int>> vsp) {
	for (auto i : *vsp)
		std::cout << i << " ";
	std::cout << std::endl;
}

std::shared_ptr<std::vector<int>> dynamic() {
	return std::make_shared<std::vector<int>> ();
}
#include <iostream>

unsigned call_count();

int main() {
	for (int i = 0; i < 10; ++i)
		std::cout << call_count() << std::endl;
	
	return 0;
}

unsigned call_count (){
	static unsigned cnt = 0;
	++cnt;
	return cnt;
}
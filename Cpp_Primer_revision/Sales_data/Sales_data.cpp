#include <iostream>
#include "Sales_data.h"

int main(){
	Sales_data total (std::cin);
	Sales_data test1 ("X-201");
	Sales_data test2 ("X-202", 25, 9.0);
	
	print(std::cout, test1);
	print(std::cout, test2);
	
	Sales_data trans;
	while(read(std::cin, trans)){
		if (total.isbn() ==trans.isbn()) {
			total.combine(trans);
		} else {
			print(std::cout, total) <<std::endl;
			total = trans;
		}
	}
	print(std::cout, total) << std::endl;
}



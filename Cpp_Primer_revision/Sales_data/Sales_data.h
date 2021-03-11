#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data;

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

class Sales_data{
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);
public:
	Sales_data (const std::string &s, unsigned n, double price) : bookNo (s), units_sold(n), revenue (price * n) {}
	Sales_data () : Sales_data("", 0, 0) {}
	Sales_data (const std::string &s) : Sales_data(s, 0, 0) {}
	Sales_data (std::istream &is);
	std::string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);

	double avg_price() const { return units_sold ? revenue / units_sold : 0; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data::Sales_data (std::istream &is) {read(is, *this);}

Sales_data& Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, Sales_data &item){
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}





#endif
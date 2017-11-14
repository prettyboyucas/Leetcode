
#ifndef QUOTE_H_
#define QUOTE_H_
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price):
		bookNo(book), price(sales_price) {}

	std::string isbn() const;
	virtual double net_price(std::size_t n) const {
		return n*price;
	}

	virtual ~Quote() = default;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};


//derived
class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
		Quote(book, p), min_qty(qty),discount(disc){}
	double net_price(std::size_t cnt) const override
	{
		if (cnt > min_qty)
			return cnt*(1 - discount) *price;
		else
			return cnt*price;
	}

private:
	std::size_t min_qty = 0;
	double discount = 0.0;

};







#endif // !QUOTE_H_
#include <iostream>

class rational
{
	public:
		rational(int num=0, int denom=1) : num(num), denom(denom) {}

		int numerator() const { return num; }
		int denominator() const { return denom;}
	private:
		int num;
		int denom;	
};

std::ostream& operator<<(std::ostream& os, const rational& r)
{
	return os << r.numerator() << "/" << r.denominator();
}
const rational operator*(const rational& a, const rational& b)
{
	return rational(a.numerator() * b.numerator(), a.denominator() * b.denominator());
}

int main()
{
	rational a(1, 3);
	rational b(3, 4);

	int x = 5;

	std::cout << x*a << std::endl;

	return 0;
}

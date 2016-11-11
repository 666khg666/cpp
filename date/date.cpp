/*
 * Simple class for representing dates.
 * Tries to conform to good interface design.
 */
#include <iostream>

struct day
{
	explicit day(int v) : val(v) {}

	int val;
};

struct month
{
	explicit month(int v) : val(v) {}

	int val;
};

struct year
{
	explicit year(int v) : val(v) {}

	int val;
};

class date
{
	public:
		explicit date(const struct day& d, const struct month& m, const struct year& y) : day(d.val), month(m.val), year(y.val) {}

		friend std::ostream& operator<<(std::ostream& os, const date& d);
	private:
		int day;
		int month;
		int year;
};

std::ostream& operator<<(std::ostream& os, const date& d)
{
	return os << d.day << "." << d.month << "." << d.year;
}

int main()
{
	date now(day(11), month(11), year(2016));

	std::cout << now << std::endl;
	return 0;
}

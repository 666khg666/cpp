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

class month
{
	public:
		static month january() { return month(1); }
		static month february() { return month(2); }
		static month march() { return month(3); }
		static month april() { return month(4); }
		static month may() { return month(5); }
		static month june() { return month(6); }
		static month july() { return month(7); }
		static month august() { return month(8); }
		static month september() { return month(9); }
		static month october() { return month(10); }
		static month november() { return month(11); }
		static month december() { return month(12); }

		int get_val() const { return val; }
	private:
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
		explicit date(const struct day& d, const month& m, const struct year& y) : day(d.val), month(m.get_val()), year(y.val) {}

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
	date now(day(11), month::november(), year(2016));

	std::cout << now << std::endl;
	return 0;
}

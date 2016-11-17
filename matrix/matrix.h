#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

namespace matrix {
template <typename T>
class matrix
{
	public:
		matrix(const std::size_t rows, const std::size_t columns, const std::vector<T>& vals);

		T get(const std::size_t i, const std::size_t j) const;
		std::size_t rows() const { return r; }
		std::size_t columns() const { return c; }
	private:
		std::size_t r;
		std::size_t c;
		std::vector<T> vals;


		// friends
		friend std::ostream& operator<<(std::ostream& os, const matrix<T>& m)
		{
			for (std::size_t i = 0; i < m.r*m.c; ++i) {
				os << (m.vals[i]) << "\t";
				if ((i+1) % m.c == 0 && ((i) % m.c) != (m.r-1)*m.c) {
					os << std::endl;
				}
			}

			return os;
		}
};

template <typename T>
matrix<T> operator*(const matrix<T>& a, const matrix<T>& b);

}
#endif

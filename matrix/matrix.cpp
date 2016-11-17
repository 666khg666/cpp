#include "matrix.h"
#include <cmath>

namespace matrix {
template <typename T>
matrix<T>::matrix(const std::size_t rows, const std::size_t columns, const std::vector<T>& vals)
: r(rows), c(columns), vals(vals)
{
	if ( rows*columns != vals.size())
	{
		throw std::range_error("rows*columns != matrix.size()");
	}
}

template <typename T>
T matrix<T>::get(const std::size_t i, const std::size_t j) const
{
	return vals[i*c + j];
}

template <typename T>
matrix<T> operator*(const matrix<T>& a, const matrix<T>& b)
{
	if (a.columns() != b.rows()) {
		throw std::range_error("a.columns != b.rows");
	}

	std::vector<T> res(a.rows()*b.columns());
	std::size_t rows = a.rows();
	std::size_t columns = b.columns();
	std::size_t common_dim = a.columns();

	for (std::size_t i = 0; i < rows; ++i) {
		for (std::size_t j = 0; j < columns; ++j) {
			T sum(0);
			for (std::size_t k = 0; k < common_dim; ++k) {
				sum += a.get(i, k) * b.get(k, j);
			}
			res[i*columns + j] = sum;
		}
	}

	return matrix<T>(rows, columns, res);
}

}

int main()
{

	double phi = std::atan(1)*4;
	matrix::matrix<double> m(3, 3, std::vector<double>({std::cos(phi), -std::sin(phi), 0,
						      std::sin(phi), std::cos(phi), 0,
						      0,             0,             1}));
	matrix::matrix<double> p(3, 1, std::vector<double>({0.5, 0.5, 2.0}));
	std::cout << m*p << std::endl;
	return 0;
}

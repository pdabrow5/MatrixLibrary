#ifndef UTIL_INC_MATRIX_HPP_
#define UTIL_INC_MATRIX_HPP_

#include "Vector.hpp"

#include <utility>

namespace Mat
{

using u_short = unsigned char;

/// @brief Pair contatining Matrix dimensions: Heigth and Width
using MatShape = std::pair<u_short, u_short>;

template <u_short heigth, u_short width>
class Matrix : private Vector<heigth * width>
{
public:
    using BaseVector = Vector<heigth * width>;
	Matrix();
	explicit Matrix(float val);
	explicit Matrix(const std::array<float, heigth*width>& values);

	inline float& operator()(u_short row, u_short col);
	inline const float& operator()(u_short row, u_short col) const;

	inline Matrix<heigth, width>& operator+= (const Matrix<heigth, width>& other);
	inline Matrix<heigth, width>& operator-= (const Matrix<heigth, width>& other);

	inline Matrix<heigth, width>& operator+= (float val);
	inline Matrix<heigth, width>& operator-= (float val);

	inline Matrix<heigth, width>& operator*= (float f);
	template <u_short other_width>
	Matrix<heigth, other_width> operator*(const Matrix<width, other_width>& other) const;

	template <u_short other_width>
	void Multiply(const Matrix<width, other_width>& other, Matrix<heigth, other_width>& result) const;

	const MatShape& Shape() const;
	static constexpr MatShape shape{heigth, width};
};

template <u_short heigth, u_short width>
Matrix<heigth, width>::Matrix() {static_assert(heigth > 0 && width > 0, "Matrix width and heigth must be positive!");}

template <u_short heigth, u_short width>
Matrix<heigth, width>::Matrix(float val): Vector<heigth*width>(val) {static_assert(heigth > 0 && width > 0, "Matrix width and heigth must be positive!");}

template <u_short heigth, u_short width>
Matrix<heigth, width>::Matrix(const std::array<float, heigth*width>& values): Vector<heigth*width>(values) {static_assert(heigth > 0 && width > 0, "Matrix width and heigth must be positive!");}

template <u_short heigth, u_short width>
float& Matrix<heigth, width>::operator()(u_short row, u_short col)
{
	u_int index = width * row + col;
	return Vector<heigth * width>::operator()(index);
}

template <u_short heigth, u_short width>
const float& Matrix<heigth, width>::operator()(u_short row, u_short col) const
{
	u_int index = width * row + col;
	return Vector<heigth * width>::operator()(index);
}

template <u_short heigth, u_short width>
Matrix<heigth, width>& Matrix<heigth, width>::operator+=(const Matrix<heigth, width>& other)
{
	BaseVector::operator+=(other);
	return *this;
}

template <u_short heigth, u_short width>
Matrix<heigth, width>& Matrix<heigth, width>::operator-=(const Matrix<heigth, width>& other)
{
	Vector<heigth * width>::operator-=(other);
	return *this;
}

template <u_short heigth, u_short width>
Matrix<heigth, width>& Matrix<heigth, width>::operator+=(float val)
{
	Vector<heigth * width>::operator+=(val);
	return *this;
}

template <u_short heigth, u_short width>
Matrix<heigth, width>& Matrix<heigth, width>::operator-=(float val)
{
	Vector<heigth * width>::operator-=(val);
	return *this;
}

template <u_short heigth, u_short width>
Matrix<heigth, width>& Matrix<heigth, width>::operator*=(float val)
{
	Vector<heigth * width>::operator*=(val);
	return *this;
}

template <u_short heigth, u_short width> template <u_short other_width>
Matrix<heigth, other_width> Matrix<heigth, width>::operator*(const Matrix<width, other_width>& other) const
{
	Matrix<heigth, other_width> result;
	Multiply(other, result);
	return result;
}

template <u_short heigth, u_short width> template <u_short other_width>
void Matrix<heigth, width>::Multiply(const Matrix<width, other_width>& other, Matrix<heigth, other_width>& result) const
{
	std::array<Vector<width>, other_width> other_columns;
	std::array<Vector<width>, heigth> this_rows;
	for(u_short row = 0; row < heigth; ++row)
		for(u_short col = 0; col < width; ++col)
			this_rows[row](col) = this->operator()(row, col);

	for(u_short col = 0; col < other_width; ++col)
		for(u_short row = 0; row < width; ++row)
			other_columns[col](row) = other(row, col);

	for(u_short row = 0; row < heigth; ++row)
		for(u_short col = 0; col < other_width; ++col)
			result(row, col) = this_rows[row] * other_columns[col];
}

template <u_short heigth, u_short width>
const MatShape& Matrix<heigth, width>::Shape() const
{
	return Matrix<heigth, width>::shape;
}

template <u_short size>
Matrix <size, size> Eye(float val)
{
	Matrix <size, size> result{};
	for(u_short i = 0; i < size; ++i)
		result(i, i) = val;
	return result;
}

} //namespace Mat
#endif /* UTIL_INC_MATRIX_HPP_ */

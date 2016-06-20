#pragma once
/*!
\brief  Matrix class
\author Danila Balyakin https://github.com/Pacman29/OOP_3/tree/master/matrix
\author modified (cut) by Dmitry Zaytsev
\version 2.0
\date 19 June 2016

Set base interface for camera
*/

#include "array.h"
#include "vector.h"

class BaseMatrix
{
public:
	virtual const size_t& rowcount() = 0;
	virtual const size_t& columncount() = 0;

	virtual const size_t& rowcount() const = 0;
	virtual const size_t& columncount() const = 0;
protected:
	size_t _rowcount;
	size_t _columncount;
};

template <typename type_t>
class Matrix : public BaseMatrix
{
public:
	Matrix();
	Matrix(Matrix<type_t>&);
	Matrix(Matrix<type_t>&&);
	Matrix(size_t, size_t);
	virtual const size_t& rowcount() override { return _rowcount; }
	virtual const size_t& columncount() override { return _columncount; }

	void addColumn(Array<type_t>&);
	void addRow(Array<type_t>&);

	void setRow(size_t, Array<type_t>);
	void setColumn(size_t, Array<type_t>);

	virtual const size_t& rowcount() const override { return _rowcount; }
	virtual const size_t& columncount() const override { return _columncount; }

	Matrix<type_t>& operator=  (Matrix<type_t>&);
	Matrix<type_t>& operator=  (Matrix<type_t>&&);

	Array<type_t>& operator[] (const size_t index);

	~Matrix();

	//Matrix<type_t> transposition();
	Array<type_t>& getRow(size_t index);
	Array<type_t>& getColumn(size_t index);

	const Array<type_t>& getRow(size_t index) const;
	const Array<type_t>& getColumn(size_t index) const;


	/*Matrix<type_t>  operator+  ();
	Matrix<type_t>  operator+  (const Matrix<type_t>& other);
	Matrix<type_t>  operator+  (const type_t& value);
	Matrix<type_t>& operator+= (const type_t& value);
	Matrix<type_t>& operator+= (const Matrix<type_t>& other);
	Matrix<type_t>  operator-  ();
	Matrix<type_t>  operator-  (const Matrix<type_t>& other);
	Matrix<type_t>  operator-  (const type_t& value);
	Matrix<type_t>& operator-= (const type_t& value);
	Matrix<type_t>& operator-= (const Matrix<type_t>& other);

	Matrix<type_t>  operator*  (const Matrix<type_t>& other);
	Matrix<type_t>  operator*  (const type_t& value);

	Matrix<type_t>& operator*= (const type_t& value);
	Matrix<type_t>& operator*= (const Matrix<type_t>& other);
	Matrix<type_t>  operator/  (const type_t& value);
	Matrix<type_t>& operator/= (const type_t& value);

	bool            operator== (const Matrix<type_t>& other);
	bool            operator!= (const Matrix<type_t>& other);
	*/
private:
	Array<Array<type_t>> M;
	//bool check_size(const Matrix<type_t>& other);
};

/*
template <typename type_tn>
Matrix<type_tn> operator*(const type_tn &value, const Matrix<type_tn> &other)
{
	Matrix<type_tn> res(other);
	for (size_t i = 0; i<res.row_count(); ++i)
		for (size_t j = 0; j<res.column_count(); ++j)
			res[i][j] *= value;
	return res;
}
*/

template <typename type_tn>
Array<type_tn> operator*(Vector vec, Matrix<type_tn> other)
{
	Array<type_tn> res;
	IArray<type_tn> ires(res);
	double t = 0;
	for (size_t i = 0; i < other.columncount(); ++i)
	{
		res.addItem(t);
		for (size_t j = 0; j < other.rowcount(); ++j)
		{
			IArray<double> irow(other[j]);
			ires[i].updatedir(ires[i].value() + irow[i].value() * vec[j]);
		}
	}
	return res;
}

#include "Matrix.tpl.h"
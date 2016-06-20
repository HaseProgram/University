template<typename type_t>
Matrix<type_t>::Matrix()
{
	Matrix<type_t>(1, 1);
}

template<typename type_t>
Matrix<type_t>::Matrix(Matrix<type_t>& other)
{
	this->M.clear();
	for (unsigned int i = 0; i < other.rowcount(); i++)
	{
		this->M.addItem(other.getRow(i));
	}
	this->_columncount = other.columncount();
	this->_rowcount = other.rowcount();
}

template<typename type_t>
Matrix<type_t>::Matrix(Matrix<type_t>&& other)
{
	this->M.clear();
	for (unsigned int i = 0; i < other.rowcount(); i++)
	{
		this->M.addItem(other.getRow(i));
	}
	this->_columncount = other.columncount();
	this->_rowcount = other.rowcount();
}

template<typename type_t>
Matrix<type_t>::Matrix(size_t rowcount, size_t columncount)
{
	this->M.clear();
	double null = 0;
	for (unsigned int i = 0; i < rowcount; i++)
	{
		Array<type_t> temp;
		for (unsigned int j = 0; j < columncount; j++)
		{
			temp.addItem(null);
		}
		this->M.addItem(temp);
	}
	this->_columncount = columncount;
	this->_rowcount = rowcount;
}

template<typename type_t>
void Matrix<type_t>::addColumn(Array<type_t> & arr)
{
	IArray<type_t> iarr(arr);
	IArray<Array<type_t>> iM(this->M);
	for (unsigned int i = 0; i < this->rowcount(); i++)
	{
		iM[i].addItem(iarr[i]);
	}
	this->_columncount++;
}

template<typename type_t>
void Matrix<type_t>::addRow(Array<type_t> & arr)
{
	this->M.addItem(arr);
	this->_rowcount++;
}

template<typename type_t>
void Matrix<type_t>::setColumn(size_t index, Array<type_t> arr)
{
	IArray<type_t> iarr(arr);
	IArray<Array<type_t>> iM(this->M);
	for (unsigned int i = 0; i < this->rowcount(); i++)
	{
		IArray<type_t> irow(iM[i].value());
		irow[index].update(iarr[i].value());
	}
}

template<typename type_t>
void Matrix<type_t>::setRow(size_t index, Array<type_t> arr)
{
	IArray<Array<type_t>> iM(this->M);
	iM[index].update(arr);
}

template <typename type_t>
Matrix<type_t>& Matrix<type_t>::operator=(Matrix<type_t>& other)
{
	this->M.clear();
	for (unsigned int i = 0; i < other.rowcount(); i++)
	{
		this->M.addItem(other.getRow(i));
	}
	this->_columncount = other.columncount();
	this->_rowcount = other.rowcount();
	return *this;
}

template <typename type_t>
Matrix<type_t>& Matrix<type_t>::operator=(Matrix<type_t>&& other)
{
	this->M.clear();
	for (unsigned int i = 0; i < other.rowcount(); i++)
	{
		this->M.addItem(other.getRow(i));
	}
	this->_columncount = other.columncount();
	this->_rowcount = other.rowcount();
	return *this;
}

template <typename type_t>
Array<type_t>& Matrix<type_t>::operator[](const size_t index)
{
	return this->getRow(index);
}

template<typename type_t>
Matrix<type_t>::~Matrix()
{
	this->M.clear();
}

template <typename type_t>
Array<type_t>& Matrix<type_t>::getRow(size_t index)
{
	IArray<Array<type_t>> iM(this->M);
	return iM[index].value();
}

template <typename type_t>
Array<type_t>& Matrix<type_t>::getColumn(size_t index)
{
	IArray<Array<type_t>> iM(this->M);
	Array<type_t> column;
	while (iM.check())
	{
		IArray<Array<type_t>> irow(iM.value());
		column.addItem()
	}
	return column;
}

template <typename type_t>
const Array<type_t>& Matrix<type_t>::getRow(size_t index) const
{
	IArray<Array<type_t>> iM(this->M);
	Array<type_t> row = iM[index];
	return row;
}

template <typename type_t>
const Array<type_t>& Matrix<type_t>::getColumn(size_t index) const
{
	IArray<Array<type_t>> iM(this->M);
	Array<type_t> column;
	while (iM.check())
	{
		IArray<Array<type_t>> irow(iM.value());
		column.addItem()
	}
	return column;
}


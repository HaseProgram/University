#include "stdafx.h"
#include "cameramatrixmodification.h"

matrixrotationOX::matrixrotationOX(double angle) :
	Matrix<double>(4, 4)
{
	double cos_alpha = cos(angle);
	double sin_alpha = sin(angle);

	{
		IArray<double> irow((*this)[0]);
		irow[0].updatedir(1);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[1]);
		irow[0].updatedir(0);
		irow[1].updatedir(cos_alpha);
		irow[2].updatedir(sin_alpha);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[2]);
		irow[0].updatedir(0);
		irow[1].updatedir(-sin_alpha);
		irow[2].updatedir(cos_alpha);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[3]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(1);
	}
}

matrixrotationOY::matrixrotationOY(double angle) :
	Matrix<double>(4, 4)
{
	double cos_alpha = cos(angle);
	double sin_alpha = sin(angle);

	{
		IArray<double> irow((*this)[0]);
		irow[0].updatedir(cos_alpha);
		irow[1].updatedir(0);
		irow[2].updatedir(sin_alpha);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[1]);
		irow[0].updatedir(0);
		irow[1].updatedir(1);
		irow[2].updatedir(0);
		irow[3].updatedir(0);
	}
	
	{
		IArray<double> irow((*this)[2]);
		irow[0].updatedir(sin_alpha);
		irow[1].updatedir(0);
		irow[2].updatedir(cos_alpha);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[3]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(1);
	}
}

matrixrotationOZ::matrixrotationOZ(double angle) :
	Matrix<double>(4, 4)
{
	double cos_alpha = cos(angle);
	double sin_alpha = sin(angle);

	{
		IArray<double> irow((*this)[0]);
		irow[0].updatedir(cos_alpha);
		irow[1].updatedir(sin_alpha);
		irow[2].updatedir(0);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[1]);
		irow[0].updatedir(-sin_alpha);
		irow[1].updatedir(cos_alpha);
		irow[2].updatedir(0);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[2]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(1);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[3]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(1);
	}
}

matrixrotation::matrixrotation(double x, double y, double z, double angle) :
	Matrix<double>(4, 4)
{
	double cos_alpha = cos(angle);
	double sin_alpha = sin(angle);

	{
		IArray<double> irow((*this)[0]);
		irow[0].updatedir(cos_alpha + (1 - cos_alpha)*x*x);
		irow[1].updatedir((1 - cos_alpha)*y*x + sin_alpha*z);
		irow[2].updatedir((1 - cos_alpha)*z*x - sin_alpha*y);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[1]);
		irow[0].updatedir((1 - cos_alpha)*x*y - sin_alpha*z);
		irow[1].updatedir(cos_alpha + (1 - cos_alpha)*y*y);
		irow[2].updatedir((1 - cos_alpha)*z*y + sin_alpha*x);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[2]);
		irow[0].updatedir((1 - cos_alpha)*x*z + sin_alpha*y);
		irow[1].updatedir((1 - cos_alpha)*y*z - sin_alpha*x);
		irow[2].updatedir(cos_alpha + (1 - cos_alpha)*z*z);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[3]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(1);
	}
}

matrixmove::matrixmove(double x, double y, double z) :
	Matrix<double>(4, 4)
{
	{
		IArray<double> irow((*this)[0]);
		irow[0].updatedir(1);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(x);
	}

	{
		IArray<double> irow((*this)[1]);
		irow[0].updatedir(0);
		irow[1].updatedir(1);
		irow[2].updatedir(0);
		irow[3].updatedir(y);
	}

	{
		IArray<double> irow((*this)[2]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(1);
		irow[3].updatedir(z);
	}

	{
		IArray<double> irow((*this)[3]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(1);
	}
}


matrixscale::matrixscale(double s) :
	Matrix<double>(4, 4)
{
	{
		IArray<double> irow((*this)[0]);
		irow[0].updatedir(s);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[1]);
		irow[0].updatedir(0);
		irow[1].updatedir(s);
		irow[2].updatedir(0);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[2]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(s);
		irow[3].updatedir(0);
	}

	{
		IArray<double> irow((*this)[3]);
		irow[0].updatedir(0);
		irow[1].updatedir(0);
		irow[2].updatedir(0);
		irow[3].updatedir(1);
	}
}
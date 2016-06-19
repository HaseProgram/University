#include "matrix.h"
#include "point.h"
#include <cmath>
namespace transform_matrix {

	class matrixrotationOX : public Matrix<double>
	{
	public:
		matrixrotationOX(double angle);
	};

	class matrixrotationOY : public Matrix<double>
	{
	public:
		matrixrotationOY(double angle);
	};

	class matrixrotationOZ : public Matrix<double>
	{
	public:
		matrixrotationOZ(double angle);
	};

	class matrixrotation : public Matrix<double>
	{
	public:
		matrixrotation(double x, double y, double z, double angle);
	};

	class matrixmove : public Matrix<double>
	{
	public:
		matrixmove(double x, double y, double z);
	};

	class matrixmoveOX : public matrixmove
	{
	public:
		matrixmoveOX(double x) : matrixmove(x, 0, 0) {}
	};

	class matrixmoveOY : public matrixmove
	{
	public:
		matrixmoveOY(double y) : matrixmove(0, y, 0) {}
	};

	class matrixmoveOZ : public matrixmove
	{
	public:
		matrixmoveOZ(double z) : matrixmove(0, 0, z) {}
	};

	class matrixscale : public Matrix<double>
	{
	public:
		matrixscale(double s);
	};
}
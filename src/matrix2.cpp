#include "matrix2.h"

#include <cmath>
#include <cfloat>

namespace abyss
{
	namespace math
	{
		void Matrix2::Transpose(const float* srcMatrix, float* destinationMatrix, int srcRows, int srcColumns)
		{
			for (int i = 0; i < srcRows * srcColumns; i++)
			{
				int row = i / srcRows;
				int column = i % srcRows;

				destinationMatrix[i] = srcMatrix[srcColumns * column + row];
			}
		}

		Matrix2 Matrix2::Transpose(const Matrix2& matrix)
		{
			Matrix2 result;
			Transpose(matrix.asArray, result.asArray, 2, 2);
			return result;
		}

		bool Matrix2::Multiply(float* out, const float* matrixA, int aRows, int aColumns, const float* matrixB, int bRows, int bColumns)
		{
			if(aColumns != bRows)
			{
				return false;
			}

			for(int i = 0; i < aRows; ++i)
			{
				for(int j = 0; j < bColumns; ++j)
				{
					out[bColumns * i + j] = 0.0f;
					for(int k = 0; k < bRows; ++k)
					{
						int a = aColumns * i + k;
						int b = bColumns * k + j;
						out[bColumns * i + j] += matrixA[a] * matrixB[b];
					}
				}
			}

			return true;
		}
	}
}
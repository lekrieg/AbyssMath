#ifndef MATRIX_2_H
#define MATRIX_2_H

#include "vector2.h"

namespace abyss
{
	namespace math
	{
		class Matrix2
		{
			public:
				union
				{
					struct
					{
						float _11, _12, _21, _22;
					};
					float asArray[4];
				};

				Matrix2() : _11(0.0f), _12(0.0f), _21(0.0f), _22(0.0f) { }
				Matrix2(float _11, float _12, float _21, float _22) : _11(_11), _12(_12), _21(_21), _22(_22) { }

				inline float* operator[] (int i)
				{
					return &(asArray[i * 2]);
				}

				void Transpose(const float* srcMatrix, float* destinationMatrix, int srcRows, int srcColumns);
				Matrix2 Transpose(const Matrix2& matrix);

				// TODO: refactor this whole thing
				static bool Multiply(float* out, const float* matrixA, int aRows, int aColumns, const float* matrixB, int bRows, int bColumns);
				
				friend Matrix2 operator* (const Matrix2& matrixA, const Matrix2& matrixB)
				{
					Matrix2 result;
					Multiply(result.asArray, matrixA.asArray, 2, 2, matrixB.asArray, 2, 2);

					return result;
				}

				friend Matrix2 operator* (const Matrix2& matrix, float scalar)
				{
					Matrix2 result;
					for(int i = 0; i < 4; i++)
					{
						result.asArray[i] = matrix.asArray[i] * scalar;
					}

					return result;
				}
		};
	}
}
#endif
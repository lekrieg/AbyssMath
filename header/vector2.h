#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <iostream>
#include <cmath>
#include <cfloat>

namespace abyss
{
	namespace math
	{
		#define RAD2DEG(x) ((x) * 57.295754f)
		#define DEG2RAD(x) ((x) * 0.0174533f)
		#define CMP(x, y)(fabsf((x) - (y)) <= FLT_EPSILON * fmaxf(1.0f, fmaxf(fabsf(x), fabsf(y))))

		// TODO: colocar a implementação aqui direto e dar inline nas funcoes
		// não da pra dar inline nos assemblys das funções dentro .o
		// lembrar de adicionar o .o das coisas da lib na engine
		class Vector2
		{
			public:
			union
			{
				struct
				{
					float x;
					float y;
				};
				float asArray[2];
			};

			Vector2() : x(0.0f), y(0.0f) { }
			Vector2(float x, float y) : x(x), y(y) { }

			float Dot(const Vector2& vec) const;
			float Magnitude() const;
			float MagnitudeSquare() const;

			void Normalize();
			Vector2 Normalized() const;

			float Distance(const Vector2& vec) const;
			void Scale(float scale);

			float Angle(const Vector2& vec) const;

			float& operator[](int i)
			{
				return asArray[i];
			}

			friend bool operator== (const Vector2& lhs, const Vector2& rhs)
			{
				return CMP(lhs.x, rhs.y) && CMP(lhs.y, rhs.y);
			}

			friend bool operator!= (const Vector2& lhs, const Vector2& rhs)
			{
				return !(lhs == rhs);
			}

			friend Vector2 operator+ (const Vector2& lhs, const Vector2& rhs)
			{
				return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
			}

			friend Vector2 operator- (const Vector2& lhs, const Vector2& rhs)
			{
				return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
			}

			friend Vector2 operator* (const Vector2& lhs, const Vector2& rhs)
			{
				return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
			}

			friend Vector2 operator* (const Vector2& lhs, const float value)
			{
				return Vector2(lhs.x * value, lhs.y * value);
			}

			friend Vector2 operator+= (const Vector2& lhs, const Vector2& rhs)
			{
				return lhs + rhs;
			}

			friend Vector2 operator-= (const Vector2& lhs, const Vector2& rhs)
			{
				return lhs - rhs;
			}

			friend Vector2 operator*= (const Vector2& lhs, const Vector2& rhs)
			{
				return lhs * rhs;
			}

			friend Vector2 operator*= (const Vector2& lhs, const float value)
			{
				return Vector2(lhs.x * value, lhs.y * value);
			}

			// override << and return a stream with the value
			friend std::ostream& operator << (std::ostream& stream, const Vector2& vector)
			{
				return stream << "{" << vector.x << " " << vector.y << "}" << '\n';
			}

			// usar sstream para concatenar strings e outros valores de forma eficiente
			// procurar sobre first operator sei la o nome, exemplo: 13 + v2
		};

		float dot(const Vector2& lhs, const Vector2& rhs);
		float magnitude(const Vector2& vec);
		float magnitudeSquare(const Vector2& vec);

		float distance(const Vector2& vecTarget, const Vector2& vecItem);

		Vector2 project(const Vector2& lenght, const Vector2& direction);
		Vector2 perpendicular(const Vector2& lenght, const Vector2& direction);

		Vector2 reflection(const Vector2& vec, const Vector2& normal);
	}
}

#endif
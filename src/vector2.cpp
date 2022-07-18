#include "vector2.h"

namespace abyss
{
	namespace math
	{
		float Vector2::Dot(const Vector2& vec) const
		{
			return x * vec.x + y * vec.y;
		}

		float Vector2::Magnitude() const
		{
			return sqrtf(Dot(*this));
		}

		float Vector2::MagnitudeSquare() const
		{
			return Dot(*this);
		}

		void Vector2::Normalize()
		{
			Vector2 temp = (*this) * (1.0f / Magnitude());
			x = temp.x;
			y = temp.y;
		}
		
		// TODO: Talvez implementar o overloading do =
		// TODO: Implementar Cross product no Vector3
		Vector2 Vector2::Normalized() const
		{
			return (*this) * (1.0f / Magnitude());
		}

		float Vector2::Distance(const Vector2& vec) const
		{
			return abyss::math::distance(vec, *this);
		}

		void Vector2::Scale(float scale)
		{
			x *= scale;
			y *= scale;
		}

		float Vector2::Angle(const Vector2& vec) const
		{
			float magnitude = sqrtf(MagnitudeSquare() * abyss::math::magnitudeSquare(vec));
			return acos(abyss::math::dot(*this, vec) / magnitude);
		}

		// -- outside class methods
		float dot(const Vector2& lhs, const Vector2& rhs)
		{
			return lhs.x * rhs.x + lhs.y * rhs.y;
		}

		float magnitude(const Vector2& vec)
		{
			return sqrtf(dot(vec, vec));
		}

		float magnitudeSquare(const Vector2& vec)
		{
			return dot(vec, vec);
		}

		float distance(const Vector2& target, const Vector2& actualItem)
		{
			Vector2 temp = target - actualItem;
			return magnitude(temp);
		}

		Vector2 project(const Vector2& lenght, const Vector2& direction)
		{
			float dotValue = dot(lenght, direction);
			float magnitudeSqr = magnitudeSquare(direction);

			return direction * (dotValue / magnitudeSqr);
		}

		Vector2 perpendicular(const Vector2& lenght, const Vector2& direction)
		{
			return lenght - project(lenght, direction);
		}

		Vector2 reflection(const Vector2& vec, const Vector2& normal)
		{
			float dotValue = dot(vec, normal);

			return vec - normal * (dotValue * 2.0f);
		}
	}
}
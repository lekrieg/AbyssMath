#ifndef VECTOR_3_H
#define VECTOR_3_H

namespace abyssS
{
	namespace math
	{
		class Vector3
		{
			public:
			union
			{
				struct
				{
					float x;
					float y;
					float z;
				};
				float asArray[3];
			};

			Vector3(float x, float y, float z) : x(x), y(y), z(z) { }

			float& operator[](int i)
			{
				return asArray[i];
			}
		};
	}
}

#endif
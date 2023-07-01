class CVector
{
public:
	float x, y, z;

	float Heading() { return atan2(-x, y); }
	float MagnitudeSqr() { return x * x + y * y + z * z; }
	float MagnitudeSqr2D() { return x * x + y * y; }
	float Magnitude() { return sqrt(MagnitudeSqr()); }
	float Magnitude2D() { return sqrt(MagnitudeSqr2D()); }
};

class CVector_pad : public CVector
{
public:
	unsigned int flags; // ???
};
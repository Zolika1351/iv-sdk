class CVector
{
public:
	float x, y, z;
};
// i wonder if anyone will one day find out what the fuck this value is for
class CVector_pad : public CVector
{
	unsigned int __pad;
};
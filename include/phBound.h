namespace rage
{
	class phBound
	{
	public:
		uint8_t pad[0x80];				// 00-80

		// +0x50 off vft is set mass for cars but seems to be userpurge, todo
	};
	VALIDATE_SIZE(phBound, 0x80);

	class phBoundComposite : public phBound
	{
	public:
		uint8_t pad[0x20];				// 80-A0
	};
	VALIDATE_SIZE(phBoundComposite, 0xA0);
};
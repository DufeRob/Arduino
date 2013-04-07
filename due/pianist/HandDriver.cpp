#include "HandDriver.h"

#define SERVODELAY 150

HandDriver::HandDriver()
{
	for (unsigned char i = 0; i < SERVOCOUNT; i++)
	{
		servos[i] = new Servo();
	}

}

void HandDriver::init(unsigned char noOfFirstPin)
{
	for (unsigned char i = 0; i < SERVOCOUNT; i++)
	{
		servos[i]->attach(noOfFirstPin + i);
		servos[i]->write(90);
	}
}

void HandDriver::demo()
{
	for (unsigned char i = 0; i < SERVOCOUNT; i++)
	{
		SetFinger(i, PosMiddle);
	}
	delay(SERVODELAY);

	for (unsigned char i = 0; i < SERVOCOUNT; i++)
	{
		SetFinger(i, PosUp);
		delay(SERVODELAY);
	}
	for (unsigned char i = 0; i < SERVOCOUNT; i++)
	{
		SetFinger(i, PosMiddle);
		delay(SERVODELAY);
	}

	for (unsigned char i = 0; i < SERVOCOUNT; i++)
	{
		SetFinger(i, PosDown);
		delay(SERVODELAY);
	}
	for (unsigned char i = 0; i < SERVOCOUNT; i++)
	{
		SetFinger(i, PosMiddle);
		delay(SERVODELAY);
	}
}

void HandDriver::SetFinger(unsigned char fingerNo, FingerPosition position)
{
	unsigned char degree = 90;
	
	switch(position)
	{
		case PosUp:
			degree = 20;
			break;
		case PosDown:
			degree = 160;
			break;
		default:
			degree = 90;
	}
	servos[fingerNo]->write(degree);
}
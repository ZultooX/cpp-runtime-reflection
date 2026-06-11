#pragma once


class Test
{
private:
	[[serializefield, replicatefield]]
	int health;

	[[serializefield, range(0, 10)]]
	float MovementSpeed;


	[[kukensmamma]] float* test = nullptr;

	[[method]]
	void test()
	{

	}


	[[dont_reflect]] float* othertest = nullptr;

};
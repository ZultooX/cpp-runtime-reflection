#pragma once

#define CLS
#define END_CLS


namespace Testing::TEstd
{
CLS
	class Test
	{
	private:
		[[serializefield, replicatefield]]
		int health;

		[[serializefield, range(0, 10)]]
		float MovementSpeed;


		[[kukensmamma]] float* test = nullptr;


		[[dont_reflect]] float* othertest = nullptr;

	};
END_CLS
}

template<typename T>
struct TypeInfo;

CLS
class SimonsMamma : Testing::TEstd::Test
{
	friend struct TypeInfo<SimonsMamma>;

private:
	[[serializefield, replicatefield]]
	int thisShouldWork;

	[[reflect]] 
	Testing::TEstd::Test test;
};
END_CLS
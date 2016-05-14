#include <cstdio>

#pragma once
template<typename T, typename S>
class pair
{
private:
	T val1;
	S val2;

public:	
	pair(T val1, S val2) : val1(val1) ,val2(val2) {}
	T readValue1() {return val1;}
	S readValue2() {return val2;}
	/** 
	 * Returns a pointer to the value so it can be modified
	 * @return pointer to the value;
	 */
	T* getValue1() {return &val1;}
	S* getValue2() {return &val2;}

	
	T setValue1(T v1)
		{
			val1 = v1;
		}
	S setValue2(S v2)
		{		
			val2 = v2;
		}
};

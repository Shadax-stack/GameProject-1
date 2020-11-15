#pragma once
#include <stdint.h>

namespace gp1 {

	template<uint32_t ID>
	class Item
	{
	public:
		virtual ~Item() = 0;
		// I used virtual functions since static variables are shared among all the subclasses as well.  Is there a better way to do this?
		// I also used a 32 bit integer for stack size just in case we ever need more than 2^16 items in one stack 
		virtual uint32_t GetStackSize() = 0;
		//Should I make ID public or use a get function for that instead?
		uint32_t GetID() {
			return ID;
		}
	};

}

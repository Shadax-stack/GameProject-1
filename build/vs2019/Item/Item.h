#pragma once
#include <stdint.h>

namespace gp1 {

	class Item
	{
	public:
		virtual ~Item() = delete;
	private:
		// I used virtual functions since static variables are shared among all the subclasses as well.  Is there a better way to do this?
		// I also used a 32 bit integer for stack size just in case we ever need more than 2^16 items in one stack 
		virtual uint32_t GetStackSize(void) = 0;
		// I do not think I need to implement this as virtual since it is less memory and faster to acess a value than call a function
		// Also I used a 16 bit integer instead of a 32 bit integer to save memory, it can always be changed to 32 bit if we are planning to support mods that add in a lot of items
		uint16_t ID;
	};

}

#pragma once
#include <stdint.h>

namespace gp1 {

	class Item
	{
	public:
		// Sets the ID to 0 by default. Do we need to do that?
		// It might be useful for making sure that the object is properly initialized or something like that
		Item();
		virtual ~Item() = 0;
		// I used virtual functions since static variables are shared among all the subclasses as well.  Is there a better way to do this?
		// I also used a 32 bit integer for stack size just in case we ever need more than 2^16 items in one stack 
		virtual uint32_t GetStackSize() = 0;
		//Should I make ID public or use a get function for that instead?
		uint16_t GetID();
	protected:
		// I do not think I need to implement this as virtual since it is less memory and faster to acess a value than call a function
		// Also I used a 16 bit integer instead of a 32 bit integer to save memory, it can always be changed to 32 bit if we are planning to support mods that add in a lot of items
		uint16_t ID;
	};

}

#pragma once
#include <stdint.h>
#include <string>

namespace gp1 {

	enum ItemType {
		//Add some types here
	};

	enum ItemTier {
		//Add some tiers here
	};

	template<uint32_t ID>
	class Item
	{
	public:
		ItemTier m_tier;
		Item(const std::string& name, ItemType type, ItemTier tier) : m_Name(name), m_Type(type), m_Tier(tier) {}
		virtual ~Item() = 0;
		// I used virtual functions since static variables are shared among all the subclasses as well.  Is there a better way to do this?
		// I also used a 32 bit integer for stack size just in case we ever need more than 2^16 items in one stack 
		virtual uint32_t GetStackSize() = 0;
		//Should I make ID public or use a get function for that instead?
		uint32_t GetID() {
			return ID;
		}

		void SetName(const std::string& newName) {
			m_Name = newName;
		}

		std::string GetName() {
			return m_Name;
		}
	private:
		// name is a member variable not a template because we may want to support item renaming functionality in the future, like how minecraft allows to to rename items using an anvil
		std::string m_Name;
		ItemType m_Type;
		ItemTier m_Tier;
	};

}

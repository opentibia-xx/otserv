//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __OTSERV_CONTAINER_H
#define __OTSERV_CONTAINER_H

#include "item.h"

class Container : public Item
{
	private:
		unsigned short maxitems; //number of max items in container  
		unsigned short actualitems; // number of items in container
		std::list<Item *> lcontained;

	public:
		typedef std::list<Item *>::const_iterator iterator;

		Container(const unsigned short _type);
		virtual ~Container();

		int size() const {return actualitems;};
		int capacity() const {return maxitems;};

		iterator getItems() const;     // begin();
		iterator getEnd() const;       // iterator beyond the last element
		bool addItem(Item* newitem);     // add an item to the container
		bool removeItem(Item* item); //remove an item from the container
		void moveItem(unsigned char from_slot, unsigned char to_slot);
		Item* getItem(unsigned long slot_num);
		unsigned char getSlotNumberByItem(Item* item) const;
		void isHolding(const Item* item, bool& found) const; //search all containers for the item recursively
		//Item& operator<<(Item*); // put items into the container
};

#endif //__OTSERV_CONTAINER_H


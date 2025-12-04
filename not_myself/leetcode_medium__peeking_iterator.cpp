/* 
    leetcode medium 284. Peeking Iterator
    i solved it one night after reading the proposed solution, but used Optional
*/
#include <optional>

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!peeked_value) {
            peeked_value = Iterator::next();
        }
        return peeked_value.value();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (peeked_value) {
            auto returned = peeked_value;
            peeked_value = nullopt;
            return returned.value();
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
	    if (peeked_value) {
            return true;
        }
        return Iterator::hasNext();
	}

private:
    optional<int> peeked_value;
};

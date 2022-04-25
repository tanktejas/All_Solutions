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
    int val;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        val=Iterator::next();
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	     int curr=val;
         if(Iterator::hasNext()){
            val=Iterator::next();
         }else{
             val=-1;
         }
        return curr;
	}
	
	bool hasNext() const {
	    return val!=-1;
	} 
};    
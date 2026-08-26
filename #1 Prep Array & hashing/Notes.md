# #1 Prep Array & Hashing
## std::vector time complexities
|Operation|Time Complexity|Notes
|:-:|:-:|:-:|
|v[i]|O(1)|Knowing the index you want is always best
|push_back()|O(1) amortized|This may trigger an allocation based on capacity vs. size
|pop_back()|O(1)|Pops the last element (top of stack)
|Searching|O(n)|
|insert() at the beginning|O(n)|Invloves repositioning the entire array
|erase() at the beginning|O(n)|Invlves repositioning the entire array
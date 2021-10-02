---
Problem: 'Binary Search'

Description: 'To search & check if particular element is present in the list or not using binary search.'

Explanation: 'Size of an array, Array, & key element is given by user & following algorithm will 
check if that element is present in arraylist or not & give it's index accordingly!
Ex. 
Size of an array: 5     (given by user)
A:  12, 34, 45, 57, 67  (given by user)
Key: 45                 (given by user)

// recursive binary search algo/logic
RBinSearch(A, l, h, key) = {
        // get mid index of list
        mid = (l + h) / 2;

        // low(l) shouldn't get greater than/equals to high(h), if becomes then STOP!
        while(l <= h)
            // if key found at middle of list, return it's index.
            A[mid] == key

            // if key is less than mid, search in 1st half of divided list
            RBinSearch(A, l, mid - 1, key);

            // if key is greater/equals than mid, search in 2nd half of divided list
            RBinSearch(A, mid + 1, h, key);

        // else returns -1 as element not found in the list at last!
        return -1;
}
O/P of given info & code -
The element is found at index: 2
'
Language: 'C++' 
---  
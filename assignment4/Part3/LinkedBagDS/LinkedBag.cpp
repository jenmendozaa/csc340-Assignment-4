//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <type_traits>

//   SORTING ----------------------------------------------------
template<class ItemType>
void LinkedBag<ItemType>::sort(int method){
	if (itemCount <= 1)
		return;
	
	if (method == 0){
		// update function call if you change the prototype. 
		mergeSort();
	}else{
		// for EC, update function call if you change the prototype.
		// If you do implement quickSort, not action needed here
		quickSort(); 
	}
}

//TO DO: implement merge sort and change its prototype if you need to.
template<class ItemType>
void LinkedBag<ItemType>::mergeSort(){
	headPtr = mergeSortHelper(headPtr);

}

// Recursive helper function for merge sort
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::mergeSortHelper(Node<ItemType>* head) {
	if (!head || !head->getNext()) {
		return head; // Base case: empty or single-node list
	}

	// Split list into two halves
	Node<ItemType>* middle = findMiddle(head);
	Node<ItemType>* rightHalf = middle->getNext();
	middle->setNext(nullptr);

	// Recursively sort each half
	Node<ItemType>* leftSorted = mergeSortHelper(head);
	Node<ItemType>* rightSorted = mergeSortHelper(rightHalf);

	// Merge the two sorted halves
	return merge(leftSorted, rightSorted);
}

// Helper function to merge two sorted linked lists
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::merge(Node<ItemType>* left, Node<ItemType>* right) {
	Node<ItemType> dummy; // Dummy node to simplify the merging process
	Node<ItemType>* current = &dummy;

	// Merge nodes in sorted order
	while (left && right) {
		if (left->getItem() <= right->getItem()) {
			current->setNext(left);
			left = left->getNext();
		} else {
			current->setNext(right);
			right = right->getNext();
		}
		current = current->getNext();
	}

	// Attach any remaining nodes
	current->setNext(left ? left : right);

	return dummy.getNext();
}

// Helper function to find the middle of the linked list
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::findMiddle(Node<ItemType>* head) {
	if (!head) return head;

	Node<ItemType>* slow = head;
	Node<ItemType>* fast = head->getNext();

	// Move 'slow' one step and 'fast' two steps until 'fast' reaches the end
	while (fast && fast->getNext()) {
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	}

	return slow; // Return the middle node
}

//Extra Credit -- TO DO: implement quick sort and change its prototype 
//                       if you need to.
template<class ItemType>
void LinkedBag<ItemType>::quickSort(){
 headPtr = quickSortHelper(headPtr, getTail(headPtr));
}

// Recursive quick sort helper function
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::quickSortHelper(Node<ItemType>* head, Node<ItemType>* end) {
    if (!head || head == end) return head;  // Base case: empty or single element list

    Node<ItemType>* newHead = nullptr;
    Node<ItemType>* newEnd = nullptr;

    // Partition the list around a pivot
    Node<ItemType>* pivot = partition(head, end, &newHead, &newEnd);

    // If the pivot is not the first element, recursively sort the left part
    if (newHead != pivot) {
        Node<ItemType>* temp = newHead;

        // Recursively sort the list before the pivot
        while (temp->getNext() != pivot) {
            temp = temp->getNext();
        }
        temp->setNext(nullptr);

        newHead = quickSortHelper(newHead, temp);

        // Connect the sorted part to pivot
        temp = getTail(newHead);
        temp->setNext(pivot);
    }

    // Recursively sort the right part of the list
    pivot->setNext(quickSortHelper(pivot->getNext(), newEnd));

    return newHead;
}

// Partition function for quick sort
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::partition(Node<ItemType>* head, Node<ItemType>* end, Node<ItemType>** newHead, Node<ItemType>** newEnd) {
    Node<ItemType>* pivot = end;
    Node<ItemType>* prev = nullptr;
    Node<ItemType>* curr = head;
    Node<ItemType>* tail = pivot;

    while (curr != pivot) {
        if (curr->getItem() < pivot->getItem()) {
            if (*newHead == nullptr) {
                *newHead = curr;  // First node less than pivot
            }
            prev = curr;
            curr = curr->getNext();
        } else {
            // Move the node to the tail of the list
            if (prev) {
                prev->setNext(curr->getNext());
            }
            Node<ItemType>* temp = curr->getNext();
            curr->setNext(nullptr);
            tail->setNext(curr);
            tail = curr;
            curr = temp;
        }
    }

    // Set the new head and tail pointers
    if (*newHead == nullptr) {
        *newHead = pivot;
    }
    *newEnd = tail;

    return pivot;
}

// Utility function to get the tail of the list
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getTail(Node<ItemType>* head) {
    while (head != nullptr && head->getNext() != nullptr) {
        head = head->getNext();
    }
    return head;
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0){
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag){
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
	
	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original bag is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		
		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;		// Points to last node in new chain
		origChainPtr = origChainPtr->getNext();	  // Advance original-chain pointer
		
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
				  
			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			
			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			
			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while
		
		newChainPtr->setNext(nullptr);				  // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag(){
	clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)		  
	Node<ItemType>* nextNodePtr = new Node<ItemType>();

	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr);  // New node points to chain
	headPtr = nextNodePtr;			 // New node is now first node
	itemCount++;
	
	return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const{
	std::vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while
	
	return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry){
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem){
		// Copy data from first node to located node
		entryNodePtr->setItem(headPtr->getItem());
		
		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		
		itemCount--;
	} // end if
	
	return canRemoveItem;
}  // end remove

template<class ItemType>
bool LinkedBag<ItemType>::removeAlt(const ItemType& anEntry){
	Node<ItemType>* prev = headPtr;
	Node<ItemType>* cur = headPtr;
	bool found = false;

	while((cur != nullptr) && !found){
		found = (*(cur->getItem()) == *anEntry);
		if (!found){
			prev = cur;
			cur = cur->getNext();
		}
	}

	if (found){
		prev->setNext(cur->getNext());
		// delete cur->getItem();
		delete cur;
		cur = nullptr;
		itemCount--;
	}

	return found;

}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear(){
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr){
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);

		// delete nodeToDeletePtr->getItem(); 
		delete nodeToDeletePtr;
		
		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr
	
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if
		
		counter++;
		curPtr = curPtr->getNext();
	} // end while
	
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains


// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	
	while (!found && (curPtr != nullptr))
	{
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while
	
	return curPtr;
} // end getPointerTo



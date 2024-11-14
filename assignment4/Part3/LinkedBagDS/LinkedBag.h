//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.h 
	 Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>{
	private:
		Node<ItemType>* headPtr; // Pointer to first node
		int itemCount;			 // Current count of bag items
		
		// Returns either a pointer to the node containing a given entry
		// or the null pointer if the entry is not in the bag.
		Node<ItemType>* getPointerTo(const ItemType& target) const;
		
	public:
		LinkedBag();
		LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
		virtual ~LinkedBag(); // Destructor should be virtual
		
		//   SORTING ----------------------------------------------------
		void sort(int method=0);

		// TO DO: update prototype of merge sort based on your implementat
		void mergeSort();
		Node<ItemType>* mergeSortHelper(Node<ItemType>* head);
		Node<ItemType>* merge(Node<ItemType>* left, Node<ItemType>* right);
		Node<ItemType>* findMiddle(Node<ItemType>* head);

		// EC TO DO: update prototype of quick sort based on your implementation
		void quickSort();
		Node<ItemType>* quickSortHelper(Node<ItemType>* head, Node<ItemType>* end);
		Node<ItemType>* partition(Node<ItemType>* head, Node<ItemType>* end, Node<ItemType>** newHead, Node<ItemType>** newEnd);
		Node<ItemType>* getTail(Node<ItemType>* head);

		int getCurrentSize() const;
		bool isEmpty() const;
		bool add(const ItemType& newEntry);
		bool remove(const ItemType& anEntry);
		void clear();
		bool contains(const ItemType& anEntry) const;
		int getFrequencyOf(const ItemType& anEntry) const;
		std::vector<ItemType> toVector() const;
		bool removeAlt(const ItemType& anEntry);
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif
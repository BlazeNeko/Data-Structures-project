/*
 * queue.h
 *
 *  Created on: 3/04/2016
 *      Author: DIS/EDI teachers
 */


#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
/**
* Generic class Queue
* It is composed by two pointers (head and tail) and a set of linked elements (Node)
*/
template <class TYPE>
class Queue {

private:
	/**
	* Class Node
	* Elements linked in the class Queue are Nodes.
	*/
	class Node {

	public:
		/** Data stored in a node */
		TYPE  elem;
		/** pointer to the next element (Node) in the queue */
		Node *next;

		Node (TYPE elem) {
			this->elem = elem;
			this->next = NULL;
		}
	};
	/** Pointer to the head element of the Queue */
	Node *head;
	/** Pointer to the tail element of the Queue */
	Node *tail;

public:
	/*
	 * Default constructor
	 * Pre ={}
	 * Post= {empty(queue) == True}
	 */
	Queue ();

    /* Is a queue empty?
     * Pre = {}
     * \return true if empty queue, false in all other cases
     * Complexity:   O(1)
     */
	bool empty () const;

    /* Get the head element in the queue.
     * Pre = {empty(queue) == False}
     * \param  Elem -> element in the head of the queue
     * Complexity:   O(1)
     */
	void front (TYPE &elem) const;

    /* Return the head element in the queue.
     * Pre = {empty(queue) == False}
     * \return  Elem -> element in the head of the queue
     * Complexity:   O(1)
     */
	TYPE front () const;

    /* Insert a new element in the queue
     * Pre = {}
     * Post = {} 
     * \param Elem -> element to insert
     * Complexity:   O(1)
     */
	void enqueue (const TYPE &elem);

    /* Delete the head elenent of the queue
     * Pre = {empty(queue) == False}
     * Post = {}
     * \Complexity: O(1)
     */
	void dequeue ();

	/**
	* Destructor
	* Complexity: O(1)
	*/
	~Queue ();
};



template <class TYPE>
Queue<TYPE>::Queue() {
	this->head = NULL;
	this->tail = NULL;

}

template <class TYPE>
bool Queue<TYPE>::empty () const {
    return (this->head == NULL);
}



template <class TYPE>
void Queue<TYPE>::front (TYPE &elem) const {
	elem = this->head->elem;
}


template <class TYPE>
TYPE Queue<TYPE>::front () const {
	return this->head->elem;
}


template <class TYPE>
void Queue<TYPE>::enqueue (const TYPE &elem) {
	Node *aux = new Node(elem);

	if(!empty()) {
		this->tail->next = aux;
	}else{
		this->head = aux;
	}
	this->tail = aux;
}


template <class TYPE>
void Queue<TYPE>::dequeue () {

    Node *aux;

    aux = this->head;
    this->head = this->head->next;

    delete aux;
}


template <class TYPE>
Queue<TYPE>::~Queue () {

    Node *aux;

    while (! empty()) {
    	aux = this->head;
    	this->head = this->head->next;
    	delete aux;
    }

    this->head = NULL;
    this->tail = NULL;
}

#endif /* QUEUE_H_ */

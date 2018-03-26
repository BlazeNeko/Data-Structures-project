/**
 * \file bstree.h
 * \brief Specification / Implementation of the Binary Search Tree
 * \author
 *   \b Autor: Profesores EDI \n
 *   \b Course: Data and Information Structures \n
 *   \b Course 15/16
 */

#ifndef _BSTREE_H
#define _BSTREE_H

// Old C++ compilers (v. < Std. 11)
#ifndef nullptr
#define nullptr NULL
#endif


#include <iostream>

using namespace std;

/**
 * \class BSTree
 * \brief Class Binary Search Tree implementation
 *
 */

template <class TYPE, class Compare>
class BSTree {

private:

	TYPE                  nData;
	BSTree<TYPE,Compare> *tLeft;
	BSTree<TYPE,Compare> *tRight;

	bool  isEmpty;

	BSTree<TYPE,Compare> *removeOrder (TYPE data);

public:

	BSTree  ();
	BSTree  (BSTree<TYPE,Compare> *tLeft,TYPE nData,BSTree<TYPE,Compare> *tRight);
	~BSTree ();

	BSTree  *left  ();
	BSTree  *right ();
	TYPE     root  ();

	bool  empty    ();
	void  insert   (const TYPE &data);
	void  remove   (      TYPE  data);
	bool  exist    (const TYPE &data);
};


/**
 * Default onstructor
 * \param ""
 * Complexity: O(1)
 */
template <class TYPE, class Compare>
BSTree<TYPE,Compare>::BSTree() {

	isEmpty = true;
	tLeft   = nullptr;
	tRight  = nullptr;
}


/**
 * Parametrized constructor: it creates a tree from a value and two left and right trees.
 * \param tLeft  left BSTree
 * \param data   Value of the root
 * \param tRight right BSTree
 * Complexity: O(1)
 */
template <class TYPE, class Compare>
BSTree<TYPE,Compare>::BSTree (BSTree<TYPE,Compare> *tLeft, TYPE data, BSTree<TYPE,Compare> *tRight) {

	isEmpty = false;
	this->nData  = data;
	this->tLeft  = tLeft;
	this->tRight = tRight;
}


/**
 * Return the left subtree of a node
 * \return Left subbstree
 * \pre: BSTree not nullptr
 * Complexity: O(1)
 */
template <class TYPE, class Compare>
BSTree<TYPE,Compare> *BSTree<TYPE,Compare>::left() {

	return this->tLeft;
}


/**
 * Return the right subtree of a node
 * \return Right subbstree
 * \pre: BSTree not nullptr
 * Complexity: O(1)
 */
template <class TYPE, class Compare>
BSTree<TYPE,Compare> *BSTree<TYPE,Compare>::right() {

	return this->tRight;
}


/**
 * Return the root of a BSTree
 * \return Root of the subtree
 * \pre: BSTree not nullptr
 * Complexity: O(1)
 */
template <class TYPE, class Compare>
TYPE BSTree<TYPE,Compare>::root() {

	return this->nData;
}


/**
 * Is it the BSTree empty? (empty is different of nullptr)
 * \return true if the tree is empty, false otherwise
 * Complexity: O(1)
 */
template <class TYPE, class Compare>
bool BSTree<TYPE,Compare>::empty() {

	return this->isEmpty;
}


/**
 * Insert a value in the BST
 * \param data: Value to insert
 * \return
 * \pre: exist(data) = false
 * \post: empty(BSTree) = false
 * Complexity: O(log(n))
 */
template <class TYPE, class Compare>
void BSTree<TYPE,Compare>::insert (const TYPE &data) {

	Compare c;

	if (empty()) {

		nData   = data;
		isEmpty = false;

	} else {

		if (c.operator() (data , nData) != 0){

			BSTree<TYPE, Compare> *aux;

			if (c.operator() (data , nData) < 0) {
				aux = left();
				if (aux == nullptr) {
					tLeft = aux = new BSTree<TYPE, Compare>();
				}
			} else {
				aux = right();
				if (aux == nullptr) {
					tRight = aux = new BSTree<TYPE, Compare>();
				}
			}
			aux->insert(data);

		}
	}
}


/**
 * Remove the node of the tree with the value
 * \param data: Value to remove
 * \return
 * \pre:  empty(BSTree) = false
 * Complexity: O(log(n))
 */
template <class TYPE, class Compare>
void BSTree <TYPE,Compare>::remove(TYPE data) {

	Compare  c;

	if (!empty()) {

		if (c.operator() (data, nData) < 0) {

			if (tLeft != nullptr)
				tLeft = tLeft->removeOrder(data);

		} else if (c.operator() (data, nData) > 0) {

			if (tRight != nullptr)
				tRight = tRight->removeOrder(data);

			// Encontrado el data a remove: nData
		} else {

			if ((tLeft == nullptr) && (tRight == nullptr)) {
				isEmpty = true;
			} else {
				removeOrder(data);
			}

		}

	}
}


/**
 * Auxiliar method to remove a node. It rebuilds the tree after removing.
 * Possibilities:
 * 	a) The node has not children (it is a leaf): it is removed.
 * 	b) The node has one child: the node is replaced by the child node.
 * 	c) The node has two children: the node is replaced by the higher value in its left subtree.
 * \param this->ndata: this->ndata to remove
 * \return BSTree resulting after removing
 * Complexity: O(log(n))
 */
template <class TYPE, class Compare>
BSTree<TYPE,Compare> *BSTree<TYPE,Compare>::removeOrder (TYPE data) {

	TYPE dataaux;
	BSTree *toreturn = this, *toremove, *candidate, *ancestor;
	Compare  c;

	if (!empty()) {

		if (c.operator() (data, nData)<0) {

			if (tLeft != nullptr)
				tLeft = tLeft->removeOrder(data);

		} else if (c.operator() (data, nData)>0) {
			if (tRight != nullptr)
				tRight = tRight->removeOrder(data);

		} else {

			toremove=this;

			// 1. It is a leaf
			if ((tRight == nullptr) && (tLeft == nullptr)) {

				delete toremove;
				toreturn = nullptr;

			} else {

				// 2. It has only one child
				// 2.1. Only the left child:
				if (tRight == nullptr) {

					toremove = tLeft;
					dataaux = nData;
					nData = tLeft->root();
					tLeft->nData = dataaux;
					tLeft = tLeft->left();
					tRight = toremove->right();

					toreturn = this;

					// 2.2. Only the right child:
				} else if (tLeft == nullptr) {

					toremove = tRight;
					dataaux = nData;
					nData = tRight->root();
					tRight->nData = dataaux;
					tRight = tRight->right();
					tLeft = toremove->left();

					toreturn = this;

					// 3. It has two children.
				} else {

					candidate = left();
					ancestor = this;
					while (candidate->right()) {
						ancestor = candidate;
						candidate = candidate->right();
					}

					// Exchange of candidate data
					dataaux = nData;
					nData = candidate->root();
					candidate->nData = dataaux;
					toremove = candidate;
					if (ancestor == this) {
						tLeft = candidate->left();
					} else {
						ancestor->tRight = candidate->left();
					}
				}

				// Remove the node (not the whole subtree)
				toremove->tLeft  = nullptr;
				toremove->tRight = nullptr;
				delete toremove;
			}
		}

	}

	return toreturn;
}


/**
 * Search for a this->ndata in the BSTree
 * \param data: this->ndata to search for
 * \return true: Data is in the BSTree, false: otherwise
 * \pre: BSTree not empty
 * Complexity: O(log(n))
 */
template <class TYPE, class Compare>
bool BSTree<TYPE,Compare>::exist (const TYPE &data) {

	bool enc = false;
	Compare  c;

	if (empty()) {

		enc  = false;

	} else {

		BSTree<TYPE, Compare> *aux;

		if (c.operator() (data, nData) < 0) {

			aux = left();
			if (aux != nullptr)
				enc = aux->exist(data);

		//} else if (*data > *nData) {
		} else if (c.operator() (data, nData) > 0) {

			aux = right();
			if (aux != nullptr)
				enc = aux->exist(data);

		} else {
			enc = true;
		}

	}

	return enc;
}


/**
 * Destructor. Destroys the nodes in the BSTree.
 * \param ""
 * \return
 * Complexity: O(n)
 */
template <class TYPE, class Compare>
BSTree<TYPE,Compare>::~BSTree() {

	BSTree<TYPE, Compare> *aux;

	if (!empty()) {

		aux = left();
		if (aux != nullptr)
			delete aux;

		aux = right();
		if (aux != nullptr)
			delete aux;

		isEmpty = true;
	}
}


#endif /* _BSTREE_H_ */



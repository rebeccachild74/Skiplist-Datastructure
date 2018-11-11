#pragma once
class Skiplist
{
private:
	class Node {
	public:
		Node * next;
		Node * above;
		Node * below;

		//suggested
		int key;
		Node ** forward;
		Node(int, int); // array to hold

		Node::Node(int key, int level)
		{
			this->key = key;

			// Allocate memory to forward 
			forward = new Node*[level + 1];

			// Fill forward array with 0(NULL)
			memset(forward, 0, sizeof(Node*)*(level + 1));
		}
	}; // end Node class

	int MAXLVL;

	// P is the fraction of the nodes with level 
	// i pointers also having level i+1 pointers
	float P;

	// current level of skip list
	int level;

	// pointer to header node
	Node *header;

public:
	Skiplist();
	~Skiplist();
	SkipList(int, float);
	int randomLevel();
	Node* createNode(int, int);
	void insertElement(int);
	void displayList();
};


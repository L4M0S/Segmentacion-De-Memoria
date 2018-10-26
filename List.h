#ifndef __list
#define __list
#include "Node.cpp"
class List
{
	private:
		Node *initial;
		Node *temporal;
		int _id;
		int _memory;
		int _uam;
		int _blocks;
		bool _isFree;
		
		Node* search(int);
		int search(Node*);
		Node* idSearch(int);
		void add(Node*, Node*);
		void add(Node*);
		void busy(Node*, Node*);
		void join(Node*, Node*);
		void remove(int);
	
	public:
		List(int, int);
		~List();
		void first_fit(int);
		void next_fit(int);
		void best_fit(int);
		void wors_fit(int);
		void free(int);
		void print_all();
};
#endif
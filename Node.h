#ifndef __node
#define __node
class Node
{
	private:
		int _id;
		int _memory;
		int _blocks;
		int _freeMemory;
		bool _status;
		Node *_next;
	
	public:
		Node(int, int, bool);
		~Node();

		inline int id();
		inline void id(int);
		inline int memory();
		inline void memory(int);
		inline int blocks();
		inline void blocks(int);
		inline int freeMemory();
		inline void freeMemory(int);
		inline bool status();
		inline void status(bool);
		inline Node* next();
		inline void next(Node*);
};
#endif
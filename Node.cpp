#include <cstdlib>
#include "Node.h"

Node::Node(int id, int memory, bool status=true)
{
	this->_id = id;
	this->_memory = memory;
	this->_blocks = 0;
	this->_freeMemory = 0;
	this->_status = status;
	this->_next  = NULL;
}

Node::~Node()
{
	delete this->_next;
}

inline int Node::id()
{
	return this->_id;
}

inline void Node::id(int id)
{
	this->_id = id;
}

inline int Node::memory()
{
	return this->_memory;
}

inline void Node::memory(int memory)
{
	this->_memory = memory;
}

inline int Node::blocks()
{
	return this->_blocks;
}

inline void Node::blocks(int blocks)
{
	this->_blocks = blocks;
}

inline int Node::freeMemory()
{
	return this->_freeMemory;
}

inline void Node::freeMemory(int freeMemory)
{
	this->_freeMemory = freeMemory;
}

inline bool Node::status()
{
	return this->_status;
}

inline void Node::status(bool status)
{
	this->_status = status;
}

inline Node* Node::next()
{
	return this->_next;
}

inline void Node::next(Node *next)
{
	this->_next = next;
}
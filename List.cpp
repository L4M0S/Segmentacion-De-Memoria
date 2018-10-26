#include <cstdlib>
#include<cstdio>
#include<iostream>

using namespace std;

#include "List.h"

List::List(int memory, int uam)
{
	this->initial = NULL;
	this->temporal = NULL;
	this->_id = 0;
	this->_uam = uam;
	this->_blocks = memory / this->_uam;
	this->_memory = this->_blocks * this->_uam;
	this->_isFree = false;
}

List::~List()
{
	if(this->initial == this->temporal) this->temporal = NULL;
	if(this->initial != NULL) delete this->initial;
	if(this->temporal != NULL)  delete this->temporal;
}

Node* List::search(int pos)
{
	Node *aux = this->initial;
	for (int i = 0; i < pos; ++i)
		aux = aux->next();
	return aux;
}

int List::search(Node *node)
{
	Node *aux = this->initial;
	int i = 0;
	while(aux)
	{
		if(aux == node) return i;
		aux = aux->next();
		i++;
	}
	return -1;
}

Node* List::idSearch(int id)
{
	Node *aux = this->initial;
	int i = 0;
	while(aux)
	{
		if(aux->id() == id) return aux;
		aux = aux->next();
		i++;
	}
	return NULL;
}

void List::busy(Node *current, Node *new_node)
{
	int total = new_node->memory();
	
	while(total % this->_uam != 0) ++total;
	
	new_node->freeMemory(total - new_node->memory());
	new_node->memory(total);
	new_node->blocks(total/this->_uam);

	this->_memory -= new_node->memory();
	this->_blocks -= new_node->blocks();

	current->blocks(current->blocks() - new_node->blocks());
	current->memory(current->blocks() * this->_uam);
	current->freeMemory(current->memory());

}

void List::add(Node *new_node)
{
	this->initial = new_node;
	this->temporal = this->initial;
	
	Node *free = new Node(-1, this->_memory, false);
	free->blocks(this->_blocks);
	
	busy(free, new_node);
	
	this->initial->next(free);
	
	if(this->initial->next()->memory() == 0) 
	{
		remove(1);
		this->_isFree = false;
	}
}

void List::add(Node *current, Node *new_node)
{
	if(current == this->initial and  this->initial->status() == false)
	{
		new_node->next(this->initial);
		busy(this->initial, new_node);
		this->initial = new_node;
		if(this->initial->next()->memory() == 0) remove(1);
	}

	else
	{
		busy(current->next(), new_node);
		new_node->next(current->next());
		current->next(new_node);
		if(new_node->next()->memory() == 0) remove(search(new_node->next()));
	}
}

void List::first_fit(int memory)
{
	Node *new_node = new Node(this->_id++, memory);

	if(this->initial == NULL) add(new_node);
	else
	{
		Node *aux = this->initial;
		while(aux)
		{
			if(this->initial->status() == false and this->initial->memory() >= new_node->memory())
			{
				add(this->initial, new_node);
				return;
			}

			if(aux->next() != NULL and aux->next()->status() == false and aux->next()->memory() >= memory)
			{
				add(aux, new_node);
				return;
			}
			aux = aux->next();
		}
	}
}


void List::next_fit(int memory)
{
	Node *new_node = new Node(this->_id++, memory);

	if(this->initial == NULL) add(new_node);

	else
	{
		Node *aux = this->temporal;
		while(aux)
		{
			if(aux->next() != NULL and aux->next()->status() == false and aux->next()->memory() >= memory)
			{
				add(aux, new_node);
				aux = aux->next();
				break;
			}

			else if(aux == this->initial and this->initial->status() == false and this->initial->memory() >= memory)
			{
				add(this->initial, new_node);
				if(this->_isFree) 
				{
					aux = this->initial->next();
					this->_isFree = false;
				}
				
				else aux = this->initial;
				
				break;
			}

			aux = aux->next();
			if(aux == NULL) aux = this->initial;
		}

		this->temporal = aux;
		if(this->_memory == 0) this->temporal = this->initial;
	}
}

void List::best_fit(int memory)
{
	Node *new_node = new Node(this->_id++, memory);

	if(this->initial == NULL) add(new_node);

	else
	{
		this->temporal = NULL;
		if(this->initial->status() == false and this->initial->memory() == memory)
		{
			add(this->initial, new_node);
			return;
		}

		if(this->initial->status() == false and this->initial->memory() > memory) this->temporal = this->initial;

		Node *aux = this->initial;
		while(aux->next())
		{
			if(aux->next()->status() == false and aux->next()->memory() == memory) 
			{
				add(aux, new_node);
				return;
			}

			if(aux->next()->status() == false and aux->next()->memory() > memory)
			{
				if(this->temporal == NULL) this->temporal = aux;
				else if(aux->next()->memory() < this->temporal->memory()) this->temporal = aux;
			}
			aux = aux->next();
		}
		add(this->temporal , new_node);
	}
}

void List::wors_fit(int memory)
{
	Node *new_node = new Node(this->_id++, memory);

	if(this->initial == NULL) add(new_node);

	else
	{
		this->temporal = NULL;

		if (this->initial->status() == false and this->initial->memory() >= memory) this->temporal = this->initial;
		
		Node *aux = this->initial;
		
		while(aux->next())
		{
			if(aux->next()->status() == false and aux->next()->memory() >= memory)
			{
				if(this->temporal == NULL) this->temporal = aux;
				else if(aux->next()->memory() > this->temporal->memory()) this->temporal = aux;
			}
			aux = aux->next();
		}
		add(this->temporal , new_node);
	}
}
/*
void List::wors_fit(int memory)
{
	int auxiliar;
	Node aux;
	Node temporal=0;
	aux=this->initial;
	
	Node *new_node = new Node(this->_id++, memory);

	if(this->initial == NULL) add(new_node);
	else
	{
		while(aux->next())
		{
			if(aux->memory()>= memory&&aux->status() == false&&aux->memory()> temporal)
			{
				auxiliar=aux->memory();
				temporal=aux;
			}
			aux=aux->next();
		}
		add(this->temporal , new_node);
	}
}
*/
void List::remove(int pos)
{
	Node *aux;
	if (pos == 0)
	{
		aux = this->initial;
		this->initial = this->initial->next();
		aux->next(NULL);
		delete aux;
	}

	else
	{
		Node *located = search(pos - 1);
		aux = located;
		located = located->next();
		aux->next(aux->next()->next());
		located->next(NULL);
		delete located;
	}
}

void List::free(int id)
{
	Node *aux = idSearch(id);
	aux->id(-1);
	aux->status(false);
	aux->freeMemory(aux->memory());
	this->_memory += aux->memory();
	this->_blocks += aux->blocks();
	this->_isFree = true;
	aux = this->initial;
	while(aux)
	{
		if(aux->next() != NULL && aux->status() == false && aux->next()->status() == false)
		{
			join(aux, aux->next());
			aux = this->initial;
		}

		else aux = aux->next();
	}
}

void List::join(Node *before, Node *after)
{
	before->id(-1);
	before->memory(before->memory()  + after->memory());
	before->blocks(before->blocks()  + after->blocks());
	before->freeMemory(before->memory());
	//
	before->next(after->next());
	//
	remove(search(after));	
}

void List::print_all()
{
	Node *aux = this->initial;
	int i = 0;
	printf("Memoria Libre: %iKB UAMs: %i\n", this->_memory, this->_blocks);
	
	if(aux)printf("Tipo\tId\tTamKB\tUAMs\tDesperdicioKB\n");
	
	while(aux)
	{
		printf("%s\t%i\t%i\t%i\t%i\n", aux->status() ? "P" : "H", aux->id(), aux->memory(), aux->blocks(), aux->freeMemory());
		aux = aux->next();	
	}
	puts("");
}

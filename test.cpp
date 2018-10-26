#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "List.cpp"
int main()
{
	srand((unsigned)time(NULL));
	List *l = new List(100, 10);
	
	//
	l->print_all();

	l->first_fit(20);
	l->print_all();

	
	l->first_fit(50);
	l->print_all();

	
	l->first_fit(25);
	l->print_all();

	l->free(1);
	l->print_all();

	l->first_fit(50);
	l->print_all();

	l->free(2);
	l->print_all();

	l->first_fit(10);
	l->print_all();

	l->free(0);
	l->print_all();


	l->first_fit(20);
	l->print_all();

	
	l->free(2);
	l->print_all();

	l->first_fit(10);
	l->print_all();

	l->first_fit(20);
	l->print_all();

	l->free(0);
	l->print_all();

	l->free(3);
	l->print_all();
	
	l->free(2);
	l->print_all();
	
	l->free(1);
	l->print_all();

	l->first_fit(50);
	l->print_all();


	l->first_fit(40);
	l->print_all();

	l->free(0);
	l->print_all();

	l->first_fit(40);
	l->print_all();

	l->first_fit(10);
	l->print_all();

	l->free(1);
	l->print_all();

	l->first_fit(10);
	l->print_all();

	l->first_fit(10);
	l->print_all();

	/**/

	/*
	l->next_fit(100);
	l->print_all();

	
	l->free(0);
	l->print_all();

	l->next_fit(25);
	l->print_all();


	l->next_fit(25);
	l->print_all();

	
	l->next_fit(25);
	l->print_all();

	
	l->next_fit(10);
	l->print_all();

	
	l->free(0);
	l->free(3);

	l->print_all();


	l->next_fit(25);
	l->print_all();

	
	l->free(2);
	l->print_all();

	/*
	l->next_fit(25);
	l->print_all();
	
	l->next_fit(25);
	l->print_all();

	
	l->free(2);
	l->print_all();

	l->next_fit(10);
	l->print_all();


	l->free(4);
	l->print_all();

	l->next_fit(40);
	l->print_all();

	l->free(0);
	l->print_all();

	l->next_fit(15);
	l->print_all();

	l->free(3);
	l->print_all();

	l->next_fit(10);
	l->print_all();

	l->next_fit(10);
	l->print_all();

	l->free(1);
	l->free(3);
	l->print_all();

	l->next_fit(10);
	l->print_all();
	
	l->free(1);
	l->print_all();
	
	l->next_fit(10);
	l->print_all();

	l->next_fit(10);
	l->print_all();

	/**/

	/*
	l->best_fit(25);
	l->print_all();

	l->best_fit(25);
	l->print_all();

	l->best_fit(25);
	l->print_all();

	l->best_fit(25);
	l->print_all();
	
	l->free(0);
	l->print_all();

	l->free(1);
	l->print_all();

	l->free(2);
	l->print_all();

	l->best_fit(25);
	l->print_all();

	l->best_fit(25);
	l->print_all();

	l->best_fit(25);
	l->print_all();

	l->free(0);
	l->print_all();

	l->free(2);
	l->print_all();

	l->free(3);
	l->print_all();

	l->best_fit(20);
	l->print_all();

	l->best_fit(25);
	l->print_all();

	l->best_fit(25);
	l->print_all();

	l->best_fit(5);
	l->print_all();
	/**/

	/*
	l->wors_fit(25);
	l->print_all();

	l->wors_fit(25);
	l->print_all();

	l->wors_fit(25);
	l->print_all();

	l->wors_fit(25);
	l->print_all();
	
	l->free(2);
	l->print_all();

	l->free(3);
	l->print_all();

	l->free(0);
	l->print_all();

	l->wors_fit(25);
	l->print_all();

	l->free(1);
	l->print_all();

	l->wors_fit(25);
	l->print_all();

	l->wors_fit(25);
	l->print_all();

	l->wors_fit(25);
	l->print_all();

	/**/

	delete l;
	return 0;
}
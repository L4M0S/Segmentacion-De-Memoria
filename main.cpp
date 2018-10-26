#include <cstdio>

#include "List.cpp"
int main()
{
	int memory = 0;
		int uam = 0;
		int option = 0;
		int algorithm = 0;
		
		int contador=0;
		
	do
	{
		contador=0;
		printf("Tamaño de la memoria KB: ");
		scanf("%i", &memory);

		printf("Tamaño de las UAMs KB: ");
		scanf("%i", &uam);

		printf("\nAjustes:\n1:Primer Ajuste\n2:Siguiente Ajuste\n3:Mejor Ajuste\n4:Peor Ajuste\n5:Salir\n");
		scanf("%i", &algorithm);
		if(algorithm == 5) break;

		List *l = new List(memory, uam);
		l->print_all();

		do
		{
			
			printf("\nOpciones:\n1:Crear Proceso\n2:Borrar Proceso\n3:Cambiar Ajuste\n");
			scanf("%i", &option);

			if(option == 3) break;
			
			if(option == 1)
			{
				contador++;
				
				int value = 0;
				printf("Tamaño KB: ");
				scanf("%i", &value);

				try
				{
					if(algorithm == 1) l->first_fit(value);
					else if(algorithm == 2) l->next_fit(value);
					else if(algorithm == 3) l->best_fit(value);
					else if(algorithm == 4) l->wors_fit(value);
				}

				catch(int exception )
				{
					return 0;
				}
			}

			else if(option == 2)
			{
				
				contador--;
				
				int value = 0;
				printf("Id: ");
				scanf("%i", &value);
				l->free(value);
			}
			if(contador!=0)	l->print_all();
			else if(contador==0) 
			{
				printf("Memoria Libre: %iKB UAMs: %i\n", (memory / uam)*(uam), (memory / uam));
				printf("Tipo\tId\tTamKB\tUAMs\tDesperdicioKB\n");
				printf("%s\t%i\t%i\t%i\t%i\n", "H", -1, (memory / uam)*(uam), (memory / uam), (memory / uam)*(uam));
				delete l;
				List *a = new List(memory, uam);
				a->print_all();
				cin>> option;
				if(option == 1)
			{
				contador++;
				
				int value = 0;
				printf("Tamaño KB: ");
				scanf("%i", &value);

				try
				{
					if(algorithm == 1) a->first_fit(value);
					else if(algorithm == 2) a->next_fit(value);
					else if(algorithm == 3) a->best_fit(value);
					else if(algorithm == 4) a->wors_fit(value);
				}

				catch(int exception )
				{
					return 0;
				}
				a->print_all();
			}
				
			}
		}while(true);
		
		delete l;
	}while(true);

	return 0;
}

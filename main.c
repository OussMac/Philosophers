#include "philo.h"

int main(int argc, char *argv[])
{
	t_table	table;

	if(parse_input(argc, argv, &table) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
	print_table(&table);
	return(EXIT_SUCCESS);
}
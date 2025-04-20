#include "philo.h"

int main(int argc, char *argv[])
{
	t_table	table;

	if(parse_input(argc, argv, &table) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
	if(allocate_data(&table) != EXIT_SUCCESS)
		return(print_error("Failed Allocating Resauces"), EXIT_FAILURE);
	clean_up(&table);
	print_table(&table);
	return(EXIT_SUCCESS);
}
#include "philo.h"

int main(int argc, char *argv[])
{
	t_table	table;

	if (parse_input(argc, argv) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
	if(allocate_data(&table) != EXIT_SUCCESS)
			return(print_error("Failed Allocating Resauces"), EXIT_FAILURE);
	if (init_table_data(argc, argv, &table) != EXIT_SUCCESS)
		return (print_error("Table Initalization Failed.\n"), EXIT_FAILURE);
	print_scene(&table);
	clean_up(&table);
	return(EXIT_SUCCESS);
}
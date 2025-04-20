#include "philo.h"

void    free_data(t_table *table)
{
    free(table->philos);
    free(table->forks);
}

void    clean_up(t_table *table)
{
    free_data(table);
}
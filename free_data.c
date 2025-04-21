#include "philo.h"

void    print_error(char *error)
{
    printf(RED"[-] %s"RST, error);
}

void    print_comm(char *comment)
{
    printf(ORN"[*] %s"RST, comment);
}

void    free_data(t_table *table)
{
    free(table->philos);
    free(table->forks);
}

void    clean_up(t_table *table)
{
    free_data(table);
    pthread_mutex_destroy(&table->print_lock);
    pthread_mutex_destroy(&table->death_lock);
}
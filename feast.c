#include "philo.h"

extern int counter;

void *philosopher(void *arg)
{
    t_table *table;
    
    table = (t_table *) arg;
    int i = 0;
    while (i < 100000)
    {
        pthread_mutex_lock(&table->print_lock);
        counter++;
        pthread_mutex_unlock(&table->print_lock);
        i++;
    }
    table = (t_table *) arg;
    return (NULL);
}

int start_scenario(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_number)
        pthread_create(&table->philos[i++].th_id, NULL, philosopher, table);
    i = 0;
    while (i < table->philo_number)
        pthread_join(table->philos[i++].th_id, NULL);
    return (EXIT_SUCCESS);
}
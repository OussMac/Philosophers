#include "philo.h"

int general_table(int argc , char *argv[],t_table *table)
{
    table->end_feast = false;
    table->philo_number = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->nbr_of_meals = ft_atol(argv[5]);
	else
		table->nbr_of_meals = -1;
    table->start = u_time();
    if (table->start == -1)
        return(EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int init_philos(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_number)
    {
        printf("=== %d < %d\n", i, table->philo_number);
        table->philos[i].ph_id = i + 1;
        table->philos[i].meals_eaten = 0;
        printf("=== meals eaten %d\n", table->philos[i].meals_eaten);
        table->philos[i].last_meal = table->start;
        table->philos[i].table = table;
        i++;
    }
    return(EXIT_SUCCESS);
}

long u_time(void)
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL) != 0)
        return (print_error("Failed To Get Time.\n"), -1);
    return(tv.tv_usec);
}

int init_table_data( t_table *table)
{
    init_philos(table);
    return(EXIT_SUCCESS);
}

int allocate_data(t_table *table)
{
    printf("\n");
    table->philos = (t_philo *) malloc(table->philo_number * sizeof(t_philo));
    if (!table->philos)
        return(EXIT_FAILURE);
    table->forks = (t_fork *) malloc(table->philo_number * sizeof(t_fork));
    if (!table->forks)
        return(free(table->philos), EXIT_FAILURE);
    if (pthread_mutex_init(&table->print_lock, NULL) != 0 
        || pthread_mutex_init(&table->death_lock, NULL) != 0)
        return(free(table->forks), free(table->philos), EXIT_FAILURE);
    return(EXIT_SUCCESS);
}

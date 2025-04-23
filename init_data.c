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
    table->start = m_time();
    if (table->start == -1)
        return(EXIT_FAILURE);
    table->forks = NULL;
    table->philos = NULL;
    return (EXIT_SUCCESS);
}

long    m_time(void)
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL) != 0)
        return (print_error("Failed To Get Time.\n"), -1);
    return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int init_table_data( t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_number)
    {
        // initing philos
        table->philos[i].ph_id = i + 1;
        table->philos[i].meals_eaten = 0;
        table->philos[i].last_meal = table->start;
        table->philos[i].left_fork = &table->forks[i];
        table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_number];
        table->philos[i].table = table;
        // initing forks
        table->philos[i].left_fork->fork_id = i;
        table->philos[i].right_fork->fork_id = (i + 1) % table->philo_number;
        pthread_mutex_init(&table->forks->fork + i, NULL);
        i++;
    }
    return(EXIT_SUCCESS);
}

int allocate_data(t_table *table)
{
    table->philos = malloc(table->philo_number * sizeof(t_philo));
    if (!table->philos)
        return(EXIT_FAILURE);
    table->forks = malloc(table->philo_number * sizeof(t_fork));
    if (!table->forks)
        return(free(table->philos), EXIT_FAILURE);
    if (pthread_mutex_init(&table->print_lock, NULL) != 0 
        || pthread_mutex_init(&table->death_lock, NULL) != 0 
        || pthread_mutex_init(&table->eat_lock, NULL) != 0 
        || pthread_mutex_init(&table->write_lock, NULL) != 0 
        || pthread_mutex_init(&table->nbr_lock, NULL) != 0)
        return(free(table->forks), free(table->philos), EXIT_FAILURE);
    return(EXIT_SUCCESS);
}

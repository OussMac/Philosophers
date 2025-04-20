#include "philo.h"

void    print_error(char *error)
{
    printf(RED"[-] %s"RST, error);
}

void    print_comm(char *comment)
{
    printf(ORN"[*] %s"RST, comment);
}

long u_time(void)
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL) != 0)
        return (print_error("Failed To Get Time.\n"), -1);
    return(tv.tv_usec);
}

int init_table_data(int argc , char *argv[], t_table *table)
{
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
    return(EXIT_SUCCESS);
}

#include "philo.h"

void    *philosopher(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *) arg;
    while (true)
    {
        if (philo->ph_id % 2 == 0)
            ft_usleep(3);
        if (check_end_flag(philo->table))
        {
            set_philo_nbr(philo->table);
            break;
        }
        p_eating(philo);
        p_sleep(philo);
        p_think(philo);
    }
    return (NULL);
}

void    *watcher(void *arg)
{
    t_table *table;
    int     i;

    table = (void *)arg;
    while (true)
    {
        i = 0;
        while(i < table->philo_number)
        {
            if (check_eaten(&table->philos[i]) || check_last_meal(table->philos[i].last_meal, table->time_to_die, table))
            {
                write_death(&table->end_feast, table);
                print_action(&table->philos[i], "died");
                return (NULL);
            }
            i++;
        }
        ft_usleep(5);
    }
    return (NULL);
}

int start_scenario(t_table *table)
{
    int i;
    pthread_t    t_watcher;

    i = 0;
    while (i < table->philo_number)
    {
        pthread_create(&table->philos[i].th_id, NULL, philosopher, &table->philos[i]);
        i++;
    }
    i = 0;
    pthread_create(&t_watcher, NULL, watcher, table);
    pthread_join(t_watcher, NULL);
    while (i < table->philo_number)
        pthread_join(table->philos[i++].th_id, NULL);
    return (EXIT_SUCCESS);
}
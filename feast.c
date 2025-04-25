#include "philo.h"

void    *philosopher(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *) arg;
    while (true)
    {
        if (philo->ph_id % 2 == 0)
            ft_usleep(5, philo->table);
        if (check_end_flag(philo->table) || check_eaten(philo))
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
    int     ph_nbr;

    table = (void *)arg;
    while (true)
    {
        i = 0;
        pthread_mutex_lock(&table->nbr_lock);
        ph_nbr = table->philo_number;
        pthread_mutex_unlock(&table->nbr_lock);
        while(i < ph_nbr)
        {
            if (check_last_meal(&table->philos[i]))
            {
                write_death(&table->end_feast, table);
                print_action(&table->philos[i], RED"died"RST);
                return (NULL);
            }
            if (check_nbr(table))
            {
                write_death(&table->end_feast, table);
                return (NULL);
            }
            i++;
        }
        ft_usleep(5, table);
    }
    return (NULL);
}

int start_scenario(t_table *table)
{
    int i;
    pthread_t    t_watcher;

    i = 0;
    int ph_nbr = table->philo_number;
    while (i < ph_nbr)
    {
        pthread_create(&table->philos[i].th_id, NULL, philosopher, &table->philos[i]);
        i++;
    }
    i = 0;
    pthread_create(&t_watcher, NULL, watcher, table);
    pthread_join(t_watcher, NULL);
    while (i < ph_nbr)
        pthread_join(table->philos[i++].th_id, NULL);
    return (EXIT_SUCCESS);
}
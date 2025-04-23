#include "philo.h"

void    *philosopher(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *) arg;
    while (true)
    {
        // if (philo->ph_id % 2 == 0)
        //     ft_usleep(500);
        if (philo->table->end_feast ||(philo->meals_eaten >= philo->table->nbr_of_meals))
            break;
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
            if (m_time() - table->philos[i].last_meal  > table->time_to_die)
            {
                pthread_mutex_lock(&table->death_lock);
                table->end_feast = true;
                pthread_mutex_unlock(&table->death_lock);
                print_action(&table->philos[i], "died");
                break;
            }
            i++;
        }
        pthread_mutex_lock(&table->death_lock);
        if (table->end_feast)
        {
            pthread_mutex_unlock(&table->death_lock);
            break;
        }
        pthread_mutex_unlock(&table->death_lock);
        ft_usleep(100);
    }
    return (NULL);
}

int start_scenario(t_table *table)
{
    int i;
    pthread_t    t_watcher;

    i = 0;
    pthread_create(&t_watcher, NULL, watcher, table);
    while (i < table->philo_number)
    {
        pthread_create(&table->philos[i].th_id, NULL, philosopher, &table->philos[i]);
        i++;
    }
    i = 0;
    while (i < table->philo_number)
        pthread_join(table->philos[i++].th_id, NULL);
    pthread_join(t_watcher, NULL);
    return (EXIT_SUCCESS);
}
#include "philo.h"

void    print_action(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->table->print_lock);
    printf("%ld %d %s\n", m_time() - philo->table->start, philo->ph_id, str);
    pthread_mutex_unlock(&philo->table->print_lock);
}

void *philosopher(void *arg)
{
    t_philo *philo;
    bool    end;
    
    philo = (t_philo *) arg;
    while (true)
    {
        if (philo->ph_id % 2 == 0)
            usleep(400);
        pthread_mutex_lock(&philo->table->death_lock);
        end = philo->table->end_feast;
        pthread_mutex_unlock(&philo->table->death_lock);
        if (end || (philo->meals_eaten >= philo->table->nbr_of_meals))
            break;
        pthread_mutex_lock(&philo->right_fork->fork);
        print_action(philo, "has taken a fork");
        pthread_mutex_lock(&philo->left_fork->fork);
        print_action(philo, "has taken a fork");

        print_action(philo, "is eating");
        pthread_mutex_lock(&philo->table->eat_lock);
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->table->eat_lock);
        usleep(philo->table->time_to_eat * 1000);

        pthread_mutex_unlock(&philo->right_fork->fork);
        pthread_mutex_unlock(&philo->left_fork->fork);

        print_action(philo, "is sleeping");
        usleep(philo->table->time_to_sleep * 1000);
        print_action(philo, "is thinking");
    }
    return (NULL);
}

int start_scenario(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_number)
    {
        pthread_create(&table->philos[i].th_id, NULL, philosopher, &table->philos[i]);
        i++;
    }
    i = 0;
    while (i < table->philo_number)
        pthread_join(table->philos[i++].th_id, NULL);
    return (EXIT_SUCCESS);
}
#include "philo.h"

void    write_last_meal(long last_meal, long current_t, t_table *table)
{
    pthread_mutex_lock(&table->write_lock);
    last_meal = current_t;
    pthread_mutex_unlock(&table->write_lock);
}

bool    check_last_meal(long last_meal, long time_to_die, t_table *table)
{
    pthread_mutex_lock(&table->write_lock);
    if (m_time() - last_meal >= time_to_die)
    {
        pthread_mutex_unlock(&table->write_lock);
        return(true);
    }
    pthread_mutex_unlock(&table->write_lock);
    return (false);
}

void    write_death(bool *end, t_table *table)
{
    pthread_mutex_lock(&table->death_lock);
    *end = true;
    pthread_mutex_unlock(&table->death_lock);
}

bool    check_end_flag(t_table *table)
{
    pthread_mutex_lock(&table->death_lock);
    if (table->end_feast)
    {
        pthread_mutex_unlock(&table->death_lock);
        return (true);
    }
    pthread_mutex_unlock(&table->death_lock);
    return(false);
}

void    write_eaten(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->eat_lock);
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->table->eat_lock);
}

bool    check_eaten(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->eat_lock);
    if (philo->meals_eaten >= philo->table->nbr_of_meals)
    {
        pthread_mutex_unlock(&philo->table->eat_lock);
        return(true);
    }
    pthread_mutex_unlock(&philo->table->eat_lock);
    return (false);
}

void    set_philo_nbr(t_table *table)
{
    pthread_mutex_lock(&table->nbr_lock);
    table->philo_number--;
    pthread_mutex_unlock(&table->nbr_lock);
}

bool    check_nbr(t_table *table)
{
    pthread_mutex_lock(&table->nbr_lock);
    if (table->philo_number <= 0)
    {
        pthread_mutex_unlock(&table->nbr_lock);
        return (true);
    }
    pthread_mutex_unlock(&table->nbr_lock);
    return (false);
}

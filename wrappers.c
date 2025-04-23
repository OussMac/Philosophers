#include "philo.h"

void    write_meals_eaten(long last_meal, long current_t, t_table *table)
{
    pthread_mutex_lock(&table->write_lock);
    last_meal = current_t;
    pthread_mutex_unlock(&table->write_lock);
}

bool    check_meals_eaten(long last_meal, long time_to_die, t_table *table)
{
    pthread_mutex_lock(&table->write_lock);
    if (m_time() - last_meal > time_to_die)
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

bool    check_death(t_table *table)
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



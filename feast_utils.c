#include "philo.h"

void    print_action(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->table->print_lock);
    printf("%ld %d %s\n", get_time(philo->table), philo->ph_id, str);
    pthread_mutex_unlock(&philo->table->print_lock);
}

int     ft_usleep(long miliseconds)
{
    long    start_time;

    start_time = m_time();
    while ((m_time() - start_time) < miliseconds)
        usleep(100);
    return (EXIT_SUCCESS);
}

void    p_eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->right_fork->fork);
    print_action(philo, "has taken a fork");
    pthread_mutex_lock(&philo->left_fork->fork);
    print_action(philo, "has taken a fork");

    print_action(philo, "is eating");
    write_eaten(philo);
    ft_usleep(philo->table->time_to_eat);
    
    write_last_meal(philo, philo->table);

    pthread_mutex_unlock(&philo->right_fork->fork);
    pthread_mutex_unlock(&philo->left_fork->fork);
}

void    p_sleep(t_philo *philo)
{
    print_action(philo, "is sleeping");
    ft_usleep(philo->table->time_to_sleep);
}
void    p_think(t_philo *philo)
{
    print_action(philo, "is thinking");
}

#include "philo.h"

void    print_action(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->table->print_lock);
    printf("%ld %d %s\n", get_time(philo->table), philo->ph_id, str);
    pthread_mutex_unlock(&philo->table->print_lock);
}

int     ft_usleep(long miliseconds, t_table *table)
{
    long    start_time;

    pthread_mutex_lock(&table->sleep_lock);
    start_time = m_time();
    while ((m_time() - start_time) < miliseconds)
        usleep(100);
    pthread_mutex_unlock(&table->sleep_lock);
    return (EXIT_SUCCESS);
}

void    p_eating(t_philo *philo)
{

    // algo always pickup lowest index fork to prevent a deadlock better

    // pthread_mutex_lock(&philo->table->print_lock);
    // printf(YLW"left = %d < right = %d \n"RST, philo->left_fork->fork_id, philo->right_fork->fork_id);
    // pthread_mutex_unlock(&philo->table->print_lock);


    if (check_forks(philo)) // problem is fork id have value 0 and not initalized correctly
    {
        pthread_mutex_lock(&philo->left_fork->fork);
        print_action(philo, GRN"has taken a fork"RST);
        pthread_mutex_lock(&philo->right_fork->fork);
        print_action(philo, GRN"has taken a fork"RST);
    } 
    else
    {
        pthread_mutex_lock(&philo->right_fork->fork);
        print_action(philo, BLU"has taken a fork"RST);
        pthread_mutex_lock(&philo->left_fork->fork);
        print_action(philo, BLU"has taken a fork"RST);
    }


    // pthread_mutex_lock(&philo->right_fork->fork);
    // print_action(philo, "has taken a fork");
    // pthread_mutex_lock(&philo->left_fork->fork);
    // print_action(philo, "has taken a fork");

    print_action(philo, MGN"is eating"RST);
    write_eaten(philo);
    ft_usleep(philo->table->time_to_eat, philo->table);
    
    write_last_meal(philo, philo->table);

    pthread_mutex_unlock(&philo->right_fork->fork);
    pthread_mutex_unlock(&philo->left_fork->fork);
}

void    p_sleep(t_philo *philo)
{
    print_action(philo, "is sleeping");
    ft_usleep(philo->table->time_to_sleep, philo->table);
}
void    p_think(t_philo *philo)
{
    print_action(philo, YLW"is thinking"RST);
}

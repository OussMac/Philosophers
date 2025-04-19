#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // for printf
# include <stdlib.h> // for malloc, free 
# include <unistd.h> // for usleep
# include <sys/time.h> // for gettimeofday
# include <pthread.h> // pthread_create, pthread_join...
# include <stdbool.h> // for boolean flags
# include <limits.h>


// table type exists
typedef struct s_table t_table;

// fork object
typedef struct s_fork
{
    int             fork_id;
    pthread_mutex_t fork;
}   t_fork;


// philosopher object
typedef struct s_philo
{
    int         ph_id;
    pthread_t   th_id;

    long        last_meal;
    int         meals_eaten;


    t_fork      *left_fork;
    t_fork      *right_fork;
    t_table     *table;
}   t_philo;

// table object
typedef struct s_table
{
    int     philo_number;
    long    time_to_eat;
    long    time_to_sleep;
    long    time_to_die;

    int     nbr_of_meals;
    long    start;

    t_fork  *forks;
    t_philo *philos;

    pthread_mutex_t print_lock;
    pthread_mutex_t death_lock;
} t_table;


int parse_input(int argc, char *argv[]);


#endif // PHILO_H
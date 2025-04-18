#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // for printf
# include <stdlib.h> // for malloc, free 
# include <unistd.h> // for usleep
# include <sys/time.h> // for gettimeofday
# include <pthread.h> // pthread_create, pthread_join...
# include <stdbool.h> // for boolean flags


// fork object
typedef struct s_fork
{
    pthread_mutex_t fork;
    int             fork_id;
}   t_fork;


// philosopher object
typedef struct s_philo
{
    pthread_t   tr_id;
    int         ph_id;
    t_fork      *left_fork;
    t_fork      *right_fork;
}   t_philo;


int parse_input(int argc, char *argv[]);


#endif // PHILO_H
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // for printf
# include <stdlib.h> // for malloc, free 
# include <unistd.h> // for usleep
# include <sys/time.h> // for gettimeofday
# include <pthread.h> // pthread_create, pthread_join...
# include <stdbool.h> // for boolean flags
# include <limits.h> // for overflow check

// text colors
# define RED "\e[31m"
# define GRN "\e[32m"
# define RST "\e[97m"
# define ORN "\e[33m"
# define BLU "\e[34m"
# define YLW "\e[33m"
# define MGN "\e[35m"

// # define gettimeofday(...) -1
// # define malloc(...) NULL
// # define pthread_mutex_init(...) 1


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
    bool    end_feast;
    int     philo_number;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;

    int     nbr_of_meals;
    long    start;

    t_fork  *forks;
    t_philo *philos;

    pthread_mutex_t print_lock;
    pthread_mutex_t death_lock;
    pthread_mutex_t eat_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t nbr_lock;
    pthread_mutex_t sleep_lock;
    pthread_mutex_t forks_lock;
} t_table;

// parsing and input.
int     parse_input(int argc, char *argv[], t_table *table);
int     general_table(int argc , char *argv[],t_table *table);
int     init_table_data(t_table *table);
long	ft_atol(const char *str);

// allocate_data
int     allocate_data(t_table *table);
int     stack_data(t_table *table);
void    free_data(t_table *table);
void    clean_up(t_table *table);

// scenario
int     start_scenario(t_table *table);
void    *philosopher(void *arg);
void    p_eating(t_philo *philo);
void    p_sleep(t_philo *philo);
void    p_think(t_philo *philo);
void    print_action(t_philo *philo, char *str);

// wrrappers
void    write_last_meal(t_philo *philo, t_table *table);
bool    check_last_meal(t_philo *philo);
void    write_death(bool *end, t_table *table);
bool    check_end_flag(t_table *table);
void    write_eaten(t_philo *philo);
bool    check_eaten(t_philo *philo);
void    set_philo_nbr(t_table *table);
bool    check_nbr(t_table *table);
bool    check_forks(t_philo *philo);

// time
int     ft_usleep(long miliseconds, t_table *table);
long    m_time(void);
long    get_time(t_table *table); // time since start

// error handling
void    print_error(char *error);
void    print_comm(char *comment);

// for debuging
void    print_scene(t_table *table);


#endif // PHILO_H
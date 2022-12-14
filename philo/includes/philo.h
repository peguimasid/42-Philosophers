/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/13 13:42:12 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				ate_times;
	unsigned long	last_meal;
	pthread_mutex_t	check_mutex;
	struct s_info	*global;
}					t_philo;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	int				num_philo_finish_eat;
	int				finish;
	pthread_mutex_t	finish_mutex;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	unsigned long	created_at;
}					t_info;

void				init_philos_threads_and_mutexes(t_info *data);
void				join_threads_and_free_data(t_info *data);
void				*routine(void *argv);
void				*monitor(void *argv);
void				*must_eat_monitor(void *argv);

int					is_valid_args(int argc, char **argv);
int					parse_args(t_info *data, int argc, char **argv);

int					print_usage(void);
int					throw_error(char *error);

void				print_msg(t_philo *philo, char *str);
int					ft_atoi(char *str);
int					ft_isnum(char *str);
void				smart_sleep(unsigned long time, t_philo *philo);
unsigned long		time_now(void);

#endif

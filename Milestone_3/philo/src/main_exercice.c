/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:21:57 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/15 16:06:24 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <semaphore.h>

///// EXERCICE 1
/*void *thread_func(void *arg)*/
/*{*/
/*	printf("Hello thread\n");*/
/*	return (arg);*/
/*}*/
/**/
/*int	main (void)*/
/*{*/
/*	pthread_t	tid;*/
/*	pthread_create(&tid, NULL, thread_func, NULL);*/
/*	pthread_join(tid, NULL);*/
/*	return (0);*/
/*}*/

///// EXERCICE 2
/*void *thread_multi(void *arg)*/
/*{*/
/*	int *n = (int *)arg;*/
/*	int	*result = malloc(sizeof(int));*/
/*	*result = (*n) * (*n);*/
/*	return (result);*/
/*}*/
/*void *thread_div(void *arg)*/
/*{*/
/*	int *n = (int *)arg;*/
/*	int	*result = malloc(sizeof(int));*/
/*	*result = (*n) / (*n);*/
/*	return (result);*/
/*}*/
/*int	main (void)*/
/*{*/
/*	pthread_t	tid;*/
/*	pthread_t	tid2;*/
/*	int	*n = malloc(sizeof(int));*/
/*	void *ret;*/
/**/
/*	*n = 5;*/
/*	pthread_create(&tid, NULL, thread_multi, n);*/
/*	pthread_join(tid, &ret);*/
/*	printf("tid_result = %d\n", *(int*)ret);*/
/*	free(ret);*/
/**/
/*	pthread_create(&tid2, NULL, thread_div, n);*/
/*	pthread_join(tid2, &ret);*/
/*	printf("tid2_result = %d\n", *(int*)ret);*/
/**/
/*	free(n);*/
/*	free(ret);*/
/*	return (0);*/
/*}*/

///// EXERCICE 3
/*void *thread_func(void *arg)*/
/*{*/
/*	int *i = (int*)arg;*/
/*	printf("Thread %d started\n", *i);*/
/*	return (arg);*/
/*}*/
/**/
/*int	main (int ac, char **av)*/
/*{*/
/*	int	N = atoi(av[1]);*/
/*	pthread_t	tid[N];*/
/*	int ids[N];*/
/*	int	i = 0;*/
/*	int	j = 0;*/
/*	while ( i < N)*/
/*	{*/
/*		ids[i] = i;*/
/*		pthread_create(&tid[i], NULL, thread_func, &ids[i]);*/
/*		i++;*/
/*	}*/
/*	while ( j < N )*/
/*	{*/
/*		pthread_join(tid[j], NULL);*/
/*		j++;*/
/*	}*/
/*	return (0);*/
/*}*/

///// EXERCICE 4 
/*typedef struct s_shared_data {*/
/*	int *count;*/
/*	pthread_mutex_t *lock;*/
/*}	t_shared_data;*/
/**/
/**/
/*void	*thread_func(void *arg)*/
/*{*/
/*	t_shared_data *data = (t_shared_data *)arg;*/
/*	int	i = 0;*/
/**/
/*	while ( i != 10)*/
/*	{*/
/*		pthread_mutex_lock(data->lock);*/
/*		(*data->count)++;*/
/*		pthread_mutex_unlock(data->lock);*/
/*		i++;*/
/*	}*/
/*	free(data);*/
/*	return (NULL);*/
/*}*/
/**/
/*int	main (int ac, char **av)*/
/*{*/
/*	int N = atoi(av[1]);*/
/*	pthread_t *tid = malloc(sizeof(pthread_t) * N);*/
/*	pthread_mutex_t *lock = malloc(sizeof(pthread_mutex_t));*/
/*	int *count = malloc(sizeof(int));*/
/*	*count = 0;*/
/**/
/*	pthread_mutex_init(lock, NULL);*/
/**/
/*	int	i = 0;*/
/*	int	j = 0;*/
/*	while ( i < N)*/
/*	{*/
/*		t_shared_data *data = malloc(sizeof(t_shared_data));*/
/*		data->count = count;*/
/*		data->lock = lock;*/
/*		pthread_create(&tid[i], NULL, thread_func, data);*/
/*		i++;*/
/*	}*/
/*	while ( j < N )*/
/*	{*/
/*		pthread_join(tid[j], NULL);*/
/*		j++;*/
/*	}*/
/*	printf("Final count: %d\n", *count);*/
/*	// nettoyage*/
/*	free(count);*/
/*	pthread_mutex_destroy(lock);*/
/*	free(lock);*/
/*	free(tid);*/
/*	return (0);*/
/*}*/

///// EXERCICE 5 
/*typedef struct s_shared_data {*/
/*	int				buffer;*/
/*	bool			full;*/
/*	pthread_mutex_t	m;*/
/*	pthread_cond_t	c_produce;*/
/*	pthread_cond_t	c_consume;*/
/*}	t_shared_data;*/
/**/
/*void *producer(void *arg)*/
/*{*/
/*	t_shared_data *data = (t_shared_data *)arg;*/
/*	int v = 1;*/
/**/
/*	while (v <= 20)*/
/*	{*/
/*		pthread_mutex_lock(&data->m);*/
/**/
/*		while (data->full)*/
/*			pthread_cond_wait(&data->c_consume, &data->m);*/
/**/
/*		data->buffer = v;*/
/*		data->full = true;*/
/*		printf("Produced: %d\n", v);*/
/*		v++;*/
/**/
/*		pthread_cond_signal(&data->c_produce);*/
/*		pthread_mutex_unlock(&data->m);*/
/*		usleep(2000000);*/
/*	}*/
/*	return NULL;*/
/*}*/
/**/
/*void *consumer(void *arg)*/
/*{*/
/*	t_shared_data *data = (t_shared_data *)arg;*/
/*	int i = 1;*/
/**/
/*	while (i <= 20)*/
/*	{*/
/*		pthread_mutex_lock(&data->m);*/
/**/
/*		while (!data->full)*/
/*			pthread_cond_wait(&data->c_produce, &data->m);*/
/**/
/*		printf("Consumed: %d\n", data->buffer);*/
/*		data->full = false;*/
/*		i++;*/
/**/
/*		pthread_cond_signal(&data->c_consume);*/
/*		pthread_mutex_unlock(&data->m);*/
/**/
/*	}*/
/*	return NULL;*/
/*}*/
/**/
/**/
/*int	main (void)*/
/*{*/
/*	t_shared_data data;*/
/*	data.buffer = 0;*/
/*	data.full = false;*/
/*	pthread_mutex_init(&data.m, NULL);*/
/*	pthread_cond_init(&data.c_produce, NULL);*/
/*	pthread_cond_init(&data.c_consume, NULL);*/
/**/
/*	pthread_t prod, cons;*/
/**/
/*	pthread_create(&prod, NULL, producer, &data);*/
/*	pthread_create(&cons, NULL, consumer, &data);*/
/**/
/*	pthread_join(prod, NULL);*/
/*	pthread_join(cons, NULL);*/
/**/
/**/
/*	pthread_mutex_destroy(&data.m);*/
/*	pthread_cond_destroy(&data.c_produce);*/
/*	pthread_cond_destroy(&data.c_consume);*/
/*	return (0);*/
/*}*/

//// EXERCICE 6 
/*#define SIZE 5*/
/**/
/*typedef struct s_shared_data*/
/*{*/
/*	int				buffer[SIZE];*/
/*	int				head;*/
/*	int				tail;*/
/*	pthread_mutex_t	mutex;*/
/*	sem_t			sem_empty;*/
/*	sem_t			sem_full;*/
/*}	t_shared_data;*/
/**/
/*void *producer(void *arg)*/
/*{*/
/*	t_shared_data *data = (t_shared_data *)arg;*/
/*	int v = 1;*/
/**/
/*	while (v <= 50)*/
/*	{*/
/*		sem_wait(&data->sem_empty);*/
/*		pthread_mutex_lock(&data->mutex);*/
/**/
/*		data->buffer[data->tail] = v;*/
/*		data->tail = (data->tail+1)%5;*/
/**/
/*		pthread_mutex_unlock(&data->mutex);*/
/*		printf("Produced: %d\n", v);*/
/*		sem_post(&data->sem_full);*/
/*		v++;*/
/*	}*/
/*	return NULL;*/
/*}*/
/**/
/*void *consumer(void *arg)*/
/*{*/
/*	t_shared_data *data = (t_shared_data *)arg;*/
/*	int i = 1;*/
/*	int	x;*/
/*	while (i <= 50)*/
/*	{*/
/*		sem_wait(&data->sem_full);*/
/*		pthread_mutex_lock(&data->mutex);*/
/*		x = data->buffer[data->head];*/
/*		data->head = (data->head+1)%5;*/
/*		pthread_mutex_unlock(&data->mutex);*/
/*		printf("%d\n", x);*/
/*		sem_post(&data->sem_empty);	*/
/*		i++;*/
/*	}*/
/*	return NULL;*/
/*}*/
/*int	main (void)*/
/*{*/
/*	t_shared_data data;*/
/*	pthread_t prod, cons;*/
/**/
/*	data.head = 0;*/
/*	data.tail = 0;*/
/*	pthread_mutex_init(&data.mutex, NULL);*/
/*	sem_init(&data.sem_empty, 0, SIZE);*/
/*	sem_init(&data.sem_full, 0, 0);*/
/**/
/**/
/*	pthread_create(&prod, NULL, producer, &data);*/
/*	pthread_create(&cons, NULL, consumer, &data);*/
/**/
/*	pthread_join(prod, NULL);*/
/*	pthread_join(cons, NULL);*/
/**/
/**/
/*	pthread_mutex_destroy(&data.mutex);*/
/*	sem_destroy(&data.sem_empty);*/
/*	sem_destroy(&data.sem_full);*/
/**/
/*	return (0);*/
/*}*/

///// EXERCICE 7
/*typedef struct s_philosopher {*/
/*	int	turn;*/
/*	int id;                          // numéro du philosophe (0 à N-1)*/
/*	pthread_mutex_t *left_fork;     // pointeur vers sa fourchette gauche*/
/*	pthread_mutex_t *right_fork;    // pointeur vers sa fourchette droite*/
/*}	t_philosopher;*/
/**/
/*void *philosopher(void *arg)*/
/*{*/
/*	t_philosopher *philo = (t_philosopher *)arg;*/
/*	int i = 0;*/
/**/
/*	while (i <= philo->turn)*/
/*	{*/
/*		printf("Philosopher %d is thinking\n", philo->id);*/
/*		usleep(1000);*/
/**/
/*		if (philo->id % 2 == 0)*/
/*		{*/
/*			pthread_mutex_lock(philo->left_fork);*/
/*			printf("Philosopher %d took left fork\n", philo->id);*/
/**/
/*			pthread_mutex_lock(philo->right_fork);*/
/*			printf("Philosopher %d took right fork\n", philo->id);*/
/*		}*/
/*		else*/
/*		{*/
/*			pthread_mutex_lock(philo->right_fork);*/
/*			printf("Philosopher %d took right fork\n", philo->id);*/
/**/
/*			pthread_mutex_lock(philo->left_fork);*/
/*			printf("Philosopher %d took left fork\n", philo->id);*/
/*		}*/
/**/
/*		printf("Philosopher %d is eating\n", philo->id);*/
/*		usleep(300000);*/
/**/
/*		pthread_mutex_unlock(philo->left_fork);*/
/*		pthread_mutex_unlock(philo->right_fork);*/
/**/
/*		i++;*/
/*	}*/
/*	return NULL;*/
/*}*/
/**/
/**/
/*int	main (int ac, char **av)*/
/*{*/
/*	int	number_philo = atoi(av[1]);*/
/*	int	nbr_of_turn = atoi(av[2]);*/
/*	pthread_t threads[number_philo];*/
/*	pthread_mutex_t forks[number_philo];*/
/*	t_philosopher philosophers[number_philo];*/
/**/
/*	// Initialiser les mutex*/
/*	for (int i = 0; i < number_philo; i++)*/
/*		pthread_mutex_init(&forks[i], NULL);*/
/**/
/*	// Initialiser les philosophes*/
/*	for (int i = 0; i < number_philo; i++)*/
/*	{*/
/*		philosophers[i].turn = nbr_of_turn;*/
/*		philosophers[i].id = i;*/
/*		philosophers[i].left_fork = &forks[i];*/
/*		philosophers[i].right_fork = &forks[(i + 1) % number_philo];*/
/*		pthread_create(&threads[i], NULL, philosopher, &philosophers[i]);*/
/**/
/*	}*/
/*	// Join (optionnel ici, ou sleep infini)*/
/*	for (int i = 0; i < number_philo; i++)*/
/*		pthread_join(threads[i], NULL);*/
/**/
/*	return (0);*/
/*}*/

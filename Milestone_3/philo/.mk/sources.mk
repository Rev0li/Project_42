HEADER = \
		 includes/philo.h		\
		 includes/memory.h		\
		 includes/mutex_utils.h

SRCS = \
	   src/main.c				\
	   src/philo.c				\
	   src/memory.c				\
	   src/init.c				\
	   src/mutex_utils.c		\
	   src/start.c				\
	   \
	   src/utils/ft_atoi.c		\
	   src/utils/ft_safe_atoi.c	\
	   src/utils/sleep_utils.c	\
	   src/utils/cleanup.c	\
	   src/utils/ft_get_time_in_ms.c

BONUS_SRCS = bonus/main_bonus.c \
			 bonus/init_bonus.c \
			 bonus/process_bonus.c \
			 bonus/semaphore_bonus.c \
			 bonus/supervisor_bonus.c \
			 bonus/utils_bonus.c

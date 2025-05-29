#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648


typedef struct s_philo t_philo;

typedef struct s_info
{
	int				dead;
	int				philo_count;		// Filozof sayısı
	int				time_to_eat;		// ms cinsinden: yeme süresi
	int				time_to_sleep;		// ms cinsinden: uyuma süresi
	int				time_to_starve;		// ms cinsinden: ölüm süresi
	int				must_eat_count;		// Opsiyonel: her filozofun yemesi gereken minimum sayı
	int				all_ate_flag;		// Hepsi yeterince yedi mi?
	int				end_sim;			// Ölüm oldu mu? Simülasyonu durdur

	size_t			start_time;			// Simülasyon başlangıç zamanı (ms)

	pthread_t		monitor_thread;

	pthread_mutex_t	*forks;				// Çatal mutexleri
	pthread_mutex_t	print_mutex;		// Çıktıların karışmaması için
	pthread_mutex_t	stop_mutex;			// stop_flag erişimini korur
	pthread_mutex_t	eat_mutex;

	t_philo			*philo;				// Filozoflar dizisi
}	t_info;

typedef struct s_philo
{
	int				id;					// Filozof ID’si (1'den başlar)
	int				meals_eaten;		// Şu ana kadar kaç kez yedi
	int				is_alive;

	size_t			last_meal_time;		// En son yemek yediği zaman (ms)
										
	pthread_mutex_t	*left_fork;			// Solundaki çatal (mutex)
	pthread_mutex_t	*right_fork;		// Sağındaki çatal (mutex)

	t_info *info;
}	t_philo;

#endif
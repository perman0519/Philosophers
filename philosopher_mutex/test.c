/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:17:50 by junssong          #+#    #+#             */
/*   Updated: 2023/11/29 17:33:59 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mails = 0;
pthread_mutex_t  mutex;

void *routine()
{
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        ++mails;
        //read mails;
        //increment
        //write mails
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char * argv[])
{
    struct timeval time;
    pthread_t th[5];
    printf("%d", argc);
    printf("%s\n", argv[0]);
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 5; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Falied to create thread");
            return 1;
        }
        gettimeofday(&time, NULL);
        printf("%ld Thread %d has started\n", time.tv_sec - 1700000000, i);
    }
    for (int i = 0; i < 5; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Falied to join thread");
            return 1;
        }
        gettimeofday(&time, NULL);
        printf("%ld Thread %d has ended\n", time.tv_sec - 1700000000, i);
    }
    pthread_mutex_destroy(&mutex);
    printf("number of mails : %d\n", mails);
    return 0;
}
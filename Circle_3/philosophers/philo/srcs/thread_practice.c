#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void *p_function(void * data);

// int main(void)
// {
//   pthread_t pthread;
//   int thr_id;
//   int status;
//   char p1[] = "thread_created";
//   char p2[] = "thread_main";

//   thr_id = pthread_create(&pthread, NULL, p_function, (void*)p1);
//   if(thr_id < 0)
//   {
//     perror("pthread0 create error");
//     exit(EXIT_FAILURE);
//   }

//   p_function((void *)p2);

//   printf("created thread id: %x\n", pthread);
//   printf("end\n");
//   return 0;
// }

// void *p_function(void * data)
// {
//   pthread_t tid; // thread id

//   tid = pthread_self();

//   char* thread_name = (char *)data;
//   int i = 0;

//   while(i < 3)
//   {
//     printf("thread name : %s, tid : %x\n", thread_name, (unsigned int)tid);
//     i++;
//     usleep(1000 * 1000);
//   }
// }

void *t_function(void *param)
{
    for (int i = 1; i <= 5; i++)
    {
        usleep(1000 * 1000 * 2); //2초 대기
        printf("%s: ", (char *)param);
        printf("쓰레드 함수 실행 중..%d/5\n",i);
    }
        printf("쓰레드 함수 종료\n");
        return (void *)2147483647;
}

int main()
{
    pthread_t p_thread1;
    pthread_t p_thread2;
    int thr_id1;
    int thr_id2;

    thr_id1 = pthread_create(&p_thread1, NULL, t_function, "thread1");
    thr_id2 = pthread_create(&p_thread2, NULL, t_function, "thread2");
    if (thr_id1 < 0 || thr_id2 < 0)
    {
        perror("thread create error : ");
        exit(0);
    } 
    pthread_detach(p_thread1);
    pthread_detach(p_thread2);
    //  pthread_join(p_thread1, 0);
  //  pthread_join(p_thread2, 0);

    int s = 0;
    while (42)
{
    printf("%d초 경과\n", s++);
    usleep(1000 * 1000);
}

    printf("main() 종료\n");
    return 0;
}
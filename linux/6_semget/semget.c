#include "comm.h"
int main()
{
    int semid = createSemSet(1);
    initSem(semid,0,1);
    pid_t id =fork();
    if(id==0)
    {
        int _semid =getSemSet(0);
        while(1)
        {
            P(_semid,0);
            printf("a");
            fflush(stdout);
            usleep(123456);
            printf("a ");
            fflush(stdout);
            usleep(321456);
            V(_semid,0);
        }
    }
    else{
         while(1)
         {
             P(semid,0);
             printf("b");
             fflush(stdout);
             usleep(223456);
             printf("b ");
             fflush(stdout);
             usleep(123456);
             V(semid,0);
         }
         wait(NULL);
    }
    destoySemSet(semid);
    return 0;
}

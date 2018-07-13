#include "comm.h"
static int commShm(int size,int flags)
{
    key_t _key=ftok(PATHNAM,PROJ_I);
    if(_key<0)
    {
        perror("ftok");
        return -1;
    }
    int shmid=0;
    shmid = shmget(_key,size,flags);
        
    return shmid;
}
int destroyShm(int shmid)
{
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}

int createShm(int size)
{
    return commShm(size,IPC_CREAT|IPC_EXCL|0666);
}
int getShm(int size)
{
    return commShm(size,IPC_CREAT);
}

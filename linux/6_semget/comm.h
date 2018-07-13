#pragma once
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define PATHNAME "."
#define PROJ_ID 0X5555

union semun
{
    int val;
    struct semid *buf;
    unsigned short *array;
    struct semifo *_buf;
};
int createSemSet(int nums);
int initSem(int semid,int nums,int initVal);
int getSemSet(int nums);
int p(int semid,int who);
int v(int semid,int who);
int destroySemSet(int semid);

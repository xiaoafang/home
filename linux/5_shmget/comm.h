#pragma once
#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>

#define PATHNAM "."
#define PROJ_I 0x7777

int createShe(int size);
int destroyShm(int shmid);
int getShm(int size);

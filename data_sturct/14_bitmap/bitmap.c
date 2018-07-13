#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t BitmapType;

#define MAX_SIZE 50 //需要100位位图

typedef struct Bitmap
{
    BitmapType *data;
    uint64_t capacity;//位图总共多少位
}Bitmap;

uint64_t getsize(uint64_t index)
{
    //根据位图位数找到相应字节
    return index/(sizeof(BitmapType)*8)+1;
}
void Bitmapinit(Bitmap *bm)
{
    if(bm==NULL)
        return ;
    bm->capacity=MAX_SIZE;
    uint64_t size=getsize(bm->capacity);//根据位图数得到相应字节数
    bm->data=(BitmapType*)malloc(sizeof(BitmapType)*size);//开辟空间
    memset(bm->data,0x0,sizeof(BitmapType)*size);
}
void Bitmapset(Bitmap *bm,uint64_t index)
{
    if(bm==NULL)
        return ;
    if(index>bm->capacity)
        return ;
    uint64_t offset = getsize(index);
    uint64_t size = index%(sizeof(BitmapType)*8);
    bm->data[offset]|=(0x1ul<<size); //?
}
void Bitmapunset(Bitmap *bm,uint64_t index)
{
    if(bm==NULL)
        return ;
    if(index>bm->capacity)
        return ;
    uint64_t offset=getsize(index);
    uint64_t size=index%(sizeof(BitmapType)*8);
    bm->data[offset]&=~(0x1ul<<size);//?<<
}

int Bitmaptext(Bitmap *bm,uint64_t index)
{
    if(bm==NULL)
        return ;
    if(index>bm->capacity)
        return ;
    uint64_t offset=getsize(index);
    uint64_t size=index%(sizeof(BitmapType)*8);
    uint64_t ret=bm->data[offset]&(0x1<<size);//?
    return ret>0?1:0;
}
void Bitmapfill(Bitmap *bm)
{
    if(bm==NULL)
        return ;
    memset(bm->data,0xff,bm->capacity);
}
void Bitmapempty(Bitmap *bm)
{
    if(bm==NULL)
        return;
    memset(bm->data,0x0,bm->capacity);
}
int main()
{
    uint64_t a;
    int b;
    Bitmap Bm;
    Bitmapinit(&Bm);
    for(a=0;a<100;a++)
    {
        b=Bitmaptext(&Bm,a);
        printf("%d ",b);
    }
    printf("\n");
    Bitmapset(&Bm,20);
    //Bitmapunset(&Bm,20);
    for(a=0;a<100;a++)
    {
        b=Bitmaptext(&Bm,a);
        printf("%d ",b);
    }
    return 0;
}
//布隆过滤器定义一个bitmap,和一个存哈希函数指针的数组，
//init   bitmapinit，数组中函数指针指向相应函数
//insert 要插入的数经过数组中函数计算在%bitMAXSIZE插入bitmap
//查询   要查询的数经过数组中的每个函数计算在%bitMAXSIZE在
//bitmaptest()检查

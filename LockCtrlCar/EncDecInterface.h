#ifndef   __ENCDECINTERFACE_H__
#define   __ENCDECINTERFACE_H__

#include <string.h>
#include <stdio.h>

#define ENCDATAMAXSIZE       (15)

//typedef unsigned int (QueueElemType)[ENCDATAMAXSIZE]; //frist Index  data lenght

typedef struct 
{
    unsigned char data[ENCDATAMAXSIZE];
    unsigned int datalen;
}QueueElemType;



typedef int (*EncDataFunc)(QueueElemType *inData,QueueElemType *outData,void *Ref,int Reflen);
#endif
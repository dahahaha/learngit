#ifndef   __ENCDECINTERFACE_H__
#define   __ENCDECINTERFACE_H__


#define ENCDATAMAXSIZE       (15)

typedef unsigned int (QueueElemType)[ENCDATAMAXSIZE]; //frist Index  data lenght

typedef int (*EncDataFunc)(QueueElemType *inData,QueueElemType *outData,void *Ref,int Reflen);
#endif
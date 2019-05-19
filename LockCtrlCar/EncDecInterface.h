#ifndef   __ENCDECINTERFACE_H__
#define   __ENCDECINTERFACE_H__


typedef int (*EncDataFunc)(unsigned int *inData,int inDataLen,\
                           unsigned int *outData,int *outDataLen,\
                           void *Ref,int Reflen
                           );
#endif
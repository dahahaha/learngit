#ifndef   __TRANSMITENCDATA_H__
#define   __TRANSMITENCDATA_H__

#include "MD5.h"
#include "RollingCode.h"
#include "EncDecInterface.h"


/* Authoritarian Data*/

#define FIFOQUEUEMAXSIZE     (10)

typedef enum
{
    FIFO_OK = 0,
    FIFO_NOT_OK,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_DEFAULT
  
}FIFOStatus;

typedef struct 
{
    QueueElemType Data[FIFOQUEUEMAXSIZE];
    int front;
    int rear;
}FIFO_QUEUE;


extern FIFOStatus InitFIFO(FIFO_QUEUE *QUEUE_FIFO);
extern int FIFOLENGTH(FIFO_QUEUE QUEUE_FIFO);
extern FIFOStatus EnFIFO(FIFO_QUEUE *QUEUE_FIFO,QueueElemType ElemData);
extern FIFOStatus DeFIFO(FIFO_QUEUE *QUEUE_FIFO,QueueElemType *ElemData);


#endif
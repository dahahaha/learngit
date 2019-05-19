#include "TransmitEncData.h"
#include "EncDecInterface.h"

FIFOStatus InitFIFO(FIFO_QUEUE *QUEUE_FIFO)
{
    QUEUE_FIFO->front=QUEUE_FIFO->rear=0;
    return FIFO_OK;    
}

int FIFOLENGTH(FIFO_QUEUE QUEUE_FIFO)
{
    return (QUEUE_FIFO.rear-QUEUE_FIFO.front+FIFOQUEUEMAXSIZE)%FIFOQUEUEMAXSIZE;
}

FIFOStatus EnFIFO(FIFO_QUEUE *QUEUE_FIFO,QueueElemType ElemData)
{
    int tempdatalen;

    if((QUEUE_FIFO->rear+1)%FIFOQUEUEMAXSIZE ==QUEUE_FIFO->front)
        return FIFO_FULL;

    /*data length*/
    tempdatalen = ElemData[0];
    
    /*data copy*/
    memcpy(QUEUE_FIFO->Data[QUEUE_FIFO->rear],ElemData[1],tempdatalen);

    QUEUE_FIFO->rear = (QUEUE_FIFO->rear+1)%FIFOQUEUEMAXSIZE;

    return FIFO_OK;
    
}

FIFOStatus DeFIFO(FIFO_QUEUE *QUEUE_FIFO,QueueElemType *ElemData)
{
    if( QUEUE_FIFO->front == QUEUE_FIFO->rear)
        return FIFO_EMPTY;
    /*data copy*/
    memcpy(ElemData[0],QUEUE_FIFO->Data[QUEUE_FIFO->front],QUEUE_FIFO->Data[QUEUE_FIFO->front][0]);
    QUEUE_FIFO->front = (QUEUE_FIFO->front+1)%FIFOQUEUEMAXSIZE;

    return FIFO_OK;
    
}

int Data_Key(EncDataFunc EncFunc,QueueElemType* InData,\
             QueueElemType* OutData ,void *Ref,int RefLen)
{
    int rv;

    if( NULL != EncFunc)
    {
        rv = EncFunc(InData,OutData,NULL,0);
    }

    return rv;
}
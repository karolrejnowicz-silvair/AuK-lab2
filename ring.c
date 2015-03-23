/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "ring.h"
#include  <string.h>
//#include "core.h"
#include <stdio.h>
#include <stdlib.h>


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize) 
{
    assert(ringBuffer);
    assert(dataBuffer);
    assert(dataBufferSize > 0);
    
    if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {
        malloc(dataBufferSize);
        ringBuffer->capacity=dataBufferSize;
        ringBuffer->head = 0;
        ringBuffer->tail=0;
        ringBuffer->full=0;
				ringBuffer->end = dataBufferSize;
				ringBuffer->size = 0;
        
        return true;
    }
    
    return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
    assert(ringBuffer);
    
    if (ringBuffer) {
            ringBuffer->head=0;
            ringBuffer->tail=0;
            ringBuffer->full=0;
            ringBuffer->size=0;
        
            return true;
        }
    return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
  assert(ringBuffer);    
    if (0==ringBuffer->size)
        return true;
    else
        return false;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
    assert(ringBuffer);
    
        return ringBuffer->size;
    
}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
    assert(ringBuffer);
    
    if (ringBuffer) {
        return ringBuffer->capacity;
    }
    return 0;    
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
    assert(ringBuffer);
    
    if (ringBuffer->head == ringBuffer->tail && ringBuffer->full==1) {
			//ringBuffer->capacity = ringBuffer->size;	
			return false;
		}
		else
		{
        ringBuffer->buffer[ringBuffer->head] = c;
				ringBuffer->head++;
        ringBuffer->size++;
        
				
				if(ringBuffer->head >= ringBuffer->end)
				{ // end of ring buffer
					ringBuffer->head = 0;
				}
				
				if(ringBuffer->head == ringBuffer->tail)
				{ //ring buffer is full, can't add any more data
					ringBuffer->full = 1;
				}
			
        return true;
        }
		}   

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
    assert(ringBuffer);
    assert(c);
    
  if ((ringBuffer) && (c)) {
        if(ringBuffer->head == ringBuffer->tail && !(ringBuffer->full))
            return false;
				else{
        *c = ringBuffer->buffer[ringBuffer->tail];
        ringBuffer->tail++;
					if(ringBuffer->tail >= ringBuffer->end)
					{
						ringBuffer->tail = 0;
					}
				ringBuffer->full = 0;
				ringBuffer->size--;
        return true;   
    }
	}
}

int RingBuffer_GetHead(RingBuffer *ringBuffer)
{
	
	return ringBuffer->head;
	
}

int RingBuffer_GetTail(RingBuffer *ringBuffer)
{
	
	return ringBuffer->tail;
	
}

int RingBuffer_GetEnd(RingBuffer *ringBuffer)
{
	
	return ringBuffer->end;
	
}
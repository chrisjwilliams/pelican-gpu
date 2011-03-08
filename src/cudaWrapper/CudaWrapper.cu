// This files provides a wrapper for all CUDA calls
#include "cutil_inline.h"
#include "CudaWrapper.h"

// =================== CUDA-related function implementation ===========================

// Memory allocation calls
extern "C" void allocateGpuMemory(void **buffer, unsigned long size)
{    cutilSafeCall( cudaMalloc(buffer, size));    }

extern "C" void freeGpuMemory(void *buffer)
{    cutilSafeCall(cudaFree(buffer));    }

// Memory management calls
extern "C" void copyData(void *destination, void *source, unsigned long size, CopyDirection direction)
{    
    switch(direction) {
        case 1: 
        {
            cutilSafeCall( cudaMemcpy(destination, source, size, cudaMemcpyHostToDevice) );              
            break;
        }
        case 2:
        {
            cutilSafeCall( cudaMemcpy(destination, source, size, cudaMemcpyDeviceToHost) );              
            break;
        }
        case 3:
        {
            cutilSafeCall( cudaMemcpy(destination, source, size, cudaMemcpyDeviceToDevice) );              
            break;
        }
    }
}

extern "C" void setGpuBuffer(void *buffer, char value, unsigned long size)
{    cudaMemset(buffer, value, size);    }

extern "C" void copyDataToSymbol(void *symbol, void *source, unsigned long size)
{    cutilSafeCall( cudaMemcpyToSymbol(symbol, source, size) );    }

// GPU management calls
extern "C"  unsigned getDeviceInformation(DeviceInfo** devices)
{    return NULL;    }

extern "C" void setDevice(unsigned deviceId)
{    cutilSafeCall( cudaSetDevice(deviceId));    }

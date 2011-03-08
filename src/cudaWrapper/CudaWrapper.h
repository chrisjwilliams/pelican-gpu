#ifndef CUDA_WRAPPER_H
#define CUDA_WRAPPER_H

typedef enum
{
    HostToDevice = 1,
    DeviceToHost = 2,
    DeviceToDevice = 3
} CopyDirection;

typedef struct {

    // Device capabilities
    int multiprocessor_count;
    int constant_memory;
    int global_memory;
    int shared_memory;
    int register_count;
    int thread_count;
    int clock_rate;
    int device_id;

} DeviceInfo;

// =================== CUDA-related function declarations ===========================

// Memory allocation calls
extern "C" void allocateGpuMemory(void **buffer, unsigned long size);
extern "C" void freeGpuMemory(void *buffer);

// Data-copying calls
extern "C" void copyData(void *destination, void *source, unsigned long size, CopyDirection direction);
extern "C" void copyDataToSymbol(void *symbol, void *source, unsigned long size);

// GPU-management calls
extern "C" void setGpuMemory(void *buffer, char value, unsigned long size);
extern "C" unsigned getDeviceInformation(DeviceInfo** devices);
extern "C" void setDevice(unsigned deviceId);

#endif

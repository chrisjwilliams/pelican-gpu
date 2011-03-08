#include "AbstractCudaModule.h"
#include "CudaWrapper.h"

namespace pelican {
namespace gpu {

// Class constructor
AbstractCudaModule::AbstractCudaModule(const ConfigNode config)
    : AbstractModule(config)
{

}

// Execute method
void AbstractCudaModule::execute()
{
    // OpenMP magic
    
    #pragma omp parallel num_threads(_numDevices)
    {
        // Get thread number
        unsigned threadNum = omp_get_thread_num();
        
        // Associate thread with one GPU
        setDevice(threadNum);

        // Execute the kernel
        kernel(_numDevices, threadNum);       
    }
}

}
}

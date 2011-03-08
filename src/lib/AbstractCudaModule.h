#ifndef ABSTRACT_CUDA_MODULE_H
#define ABSTRACT_CUDA_MODULE_H

#include "pelican/modules/AbstractModule.h"
#include "pelican/utility/ConfigNode.h"

#include <omp.h>

namespace pelican {
namespace gpu {

class AbstractCudaPipeline;

class AbstractCudaModule: public AbstractModule {

    private:    
        friend class AbstractCudaPipeline;

    protected:
        // Kernel must be implemented by all subclasses and will contain the GPU code
        virtual void kernel(unsigned int numDevices, unsigned int deviceId) = 0;

        // Called by the subclass to process the kernel on all GPUs
        void execute();

    public:
        // Constructor
        AbstractCudaModule(const ConfigNode config);

        // Queries the module for memory requirements
        // Note that at least two buffer are required, the input and output buffers
        virtual QHash<QString, size_t > getMemoryRequirements(size_t memorySize) const = 0;

        // Total number of GPUs being used
        unsigned  _numDevices;
};
}
}

#endif


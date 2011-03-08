#ifndef ABSTRACT_CUDA_PIPELINE_H
#define ABSTRACT_CUDA_PIPELINE_H

// Pelican includes
#include "pelican/core/AbstractPipeline.h"

// Pelican-gpu includes
#include "AbstractCudaModule.h"
#include "CudaDataBlob.h"

// QT includes
#include <QThread>
#include <QHash>

namespace pelican {
namespace gpu {

class AbstractCudaPipeline: public AbstractPipeline {

    public:
        // Class constructor
        AbstractCudaPipeline();

        // Getter for global device memory
        size_t getGlobalDeviceMemory() { return _globalDeviceMemory; }

    private:
        // Calculate CUDA memory requirements
        void calculateCudaMemoryRequirements();

    private:
        // Maximum amount of global device memory usable by CUDA modules
        size_t                       _globalDeviceMemory;

};
}
}

#endif
;

#include "AbstractCudaPipeline.h"
#include "CudaWrapper.h"

#include <QHashIterator>

#include <typeinfo>

namespace pelican {
namespace gpu {

/**
 * @details
 * AbstractCudaPipeline constructor.
 */
AbstractCudaPipeline::AbstractCudaPipeline()
    : AbstractPipeline()
{
    DeviceInfo** devices = NULL;
    unsigned usableDevices = 0;

    // Query system for GPU devices
    unsigned numDevices  = getDeviceInformation(devices);

    // Loop over devices to examine properties and create CudaGpuThreads
    for(unsigned i = 0; i < numDevices; i++)
    {
        // TODO: Initialise Pipeline properties for each device

    }
}

/**
 * @details
 * Query all CUDA modules for their memory requirements, then calaculte maximum
 * buffer sizes and set these sizes in the appropriate object
 * NOTE: Currently assumes that extra buffers have static sizes, and that 
 *       the input and output buffers sizes for the same module can be 
 *       scaled down proportionally with each other
 */
void AbstractCudaPipeline::calculateCudaMemoryRequirements()
{
//    QHash<QString, size_t> reqs;

//    // Loop over all modules
//    foreach(AbstractModule *module, _modules)
//    {
//        // Check if module is an instance of AbstractCudaModule
//        if (dynamic_cast<AbstractCudaModule *>(module)) {
//            // Not a CUDA module
//        }

//        // Dealing with a CUDA module
//        AbstractCudaModule *cudaModule = dynamic_cast<AbstractCudaModule *>(module);
//        reqs = cudaModule -> getMemoryRequirements(_globalDeviceMemory);

//        // Check if input and output buffer sizes are specified
//        if (reqs.contains(QString("input")) && reqs.contains(QString("output"))) {
//            throw QString("Input and output buffer sizes must be in memory requirements for module %1")
//                  .arg(QString(typeid(*cudaModule).name()));
//        }
//    }
}

}
}

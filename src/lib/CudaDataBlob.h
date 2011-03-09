#ifndef CUDA_DATABLOB_H
#define CUDA_DATABLOB_H

#include "pelican/data/DataBlob.h"

namespace pelican {
namespace gpu {

class CudaDataBlob: public DataBlob {

    public:
        // Returns pointer to main GPU input buffer
        void *getInputBuffer() { return inputBuffer; }

        // Sets pointer to main GPU input buffer
        void setInputBuffer(void *buffer) {inputBuffer = buffer; }

        // Returns pointer to main GPU output buffer
        void *getOutputBuffer() { return outputBuffer; }

        // Sets pointer to main GPU output buffer
        void setOutputBuffer(void *buffer) {outputBuffer = buffer; }

    private:
        // Pointer to main input and output buffers of GPU
        void *inputBuffer, *outputBuffer;

};
} // naemspace gpu
} // naemspace pelican

#endif


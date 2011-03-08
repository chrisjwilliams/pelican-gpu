include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Cuda source files
set(cuda_SRC
    CudaWrapper.cu
)

CUDA_ADD_LIBRARY(cudaLib STATIC ${cuda_SRC})

include_directories(${CUDA_INCLUDE_DIRS})

target_link_libraries(cudaLib
    ${CUDA_LIBRARIES}
)

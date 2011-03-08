include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# C++ source files
set(pelican_gpu_SRC
    src/AbstractCudaPipeline.cpp
    src/AbstractCudaModule.cpp
    src/CudaDataBlob.cpp
)

add_library(pelicanGpuLib STATIC ${pelican_gpu_SRC})

target_link_libraries(pelicanGpuLib
    ${QT_QTCORE_LIBRARY}
    ${PELICAN_LIBRARIES}
    cudaLib
)


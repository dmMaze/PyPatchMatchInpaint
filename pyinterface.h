#pragma once
#ifdef DLL_API  
#else  
#define DLL_API __declspec(dllexport)  
#endif 

#include <opencv2/core.hpp>
#include <cstdlib>
#include <cstdio>
#include <cstring>

extern "C" {

    DLL_API struct PM_shape_t {
        int width, height, channels;
    };

    DLL_API enum PM_dtype_e {
        PM_UINT8,
        PM_INT8,
        PM_UINT16,
        PM_INT16,
        PM_INT32,
        PM_FLOAT32,
        PM_FLOAT64,
    };

    DLL_API struct PM_mat_t {
        void* data_ptr;
        PM_shape_t shape;
        int dtype;
    };

    DLL_API void PM_set_random_seed(unsigned int seed);
    DLL_API void PM_set_verbose(int value);

    DLL_API void PM_free_pymat(PM_mat_t pymat);
    DLL_API PM_mat_t PM_inpaint(PM_mat_t image, PM_mat_t mask, int patch_size);
    DLL_API PM_mat_t PM_inpaint_regularity(PM_mat_t image, PM_mat_t mask, PM_mat_t ijmap, int patch_size, float guide_weight);
    DLL_API PM_mat_t PM_inpaint2(PM_mat_t image, PM_mat_t mask, PM_mat_t global_mask, int patch_size);
    DLL_API PM_mat_t PM_inpaint2_regularity(PM_mat_t image, PM_mat_t mask, PM_mat_t global_mask, PM_mat_t ijmap, int patch_size, float guide_weight);

} /*  extern "C" */



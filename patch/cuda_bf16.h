#ifndef CUDA_BF16_H
#define CUDA_BF16_H
#define CUDA_R_16BF CUDA_R_16F
#include <cuda_fp16.h>

// Define nv_bfloat16 as half
typedef half nv_bfloat16;
struct nv_bfloat162 {
	nv_bfloat16 x;
    	nv_bfloat16 y;
	__host__ __device__ operator float2() const { return make_float2(0.0f, 0.0f); }
	};

#endif // CUDA_BF16_H

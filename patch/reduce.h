#ifndef COOPERATIVE_GROUPS_REDUCE_H
#define COOPERATIVE_GROUPS_REDUCE_H

#include <cooperative_groups.h>

namespace cooperative_groups {
    // Operadores matemáticos que Llama.cpp intentará llamar
    template <typename T>
    struct plus {
        __device__ T operator()(const T& a, const T& b) const { return a + b; }
    };

    template <typename T>
    struct greater {
        __device__ T operator()(const T& a, const T& b) const { return a > b ? a : b; }
    };

    template <typename T>
    struct less {
        __device__ T operator()(const T& a, const T& b) const { return a < b ? a : b; }
    };

    // El motor de reducción simulado para tu hardware
    template <unsigned int Size, typename T, typename Op>
    __device__ T reduce(thread_block_tile<Size> g, T val, Op op) {
        #pragma unroll
        for (int i = Size / 2; i > 0; i /= 2) {
            // Intercambio de memoria hiper-rápido a nivel de warp
            val = op(val, __shfl_down_sync(0xffffffff, val, i));
        }
        return val;
    }
}

#endif // COOPERATIVE_GROUPS_REDUCE_H

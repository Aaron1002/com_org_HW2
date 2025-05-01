// Vector: 一次處理多個元素
"Loop_improve:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[arr_size], x0, Exit_improve\n\t"

    //"flw f0, 0(%[h])\n\t" // Load h[i] into f0
    //"flw f1, 0(%[x])\n\t" // Load x[i] into f1
        "addi %[others_cnt], %[others_cnt], 1\n\t"
        "addi %[lw_cnt], %[lw_cnt], 2\n\t"
    "vsetvli t0, %[arr_size], e32, m1, ta, mu\n\t" // t0 ← vl （≤ arr_size, 依 e32,m1 決定): 抓 VLEN/SEW 個元素
    "vle32.v v0, (%[h])\n\t" // Load h[i] into vector register v0
    "vle32.v v1, (%[x])\n\t" // Load x[i] into vector register v1

        "addi %[fmul_cnt], %[fmul_cnt], 1\n\t"
        "addi %[fadd_cnt], %[fadd_cnt], 1\n\t"
    //"fmul.s f0, f0, f1\n\t" // f0 = h[i] * x[i] 
    //"fadd.s f0, f0, %[id]\n\t" // f0 = h[i] + x[i] + id
    "vfmul.vv v2, v0, v1\n\t" // Multiply vector registers v0 and v1
    "vfadd.vf v2, v2, %[id]\n\t" // Add id to the result in vector register v2

        "addi %[sw_cnt], %[sw_cnt], 1\n\t"
    //"fsw f0, 0(%[y])\n\t" // f0 = h[i] + x[i] + id  
    "vse32.v v2, (%[y])\n\t" // Store the result in y[i]

        "addi %[sub_cnt], %[sub_cnt], 1\n\t"
    "sub %[arr_size], %[arr_size], t0\n\t" // Decrement arr_size

        "addi %[add_cnt], %[add_cnt], 3\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "slli t0, t0, 2\n\t" 
    "addi %[h], %[h], t0\n\t" // Increment h pointer
    "addi %[x], %[x], t0\n\t" // Increment x pointer
    "addi %[y], %[y], t0\n\t" // Increment y pointer
    

        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Loop_improve\n\t" // Jump back to Loop_improve

"Exit_improve:\n\t"    
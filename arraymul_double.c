"Loop_double:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[arr_size], x0, Exit_double\n\t" // Check if arr_size is 0

        "addi %[dlw_cnt], %[dlw_cnt], 2\n\t"
    "fld f0, 0(%[h])\n\t" // Load h[i] into f0
    "fld f1, 0(%[x])\n\t" // Load x[i] into f1

        "addi %[dmul_cnt], %[dmul_cnt], 2\n\t"
    "fmul.d f2, f0, f1\n\t" // Multiply h[i] and x[i], store in f2
    "fmul.d %[result], f2, %[result]\n\t" // Multiply result with f2 (h * x)

        "addi %[add_cnt], %[add_cnt], 3\n\t"
    "addi %[h], %[h], 8\n\t" // Increment h pointer by 8 bytes (size of double)
    "addi %[x], %[x], 8\n\t" // Increment x pointer by 8 bytes (size of double)
    "addi %[arr_size], %[arr_size], -1\n\t" // Decrement arr_size
    
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Loop_double\n\t" // return to Loop_double

"Exit_double:\n\t"
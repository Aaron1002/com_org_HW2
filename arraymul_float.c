"Loop_float:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[arr_size], x0, Exit_float\n\t" // Check if arr_size is 0

        "addi %[flw_cnt], %[flw_cnt], 2\n\t"
    "flw f0, 0(%[h])\n\t" // Load h[i] into f0
    "flw f1, 0(%[x])\n\t" // Load x[i] into f1

        "addi %[fmul_cnt], %[fmul_cnt], 2\n\t"
    "fmul.s f2, f0, f1\n\t" // Multiply h[i] and x[i], store in f2
    "fmul.s %[result], f2, %[result]\n\t" // Multiply result with f2 (h * x)

        "addi %[add_cnt], %[add_cnt], 3\n\t"
    "addi %[h], %[h], 4\n\t" // Increment h pointer by 4 bytes (size of float)
    "addi %[x], %[x], 4\n\t" // Increment x pointer by 4 bytes (size of float)
    "addi %[arr_size], %[arr_size], -1\n\t" // Decrement arr_size
    
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Loop_float\n\t" // return to Loop_float

"Exit_float:\n\t"
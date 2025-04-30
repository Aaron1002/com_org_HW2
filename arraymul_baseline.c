"Loop_arrmul:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[arr_size], x0, Exit_arrmul\n\t"

        "addi %[flw_cnt], %[flw_cnt], 2\n\t"
    "flw f0, 0(%[h])\n\t" // Load h[i] into f0
    "flw f1, 0(%[x])\n\t" // Load x[i] into f1 

        "addi %[fmul_cnt], %[fmul_cnt], 1\n\t"
        "addi %[fadd_cnt], %[fadd_cnt], 1\n\t"
    "fmul.s f0, f0, f1\n\t" // f0 = h[i] * x[i] 
    "fadd.s f0, f0, %[id]\n\t" // f0 = h[i] + x[i] + id

        "addi %[fsw_cnt], %[fsw_cnt], 1\n\t"
    "fsw f0, 0(%[y])\n\t" // f0 = h[i] + x[i] + id  

        "addi %[add_cnt], %[add_cnt], 4\n\t"
    "addi %[h], %[h], 4\n\t" // Increment h pointer
    "addi %[x], %[x], 4\n\t" // Increment x pointer
    "addi %[y], %[y], 4\n\t" // Increment y pointer
    "addi %[arr_size], %[arr_size], -1\n\t" // Decrement arr_size

        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Loop_arrmul\n\t" // Jump back to Loop_arrmul

"Exit_arrmul:\n\t"    
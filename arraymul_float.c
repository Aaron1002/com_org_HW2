"Loop_float:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[arr_size], x0, Exit_float\n\t" 

        "addi %[flw_cnt], %[flw_cnt], 2\n\t"
    "flw f0, 0(%[h])\n\t" 
    "flw f1, 0(%[x])\n\t" 

        "addi %[fmul_cnt], %[fmul_cnt], 2\n\t"
    "fmul.s f2, f0, f1\n\t" 
    "fmul.s %[result], f2, %[result]\n\t" 

        "addi %[add_cnt], %[add_cnt], 3\n\t"
    "addi %[h], %[h], 4\n\t" 
    "addi %[x], %[x], 4\n\t" 
    "addi %[arr_size], %[arr_size], -1\n\t" 

        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Loop_float\n\t" 

"Exit_float:\n\t"
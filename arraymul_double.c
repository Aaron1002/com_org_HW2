"Loop_double:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"    
    "beq %[arr_size], x0, Exit_double\n\t" 

        "addi %[dlw_cnt], %[dlw_cnt], 2\n\t"
    "fld f0, 0(%[h])\n\t" 
    "fld f1, 0(%[x])\n\t" 

        "addi %[dmul_cnt], %[dmul_cnt], 2\n\t"
    "fmul.d f2, f0, f1\n\t" 
    "fmul.d %[result], f2, %[result]\n\t" 

        "addi %[add_cnt], %[add_cnt], 3\n\t"
    "addi %[h], %[h], 8\n\t" 
    "addi %[x], %[x], 8\n\t" 
    "addi %[arr_size], %[arr_size], -1\n\t" 
    
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Loop_double\n\t" 

"Exit_double:\n\t"
"Loop_improve:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[arr_size], x0, Exit_improve\n\t"

        "addi %[others_cnt], %[others_cnt], 1\n\t"
        "addi %[lw_cnt], %[lw_cnt], 2\n\t"
    "vsetvli t0, %[arr_size], e32, m1, ta, mu\n\t" 
    "vle32.v v0, (%[h])\n\t" 
    "vle32.v v1, (%[x])\n\t"

        "addi %[fmul_cnt], %[fmul_cnt], 1\n\t"
        "addi %[fadd_cnt], %[fadd_cnt], 1\n\t"
    "vfmul.vv v2, v0, v1\n\t" 
    "vfadd.vf v2, v2, %[id]\n\t" 

        "addi %[sw_cnt], %[sw_cnt], 1\n\t"
    "vse32.v v2, (%[y])\n\t" 

        "addi %[sub_cnt], %[sub_cnt], 1\n\t"
    "sub %[arr_size], %[arr_size], t0\n\t"
        
        "addi %[add_cnt], %[add_cnt], 3\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "slli t0, t0, 2\n\t"    
    "add %[h], %[h], t0\n\t" 
    "add %[x], %[x], t0\n\t"
    "add %[y], %[y], t0\n\t" 
     

        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Loop_improve\n\t" 

"Exit_improve:\n\t"    
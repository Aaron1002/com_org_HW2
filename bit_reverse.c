    "addi %[add_cnt], %[add_cnt], 3\n\t"
"addi t0, x0, 1\n\t" 
"add t1, x0, x0\n\t" 
"add t2, x0, x0\n\t" 

"Loop_bit:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[m], x0, Exit_bit\n\t" 
    
        "addi %[others_cnt], %[others_cnt], 3\n\t"
    "slli t1, t1, 1\n\t" 

    "andi t2, %[b], 1\n\t" 
    "bne t2, t0, Update_b\n\t" 

        "addi %[others_cnt], %[others_cnt], 2\n\t"
    "ori t1, t1, 1\n\t" 

    "jal x0, Update_b\n\t" 

"Update_b:\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
        "addi %[others_cnt], %[others_cnt], 2\n\t"
    "srli %[b], %[b], 1\n\t" 
    "addi %[m], %[m], -1\n\t" 
    "jal x0, Loop_bit\n\t" 

"Exit_bit:\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "add %[b], t1, x0\n\t"  
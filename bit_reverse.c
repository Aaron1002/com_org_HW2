    "addi %[add_cnt], %[add_cnt], 3\n\t"
"addi t0, x0, 1\n\t" // fix t0 to 1 (for bne)
"add t1, x0, x0\n\t" // initiallize t1 (temp_ans)
"add t2, x0, x0\n\t" // initiallize t2 (temp b)

"Loop_bit:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[m], x0, Exit_bit\n\t" // If m == iter, exit loop
    
        "addi %[others_cnt], %[others_cnt], 3\n\t"
    "slli t1, t1, 1\n\t" // ans << 1 (shift left 1 bit)

    "andi t2, %[b], 1\n\t" // t2 = b & 1 (get the last bit of b)
    "bne t2, t0, Update_b\n\t" // If t2 != 1, go to update_b 

        "addi %[others_cnt], %[others_cnt], 2\n\t"
    "ori t1, t1, 1\n\t" // ans = ans | 1 (ans + 1)

    "jal x0, Update_b\n\t" // Jump to update_b

"Update_b:\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
        "addi %[others_cnt], %[others_cnt], 2\n\t"
    "srli %[b], %[b], 1\n\t" // b >> 1 (shift right 1 bit)
    "addi %[m], %[m], -1\n\t" // Increase counter by 1
    "jal x0, Loop_bit\n\t" // Jump to the beginning of the loop

"Exit_bit:\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "add %[b], t1, x0\n\t" // b = ans    
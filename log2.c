    "addi %[add_cnt], %[add_cnt], 2\n\t"
"addi t0, x0, 1\n\t"    // fix t0 to 1 (for log's end condition)
"add t1, %[N], x0\n\t"    // fix t1 to N

"Loop_log:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq %[N], t0, Exit_log\n\t" // If N == 1(t1), exit loop
        "addi %[others_cnt], %[others_cnt], 2\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "addi %[log], %[log], 1\n\t" // Increment log
    "srli %[N], %[N], 1\n\t" // divide N by 2
    "jal x0, Loop_log\n\t" // Jump to the beginning of the loop

"Exit_log:\n\t"    
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "add %[N], t1, x0\n\t" // Restore N to its original value
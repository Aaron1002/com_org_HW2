            "addi t0, x0, 1\n\t"
            "addi %[add_cnt], %[add_cnt], 1\n\t"

"Loop:\n\t" "addi %[others_cnt], %[others_cnt], 1\n\t"
            "beq %[N], t0, Exit\n\t"

            "srli %[N], %[N], 2\n\t"
            "addi %[others_cnt], %[others_cnt], 1\n\t"

            "addi %[log], %[log], 1\n\t"
            "addi %[add_cnt], %[add_cnt], 1\n\t"

            "addi %[others_cnt], %[others_cnt], 1\n\t"
            "jal x0, Loop\n\t"

"Exit:\n\t"            
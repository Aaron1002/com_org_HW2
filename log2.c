"Loop:\n\t" "addi t0, x0, 1\n\t"
            "beq %[N], t0, Exit\n\t"
            "srli %[N], %[N], 2\n\t"
            "addi %[log], %[log], 1\n\t"
            "jal x0, Loop\n\t"

"Exit:\n\t"            
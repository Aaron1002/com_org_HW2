            "add %[pi], x0, x0\n\t"
            "addi t2, x0, 0\n\t"
            "addi t1, x0, 1\n\t"
            "fcvt.s.w f2, t1\n\t"

"Loop:\n\t" "addi %[N], %[N], -1\n\t"
            "blt %[N], x0, Exit\n\t"
            "addi t2, t2, 1\n\t" // t2 for N counter
            
            "fcvt.s.w f1, t1\n\t"
            "fdiv.s f1, f1, f2\n\t"
            
            "addi t3, x0, 2\n\t"
            "rem t3, t2, t3"
            "beq t3, x0, Even\n\t"
            "jal x0, Odd\n\t"

"Even:\n\t" "fsub.s %[pi], %[pi], f1\n\t"
            "jal x0, f2_up\n\t"

"Odd:\n\t"  "fadd.s %[pi], %[pi], f1\n\t"
            "jal x0, f2_up\n\t"

"f2_up:\n\t""addi t3, t1, 1\n\t"
            "fcvt.s.w f1, t3\n\t"
            "fadd.s f2, f2, f1\n\t"
            "jal x0, Loop\n\t"

"Exit:\n\t"            
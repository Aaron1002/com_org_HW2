    "addi %[add_cnt], %[add_cnt], 4\n\t"
"addi t1, x0, 0\n\t" // initiallize t1 (fix to 0 for iteration)
"addi t2, x0, 1\n\t" // initiallize t2 (after inintialization, t2 is for counter % 2)
"addi t3, x0, 1\n\t" // initiallize t3 (after inintialization, t3 is for rest f1)
"addi t4, x0, 2\n\t" // initiallize t4 (fix to 2 for denominator) 

    "addi %[others_cnt], %[others_cnt], 2\n\t"
"fcvt.s.wu f1, t2\n\t" // convert t2 to float (f1 initial to 1.0)
"fcvt.s.wu f2, t3\n\t" // convert t3 to float (f2 initial to 1.0)

"Loop_pi:\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "beq t1, %[N], Exit_pi\n\t" // If counter(t1) == iter, exit loop
        "addi %[others_cnt], %[others_cnt], 3\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
        "addi %[fdiv_cnt], %[fdiv_cnt], 1\n\t"
    "fcvt.s.wu f1, t3\n\t" // reset f1 to 1.0
    "addi t1, t1, 1\n\t" // Increase counter by 1
    
    "fdiv.s f1, f1, f2\n\t" // f1 = f1 / f2
    
    "rem t2, t1, t4\n\t" // t2 = counter % 2
    "beq t2, x0, Even_pi\n\t" // If counter % 2 == 0, go to Even_pi (counter is even)
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "jal x0, Odd_pi\n\t" // Else, go to Odd_pi (counter is odd)

"Even_pi:\n\t"
        "addi %[fsub_cnt], %[fsub_cnt], 1\n\t"
        "addi %[fadd_cnt], %[fadd_cnt], 1\n\t"
        "addi %[others_cnt], %[others_cnt], 2\n\t"
    "fsub.s %[pi], %[pi], f1\n\t" // pi = pi - f1
    "fcvt.s.wu f1, t4\n\t" // convert t4 to float (for update f2) 
    "fadd.s f2, f2, f1\n\t" // f2 = f2 + 2.0 (f2 is updated to next denominator)
    "jal x0, Loop_pi\n\t" // Jump to the beginning of the loop

"Odd_pi:\n\t"
        "addi %[fadd_cnt], %[fadd_cnt], 2\n\t"
        "addi %[others_cnt], %[others_cnt], 2\n\t"
    "fadd.s %[pi], %[pi], f1\n\t" // pi = pi + f1
    "fcvt.s.wu f1, t4\n\t" // convert t4 to float (for update f2) 
    "fadd.s f2, f2, f1\n\t" // f2 = f2 + 2.0 (f2 is updated to next denominator)
    "jal x0, Loop_pi\n\t" // Jump to the beginning of the loop

"Exit_pi:\n\t"
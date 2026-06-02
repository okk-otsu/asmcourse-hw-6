section .data

    ; Constants for f1(x) = 0.6 * x + 3
    f1_06 dq 0.6
    f1_3  dq 3.0

    ; Constants for f2(x) = (x - 2)^3 - 1
    f2_2  dq 2.0
    f2_1  dq 1.0

    ; Constant for f3(x) = 3 / x
    f3_3  dq 3.0

section .text
global f1
global f2
global f3

; Compute f1(x) = 0.6 * x + 3
f1:
    push ebp
    mov  ebp, esp

    fld  qword [ebp + 8]    
    fmul qword [f1_06]      
    fadd qword [f1_3]       

    mov  esp, ebp
    pop  ebp
    ret


; Compute f2(x) = (x - 2)^3 - 1
f2:
    push ebp
    mov  ebp, esp

    fld  qword [ebp + 8]      
    fsub qword [f2_2]         

    fld   st0                  
    fmul  st1, st0          
    fmulp st1, st0

    fsub qword [f2_1]        

    mov  esp, ebp
    pop  ebp
    ret


; Compute f3(x) = 3 / x
f3:
    push ebp
    mov  ebp, esp

    fld  qword [f3_3]         
    fdiv qword [ebp + 8]      

    mov  esp, ebp
    pop  ebp
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
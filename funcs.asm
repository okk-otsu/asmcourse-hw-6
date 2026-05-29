section .data
    f1_06 dq 0.6
    f1_3  dq 3.0

    f2_2  dq 2.0
    f2_1  dq 1.0

    f3_3  dq 3.0

section .text
global f1
global f2
global f3

f1:
    push ebp
    mov  ebp, esp

    fld  qword [ebp + 8]    
    fmul qword [f1_06]      
    fadd qword [f1_3]       

    mov  esp, ebp
    pop  ebp
    ret


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


f3:
    push ebp
    mov  ebp, esp

    fld  qword [f3_3]         
    fdiv qword [ebp + 8]      

    mov  esp, ebp
    pop  ebp
    ret

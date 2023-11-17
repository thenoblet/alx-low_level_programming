section .text
global main

main:
    ; Print "Hello, Holberton" to standard output
    mov rax, 1        ; syscall: write
    mov rdi, 1        ; file descriptor: STDOUT
    mov rsi, msg      ; pointer to the message string
    mov rdx, msglen   ; length of the message
    syscall

    ; Exit the program
    mov rax, 60       ; syscall: exit
    xor rdi, rdi      ; status: 0
    syscall

section .rodata
    ; Define a null-terminated string containing the message
    msg: db "Hello, Holberton", 10   ; 10 represents newline character
    msglen: equ $ - msg


BITS 64

SECTION .text

GLOBAL strstr

strstr:
        PUSH    RBP
        MOV     RBP, RSP

        MOV     RDX, RDI
        XOR     RCX, RCX

loop:
        MOV     R9B, BYTE [RDX]

        CMP     BYTE [RDX], 0
        JE      not_found

        MOV     R8, RSI
        JMP     loop_string

        INC     RDX
        JMP     loop

loop_string:
        CMP     R8, 0
        JE      loop

        CMP     BYTE [R8], R9B
        XOR     RCX, RCX
        JE      find_string

        INC     R8
        JMP     loop_string

find_string:
        INC     RCX

        MOV     R9B, BYTE [RDX + RCX]
        MOV     R10B, BYTE [R8 + RCX]

        CMP     R10B, 0
        JE      found

        CMP     R10B, R9B
        JNE     loop_string

        JMP     find_string

found:
        MOV     RAX, RDX

not_found:
        MOV     RAX, 0

end:
        MOV     RSP, RBP
        POP     RBP

        RET

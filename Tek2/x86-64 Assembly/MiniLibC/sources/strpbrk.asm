BITS 64

SECTION .text

GLOBAL strpbrk

strpbrk:
        PUSH    RBP
        MOV     RBP, RSP

        MOV     RDX, RDI

loop:
        MOV     AL, BYTE [RDX]

        CMP     BYTE [RDX], 0
        MOV     RAX, 0
        JE      end

        MOV     R8, RSI
        JMP     loop_string

        INC     RDX
        JMP     loop

loop_string:
        CMP     R8, 0
        JE      loop

        CMP     AL, BYTE [R8]
        MOV     RAX, RDX
        JE      end

        INC     R8
        JMP     loop_string

end:
        MOV     RSP, RBP
        POP     RBP

        RET

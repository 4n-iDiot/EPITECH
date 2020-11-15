BITS 64

SECTION .text

GLOBAL strcspn

strcspn:
        PUSH    RBP
        MOV     RBP, RSP

        XOR     RCX, RCX
        XOR     R8, R8
        XOR     R9B, R9B

loop:
        MOV     R9B, BYTE [RDI]

        CMP     R9B, 0
        JE      end

        MOV     R8, RSI
        JMP     loop_string

count:
        INC     RDI
        INC     RCX
        JMP     loop

loop_string:
        CMP     BYTE [R8], 0
        JE      count

        CMP     BYTE [R8], R9B
        JE      end

        INC     R8
        JMP     loop_string

end:
        MOV     RAX, RCX

        MOV     RSP, RBP
        POP     RBP

        RET

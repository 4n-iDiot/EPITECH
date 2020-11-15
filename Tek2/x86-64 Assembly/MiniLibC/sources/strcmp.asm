BITS 64

SECTION .text

GLOBAL strcmp

strcmp:
        PUSH    RBP
        MOV     RBP, RSP

loop:
        MOV     R8B, BYTE [RDI]
        MOV     R9B, BYTE [RSI]

        CMP     R8B, 0
        JE      end

        CMP     R9B, 0
        JE      end

        CMP     R8B, R9B
        JNE     end

        INC     RDI
        INC     RSI
        JMP     loop

end:
        SUB     R8B, R9B
        MOV     AL, R8B
        MOVSX     RAX, AL

        MOV     RSP, RBP
        POP     RBP

        RET

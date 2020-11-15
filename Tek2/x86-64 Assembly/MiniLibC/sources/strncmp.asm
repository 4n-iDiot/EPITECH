BITS 64

SECTION .text

GLOBAL strncmp

strncmp:
        PUSH    RBP
        MOV     RBP, RSP

        XOR     RCX, RCX

loop:
        CMP     RCX, RDX
        JE      end

        MOV     R8B, BYTE [RDI + RCX]
        MOV     R9B, BYTE [RSI + RCX]

        CMP     R8B, 0
        JE      end

        CMP     R9B, 0
        JE      end

        CMP     R8B, R9B
        JNE     end

        INC     RCX
        JMP     loop

end:
        SUB     R8B, R9B
        MOV     AL, R8B
        MOVSX     RAX, AL

        MOV     RSP, RBP
        POP     RBP

        RET

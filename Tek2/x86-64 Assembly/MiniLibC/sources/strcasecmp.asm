BITS 64

SECTION .text

GLOBAL strcasecmp

strcasecmp:
        PUSH    RBP
        MOV     RBP, RSP

loop:
        MOV     R8B, BYTE [RDI]
        MOV     R9B, BYTE [RSI]

        CMP     R8B, 0
        JE      end

        CMP     R9B, 0
        JE      end

        CMP     R8B, 90
        JL      check_r9b

        CMP     R8B, 122
        JL      to_lower_r8b

to_lower_r8b:
        SUB     R8B, 32
        JMP     check_r9b

to_lower_r9b:
        SUB     R9B, 32
        JMP     compare

check_r9b:
        CMP     R9B, 90
        JL      compare

        CMP     R9B, 122
        JL      to_lower_r9b

compare:
        CMP     R8B, R9B
        JNE     end

        INC     RDI
        INC     RSI
        JMP     loop

end:
        SUB     R8B, R9B
        MOVSX     RAX, R8B

        MOV     RSP, RBP
        POP     RBP

        RET

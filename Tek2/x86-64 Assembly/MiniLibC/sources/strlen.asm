BITS 64

SECTION .text

GLOBAL strlen

strlen:
        PUSH    RBP
        MOV     RBP, RSP

        XOR     RCX, RCX

loop:
        CMP     BYTE [RDI + RCX], 00
        JE      end
        INC     RCX
        JMP     loop

end:
        MOV     RAX, RCX

        MOV     RSP, RBP
        POP     RBP

        RET

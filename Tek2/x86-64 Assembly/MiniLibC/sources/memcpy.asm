BITS 64

SECTION .text

GLOBAL memcpy

memcpy:
        PUSH    RBP
        MOV     RBP, RSP

        XOR     RCX, RCX

loop:
        CMP     RDX, RCX
        JZ      end

        MOV     R9B, [RSI + RCX]

        MOV     [RDI + RCX], R9B

        INC     RCX
        JMP     loop

end:
        MOV     RAX, RDI

        MOV     RSP, RBP
        POP     RBP

        RET

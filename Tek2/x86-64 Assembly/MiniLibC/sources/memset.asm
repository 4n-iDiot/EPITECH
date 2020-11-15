BITS 64

SECTION .text

GLOBAL memset

memset:
        PUSH    RBP
        MOV     RBP, RSP

        XOR     RCX, RCX

loop:
        CMP     RCX, RDX
        JZ       end

        MOV     [RDI + RCX], SIL

        INC     RCX
        JMP     loop

end:
        MOV     RAX, RDI

        MOV     RSP, RBP
        POP     RBP

        RET

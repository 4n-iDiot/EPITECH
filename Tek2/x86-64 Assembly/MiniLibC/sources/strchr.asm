BITS 64

SECTION .text

GLOBAL strchr

strchr:
        PUSH    RBP
        MOV     RBP, RSP

loop:
        CMP     BYTE [RDI], SIL
        MOV     RAX, RDI
        JE      end

        CMP     BYTE [RDI], 00
        MOV     RAX, 0
        JE      end

        INC     RDI
        JMP     loop

end:
        MOV     RSP, RBP
        POP     RBP

        RET

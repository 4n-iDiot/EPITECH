BITS 64

SECTION .text

GLOBAL rindex

rindex:
        PUSH    RBP
        MOV     RBP, RSP

loop:
        CMP     BYTE [RDI], SIL
        MOV     RAX, RDI

        CMP     BYTE [RDI], 00
        JE      check_rax

        INC     RDI
        JMP     loop

check_rax:
        CMP     RAX, 0
        JE      set_rax_0

        JMP     end

set_rax_0:
        MOV     RAX, 0

        JMP     end

end:
        MOV     RSP, RBP
        POP     RBP

        RET

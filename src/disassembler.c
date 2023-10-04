#include <stdio.h>
#include <stdlib.h>

int disassemble8080(FILE *fp, unsigned char *buffer, int pc)
{
  unsigned char *code = &buffer[pc];

  int opbytes = 1;

  switch (*code) {
    //cases
    case 0x00:
      fprintf(fp, "%04x: NOP\n", pc);
      break;
    case 0x01:
      fprintf(fp, "%04x: LXI B, %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x02:
      fprintf(fp, "%04x: STAX B\n", pc);
      break;
    case 0x03:
      fprintf(fp, "%04x: INX B\n", pc);
      break;
    case 0x04:
      fprintf(fp, "%04x: INR B\n", pc);
      break;
    case 0x05:
      fprintf(fp, "%04x: DCR B\n", pc);
      break;
    case 0x06:
      fprintf(fp, "%04x: MVI B, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x07:
      fprintf(fp, "%04x: RLC\n", pc);
      break;
    case 0x08:
      break;
    case 0x09:
      fprintf(fp, "%04x: DAD B\n", pc);
      break;
    case 0x0a:
      fprintf(fp, "%04x: LDAX B\n", pc);
      break;
    case 0x0b:
      fprintf(fp, "%04x: DCX B\n", pc);
      break;
    case 0x0c:
      fprintf(fp, "%04x: INR C\n", pc);
      break;
    case 0x0d:
      fprintf(fp, "%04x: DCR C\n", pc);
      break;
    case 0x0e:
      fprintf(fp, "%04x: MVI C, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x0f:
      fprintf(fp, "%04x: RRC\n", pc);
      break;
    case 0x10:
      break;
    case 0x11:
      fprintf(fp, "%04x: LXI D, %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x12:
      fprintf(fp, "%04x: STAX D\n", pc);
      break;
    case 0x13:
      fprintf(fp, "%04x: INX D\n", pc);
      break;
    case 0x14:
      fprintf(fp, "%04x: INR D\n", pc);
      break;
    case 0x15:
      fprintf(fp, "%04x: DCR D\n", pc);
      break;
    case 0x16:
      fprintf(fp, "%04x: MVI D, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x17:
      fprintf(fp, "%04x: RAL\n", pc);
      break;
    case 0x18:
      break;
    case 0x19:
      fprintf(fp, "%04x: DAD D\n", pc);
      break;
    case 0x1a:
      fprintf(fp, "%04x: LDAX D\n", pc);
      break;
    case 0x1b:
      fprintf(fp, "%04x: DCX D\n", pc);
      break;
    case 0x1c:
      fprintf(fp, "%04x: INR E\n", pc);
      break;
    case 0x1d:
      fprintf(fp, "%04x: DCR E\n", pc);
      break;
    case 0x1e:
      fprintf(fp, "%04x: MVI E, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x1f:
      fprintf(fp, "%04x: RAR\n", pc);
      break;
    case 0x20:
      fprintf(fp, "%04x: RIM\n", pc);
      break;
    case 0x21:
      fprintf(fp, "%04x: LXI H, %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x22:
      fprintf(fp, "%04x: SHLD %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x23:
      fprintf(fp, "%04x: INX H\n", pc);
      break;
    case 0x24:
      fprintf(fp, "%04x: INR H\n", pc);
      break;
    case 0x25:
      fprintf(fp, "%04x: DCR H\n", pc);
      break;
    case 0x26:
      fprintf(fp, "%04x: MVI H, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x27:
      fprintf(fp, "%04x: DAA\n", pc);
      break;
    case 0x28:
      break;
    case 0x29:
      fprintf(fp, "%04x: DAD H\n", pc);
      break;
    case 0x2a:
      fprintf(fp, "%04x: LHLD %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x2b:
      fprintf(fp, "%04x: DCX H\n", pc);
      break;
    case 0x2c:
      fprintf(fp, "%04x: INR L\n", pc);
      break;
    case 0x2d:
      fprintf(fp, "%04x: DCR L\n", pc);
      break;
    case 0x2e:
      fprintf(fp, "%04x: MVI L, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x2f:
      fprintf(fp, "%04x: CMA\n", pc);
      break;
    case 0x30:
      fprintf(fp, "%04x: SIM\n", pc);
      break;
    case 0x31:
      fprintf(fp, "%04x: LXI SP, %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x32:
      fprintf(fp, "%04x: STA %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x33:
      fprintf(fp, "%04x: INX SP\n", pc);
      break;
    case 0x34:
      fprintf(fp, "%04x: INR M\n", pc);
      break;
    case 0x35:
      fprintf(fp, "%04x: DCR M\n", pc);
      break;
    case 0x36:
      fprintf(fp, "%04x: MVI M, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x37:
      fprintf(fp, "%04x: STC\n", pc);
      break;
    case 0x38:
      break;
    case 0x39:
      fprintf(fp, "%04x: DAD SP\n", pc);
      break;
    case 0x3a:
      fprintf(fp, "%04x: LDA %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0x3b:
      fprintf(fp, "%04x: DCX SP\n", pc);
      break;
    case 0x3c:
      fprintf(fp, "%04x: INR A\n", pc);
      break;
    case 0x3d:
      fprintf(fp, "%04x: DCR A\n", pc);
      break;
    case 0x3e:
      fprintf(fp, "%04x: MVI A, %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0x3f:
      fprintf(fp, "%04x: CMC\n", pc);
      break;
    case 0x40:
      fprintf(fp, "%04x: MOV B, B\n", pc);
      break;
    case 0x41:
      fprintf(fp, "%04x: MOV B, C\n", pc);
      break;
    case 0x42:
      fprintf(fp, "%04x: MOV B, D\n", pc);
      break;
    case 0x43:
      fprintf(fp, "%04x: MOV B, E\n", pc);
      break;
    case 0x44:
      fprintf(fp, "%04x: MOV B, H\n", pc);
      break;
    case 0x45:
      fprintf(fp, "%04x: MOV B, L\n", pc);
      break;
    case 0x46:
      fprintf(fp, "%04x: MOV B, M\n", pc);
      break;
    case 0x47:
      fprintf(fp, "%04x: MOV B, A\n", pc);
      break;
    case 0x48:
      fprintf(fp, "%04x: MOV C, B\n", pc);
      break;
    case 0x49:
      fprintf(fp, "%04x: MOV C, C\n", pc);
      break;
    case 0x4a:
      fprintf(fp, "%04x: MOV C, D\n", pc);
      break;
    case 0x4b:
      fprintf(fp, "%04x: MOV C, E\n", pc);
      break;
    case 0x4c:
      fprintf(fp, "%04x: MOV C, H\n", pc);
      break;
    case 0x4d:
      fprintf(fp, "%04x: MOV C, L\n", pc);
      break;
    case 0x4e:
      fprintf(fp, "%04x: MOV C, M\n", pc);
      break;
    case 0x4f:
      fprintf(fp, "%04x: MOV C, A\n", pc);
      break;
    case 0x50:
      fprintf(fp, "%04x: MOV D, B\n", pc);
      break;
    case 0x51:
      fprintf(fp, "%04x: MOV D, C\n", pc);
      break;
    case 0x52:
      fprintf(fp, "%04x: MOV D, D\n", pc);
      break;
    case 0x53:
      fprintf(fp, "%04x: MOV D, E\n", pc);
      break;
    case 0x54:
      fprintf(fp, "%04x: MOV D, H\n", pc);
      break;
    case 0x55:
      fprintf(fp, "%04x: MOV D, L\n", pc);
      break;
    case 0x56:
      fprintf(fp, "%04x: MOV D, M\n", pc);
      break;
    case 0x57:
      fprintf(fp, "%04x: MOV D, A\n", pc);
      break;
    case 0x58:
      fprintf(fp, "%04x: MOV E, B\n", pc);
      break;
    case 0x59:
      fprintf(fp, "%04x: MOV E, C\n", pc);
      break;
    case 0x5a:
      fprintf(fp, "%04x: MOV E, D\n", pc);
      break;
    case 0x5b:
      fprintf(fp, "%04x: MOV E, E\n", pc);
      break;
    case 0x5c:
      fprintf(fp, "%04x: MOV E, H\n", pc);
      break;
    case 0x5d:
      fprintf(fp, "%04x: MOV E, L\n", pc);
      break;
    case 0x5e:
      fprintf(fp, "%04x: MOV E, M\n", pc);
      break;
    case 0x5f:
      fprintf(fp, "%04x: MOV E, A\n", pc);
      break;
    case 0x60:
      fprintf(fp, "%04x: MOV H, B\n", pc);
      break;
    case 0x61:
      fprintf(fp, "%04x: MOV H, C\n", pc);
      break;
    case 0x62:
      fprintf(fp, "%04x: MOV H, D\n", pc);
      break;
    case 0x63:
      fprintf(fp, "%04x: MOV H, E\n", pc);
      break;
    case 0x64:
      fprintf(fp, "%04x: MOV H, H\n", pc);
      break;
    case 0x65:
      fprintf(fp, "%04x: MOV H, L\n", pc);
      break;
    case 0x66:
      fprintf(fp, "%04x: MOV H, M\n", pc);
      break;
    case 0x67:
      fprintf(fp, "%04x: MOV H, A\n", pc);
      break;
    case 0x68:
      fprintf(fp, "%04x: MOV L, B\n", pc);
      break;
    case 0x69:
      fprintf(fp, "%04x: MOV L, C\n", pc);
      break;
    case 0x6a:
      fprintf(fp, "%04x: MOV L, D\n", pc);
      break;
    case 0x6b:
      fprintf(fp, "%04x: MOV L, E\n", pc);
      break;
    case 0x6c:
      fprintf(fp, "%04x: MOV L, H\n", pc);
      break;
    case 0x6d:
      fprintf(fp, "%04x: MOV L, L\n", pc);
      break;
    case 0x6e:
      fprintf(fp, "%04x: MOV L, M\n", pc);
      break;
    case 0x6f:
      fprintf(fp, "%04x: MOV L, A\n", pc);
      break;
    case 0x70:
      fprintf(fp, "%04x: MOV M, B\n", pc);
      break;
    case 0x71:
      fprintf(fp, "%04x: MOV M, C\n", pc);
      break;
    case 0x72:
      fprintf(fp, "%04x: MOV M, D\n", pc);
      break;
    case 0x73:
      fprintf(fp, "%04x: MOV M, E\n", pc);
      break;
    case 0x74:
      fprintf(fp, "%04x: MOV M, H\n", pc);
      break;
    case 0x75:
      fprintf(fp, "%04x: MOV M, L\n", pc);
      break;
    case 0x76:
      fprintf(fp, "%04x: HLT\n", pc);
      break;
    case 0x77:
      fprintf(fp, "%04x: MOV M, A\n", pc);
      break;
    case 0x78:
      fprintf(fp, "%04x: MOV A, B\n", pc);
      break;
    case 0x79:
      fprintf(fp, "%04x: MOV A, C\n", pc);
      break;
    case 0x7a:
      fprintf(fp, "%04x: MOV A, D\n", pc);
      break;
    case 0x7b:
      fprintf(fp, "%04x: MOV A, E\n", pc);
      break;
    case 0x7c:
      fprintf(fp, "%04x: MOV A, H\n", pc);
      break;
    case 0x7d:
      fprintf(fp, "%04x: MOV A, L\n", pc);
      break;
    case 0x7e:
      fprintf(fp, "%04x: MOV A, M\n", pc);
      break;
    case 0x7f:
      fprintf(fp, "%04x: MOV A, A\n", pc);
      break;
    case 0x80:
      fprintf(fp, "%04x: ADD B\n", pc);
      break;
    case 0x81:
      fprintf(fp, "%04x: ADD C\n", pc);
      break;
    case 0x82:
      fprintf(fp, "%04x: ADD D\n", pc);
      break;
    case 0x83:
      fprintf(fp, "%04x: ADD E\n", pc);
      break;
    case 0x84:
      fprintf(fp, "%04x: ADD H\n", pc);
      break;
    case 0x85:
      fprintf(fp, "%04x: ADD L\n", pc);
      break;
    case 0x86:
      fprintf(fp, "%04x: ADD M\n", pc);
      break;
    case 0x87:
      fprintf(fp, "%04x: ADD A\n", pc);
      break;
    case 0x88:
      fprintf(fp, "%04x: ADC B\n", pc);
      break;
    case 0x89:
      fprintf(fp, "%04x: ADC C\n", pc);
      break;
    case 0x8a:
      fprintf(fp, "%04x: ADC D\n", pc);
      break;
    case 0x8b:
      fprintf(fp, "%04x: ADC E\n", pc);
      break;
    case 0x8c:
      fprintf(fp, "%04x: ADC H\n", pc);
      break;
    case 0x8d:
      fprintf(fp, "%04x: ADC L\n", pc);
      break;
    case 0x8e:
      fprintf(fp, "%04x: ADC M\n", pc);
      break;
    case 0x8f:
      fprintf(fp, "%04x: ADC A\n", pc);
      break;
    case 0x90:
      fprintf(fp, "%04x: SUB B\n", pc);
      break;
    case 0x91:
      fprintf(fp, "%04x: SUB C\n", pc);
      break;
    case 0x92:
      fprintf(fp, "%04x: SUB D\n", pc);
      break;
    case 0x93:
      fprintf(fp, "%04x: SUB E\n", pc);
      break;
    case 0x94:
      fprintf(fp, "%04x: SUB H\n", pc);
      break;
    case 0x95:
      fprintf(fp, "%04x: SUB L\n", pc);
      break;
    case 0x96:
      fprintf(fp, "%04x: SUB M\n", pc);
      break;
    case 0x97:
      fprintf(fp, "%04x: SUB A\n", pc);
      break;
    case 0x98:
      fprintf(fp, "%04x: SBB B\n", pc);
      break;
    case 0x99:
      fprintf(fp, "%04x: SBB C\n", pc);
      break;
    case 0x9a:
      fprintf(fp, "%04x: SBB D\n", pc);
      break;
    case 0x9b:
      fprintf(fp, "%04x: SBB E\n", pc);
      break;
    case 0x9c:
      fprintf(fp, "%04x: SBB H\n", pc);
      break;
    case 0x9d:
      fprintf(fp, "%04x: SBB L\n", pc);
      break;
    case 0x9e:
      fprintf(fp, "%04x: SBB M\n", pc);
      break;
    case 0x9f:
      fprintf(fp, "%04x: SBB A\n", pc);
      break;
    case 0xa0:
      fprintf(fp, "%04x: ANA B\n", pc);
      break;
    case 0xa1:
      fprintf(fp, "%04x: ANA C\n", pc);
      break;
    case 0xa2:
      fprintf(fp, "%04x: ANA D\n", pc);
      break;
    case 0xa3:
      fprintf(fp, "%04x: ANA E\n", pc);
      break;
    case 0xa4:
      fprintf(fp, "%04x: ANA H\n", pc);
      break;
    case 0xa5:
      fprintf(fp, "%04x: ANA L\n", pc);
      break;
    case 0xa6:
      fprintf(fp, "%04x: ANA M\n", pc);
      break;
    case 0xa7:
      fprintf(fp, "%04x: ANA A\n", pc);
      break;
    case 0xa8:
      fprintf(fp, "%04x: XRA B\n", pc);
      break;
    case 0xa9:
      fprintf(fp, "%04x: XRA C\n", pc);
      break;
    case 0xaa:
      fprintf(fp, "%04x: XRA D\n", pc);
      break;
    case 0xab:
      fprintf(fp, "%04x: XRA E\n", pc);
      break;
    case 0xac:
      fprintf(fp, "%04x: XRA H\n", pc);
      break;
    case 0xad:
      fprintf(fp, "%04x: XRA L\n", pc);
      break;
    case 0xae:
      fprintf(fp, "%04x: XRA M\n", pc);
      break;
    case 0xaf:
      fprintf(fp, "%04x: XRA A\n", pc);
      break;
    case 0xb0:
      fprintf(fp, "%04x: ORA B\n", pc);
      break;
    case 0xb1:
      fprintf(fp, "%04x: ORA C\n", pc);
      break;
    case 0xb2:
      fprintf(fp, "%04x: ORA D\n", pc);
      break;
    case 0xb3:
      fprintf(fp, "%04x: ORA E\n", pc);
      break;
    case 0xb4:
      fprintf(fp, "%04x: ORA H\n", pc);
      break;
    case 0xb5:
      fprintf(fp, "%04x: ORA L\n", pc);
      break;
    case 0xb6:
      fprintf(fp, "%04x: ORA M\n", pc);
      break;
    case 0xb7:
      fprintf(fp, "%04x: ORA A\n", pc);
      break;
    case 0xb8:
      fprintf(fp, "%04x: CMP B\n", pc);
      break;
    case 0xb9:
      fprintf(fp, "%04x: CMP C\n", pc);
      break;
    case 0xba:
      fprintf(fp, "%04x: CMP D\n", pc);
      break;
    case 0xbb:
      fprintf(fp, "%04x: CMP E\n", pc);
      break;
    case 0xbc:
      fprintf(fp, "%04x: CMP H\n", pc);
      break;
    case 0xbd:
      fprintf(fp, "%04x: CMP L\n", pc);
      break;
    case 0xbe:
      fprintf(fp, "%04x: CMP M\n", pc);
      break;
    case 0xbf:
      fprintf(fp, "%04x: CMP A\n", pc);
      break;
    case 0xc0:
      fprintf(fp, "%04x: RNZ\n", pc);
    case 0xc1:
      fprintf(fp, "%04x: POP B\n", pc);
      break;
    case 0xc2:
      fprintf(fp, "%04x: JNZ %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xc3:
      fprintf(fp, "%04x: JMP %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xc4:
      fprintf(fp, "%04x: CNZ %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xc5:
      fprintf(fp, "%04x: PUSH B\n", pc);
      break;
    case 0xc6:
      fprintf(fp, "%04x: ADI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xc7:
      fprintf(fp, "%04x: RST 0\n", pc);
      break;
    case 0xc8:
      fprintf(fp, "%04x: RZ\n", pc);
      break;
    case 0xc9:
      fprintf(fp, "%04x: RET\n", pc);
      break;
    case 0xca:
      fprintf(fp, "%04x: JZ %02x%02x\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xcb:
      break;
    case 0xcc:
      fprintf(fp, "%04x: CZ %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xcd:
      fprintf(fp, "%04x: CALL %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xce:
      fprintf(fp, "%04x: ACI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xcf:
      fprintf(fp, "%04x: RST 1\n", pc);
      break;
    case 0xd0:
      fprintf(fp, "%04x: RNZ\n", pc);
      break;
    case 0xd1:
      fprintf(fp, "%04x: POP D\n", pc);
      break;
    case 0xd2:
      fprintf(fp, "%04x: JNC %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xd3:
      fprintf(fp, "%04x: OUT %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xd4:
      fprintf(fp, "%04x: CNC %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xd5:
      fprintf(fp, "%04x: PUSH D\n", pc);
      break;
    case 0xd6:
      fprintf(fp, "%04x: SUI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xd7:
      fprintf(fp, "%04x: RST 2\n", pc);
      break;
    case 0xd8:
      fprintf(fp, "%04x: RC\n", pc);
      break;
    case 0xd9:
      break;
    case 0xda:
      fprintf(fp, "%04x: JC %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xdb:
      fprintf(fp, "%04x: IN %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xdc:
      fprintf(fp, "%04x: CC %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xdd:
      break;
    case 0xde:
      fprintf(fp, "%04x: SBI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xdf:
      fprintf(fp, "%04x: RST 3\n", pc);
      break;
    case 0xe0:
      fprintf(fp, "%04x: RPO\n", pc);
      break;
    case 0xe1:
      fprintf(fp, "%04x: POP H\n", pc);
      break;
    case 0xe2:
      fprintf(fp, "%04x: JPO %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xe3:
      fprintf(fp, "%04x: XTHL\n", pc);
      break;
    case 0xe4:
      fprintf(fp, "%04x: CPO %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xe5:
      fprintf(fp, "%04x: PUSH H\n", pc);
      break;
    case 0xe6:
      fprintf(fp, "%04x: ANI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xe7:
      fprintf(fp, "%04x: RST 4\n", pc);
      break;
    case 0xe8:
      fprintf(fp, "%04x: RPE\n", pc);
      break;
    case 0xe9:
      fprintf(fp, "%04x: PCHL\n", pc);
      break;
    case 0xea:
      fprintf(fp, "%04x: JPE %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xeb:
      fprintf(fp, "%04x: XCHG\n", pc);
      break;
    case 0xec:
      fprintf(fp, "%04x: CPE %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xed:
      break;
    case 0xee:
      fprintf(fp, "%04x: XRI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xef:
      fprintf(fp, "%04x: RST 5\n", pc);
      break;
    case 0xf0:
      fprintf(fp, "%04x: RP\n", pc);
      break;
    case 0xf1:
      fprintf(fp, "%04x: POP PSW\n", pc);
      break;
    case 0xf2:
      fprintf(fp, "%04x: JP %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xf3:
      fprintf(fp, "%04x: DI\n", pc);
      break;
    case 0xf4:
      fprintf(fp, "%04x: CP %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xf5:
      fprintf(fp, "%04x: PUSH PSW\n", pc);
      break;
    case 0xf6:
      fprintf(fp, "%04x: ORI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xf7:
      fprintf(fp, "%04x: RST 6\n", pc);
      break;
    case 0xf8:
      fprintf(fp, "%04x: RM\n", pc);
      break;
    case 0xf9:
      fprintf(fp, "%04x: SPHL\n", pc);
      break;
    case 0xfa:
      fprintf(fp, "%04x: JM %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xfb:
      fprintf(fp, "%04x: EI\n", pc);
      break;
    case 0xfc:
      fprintf(fp, "%04x: CM %02x%02xH\n", pc, code[2], code[1]);
      opbytes = 3;
      break;
    case 0xfd:
      break;
    case 0xfe:
      fprintf(fp, "%04x: CPI %02xH\n", pc, code[1]);
      opbytes = 2;
      break;
    case 0xff:
      fprintf(fp, "%04x: RST 7\n", pc);
      break;
    default:
      fprintf(fp, "Unknown instruction\n");
      return -1;
  }

  return opbytes;
}

int main(int argc, char *argv[])
{
  FILE *f = fopen(argv[1], "rb"); // open a file in a binary filestream
  FILE *fp = fopen("output.txt", "w+");
  if(f==NULL) {
    printf("Couldn't open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  fseek(f, 0L, SEEK_END); // put the file iposition indicator at the end of the filestream
  int fsize = ftell(f);   // gets the file position indicator of the filestream, 
                          // which is at the end of it, so it's a size of a filestream too
  fseek(f, 0L, SEEK_SET); // return the file position indicator at the start of the filestream

  unsigned char *buffer = malloc(fsize); // allocate memory of size 'fsize' to load filestream into

  fread(buffer, fsize, 1, f);
  fclose(f);

  int pc = 0;
  int retInt = 0;

  while(pc < fsize) {
    
    retInt = disassemble8080(fp, buffer, pc);
    if(retInt < 0) {
      printf("Unknown instruction\n");
      exit(1);
    } else {
      pc += retInt;
    }
  }

  return 0;
}

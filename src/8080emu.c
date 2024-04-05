#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ConditionBits {
  uint8_t c: 1;
  uint8_t ac: 1;
  uint8_t s: 1;
  uint8_t z: 1;
  uint8_t p: 1;
} ConditionBits;

typedef struct State {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
  uint8_t e;
  uint8_t h;
  uint8_t l;
  uint8_t psw;
  uint8_t *memory;
  uint16_t sp;
  uint16_t pc;
  struct ConditionBits cb;
} State;

void unimplementedInstruction(State *state) {
  printf("Didn't implement this instruction yet\n");
  exit(1);
}

void emulate8080(State *state) {

  unsigned char *code = &state->memory[state->pc];

  switch (*code) {
    case 0x00:
      break;
    case 0x01:
      state->b = code[2];
      state->c = code[1];
      state->pc += 2;
      break;
    case 0x02:
      {
        uint16_t addr = (state->b << 8) | state->c;
        state->memory[addr] = state->a;
      }
      break;
    case 0x03:
      {
        uint16_t newNum = ((state->b << 8) | state->c) + 1;
        state->b = newNum >> 8;
        state->c = newNum;
      }
      break;
    case 0x04:
      state->b = state->b + 1;
      break;
    case 0x05:
      state->b = state->b - 1;
      break;
    case 0x06:
      state->b = code[1];
      state->pc += 1;
      break;
    case 0x0c:
      state->c = state->c + 1;
      break;
    case 0x0d:
      state->c = state->c - 1;
      break;
    case 0x0e:
      state->c = code[1];
      state->pc += 1;
      break;
    case 0x11:
      state->d = code[2];
      state->e = code[1];
      state->pc += 2;
      break;
    case 0x12:
      {
        uint16_t addr = (state->d << 8) | state->e;
        state->memory[addr] = state->a;
      }
      break;
    case 0x13:
      {
        uint16_t newNum = ((state->d << 8) | state->e) + 1;
        state->d = newNum >> 8;
        state->e = newNum;
      }
      break;
    case 0x14:
      state->d = state->d + 1;
      break;
    case 0x15:
      state->d = state->d - 1;
      break;
    case 0x16:
      state->d = code[1];
      state->pc += 1;
      break;
    case 0x1c:
      state->e = state->e + 1;
      break;
    case 0x1d:
      state->e = state->e - 1;
      break;
    case 0x1e:
      state->e = code[1];
      state->pc += 1;
      break;
    case 0x21:
      state->h = code[2];
      state->l = code[1];
      state->pc += 2;
      break;
    case 0x23:
      {
        uint16_t newNum = ((state->h << 8) | state->l) + 1;
        state->h = newNum >> 8;
        state->l = newNum;
      }
      break;
    case 0x24:
      state->h = state->h + 1;
      break;
    case 0x25:
      state->h = state->h - 1;
      break;
    case 0x26:
      state->h = code[1];
      state->pc += 1;
      break;
    case 0x2c:
      state->l = state->l + 1;
      break;
    case 0x2d:
      state->l = state->l - 1;
      break;
    case 0x2e:
      state->l = code[1];
      state->pc += 1;
      break;
    case 0x31:
      state->sp = (code[2] << 8) | code[1];
      state->pc += 2;
      break;
    case 0x33:
      state->sp = state->sp + 1;
      break;
    case 0x3c:
      state->a = state->a + 1;
      break;
    case 0x3d:
      state->a = state->a - 1;
      break;
    case 0x3e:
      state->a = code[1];
      state->pc += 1;
      break;
    case 0x3f:
      state->cb.c = !state->cb.c;
      break;

  }

  state->pc += 1;
}

int main(int argc, char *argv[]) {
  return 0;
}

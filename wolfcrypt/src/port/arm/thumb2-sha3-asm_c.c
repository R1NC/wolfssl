/* thumb2-sha3-asm
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

/* Generated using (from wolfssl):
 *   cd ../scripts
 *   ruby ./sha3/sha3.rb thumb2 ../wolfssl/wolfcrypt/src/port/arm/thumb2-sha3-asm.c
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif /* HAVE_CONFIG_H */
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

#ifdef WOLFSSL_ARMASM
#if !defined(__aarch64__) && defined(__thumb__)
#ifdef WOLFSSL_ARMASM_INLINE

#ifdef __IAR_SYSTEMS_ICC__
#define __asm__        asm
#define __volatile__   volatile
#define WOLFSSL_NO_VAR_ASSIGN_REG
#endif /* __IAR_SYSTEMS_ICC__ */
#ifdef __KEIL__
#define __asm__        __asm
#define __volatile__   volatile
#endif /* __KEIL__ */
#ifdef WOLFSSL_SHA3
static const uint64_t L_sha3_thumb2_rt[] = {
    0x0000000000000001UL, 0x0000000000008082UL,
    0x800000000000808aUL, 0x8000000080008000UL,
    0x000000000000808bUL, 0x0000000080000001UL,
    0x8000000080008081UL, 0x8000000000008009UL,
    0x000000000000008aUL, 0x0000000000000088UL,
    0x0000000080008009UL, 0x000000008000000aUL,
    0x000000008000808bUL, 0x800000000000008bUL,
    0x8000000000008089UL, 0x8000000000008003UL,
    0x8000000000008002UL, 0x8000000000000080UL,
    0x000000000000800aUL, 0x800000008000000aUL,
    0x8000000080008081UL, 0x8000000000008080UL,
    0x0000000080000001UL, 0x8000000080008008UL,
};

#include <wolfssl/wolfcrypt/sha3.h>

#ifndef WOLFSSL_NO_VAR_ASSIGN_REG
void BlockSha3(word64* state_p)
#else
void BlockSha3(word64* state)
#endif /* !WOLFSSL_NO_VAR_ASSIGN_REG */
{
#ifndef WOLFSSL_NO_VAR_ASSIGN_REG
    register word64* state __asm__ ("r0") = (word64*)state_p;
    register uint64_t* L_sha3_thumb2_rt_c __asm__ ("r1") = (uint64_t*)&L_sha3_thumb2_rt;
#endif /* !WOLFSSL_NO_VAR_ASSIGN_REG */

    __asm__ __volatile__ (
        "SUB	sp, sp, #0xcc\n\t"
        "MOV	r1, %[L_sha3_thumb2_rt]\n\t"
        "MOV	r2, #0xc\n\t"
        "\n"
#if defined(__IAR_SYSTEMS_ICC__) && (__VER__ < 9000000)
    "L_sha3_thumb2_begin:\n\t"
#else
    "L_sha3_thumb2_begin_%=:\n\t"
#endif
        "STR	r2, [sp, #200]\n\t"
        /* Round even */
        /* Calc b[4] */
        "LDRD	r4, r5, [%[state], #32]\n\t"
        "LDRD	r6, r7, [%[state], #72]\n\t"
        "LDRD	r8, r9, [%[state], #112]\n\t"
        "LDRD	r10, r11, [%[state], #152]\n\t"
        "LDR	r12, [%[state], #192]\n\t"
        "LDR	lr, [%[state], #196]\n\t"
        "EOR	r2, r4, r6\n\t"
        "EOR	r3, r5, r7\n\t"
        "EOR	r2, r2, r8\n\t"
        "EOR	r3, r3, r9\n\t"
        "EOR	r2, r2, r10\n\t"
        "EOR	r3, r3, r11\n\t"
        "EOR	r2, r2, r12\n\t"
        "EOR	r3, r3, lr\n\t"
        "STRD	r2, r3, [sp, #32]\n\t"
        /* Calc b[1] */
        "LDRD	r4, r5, [%[state], #8]\n\t"
        "LDRD	r6, r7, [%[state], #48]\n\t"
        "LDRD	r8, r9, [%[state], #88]\n\t"
        "LDRD	r10, r11, [%[state], #128]\n\t"
        "LDR	r12, [%[state], #168]\n\t"
        "LDR	lr, [%[state], #172]\n\t"
        "EOR	r4, r4, r6\n\t"
        "EOR	r5, r5, r7\n\t"
        "EOR	r4, r4, r8\n\t"
        "EOR	r5, r5, r9\n\t"
        "EOR	r4, r4, r10\n\t"
        "EOR	r5, r5, r11\n\t"
        "EOR	r4, r4, r12\n\t"
        "EOR	r5, r5, lr\n\t"
        "STRD	r4, r5, [sp, #8]\n\t"
        /* Calc t[0] */
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* Calc b[0] and XOR t[0] into s[x*5+0] */
        "LDRD	r4, r5, [%[state]]\n\t"
        "LDRD	r6, r7, [%[state], #40]\n\t"
        "LDRD	r8, r9, [%[state], #80]\n\t"
        "LDRD	r10, r11, [%[state], #120]\n\t"
        "EOR	r12, r4, r6\n\t"
        "EOR	lr, r5, r7\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r4, r5, [%[state]]\n\t"
        "STRD	r6, r7, [%[state], #40]\n\t"
        "STRD	r8, r9, [%[state], #80]\n\t"
        "STRD	r10, r11, [%[state], #120]\n\t"
        "LDRD	r10, r11, [%[state], #160]\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r10, r11, [%[state], #160]\n\t"
        "STR	r12, [sp]\n\t"
        "STR	lr, [sp, #4]\n\t"
        /* Calc b[3] */
        "LDRD	r4, r5, [%[state], #24]\n\t"
        "LDRD	r6, r7, [%[state], #64]\n\t"
        "LDRD	r8, r9, [%[state], #104]\n\t"
        "LDRD	r10, r11, [%[state], #144]\n\t"
        "LDR	r12, [%[state], #184]\n\t"
        "LDR	lr, [%[state], #188]\n\t"
        "EOR	r4, r4, r6\n\t"
        "EOR	r5, r5, r7\n\t"
        "EOR	r4, r4, r8\n\t"
        "EOR	r5, r5, r9\n\t"
        "EOR	r4, r4, r10\n\t"
        "EOR	r5, r5, r11\n\t"
        "EOR	r4, r4, r12\n\t"
        "EOR	r5, r5, lr\n\t"
        "STRD	r4, r5, [sp, #24]\n\t"
        /* Calc t[2] */
        "LDRD	r2, r3, [sp, #8]\n\t"
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* Calc b[2] and XOR t[2] into s[x*5+2] */
        "LDRD	r4, r5, [%[state], #16]\n\t"
        "LDRD	r6, r7, [%[state], #56]\n\t"
        "LDRD	r8, r9, [%[state], #96]\n\t"
        "LDRD	r10, r11, [%[state], #136]\n\t"
        "EOR	r12, r4, r6\n\t"
        "EOR	lr, r5, r7\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r4, r5, [%[state], #16]\n\t"
        "STRD	r6, r7, [%[state], #56]\n\t"
        "STRD	r8, r9, [%[state], #96]\n\t"
        "STRD	r10, r11, [%[state], #136]\n\t"
        "LDRD	r10, r11, [%[state], #176]\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r10, r11, [%[state], #176]\n\t"
        "STR	r12, [sp, #16]\n\t"
        "STR	lr, [sp, #20]\n\t"
        /* Calc t[1] */
        "LDRD	r2, r3, [sp]\n\t"
        "EOR	r2, r2, lr, LSR #31\n\t"
        "EOR	r3, r3, r12, LSR #31\n\t"
        "EOR	r2, r2, r12, LSL #1\n\t"
        "EOR	r3, r3, lr, LSL #1\n\t"
        /* XOR t[1] into s[x*5+1] */
        "LDRD	r4, r5, [%[state], #8]\n\t"
        "LDRD	r6, r7, [%[state], #48]\n\t"
        "LDRD	r8, r9, [%[state], #88]\n\t"
        "LDRD	r10, r11, [%[state], #128]\n\t"
        "LDR	r12, [%[state], #168]\n\t"
        "LDR	lr, [%[state], #172]\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STRD	r4, r5, [%[state], #8]\n\t"
        "STRD	r6, r7, [%[state], #48]\n\t"
        "STRD	r8, r9, [%[state], #88]\n\t"
        "STRD	r10, r11, [%[state], #128]\n\t"
        "STR	r12, [%[state], #168]\n\t"
        "STR	lr, [%[state], #172]\n\t"
        /* Calc t[3] */
        "LDRD	r2, r3, [sp, #16]\n\t"
        "LDRD	r4, r5, [sp, #32]\n\t"
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* XOR t[3] into s[x*5+3] */
        "LDRD	r4, r5, [%[state], #24]\n\t"
        "LDRD	r6, r7, [%[state], #64]\n\t"
        "LDRD	r8, r9, [%[state], #104]\n\t"
        "LDRD	r10, r11, [%[state], #144]\n\t"
        "LDR	r12, [%[state], #184]\n\t"
        "LDR	lr, [%[state], #188]\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STRD	r4, r5, [%[state], #24]\n\t"
        "STRD	r6, r7, [%[state], #64]\n\t"
        "STRD	r8, r9, [%[state], #104]\n\t"
        "STRD	r10, r11, [%[state], #144]\n\t"
        "STR	r12, [%[state], #184]\n\t"
        "STR	lr, [%[state], #188]\n\t"
        /* Calc t[4] */
        "LDRD	r2, r3, [sp, #24]\n\t"
        "LDRD	r4, r5, [sp]\n\t"
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* XOR t[4] into s[x*5+4] */
        "LDRD	r4, r5, [%[state], #32]\n\t"
        "LDRD	r6, r7, [%[state], #72]\n\t"
        "LDRD	r8, r9, [%[state], #112]\n\t"
        "LDRD	r10, r11, [%[state], #152]\n\t"
        "LDR	r12, [%[state], #192]\n\t"
        "LDR	lr, [%[state], #196]\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STRD	r4, r5, [%[state], #32]\n\t"
        "STRD	r6, r7, [%[state], #72]\n\t"
        "STRD	r8, r9, [%[state], #112]\n\t"
        "STRD	r10, r11, [%[state], #152]\n\t"
        "STR	r12, [%[state], #192]\n\t"
        "STR	lr, [%[state], #196]\n\t"
        /* Row Mix */
        /* Row 0 */
        "LDRD	r2, r3, [%[state]]\n\t"
        "LDRD	r4, r5, [%[state], #48]\n\t"
        "LDRD	r6, r7, [%[state], #96]\n\t"
        "LDRD	r8, r9, [%[state], #144]\n\t"
        "LDRD	r10, r11, [%[state], #192]\n\t"
        /* s[1] <<< 44 */
        "MOV	lr, r4\n\t"
        "LSR	r12, r5, #20\n\t"
        "LSR	r4, r4, #20\n\t"
        "ORR	r4, r4, r5, LSL #12\n\t"
        "ORR	r5, r12, lr, LSL #12\n\t"
        /* s[2] <<< 43 */
        "MOV	lr, r6\n\t"
        "LSR	r12, r7, #21\n\t"
        "LSR	r6, r6, #21\n\t"
        "ORR	r6, r6, r7, LSL #11\n\t"
        "ORR	r7, r12, lr, LSL #11\n\t"
        /* s[3] <<< 21 */
        "LSR	r12, r9, #11\n\t"
        "LSR	lr, r8, #11\n\t"
        "ORR	r8, r12, r8, LSL #21\n\t"
        "ORR	r9, lr, r9, LSL #21\n\t"
        /* s[4] <<< 14 */
        "LSR	r12, r11, #18\n\t"
        "LSR	lr, r10, #18\n\t"
        "ORR	r10, r12, r10, LSL #14\n\t"
        "ORR	r11, lr, r11, LSL #14\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [sp, #8]\n\t"
        "STR	lr, [sp, #12]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [sp, #16]\n\t"
        "STR	lr, [sp, #20]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [sp, #24]\n\t"
        "STR	lr, [sp, #28]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [sp, #32]\n\t"
        "STR	lr, [sp, #36]\n\t"
        /* Get constant */
        "LDRD	r10, r11, [r1]\n\t"
        "ADD	r1, r1, #0x8\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        /* XOR in constant */
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [sp]\n\t"
        "STR	lr, [sp, #4]\n\t"
        /* Row 1 */
        "LDRD	r2, r3, [%[state], #24]\n\t"
        "LDRD	r4, r5, [%[state], #72]\n\t"
        "LDRD	r6, r7, [%[state], #80]\n\t"
        "LDRD	r8, r9, [%[state], #128]\n\t"
        "LDRD	r10, r11, [%[state], #176]\n\t"
        /* s[0] <<< 28 */
        "LSR	r12, r3, #4\n\t"
        "LSR	lr, r2, #4\n\t"
        "ORR	r2, r12, r2, LSL #28\n\t"
        "ORR	r3, lr, r3, LSL #28\n\t"
        /* s[1] <<< 20 */
        "LSR	r12, r5, #12\n\t"
        "LSR	lr, r4, #12\n\t"
        "ORR	r4, r12, r4, LSL #20\n\t"
        "ORR	r5, lr, r5, LSL #20\n\t"
        /* s[2] <<< 3 */
        "LSR	r12, r7, #29\n\t"
        "LSR	lr, r6, #29\n\t"
        "ORR	r6, r12, r6, LSL #3\n\t"
        "ORR	r7, lr, r7, LSL #3\n\t"
        /* s[3] <<< 45 */
        "MOV	lr, r8\n\t"
        "LSR	r12, r9, #19\n\t"
        "LSR	r8, r8, #19\n\t"
        "ORR	r8, r8, r9, LSL #13\n\t"
        "ORR	r9, r12, lr, LSL #13\n\t"
        /* s[4] <<< 61 */
        "MOV	lr, r10\n\t"
        "LSR	r12, r11, #3\n\t"
        "LSR	r10, r10, #3\n\t"
        "ORR	r10, r10, r11, LSL #29\n\t"
        "ORR	r11, r12, lr, LSL #29\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [sp, #48]\n\t"
        "STR	lr, [sp, #52]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [sp, #56]\n\t"
        "STR	lr, [sp, #60]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [sp, #64]\n\t"
        "STR	lr, [sp, #68]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [sp, #72]\n\t"
        "STR	lr, [sp, #76]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [sp, #40]\n\t"
        "STR	lr, [sp, #44]\n\t"
        /* Row 2 */
        "LDRD	r2, r3, [%[state], #8]\n\t"
        "LDRD	r4, r5, [%[state], #56]\n\t"
        "LDRD	r6, r7, [%[state], #104]\n\t"
        "LDRD	r8, r9, [%[state], #152]\n\t"
        "LDRD	r10, r11, [%[state], #160]\n\t"
        /* s[0] <<< 1 */
        "LSR	r12, r3, #31\n\t"
        "LSR	lr, r2, #31\n\t"
        "ORR	r2, r12, r2, LSL #1\n\t"
        "ORR	r3, lr, r3, LSL #1\n\t"
        /* s[1] <<< 6 */
        "LSR	r12, r5, #26\n\t"
        "LSR	lr, r4, #26\n\t"
        "ORR	r4, r12, r4, LSL #6\n\t"
        "ORR	r5, lr, r5, LSL #6\n\t"
        /* s[2] <<< 25 */
        "LSR	r12, r7, #7\n\t"
        "LSR	lr, r6, #7\n\t"
        "ORR	r6, r12, r6, LSL #25\n\t"
        "ORR	r7, lr, r7, LSL #25\n\t"
        /* s[3] <<< 8 */
        "LSR	r12, r9, #24\n\t"
        "LSR	lr, r8, #24\n\t"
        "ORR	r8, r12, r8, LSL #8\n\t"
        "ORR	r9, lr, r9, LSL #8\n\t"
        /* s[4] <<< 18 */
        "LSR	r12, r11, #14\n\t"
        "LSR	lr, r10, #14\n\t"
        "ORR	r10, r12, r10, LSL #18\n\t"
        "ORR	r11, lr, r11, LSL #18\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [sp, #88]\n\t"
        "STR	lr, [sp, #92]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [sp, #96]\n\t"
        "STR	lr, [sp, #100]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [sp, #104]\n\t"
        "STR	lr, [sp, #108]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [sp, #112]\n\t"
        "STR	lr, [sp, #116]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [sp, #80]\n\t"
        "STR	lr, [sp, #84]\n\t"
        /* Row 3 */
        "LDRD	r2, r3, [%[state], #32]\n\t"
        "LDRD	r4, r5, [%[state], #40]\n\t"
        "LDRD	r6, r7, [%[state], #88]\n\t"
        "LDRD	r8, r9, [%[state], #136]\n\t"
        "LDRD	r10, r11, [%[state], #184]\n\t"
        /* s[0] <<< 27 */
        "LSR	r12, r3, #5\n\t"
        "LSR	lr, r2, #5\n\t"
        "ORR	r2, r12, r2, LSL #27\n\t"
        "ORR	r3, lr, r3, LSL #27\n\t"
        /* s[1] <<< 36 */
        "MOV	lr, r4\n\t"
        "LSR	r12, r5, #28\n\t"
        "LSR	r4, r4, #28\n\t"
        "ORR	r4, r4, r5, LSL #4\n\t"
        "ORR	r5, r12, lr, LSL #4\n\t"
        /* s[2] <<< 10 */
        "LSR	r12, r7, #22\n\t"
        "LSR	lr, r6, #22\n\t"
        "ORR	r6, r12, r6, LSL #10\n\t"
        "ORR	r7, lr, r7, LSL #10\n\t"
        /* s[3] <<< 15 */
        "LSR	r12, r9, #17\n\t"
        "LSR	lr, r8, #17\n\t"
        "ORR	r8, r12, r8, LSL #15\n\t"
        "ORR	r9, lr, r9, LSL #15\n\t"
        /* s[4] <<< 56 */
        "MOV	lr, r10\n\t"
        "LSR	r12, r11, #8\n\t"
        "LSR	r10, r10, #8\n\t"
        "ORR	r10, r10, r11, LSL #24\n\t"
        "ORR	r11, r12, lr, LSL #24\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [sp, #128]\n\t"
        "STR	lr, [sp, #132]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [sp, #136]\n\t"
        "STR	lr, [sp, #140]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [sp, #144]\n\t"
        "STR	lr, [sp, #148]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [sp, #152]\n\t"
        "STR	lr, [sp, #156]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [sp, #120]\n\t"
        "STR	lr, [sp, #124]\n\t"
        /* Row 4 */
        "LDRD	r2, r3, [%[state], #16]\n\t"
        "LDRD	r4, r5, [%[state], #64]\n\t"
        "LDRD	r6, r7, [%[state], #112]\n\t"
        "LDRD	r8, r9, [%[state], #120]\n\t"
        "LDRD	r10, r11, [%[state], #168]\n\t"
        /* s[0] <<< 62 */
        "MOV	lr, r2\n\t"
        "LSR	r12, r3, #2\n\t"
        "LSR	r2, r2, #2\n\t"
        "ORR	r2, r2, r3, LSL #30\n\t"
        "ORR	r3, r12, lr, LSL #30\n\t"
        /* s[1] <<< 55 */
        "MOV	lr, r4\n\t"
        "LSR	r12, r5, #9\n\t"
        "LSR	r4, r4, #9\n\t"
        "ORR	r4, r4, r5, LSL #23\n\t"
        "ORR	r5, r12, lr, LSL #23\n\t"
        /* s[2] <<< 39 */
        "MOV	lr, r6\n\t"
        "LSR	r12, r7, #25\n\t"
        "LSR	r6, r6, #25\n\t"
        "ORR	r6, r6, r7, LSL #7\n\t"
        "ORR	r7, r12, lr, LSL #7\n\t"
        /* s[3] <<< 41 */
        "MOV	lr, r8\n\t"
        "LSR	r12, r9, #23\n\t"
        "LSR	r8, r8, #23\n\t"
        "ORR	r8, r8, r9, LSL #9\n\t"
        "ORR	r9, r12, lr, LSL #9\n\t"
        /* s[4] <<< 2 */
        "LSR	r12, r11, #30\n\t"
        "LSR	lr, r10, #30\n\t"
        "ORR	r10, r12, r10, LSL #2\n\t"
        "ORR	r11, lr, r11, LSL #2\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [sp, #168]\n\t"
        "STR	lr, [sp, #172]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [sp, #176]\n\t"
        "STR	lr, [sp, #180]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [sp, #184]\n\t"
        "STR	lr, [sp, #188]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [sp, #192]\n\t"
        "STR	lr, [sp, #196]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [sp, #160]\n\t"
        "STR	lr, [sp, #164]\n\t"
        /* Round odd */
        /* Calc b[4] */
        "LDRD	r4, r5, [sp, #32]\n\t"
        "LDRD	r6, r7, [sp, #72]\n\t"
        "LDRD	r8, r9, [sp, #112]\n\t"
        "LDRD	r10, r11, [sp, #152]\n\t"
        "LDR	r12, [sp, #192]\n\t"
        "LDR	lr, [sp, #196]\n\t"
        "EOR	r2, r4, r6\n\t"
        "EOR	r3, r5, r7\n\t"
        "EOR	r2, r2, r8\n\t"
        "EOR	r3, r3, r9\n\t"
        "EOR	r2, r2, r10\n\t"
        "EOR	r3, r3, r11\n\t"
        "EOR	r2, r2, r12\n\t"
        "EOR	r3, r3, lr\n\t"
        "STRD	r2, r3, [%[state], #32]\n\t"
        /* Calc b[1] */
        "LDRD	r4, r5, [sp, #8]\n\t"
        "LDRD	r6, r7, [sp, #48]\n\t"
        "LDRD	r8, r9, [sp, #88]\n\t"
        "LDRD	r10, r11, [sp, #128]\n\t"
        "LDR	r12, [sp, #168]\n\t"
        "LDR	lr, [sp, #172]\n\t"
        "EOR	r4, r4, r6\n\t"
        "EOR	r5, r5, r7\n\t"
        "EOR	r4, r4, r8\n\t"
        "EOR	r5, r5, r9\n\t"
        "EOR	r4, r4, r10\n\t"
        "EOR	r5, r5, r11\n\t"
        "EOR	r4, r4, r12\n\t"
        "EOR	r5, r5, lr\n\t"
        "STRD	r4, r5, [%[state], #8]\n\t"
        /* Calc t[0] */
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* Calc b[0] and XOR t[0] into s[x*5+0] */
        "LDRD	r4, r5, [sp]\n\t"
        "LDRD	r6, r7, [sp, #40]\n\t"
        "LDRD	r8, r9, [sp, #80]\n\t"
        "LDRD	r10, r11, [sp, #120]\n\t"
        "EOR	r12, r4, r6\n\t"
        "EOR	lr, r5, r7\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r4, r5, [sp]\n\t"
        "STRD	r6, r7, [sp, #40]\n\t"
        "STRD	r8, r9, [sp, #80]\n\t"
        "STRD	r10, r11, [sp, #120]\n\t"
        "LDRD	r10, r11, [sp, #160]\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r10, r11, [sp, #160]\n\t"
        "STR	r12, [%[state]]\n\t"
        "STR	lr, [%[state], #4]\n\t"
        /* Calc b[3] */
        "LDRD	r4, r5, [sp, #24]\n\t"
        "LDRD	r6, r7, [sp, #64]\n\t"
        "LDRD	r8, r9, [sp, #104]\n\t"
        "LDRD	r10, r11, [sp, #144]\n\t"
        "LDR	r12, [sp, #184]\n\t"
        "LDR	lr, [sp, #188]\n\t"
        "EOR	r4, r4, r6\n\t"
        "EOR	r5, r5, r7\n\t"
        "EOR	r4, r4, r8\n\t"
        "EOR	r5, r5, r9\n\t"
        "EOR	r4, r4, r10\n\t"
        "EOR	r5, r5, r11\n\t"
        "EOR	r4, r4, r12\n\t"
        "EOR	r5, r5, lr\n\t"
        "STRD	r4, r5, [%[state], #24]\n\t"
        /* Calc t[2] */
        "LDRD	r2, r3, [%[state], #8]\n\t"
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* Calc b[2] and XOR t[2] into s[x*5+2] */
        "LDRD	r4, r5, [sp, #16]\n\t"
        "LDRD	r6, r7, [sp, #56]\n\t"
        "LDRD	r8, r9, [sp, #96]\n\t"
        "LDRD	r10, r11, [sp, #136]\n\t"
        "EOR	r12, r4, r6\n\t"
        "EOR	lr, r5, r7\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r4, r5, [sp, #16]\n\t"
        "STRD	r6, r7, [sp, #56]\n\t"
        "STRD	r8, r9, [sp, #96]\n\t"
        "STRD	r10, r11, [sp, #136]\n\t"
        "LDRD	r10, r11, [sp, #176]\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "STRD	r10, r11, [sp, #176]\n\t"
        "STR	r12, [%[state], #16]\n\t"
        "STR	lr, [%[state], #20]\n\t"
        /* Calc t[1] */
        "LDRD	r2, r3, [%[state]]\n\t"
        "EOR	r2, r2, lr, LSR #31\n\t"
        "EOR	r3, r3, r12, LSR #31\n\t"
        "EOR	r2, r2, r12, LSL #1\n\t"
        "EOR	r3, r3, lr, LSL #1\n\t"
        /* XOR t[1] into s[x*5+1] */
        "LDRD	r4, r5, [sp, #8]\n\t"
        "LDRD	r6, r7, [sp, #48]\n\t"
        "LDRD	r8, r9, [sp, #88]\n\t"
        "LDRD	r10, r11, [sp, #128]\n\t"
        "LDR	r12, [sp, #168]\n\t"
        "LDR	lr, [sp, #172]\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STRD	r4, r5, [sp, #8]\n\t"
        "STRD	r6, r7, [sp, #48]\n\t"
        "STRD	r8, r9, [sp, #88]\n\t"
        "STRD	r10, r11, [sp, #128]\n\t"
        "STR	r12, [sp, #168]\n\t"
        "STR	lr, [sp, #172]\n\t"
        /* Calc t[3] */
        "LDRD	r2, r3, [%[state], #16]\n\t"
        "LDRD	r4, r5, [%[state], #32]\n\t"
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* XOR t[3] into s[x*5+3] */
        "LDRD	r4, r5, [sp, #24]\n\t"
        "LDRD	r6, r7, [sp, #64]\n\t"
        "LDRD	r8, r9, [sp, #104]\n\t"
        "LDRD	r10, r11, [sp, #144]\n\t"
        "LDR	r12, [sp, #184]\n\t"
        "LDR	lr, [sp, #188]\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STRD	r4, r5, [sp, #24]\n\t"
        "STRD	r6, r7, [sp, #64]\n\t"
        "STRD	r8, r9, [sp, #104]\n\t"
        "STRD	r10, r11, [sp, #144]\n\t"
        "STR	r12, [sp, #184]\n\t"
        "STR	lr, [sp, #188]\n\t"
        /* Calc t[4] */
        "LDRD	r2, r3, [%[state], #24]\n\t"
        "LDRD	r4, r5, [%[state]]\n\t"
        "EOR	r2, r2, r5, LSR #31\n\t"
        "EOR	r3, r3, r4, LSR #31\n\t"
        "EOR	r2, r2, r4, LSL #1\n\t"
        "EOR	r3, r3, r5, LSL #1\n\t"
        /* XOR t[4] into s[x*5+4] */
        "LDRD	r4, r5, [sp, #32]\n\t"
        "LDRD	r6, r7, [sp, #72]\n\t"
        "LDRD	r8, r9, [sp, #112]\n\t"
        "LDRD	r10, r11, [sp, #152]\n\t"
        "LDR	r12, [sp, #192]\n\t"
        "LDR	lr, [sp, #196]\n\t"
        "EOR	r4, r4, r2\n\t"
        "EOR	r5, r5, r3\n\t"
        "EOR	r6, r6, r2\n\t"
        "EOR	r7, r7, r3\n\t"
        "EOR	r8, r8, r2\n\t"
        "EOR	r9, r9, r3\n\t"
        "EOR	r10, r10, r2\n\t"
        "EOR	r11, r11, r3\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STRD	r4, r5, [sp, #32]\n\t"
        "STRD	r6, r7, [sp, #72]\n\t"
        "STRD	r8, r9, [sp, #112]\n\t"
        "STRD	r10, r11, [sp, #152]\n\t"
        "STR	r12, [sp, #192]\n\t"
        "STR	lr, [sp, #196]\n\t"
        /* Row Mix */
        /* Row 0 */
        "LDRD	r2, r3, [sp]\n\t"
        "LDRD	r4, r5, [sp, #48]\n\t"
        "LDRD	r6, r7, [sp, #96]\n\t"
        "LDRD	r8, r9, [sp, #144]\n\t"
        "LDRD	r10, r11, [sp, #192]\n\t"
        /* s[1] <<< 44 */
        "MOV	lr, r4\n\t"
        "LSR	r12, r5, #20\n\t"
        "LSR	r4, r4, #20\n\t"
        "ORR	r4, r4, r5, LSL #12\n\t"
        "ORR	r5, r12, lr, LSL #12\n\t"
        /* s[2] <<< 43 */
        "MOV	lr, r6\n\t"
        "LSR	r12, r7, #21\n\t"
        "LSR	r6, r6, #21\n\t"
        "ORR	r6, r6, r7, LSL #11\n\t"
        "ORR	r7, r12, lr, LSL #11\n\t"
        /* s[3] <<< 21 */
        "LSR	r12, r9, #11\n\t"
        "LSR	lr, r8, #11\n\t"
        "ORR	r8, r12, r8, LSL #21\n\t"
        "ORR	r9, lr, r9, LSL #21\n\t"
        /* s[4] <<< 14 */
        "LSR	r12, r11, #18\n\t"
        "LSR	lr, r10, #18\n\t"
        "ORR	r10, r12, r10, LSL #14\n\t"
        "ORR	r11, lr, r11, LSL #14\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [%[state], #8]\n\t"
        "STR	lr, [%[state], #12]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [%[state], #16]\n\t"
        "STR	lr, [%[state], #20]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [%[state], #24]\n\t"
        "STR	lr, [%[state], #28]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [%[state], #32]\n\t"
        "STR	lr, [%[state], #36]\n\t"
        /* Get constant */
        "LDRD	r10, r11, [r1]\n\t"
        "ADD	r1, r1, #0x8\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        /* XOR in constant */
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [%[state]]\n\t"
        "STR	lr, [%[state], #4]\n\t"
        /* Row 1 */
        "LDRD	r2, r3, [sp, #24]\n\t"
        "LDRD	r4, r5, [sp, #72]\n\t"
        "LDRD	r6, r7, [sp, #80]\n\t"
        "LDRD	r8, r9, [sp, #128]\n\t"
        "LDRD	r10, r11, [sp, #176]\n\t"
        /* s[0] <<< 28 */
        "LSR	r12, r3, #4\n\t"
        "LSR	lr, r2, #4\n\t"
        "ORR	r2, r12, r2, LSL #28\n\t"
        "ORR	r3, lr, r3, LSL #28\n\t"
        /* s[1] <<< 20 */
        "LSR	r12, r5, #12\n\t"
        "LSR	lr, r4, #12\n\t"
        "ORR	r4, r12, r4, LSL #20\n\t"
        "ORR	r5, lr, r5, LSL #20\n\t"
        /* s[2] <<< 3 */
        "LSR	r12, r7, #29\n\t"
        "LSR	lr, r6, #29\n\t"
        "ORR	r6, r12, r6, LSL #3\n\t"
        "ORR	r7, lr, r7, LSL #3\n\t"
        /* s[3] <<< 45 */
        "MOV	lr, r8\n\t"
        "LSR	r12, r9, #19\n\t"
        "LSR	r8, r8, #19\n\t"
        "ORR	r8, r8, r9, LSL #13\n\t"
        "ORR	r9, r12, lr, LSL #13\n\t"
        /* s[4] <<< 61 */
        "MOV	lr, r10\n\t"
        "LSR	r12, r11, #3\n\t"
        "LSR	r10, r10, #3\n\t"
        "ORR	r10, r10, r11, LSL #29\n\t"
        "ORR	r11, r12, lr, LSL #29\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [%[state], #48]\n\t"
        "STR	lr, [%[state], #52]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [%[state], #56]\n\t"
        "STR	lr, [%[state], #60]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [%[state], #64]\n\t"
        "STR	lr, [%[state], #68]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [%[state], #72]\n\t"
        "STR	lr, [%[state], #76]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [%[state], #40]\n\t"
        "STR	lr, [%[state], #44]\n\t"
        /* Row 2 */
        "LDRD	r2, r3, [sp, #8]\n\t"
        "LDRD	r4, r5, [sp, #56]\n\t"
        "LDRD	r6, r7, [sp, #104]\n\t"
        "LDRD	r8, r9, [sp, #152]\n\t"
        "LDRD	r10, r11, [sp, #160]\n\t"
        /* s[0] <<< 1 */
        "LSR	r12, r3, #31\n\t"
        "LSR	lr, r2, #31\n\t"
        "ORR	r2, r12, r2, LSL #1\n\t"
        "ORR	r3, lr, r3, LSL #1\n\t"
        /* s[1] <<< 6 */
        "LSR	r12, r5, #26\n\t"
        "LSR	lr, r4, #26\n\t"
        "ORR	r4, r12, r4, LSL #6\n\t"
        "ORR	r5, lr, r5, LSL #6\n\t"
        /* s[2] <<< 25 */
        "LSR	r12, r7, #7\n\t"
        "LSR	lr, r6, #7\n\t"
        "ORR	r6, r12, r6, LSL #25\n\t"
        "ORR	r7, lr, r7, LSL #25\n\t"
        /* s[3] <<< 8 */
        "LSR	r12, r9, #24\n\t"
        "LSR	lr, r8, #24\n\t"
        "ORR	r8, r12, r8, LSL #8\n\t"
        "ORR	r9, lr, r9, LSL #8\n\t"
        /* s[4] <<< 18 */
        "LSR	r12, r11, #14\n\t"
        "LSR	lr, r10, #14\n\t"
        "ORR	r10, r12, r10, LSL #18\n\t"
        "ORR	r11, lr, r11, LSL #18\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [%[state], #88]\n\t"
        "STR	lr, [%[state], #92]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [%[state], #96]\n\t"
        "STR	lr, [%[state], #100]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [%[state], #104]\n\t"
        "STR	lr, [%[state], #108]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [%[state], #112]\n\t"
        "STR	lr, [%[state], #116]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [%[state], #80]\n\t"
        "STR	lr, [%[state], #84]\n\t"
        /* Row 3 */
        "LDRD	r2, r3, [sp, #32]\n\t"
        "LDRD	r4, r5, [sp, #40]\n\t"
        "LDRD	r6, r7, [sp, #88]\n\t"
        "LDRD	r8, r9, [sp, #136]\n\t"
        "LDRD	r10, r11, [sp, #184]\n\t"
        /* s[0] <<< 27 */
        "LSR	r12, r3, #5\n\t"
        "LSR	lr, r2, #5\n\t"
        "ORR	r2, r12, r2, LSL #27\n\t"
        "ORR	r3, lr, r3, LSL #27\n\t"
        /* s[1] <<< 36 */
        "MOV	lr, r4\n\t"
        "LSR	r12, r5, #28\n\t"
        "LSR	r4, r4, #28\n\t"
        "ORR	r4, r4, r5, LSL #4\n\t"
        "ORR	r5, r12, lr, LSL #4\n\t"
        /* s[2] <<< 10 */
        "LSR	r12, r7, #22\n\t"
        "LSR	lr, r6, #22\n\t"
        "ORR	r6, r12, r6, LSL #10\n\t"
        "ORR	r7, lr, r7, LSL #10\n\t"
        /* s[3] <<< 15 */
        "LSR	r12, r9, #17\n\t"
        "LSR	lr, r8, #17\n\t"
        "ORR	r8, r12, r8, LSL #15\n\t"
        "ORR	r9, lr, r9, LSL #15\n\t"
        /* s[4] <<< 56 */
        "MOV	lr, r10\n\t"
        "LSR	r12, r11, #8\n\t"
        "LSR	r10, r10, #8\n\t"
        "ORR	r10, r10, r11, LSL #24\n\t"
        "ORR	r11, r12, lr, LSL #24\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [%[state], #128]\n\t"
        "STR	lr, [%[state], #132]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [%[state], #136]\n\t"
        "STR	lr, [%[state], #140]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [%[state], #144]\n\t"
        "STR	lr, [%[state], #148]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [%[state], #152]\n\t"
        "STR	lr, [%[state], #156]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [%[state], #120]\n\t"
        "STR	lr, [%[state], #124]\n\t"
        /* Row 4 */
        "LDRD	r2, r3, [sp, #16]\n\t"
        "LDRD	r4, r5, [sp, #64]\n\t"
        "LDRD	r6, r7, [sp, #112]\n\t"
        "LDRD	r8, r9, [sp, #120]\n\t"
        "LDRD	r10, r11, [sp, #168]\n\t"
        /* s[0] <<< 62 */
        "MOV	lr, r2\n\t"
        "LSR	r12, r3, #2\n\t"
        "LSR	r2, r2, #2\n\t"
        "ORR	r2, r2, r3, LSL #30\n\t"
        "ORR	r3, r12, lr, LSL #30\n\t"
        /* s[1] <<< 55 */
        "MOV	lr, r4\n\t"
        "LSR	r12, r5, #9\n\t"
        "LSR	r4, r4, #9\n\t"
        "ORR	r4, r4, r5, LSL #23\n\t"
        "ORR	r5, r12, lr, LSL #23\n\t"
        /* s[2] <<< 39 */
        "MOV	lr, r6\n\t"
        "LSR	r12, r7, #25\n\t"
        "LSR	r6, r6, #25\n\t"
        "ORR	r6, r6, r7, LSL #7\n\t"
        "ORR	r7, r12, lr, LSL #7\n\t"
        /* s[3] <<< 41 */
        "MOV	lr, r8\n\t"
        "LSR	r12, r9, #23\n\t"
        "LSR	r8, r8, #23\n\t"
        "ORR	r8, r8, r9, LSL #9\n\t"
        "ORR	r9, r12, lr, LSL #9\n\t"
        /* s[4] <<< 2 */
        "LSR	r12, r11, #30\n\t"
        "LSR	lr, r10, #30\n\t"
        "ORR	r10, r12, r10, LSL #2\n\t"
        "ORR	r11, lr, r11, LSL #2\n\t"
        "BIC	r12, r8, r6\n\t"
        "BIC	lr, r9, r7\n\t"
        "EOR	r12, r12, r4\n\t"
        "EOR	lr, lr, r5\n\t"
        "STR	r12, [%[state], #168]\n\t"
        "STR	lr, [%[state], #172]\n\t"
        "BIC	r12, r10, r8\n\t"
        "BIC	lr, r11, r9\n\t"
        "EOR	r12, r12, r6\n\t"
        "EOR	lr, lr, r7\n\t"
        "STR	r12, [%[state], #176]\n\t"
        "STR	lr, [%[state], #180]\n\t"
        "BIC	r12, r2, r10\n\t"
        "BIC	lr, r3, r11\n\t"
        "EOR	r12, r12, r8\n\t"
        "EOR	lr, lr, r9\n\t"
        "STR	r12, [%[state], #184]\n\t"
        "STR	lr, [%[state], #188]\n\t"
        "BIC	r12, r4, r2\n\t"
        "BIC	lr, r5, r3\n\t"
        "EOR	r12, r12, r10\n\t"
        "EOR	lr, lr, r11\n\t"
        "STR	r12, [%[state], #192]\n\t"
        "STR	lr, [%[state], #196]\n\t"
        "BIC	r12, r6, r4\n\t"
        "BIC	lr, r7, r5\n\t"
        "EOR	r12, r12, r2\n\t"
        "EOR	lr, lr, r3\n\t"
        "STR	r12, [%[state], #160]\n\t"
        "STR	lr, [%[state], #164]\n\t"
        "LDR	r2, [sp, #200]\n\t"
        "SUBS	r2, r2, #0x1\n\t"
#if defined(__GNUC__)
        "BNE	L_sha3_thumb2_begin_%=\n\t"
#elif defined(__IAR_SYSTEMS_ICC__) && (__VER__ < 9000000)
        "BNE.W	L_sha3_thumb2_begin\n\t"
#else
        "BNE.W	L_sha3_thumb2_begin_%=\n\t"
#endif
        "ADD	sp, sp, #0xcc\n\t"
#ifndef WOLFSSL_NO_VAR_ASSIGN_REG
        : [state] "+r" (state),
          [L_sha3_thumb2_rt] "+r" (L_sha3_thumb2_rt_c)
        :
        : "memory", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "lr", "cc"
#else
        : [state] "+r" (state)
        : [L_sha3_thumb2_rt] "r" (L_sha3_thumb2_rt)
        : "memory", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "lr", "cc"
#endif /* WOLFSSL_NO_VAR_ASSIGN_REG */
    );
}

#endif /* WOLFSSL_SHA3 */
#endif /* !__aarch64__ && __thumb__ */
#endif /* WOLFSSL_ARMASM */
#endif /* WOLFSSL_ARMASM_INLINE */

/* ca-cert.c
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.
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


/* Certificate + keys for IoT safe example */

/* ./certs/ca-ecc-cert.der, ECC */
static const unsigned char ca_ecc_cert_der_256[] =
{
        0x30, 0x82, 0x02, 0x8A, 0x30, 0x82, 0x02, 0x30, 0xA0, 0x03,
        0x02, 0x01, 0x02, 0x02, 0x09, 0x00, 0x83, 0x47, 0x7C, 0x81,
        0xD6, 0x0D, 0x1C, 0x4E, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86,
        0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x81, 0x97, 0x31,
        0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
        0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04,
        0x08, 0x0C, 0x0A, 0x57, 0x61, 0x73, 0x68, 0x69, 0x6E, 0x67,
        0x74, 0x6F, 0x6E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55,
        0x04, 0x07, 0x0C, 0x07, 0x53, 0x65, 0x61, 0x74, 0x74, 0x6C,
        0x65, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x0A,
        0x0C, 0x07, 0x77, 0x6F, 0x6C, 0x66, 0x53, 0x53, 0x4C, 0x31,
        0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C, 0x0B,
        0x44, 0x65, 0x76, 0x65, 0x6C, 0x6F, 0x70, 0x6D, 0x65, 0x6E,
        0x74, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03,
        0x0C, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x6F, 0x6C, 0x66,
        0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x31, 0x1F, 0x30,
        0x1D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01,
        0x09, 0x01, 0x16, 0x10, 0x69, 0x6E, 0x66, 0x6F, 0x40, 0x77,
        0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D,
        0x30, 0x1E, 0x17, 0x0D, 0x32, 0x31, 0x30, 0x32, 0x31, 0x30,
        0x31, 0x39, 0x34, 0x39, 0x35, 0x33, 0x5A, 0x17, 0x0D, 0x32,
        0x33, 0x31, 0x31, 0x30, 0x37, 0x31, 0x39, 0x34, 0x39, 0x35,
        0x33, 0x5A, 0x30, 0x81, 0x97, 0x31, 0x0B, 0x30, 0x09, 0x06,
        0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x13,
        0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0C, 0x0A, 0x57,
        0x61, 0x73, 0x68, 0x69, 0x6E, 0x67, 0x74, 0x6F, 0x6E, 0x31,
        0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x0C, 0x07,
        0x53, 0x65, 0x61, 0x74, 0x74, 0x6C, 0x65, 0x31, 0x10, 0x30,
        0x0E, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x0C, 0x07, 0x77, 0x6F,
        0x6C, 0x66, 0x53, 0x53, 0x4C, 0x31, 0x14, 0x30, 0x12, 0x06,
        0x03, 0x55, 0x04, 0x0B, 0x0C, 0x0B, 0x44, 0x65, 0x76, 0x65,
        0x6C, 0x6F, 0x70, 0x6D, 0x65, 0x6E, 0x74, 0x31, 0x18, 0x30,
        0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0F, 0x77, 0x77,
        0x77, 0x2E, 0x77, 0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E,
        0x63, 0x6F, 0x6D, 0x31, 0x1F, 0x30, 0x1D, 0x06, 0x09, 0x2A,
        0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x01, 0x16, 0x10,
        0x69, 0x6E, 0x66, 0x6F, 0x40, 0x77, 0x6F, 0x6C, 0x66, 0x73,
        0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x30, 0x59, 0x30, 0x13,
        0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06,
        0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03,
        0x42, 0x00, 0x04, 0x02, 0xD3, 0xD9, 0x6E, 0xD6, 0x01, 0x8E,
        0x45, 0xC8, 0xB9, 0x90, 0x31, 0xE5, 0xC0, 0x4C, 0xE3, 0x9E,
        0xAD, 0x29, 0x38, 0x98, 0xBA, 0x10, 0xD6, 0xE9, 0x09, 0x2A,
        0x80, 0xA9, 0x2E, 0x17, 0x2A, 0xB9, 0x8A, 0xBF, 0x33, 0x83,
        0x46, 0xE3, 0x95, 0x0B, 0xE4, 0x77, 0x40, 0xB5, 0x3B, 0x43,
        0x45, 0x33, 0x0F, 0x61, 0x53, 0x7C, 0x37, 0x44, 0xC1, 0xCB,
        0xFC, 0x80, 0xCA, 0xE8, 0x43, 0xEA, 0xA7, 0xA3, 0x63, 0x30,
        0x61, 0x30, 0x1D, 0x06, 0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16,
        0x04, 0x14, 0x56, 0x8E, 0x9A, 0xC3, 0xF0, 0x42, 0xDE, 0x18,
        0xB9, 0x45, 0x55, 0x6E, 0xF9, 0x93, 0xCF, 0xEA, 0xC3, 0xF3,
        0xA5, 0x21, 0x30, 0x1F, 0x06, 0x03, 0x55, 0x1D, 0x23, 0x04,
        0x18, 0x30, 0x16, 0x80, 0x14, 0x56, 0x8E, 0x9A, 0xC3, 0xF0,
        0x42, 0xDE, 0x18, 0xB9, 0x45, 0x55, 0x6E, 0xF9, 0x93, 0xCF,
        0xEA, 0xC3, 0xF3, 0xA5, 0x21, 0x30, 0x0F, 0x06, 0x03, 0x55,
        0x1D, 0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03, 0x01,
        0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x1D, 0x0F, 0x01,
        0x01, 0xFF, 0x04, 0x04, 0x03, 0x02, 0x01, 0x86, 0x30, 0x0A,
        0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02,
        0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x21, 0x00, 0xC5, 0x83,
        0xFF, 0x1E, 0x51, 0xF7, 0xA1, 0xE9, 0xF1, 0x42, 0xC4, 0xBE,
        0xED, 0x38, 0xBD, 0x38, 0x32, 0x8F, 0xAE, 0x3F, 0xC7, 0x6D,
        0x11, 0x90, 0xE9, 0x99, 0xAB, 0x61, 0xA2, 0xDB, 0xA7, 0x4B,
        0x02, 0x20, 0x28, 0x40, 0xD9, 0xBA, 0x45, 0xCC, 0xA6, 0xEA,
        0xFA, 0x3F, 0x3E, 0x71, 0x44, 0x8E, 0x02, 0x03, 0x2F, 0x41,
        0x0B, 0x56, 0x78, 0x2D, 0xA6, 0xE8, 0x5E, 0xF6, 0xFF, 0xDA,
        0x62, 0x8C, 0xF9, 0xDF
};
static const int sizeof_ca_ecc_cert_der_256 = sizeof(ca_ecc_cert_der_256);

/* ./certs/ca-cert.der, 2048-bit */
static const unsigned char ca_cert_der_2048[] =
{
        0x30, 0x82, 0x04, 0xE9, 0x30, 0x82, 0x03, 0xD1, 0xA0, 0x03,
        0x02, 0x01, 0x02, 0x02, 0x09, 0x00, 0xAA, 0xD3, 0x3F, 0xAC,
        0x18, 0x0A, 0x37, 0x4D, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86,
        0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B, 0x05, 0x00, 0x30,
        0x81, 0x94, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
        0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x10, 0x30, 0x0E, 0x06,
        0x03, 0x55, 0x04, 0x08, 0x0C, 0x07, 0x4D, 0x6F, 0x6E, 0x74,
        0x61, 0x6E, 0x61, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55,
        0x04, 0x07, 0x0C, 0x07, 0x42, 0x6F, 0x7A, 0x65, 0x6D, 0x61,
        0x6E, 0x31, 0x11, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x04, 0x0A,
        0x0C, 0x08, 0x53, 0x61, 0x77, 0x74, 0x6F, 0x6F, 0x74, 0x68,
        0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C,
        0x0A, 0x43, 0x6F, 0x6E, 0x73, 0x75, 0x6C, 0x74, 0x69, 0x6E,
        0x67, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03,
        0x0C, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x6F, 0x6C, 0x66,
        0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x31, 0x1F, 0x30,
        0x1D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01,
        0x09, 0x01, 0x16, 0x10, 0x69, 0x6E, 0x66, 0x6F, 0x40, 0x77,
        0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D,
        0x30, 0x1E, 0x17, 0x0D, 0x32, 0x31, 0x30, 0x32, 0x31, 0x30,
        0x31, 0x39, 0x34, 0x39, 0x35, 0x32, 0x5A, 0x17, 0x0D, 0x32,
        0x33, 0x31, 0x31, 0x30, 0x37, 0x31, 0x39, 0x34, 0x39, 0x35,
        0x32, 0x5A, 0x30, 0x81, 0x94, 0x31, 0x0B, 0x30, 0x09, 0x06,
        0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x10,
        0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0C, 0x07, 0x4D,
        0x6F, 0x6E, 0x74, 0x61, 0x6E, 0x61, 0x31, 0x10, 0x30, 0x0E,
        0x06, 0x03, 0x55, 0x04, 0x07, 0x0C, 0x07, 0x42, 0x6F, 0x7A,
        0x65, 0x6D, 0x61, 0x6E, 0x31, 0x11, 0x30, 0x0F, 0x06, 0x03,
        0x55, 0x04, 0x0A, 0x0C, 0x08, 0x53, 0x61, 0x77, 0x74, 0x6F,
        0x6F, 0x74, 0x68, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55,
        0x04, 0x0B, 0x0C, 0x0A, 0x43, 0x6F, 0x6E, 0x73, 0x75, 0x6C,
        0x74, 0x69, 0x6E, 0x67, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03,
        0x55, 0x04, 0x03, 0x0C, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77,
        0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D,
        0x31, 0x1F, 0x30, 0x1D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86,
        0xF7, 0x0D, 0x01, 0x09, 0x01, 0x16, 0x10, 0x69, 0x6E, 0x66,
        0x6F, 0x40, 0x77, 0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E,
        0x63, 0x6F, 0x6D, 0x30, 0x82, 0x01, 0x22, 0x30, 0x0D, 0x06,
        0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
        0x05, 0x00, 0x03, 0x82, 0x01, 0x0F, 0x00, 0x30, 0x82, 0x01,
        0x0A, 0x02, 0x82, 0x01, 0x01, 0x00, 0xBF, 0x0C, 0xCA, 0x2D,
        0x14, 0xB2, 0x1E, 0x84, 0x42, 0x5B, 0xCD, 0x38, 0x1F, 0x4A,
        0xF2, 0x4D, 0x75, 0x10, 0xF1, 0xB6, 0x35, 0x9F, 0xDF, 0xCA,
        0x7D, 0x03, 0x98, 0xD3, 0xAC, 0xDE, 0x03, 0x66, 0xEE, 0x2A,
        0xF1, 0xD8, 0xB0, 0x7D, 0x6E, 0x07, 0x54, 0x0B, 0x10, 0x98,
        0x21, 0x4D, 0x80, 0xCB, 0x12, 0x20, 0xE7, 0xCC, 0x4F, 0xDE,
        0x45, 0x7D, 0xC9, 0x72, 0x77, 0x32, 0xEA, 0xCA, 0x90, 0xBB,
        0x69, 0x52, 0x10, 0x03, 0x2F, 0xA8, 0xF3, 0x95, 0xC5, 0xF1,
        0x8B, 0x62, 0x56, 0x1B, 0xEF, 0x67, 0x6F, 0xA4, 0x10, 0x41,
        0x95, 0xAD, 0x0A, 0x9B, 0xE3, 0xA5, 0xC0, 0xB0, 0xD2, 0x70,
        0x76, 0x50, 0x30, 0x5B, 0xA8, 0xE8, 0x08, 0x2C, 0x7C, 0xED,
        0xA7, 0xA2, 0x7A, 0x8D, 0x38, 0x29, 0x1C, 0xAC, 0xC7, 0xED,
        0xF2, 0x7C, 0x95, 0xB0, 0x95, 0x82, 0x7D, 0x49, 0x5C, 0x38,
        0xCD, 0x77, 0x25, 0xEF, 0xBD, 0x80, 0x75, 0x53, 0x94, 0x3C,
        0x3D, 0xCA, 0x63, 0x5B, 0x9F, 0x15, 0xB5, 0xD3, 0x1D, 0x13,
        0x2F, 0x19, 0xD1, 0x3C, 0xDB, 0x76, 0x3A, 0xCC, 0xB8, 0x7D,
        0xC9, 0xE5, 0xC2, 0xD7, 0xDA, 0x40, 0x6F, 0xD8, 0x21, 0xDC,
        0x73, 0x1B, 0x42, 0x2D, 0x53, 0x9C, 0xFE, 0x1A, 0xFC, 0x7D,
        0xAB, 0x7A, 0x36, 0x3F, 0x98, 0xDE, 0x84, 0x7C, 0x05, 0x67,
        0xCE, 0x6A, 0x14, 0x38, 0x87, 0xA9, 0xF1, 0x8C, 0xB5, 0x68,
        0xCB, 0x68, 0x7F, 0x71, 0x20, 0x2B, 0xF5, 0xA0, 0x63, 0xF5,
        0x56, 0x2F, 0xA3, 0x26, 0xD2, 0xB7, 0x6F, 0xB1, 0x5A, 0x17,
        0xD7, 0x38, 0x99, 0x08, 0xFE, 0x93, 0x58, 0x6F, 0xFE, 0xC3,
        0x13, 0x49, 0x08, 0x16, 0x0B, 0xA7, 0x4D, 0x67, 0x00, 0x52,
        0x31, 0x67, 0x23, 0x4E, 0x98, 0xED, 0x51, 0x45, 0x1D, 0xB9,
        0x04, 0xD9, 0x0B, 0xEC, 0xD8, 0x28, 0xB3, 0x4B, 0xBD, 0xED,
        0x36, 0x79, 0x02, 0x03, 0x01, 0x00, 0x01, 0xA3, 0x82, 0x01,
        0x3A, 0x30, 0x82, 0x01, 0x36, 0x30, 0x1D, 0x06, 0x03, 0x55,
        0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0x27, 0x8E, 0x67, 0x11,
        0x74, 0xC3, 0x26, 0x1D, 0x3F, 0xED, 0x33, 0x63, 0xB3, 0xA4,
        0xD8, 0x1D, 0x30, 0xE5, 0xE8, 0xD5, 0x30, 0x81, 0xC9, 0x06,
        0x03, 0x55, 0x1D, 0x23, 0x04, 0x81, 0xC1, 0x30, 0x81, 0xBE,
        0x80, 0x14, 0x27, 0x8E, 0x67, 0x11, 0x74, 0xC3, 0x26, 0x1D,
        0x3F, 0xED, 0x33, 0x63, 0xB3, 0xA4, 0xD8, 0x1D, 0x30, 0xE5,
        0xE8, 0xD5, 0xA1, 0x81, 0x9A, 0xA4, 0x81, 0x97, 0x30, 0x81,
        0x94, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
        0x13, 0x02, 0x55, 0x53, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03,
        0x55, 0x04, 0x08, 0x0C, 0x07, 0x4D, 0x6F, 0x6E, 0x74, 0x61,
        0x6E, 0x61, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04,
        0x07, 0x0C, 0x07, 0x42, 0x6F, 0x7A, 0x65, 0x6D, 0x61, 0x6E,
        0x31, 0x11, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x0C,
        0x08, 0x53, 0x61, 0x77, 0x74, 0x6F, 0x6F, 0x74, 0x68, 0x31,
        0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C, 0x0A,
        0x43, 0x6F, 0x6E, 0x73, 0x75, 0x6C, 0x74, 0x69, 0x6E, 0x67,
        0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C,
        0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x6F, 0x6C, 0x66, 0x73,
        0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x31, 0x1F, 0x30, 0x1D,
        0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09,
        0x01, 0x16, 0x10, 0x69, 0x6E, 0x66, 0x6F, 0x40, 0x77, 0x6F,
        0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x82,
        0x09, 0x00, 0xAA, 0xD3, 0x3F, 0xAC, 0x18, 0x0A, 0x37, 0x4D,
        0x30, 0x0C, 0x06, 0x03, 0x55, 0x1D, 0x13, 0x04, 0x05, 0x30,
        0x03, 0x01, 0x01, 0xFF, 0x30, 0x1C, 0x06, 0x03, 0x55, 0x1D,
        0x11, 0x04, 0x15, 0x30, 0x13, 0x82, 0x0B, 0x65, 0x78, 0x61,
        0x6D, 0x70, 0x6C, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x87, 0x04,
        0x7F, 0x00, 0x00, 0x01, 0x30, 0x1D, 0x06, 0x03, 0x55, 0x1D,
        0x25, 0x04, 0x16, 0x30, 0x14, 0x06, 0x08, 0x2B, 0x06, 0x01,
        0x05, 0x05, 0x07, 0x03, 0x01, 0x06, 0x08, 0x2B, 0x06, 0x01,
        0x05, 0x05, 0x07, 0x03, 0x02, 0x30, 0x0D, 0x06, 0x09, 0x2A,
        0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B, 0x05, 0x00,
        0x03, 0x82, 0x01, 0x01, 0x00, 0x62, 0x98, 0xC8, 0x58, 0xCF,
        0x56, 0x03, 0x86, 0x5B, 0x1B, 0x71, 0x49, 0x7D, 0x05, 0x03,
        0x5D, 0xE0, 0x08, 0x86, 0xAD, 0xDB, 0x4A, 0xDE, 0xAB, 0x22,
        0x96, 0xA8, 0xC3, 0x59, 0x68, 0xC1, 0x37, 0x90, 0x40, 0xDF,
        0xBD, 0x89, 0xD0, 0xBC, 0xDA, 0x8E, 0xEF, 0x87, 0xB2, 0xC2,
        0x62, 0x52, 0xE1, 0x1A, 0x29, 0x17, 0x6A, 0x96, 0x99, 0xC8,
        0x4E, 0xD8, 0x32, 0xFE, 0xB8, 0xD1, 0x5C, 0x3B, 0x0A, 0xC2,
        0x3C, 0x5F, 0xA1, 0x1E, 0x98, 0x7F, 0xCE, 0x89, 0x26, 0x21,
        0x1F, 0x64, 0x9C, 0x15, 0x7A, 0x9C, 0xEF, 0xFB, 0x1D, 0x85,
        0x6A, 0xFA, 0x98, 0xCE, 0xA8, 0xA9, 0xAB, 0xC3, 0xA2, 0xC0,
        0xEB, 0x87, 0xED, 0xBC, 0x21, 0xDF, 0xF3, 0x07, 0x5B, 0xAE,
        0xFD, 0x40, 0xD4, 0xAE, 0x20, 0xD0, 0x76, 0x8A, 0x31, 0x0A,
        0xA2, 0x62, 0x7C, 0x61, 0x0D, 0xCE, 0x5D, 0x9A, 0x1E, 0xE4,
        0x20, 0x88, 0x51, 0x49, 0xFB, 0x77, 0xA9, 0xCD, 0x4D, 0xC6,
        0xBF, 0x54, 0x99, 0x33, 0xEF, 0x4B, 0xA0, 0x73, 0x70, 0x6D,
        0x2E, 0xD9, 0x3D, 0x08, 0xF6, 0x12, 0x39, 0x31, 0x68, 0xC6,
        0x61, 0x5C, 0x41, 0xB5, 0x1B, 0xF4, 0x38, 0x7D, 0xFC, 0xBE,
        0x73, 0x66, 0x2D, 0xF7, 0xCA, 0x5B, 0x2C, 0x5B, 0x31, 0xAA,
        0xCF, 0xF6, 0x7F, 0x30, 0xE4, 0x12, 0x2C, 0x8E, 0xD6, 0x38,
        0x51, 0xE6, 0x45, 0xEE, 0xD5, 0xDA, 0xC3, 0x83, 0xD6, 0xED,
        0x5E, 0xEC, 0xD6, 0xB6, 0x14, 0xB3, 0x93, 0x59, 0xE1, 0x55,
        0x4A, 0x7F, 0x04, 0xDF, 0xCE, 0x65, 0xD4, 0xDF, 0x18, 0x4F,
        0xDD, 0xB4, 0x45, 0x7F, 0xA6, 0x56, 0x30, 0xC4, 0x05, 0x44,
        0x98, 0x9D, 0x4F, 0x26, 0x6D, 0x84, 0x80, 0xA0, 0x5E, 0xED,
        0x23, 0xD1, 0x48, 0x87, 0x0E, 0x05, 0x06, 0x91, 0x3B, 0xB0,
        0x3C, 0xBB, 0x8C, 0x8F, 0x3C, 0x7B, 0x4C, 0x4F, 0xA1, 0xCA,
        0x98
};
static const int sizeof_ca_cert_der_2048 = sizeof(ca_cert_der_2048);


/* ./certs/ecc-key.der, ECC */
static const unsigned char ecc_key_der_256[] =
{
        0x30, 0x77, 0x02, 0x01, 0x01, 0x04, 0x20, 0x45, 0xB6, 0x69,
        0x02, 0x73, 0x9C, 0x6C, 0x85, 0xA1, 0x38, 0x5B, 0x72, 0xE8,
        0xE8, 0xC7, 0xAC, 0xC4, 0x03, 0x8D, 0x53, 0x35, 0x04, 0xFA,
        0x6C, 0x28, 0xDC, 0x34, 0x8D, 0xE1, 0xA8, 0x09, 0x8C, 0xA0,
        0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01,
        0x07, 0xA1, 0x44, 0x03, 0x42, 0x00, 0x04, 0xBB, 0x33, 0xAC,
        0x4C, 0x27, 0x50, 0x4A, 0xC6, 0x4A, 0xA5, 0x04, 0xC3, 0x3C,
        0xDE, 0x9F, 0x36, 0xDB, 0x72, 0x2D, 0xCE, 0x94, 0xEA, 0x2B,
        0xFA, 0xCB, 0x20, 0x09, 0x39, 0x2C, 0x16, 0xE8, 0x61, 0x02,
        0xE9, 0xAF, 0x4D, 0xD3, 0x02, 0x93, 0x9A, 0x31, 0x5B, 0x97,
        0x92, 0x21, 0x7F, 0xF0, 0xCF, 0x18, 0xDA, 0x91, 0x11, 0x02,
        0x34, 0x86, 0xE8, 0x20, 0x58, 0x33, 0x0B, 0x80, 0x34, 0x89,
        0xD8
};
static const int sizeof_ecc_key_der_256 = sizeof(ecc_key_der_256);

/* ./certs/ecc-client-key.der, ECC */
static const unsigned char ecc_clikey_der_256[] =
{
        0x30, 0x77, 0x02, 0x01, 0x01, 0x04, 0x20, 0xF8, 0xCF, 0x92,
        0x6B, 0xBD, 0x1E, 0x28, 0xF1, 0xA8, 0xAB, 0xA1, 0x23, 0x4F,
        0x32, 0x74, 0x18, 0x88, 0x50, 0xAD, 0x7E, 0xC7, 0xEC, 0x92,
        0xF8, 0x8F, 0x97, 0x4D, 0xAF, 0x56, 0x89, 0x65, 0xC7, 0xA0,
        0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01,
        0x07, 0xA1, 0x44, 0x03, 0x42, 0x00, 0x04, 0x55, 0xBF, 0xF4,
        0x0F, 0x44, 0x50, 0x9A, 0x3D, 0xCE, 0x9B, 0xB7, 0xF0, 0xC5,
        0x4D, 0xF5, 0x70, 0x7B, 0xD4, 0xEC, 0x24, 0x8E, 0x19, 0x80,
        0xEC, 0x5A, 0x4C, 0xA2, 0x24, 0x03, 0x62, 0x2C, 0x9B, 0xDA,
        0xEF, 0xA2, 0x35, 0x12, 0x43, 0x84, 0x76, 0x16, 0xC6, 0x56,
        0x95, 0x06, 0xCC, 0x01, 0xA9, 0xBD, 0xF6, 0x75, 0x1A, 0x42,
        0xF7, 0xBD, 0xA9, 0xB2, 0x36, 0x22, 0x5F, 0xC7, 0x5D, 0x7F,
        0xB4
};
static const int sizeof_ecc_clikey_der_256 = sizeof(ecc_clikey_der_256);

/* ./certs/client-ecc-cert.der, ECC */
static const unsigned char cliecc_cert_der_256[] =
{
        0x30, 0x82, 0x03, 0x49, 0x30, 0x82, 0x02, 0xEE, 0xA0, 0x03,
        0x02, 0x01, 0x02, 0x02, 0x09, 0x00, 0xE7, 0x4A, 0x4F, 0xE5,
        0x56, 0x97, 0xCA, 0xC3, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86,
        0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x81, 0x8D, 0x31,
        0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
        0x55, 0x53, 0x31, 0x0F, 0x30, 0x0D, 0x06, 0x03, 0x55, 0x04,
        0x08, 0x0C, 0x06, 0x4F, 0x72, 0x65, 0x67, 0x6F, 0x6E, 0x31,
        0x0E, 0x30, 0x0C, 0x06, 0x03, 0x55, 0x04, 0x07, 0x0C, 0x05,
        0x53, 0x61, 0x6C, 0x65, 0x6D, 0x31, 0x13, 0x30, 0x11, 0x06,
        0x03, 0x55, 0x04, 0x0A, 0x0C, 0x0A, 0x43, 0x6C, 0x69, 0x65,
        0x6E, 0x74, 0x20, 0x45, 0x43, 0x43, 0x31, 0x0D, 0x30, 0x0B,
        0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C, 0x04, 0x46, 0x61, 0x73,
        0x74, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03,
        0x0C, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x6F, 0x6C, 0x66,
        0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x31, 0x1F, 0x30,
        0x1D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01,
        0x09, 0x01, 0x16, 0x10, 0x69, 0x6E, 0x66, 0x6F, 0x40, 0x77,
        0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D,
        0x30, 0x1E, 0x17, 0x0D, 0x32, 0x31, 0x30, 0x32, 0x31, 0x30,
        0x31, 0x39, 0x34, 0x39, 0x35, 0x33, 0x5A, 0x17, 0x0D, 0x32,
        0x33, 0x31, 0x31, 0x30, 0x37, 0x31, 0x39, 0x34, 0x39, 0x35,
        0x33, 0x5A, 0x30, 0x81, 0x8D, 0x31, 0x0B, 0x30, 0x09, 0x06,
        0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x0F,
        0x30, 0x0D, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0C, 0x06, 0x4F,
        0x72, 0x65, 0x67, 0x6F, 0x6E, 0x31, 0x0E, 0x30, 0x0C, 0x06,
        0x03, 0x55, 0x04, 0x07, 0x0C, 0x05, 0x53, 0x61, 0x6C, 0x65,
        0x6D, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0A,
        0x0C, 0x0A, 0x43, 0x6C, 0x69, 0x65, 0x6E, 0x74, 0x20, 0x45,
        0x43, 0x43, 0x31, 0x0D, 0x30, 0x0B, 0x06, 0x03, 0x55, 0x04,
        0x0B, 0x0C, 0x04, 0x46, 0x61, 0x73, 0x74, 0x31, 0x18, 0x30,
        0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0F, 0x77, 0x77,
        0x77, 0x2E, 0x77, 0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E,
        0x63, 0x6F, 0x6D, 0x31, 0x1F, 0x30, 0x1D, 0x06, 0x09, 0x2A,
        0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x01, 0x16, 0x10,
        0x69, 0x6E, 0x66, 0x6F, 0x40, 0x77, 0x6F, 0x6C, 0x66, 0x73,
        0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x30, 0x59, 0x30, 0x13,
        0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06,
        0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03,
        0x42, 0x00, 0x04, 0x55, 0xBF, 0xF4, 0x0F, 0x44, 0x50, 0x9A,
        0x3D, 0xCE, 0x9B, 0xB7, 0xF0, 0xC5, 0x4D, 0xF5, 0x70, 0x7B,
        0xD4, 0xEC, 0x24, 0x8E, 0x19, 0x80, 0xEC, 0x5A, 0x4C, 0xA2,
        0x24, 0x03, 0x62, 0x2C, 0x9B, 0xDA, 0xEF, 0xA2, 0x35, 0x12,
        0x43, 0x84, 0x76, 0x16, 0xC6, 0x56, 0x95, 0x06, 0xCC, 0x01,
        0xA9, 0xBD, 0xF6, 0x75, 0x1A, 0x42, 0xF7, 0xBD, 0xA9, 0xB2,
        0x36, 0x22, 0x5F, 0xC7, 0x5D, 0x7F, 0xB4, 0xA3, 0x82, 0x01,
        0x33, 0x30, 0x82, 0x01, 0x2F, 0x30, 0x1D, 0x06, 0x03, 0x55,
        0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xEB, 0xD4, 0x4B, 0x59,
        0x6B, 0x95, 0x61, 0x3F, 0x51, 0x57, 0xB6, 0x04, 0x4D, 0x89,
        0x41, 0x88, 0x44, 0x5C, 0xAB, 0xF2, 0x30, 0x81, 0xC2, 0x06,
        0x03, 0x55, 0x1D, 0x23, 0x04, 0x81, 0xBA, 0x30, 0x81, 0xB7,
        0x80, 0x14, 0xEB, 0xD4, 0x4B, 0x59, 0x6B, 0x95, 0x61, 0x3F,
        0x51, 0x57, 0xB6, 0x04, 0x4D, 0x89, 0x41, 0x88, 0x44, 0x5C,
        0xAB, 0xF2, 0xA1, 0x81, 0x93, 0xA4, 0x81, 0x90, 0x30, 0x81,
        0x8D, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
        0x13, 0x02, 0x55, 0x53, 0x31, 0x0F, 0x30, 0x0D, 0x06, 0x03,
        0x55, 0x04, 0x08, 0x0C, 0x06, 0x4F, 0x72, 0x65, 0x67, 0x6F,
        0x6E, 0x31, 0x0E, 0x30, 0x0C, 0x06, 0x03, 0x55, 0x04, 0x07,
        0x0C, 0x05, 0x53, 0x61, 0x6C, 0x65, 0x6D, 0x31, 0x13, 0x30,
        0x11, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x0C, 0x0A, 0x43, 0x6C,
        0x69, 0x65, 0x6E, 0x74, 0x20, 0x45, 0x43, 0x43, 0x31, 0x0D,
        0x30, 0x0B, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C, 0x04, 0x46,
        0x61, 0x73, 0x74, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55,
        0x04, 0x03, 0x0C, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x6F,
        0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x31,
        0x1F, 0x30, 0x1D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
        0x0D, 0x01, 0x09, 0x01, 0x16, 0x10, 0x69, 0x6E, 0x66, 0x6F,
        0x40, 0x77, 0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63,
        0x6F, 0x6D, 0x82, 0x09, 0x00, 0xE7, 0x4A, 0x4F, 0xE5, 0x56,
        0x97, 0xCA, 0xC3, 0x30, 0x0C, 0x06, 0x03, 0x55, 0x1D, 0x13,
        0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xFF, 0x30, 0x1C, 0x06,
        0x03, 0x55, 0x1D, 0x11, 0x04, 0x15, 0x30, 0x13, 0x82, 0x0B,
        0x65, 0x78, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x2E, 0x63, 0x6F,
        0x6D, 0x87, 0x04, 0x7F, 0x00, 0x00, 0x01, 0x30, 0x1D, 0x06,
        0x03, 0x55, 0x1D, 0x25, 0x04, 0x16, 0x30, 0x14, 0x06, 0x08,
        0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x01, 0x06, 0x08,
        0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x02, 0x30, 0x0A,
        0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02,
        0x03, 0x49, 0x00, 0x30, 0x46, 0x02, 0x21, 0x00, 0xE3, 0xBB,
        0xCA, 0x0E, 0x31, 0x2D, 0x39, 0x1D, 0x94, 0x25, 0x81, 0x90,
        0xD5, 0x11, 0xF9, 0x09, 0x6D, 0x58, 0x16, 0x23, 0xBE, 0x9F,
        0xA9, 0x18, 0x64, 0x83, 0x3C, 0x25, 0x03, 0x58, 0x58, 0x39,
        0x02, 0x21, 0x00, 0xA4, 0xAA, 0xB3, 0xF0, 0x09, 0xC9, 0x0C,
        0x2F, 0xF7, 0xB1, 0xD4, 0x8E, 0x9F, 0xA6, 0xB6, 0xAB, 0x1A,
        0xC7, 0x37, 0xED, 0x70, 0x4D, 0x34, 0x04, 0xA0, 0x9B, 0x3D,
        0x84, 0x86, 0x10, 0xA0, 0xF0
};
static const int sizeof_cliecc_cert_der_256 = sizeof(cliecc_cert_der_256);

/* ./certs/server-ecc.der, ECC */
static const unsigned char serv_ecc_der_256[] =
{
        0x30, 0x82, 0x02, 0xA1, 0x30, 0x82, 0x02, 0x47, 0xA0, 0x03,
        0x02, 0x01, 0x02, 0x02, 0x01, 0x03, 0x30, 0x0A, 0x06, 0x08,
        0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x81,
        0x97, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
        0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03,
        0x55, 0x04, 0x08, 0x0C, 0x0A, 0x57, 0x61, 0x73, 0x68, 0x69,
        0x6E, 0x67, 0x74, 0x6F, 0x6E, 0x31, 0x10, 0x30, 0x0E, 0x06,
        0x03, 0x55, 0x04, 0x07, 0x0C, 0x07, 0x53, 0x65, 0x61, 0x74,
        0x74, 0x6C, 0x65, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55,
        0x04, 0x0A, 0x0C, 0x07, 0x77, 0x6F, 0x6C, 0x66, 0x53, 0x53,
        0x4C, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0B,
        0x0C, 0x0B, 0x44, 0x65, 0x76, 0x65, 0x6C, 0x6F, 0x70, 0x6D,
        0x65, 0x6E, 0x74, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55,
        0x04, 0x03, 0x0C, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x6F,
        0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x31,
        0x1F, 0x30, 0x1D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
        0x0D, 0x01, 0x09, 0x01, 0x16, 0x10, 0x69, 0x6E, 0x66, 0x6F,
        0x40, 0x77, 0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63,
        0x6F, 0x6D, 0x30, 0x1E, 0x17, 0x0D, 0x32, 0x31, 0x30, 0x32,
        0x31, 0x30, 0x31, 0x39, 0x34, 0x39, 0x35, 0x33, 0x5A, 0x17,
        0x0D, 0x32, 0x33, 0x31, 0x31, 0x30, 0x37, 0x31, 0x39, 0x34,
        0x39, 0x35, 0x33, 0x5A, 0x30, 0x81, 0x8F, 0x31, 0x0B, 0x30,
        0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53,
        0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0C,
        0x0A, 0x57, 0x61, 0x73, 0x68, 0x69, 0x6E, 0x67, 0x74, 0x6F,
        0x6E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07,
        0x0C, 0x07, 0x53, 0x65, 0x61, 0x74, 0x74, 0x6C, 0x65, 0x31,
        0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x0C, 0x07,
        0x45, 0x6C, 0x69, 0x70, 0x74, 0x69, 0x63, 0x31, 0x0C, 0x30,
        0x0A, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C, 0x03, 0x45, 0x43,
        0x43, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03,
        0x0C, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x6F, 0x6C, 0x66,
        0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x31, 0x1F, 0x30,
        0x1D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01,
        0x09, 0x01, 0x16, 0x10, 0x69, 0x6E, 0x66, 0x6F, 0x40, 0x77,
        0x6F, 0x6C, 0x66, 0x73, 0x73, 0x6C, 0x2E, 0x63, 0x6F, 0x6D,
        0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE,
        0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D,
        0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0xBB, 0x33, 0xAC,
        0x4C, 0x27, 0x50, 0x4A, 0xC6, 0x4A, 0xA5, 0x04, 0xC3, 0x3C,
        0xDE, 0x9F, 0x36, 0xDB, 0x72, 0x2D, 0xCE, 0x94, 0xEA, 0x2B,
        0xFA, 0xCB, 0x20, 0x09, 0x39, 0x2C, 0x16, 0xE8, 0x61, 0x02,
        0xE9, 0xAF, 0x4D, 0xD3, 0x02, 0x93, 0x9A, 0x31, 0x5B, 0x97,
        0x92, 0x21, 0x7F, 0xF0, 0xCF, 0x18, 0xDA, 0x91, 0x11, 0x02,
        0x34, 0x86, 0xE8, 0x20, 0x58, 0x33, 0x0B, 0x80, 0x34, 0x89,
        0xD8, 0xA3, 0x81, 0x89, 0x30, 0x81, 0x86, 0x30, 0x1D, 0x06,
        0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0x5D, 0x5D,
        0x26, 0xEF, 0xAC, 0x7E, 0x36, 0xF9, 0x9B, 0x76, 0x15, 0x2B,
        0x4A, 0x25, 0x02, 0x23, 0xEF, 0xB2, 0x89, 0x30, 0x30, 0x1F,
        0x06, 0x03, 0x55, 0x1D, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80,
        0x14, 0x56, 0x8E, 0x9A, 0xC3, 0xF0, 0x42, 0xDE, 0x18, 0xB9,
        0x45, 0x55, 0x6E, 0xF9, 0x93, 0xCF, 0xEA, 0xC3, 0xF3, 0xA5,
        0x21, 0x30, 0x0C, 0x06, 0x03, 0x55, 0x1D, 0x13, 0x01, 0x01,
        0xFF, 0x04, 0x02, 0x30, 0x00, 0x30, 0x0E, 0x06, 0x03, 0x55,
        0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03, 0x02, 0x03,
        0xA8, 0x30, 0x13, 0x06, 0x03, 0x55, 0x1D, 0x25, 0x04, 0x0C,
        0x30, 0x0A, 0x06, 0x08, 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07,
        0x03, 0x01, 0x30, 0x11, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01,
        0x86, 0xF8, 0x42, 0x01, 0x01, 0x04, 0x04, 0x03, 0x02, 0x06,
        0x40, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D,
        0x04, 0x03, 0x02, 0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x20,
        0x61, 0x6F, 0xE8, 0xB9, 0xAD, 0xCC, 0xC9, 0x1A, 0x81, 0x17,
        0x02, 0x64, 0x07, 0xC3, 0x18, 0x44, 0x01, 0x81, 0x76, 0x18,
        0x9D, 0x6D, 0x3D, 0x7D, 0xCB, 0xC1, 0x5A, 0x76, 0x4A, 0xAD,
        0x71, 0x55, 0x02, 0x21, 0x00, 0xCD, 0x22, 0x35, 0x04, 0x19,
        0xC2, 0x23, 0x21, 0x02, 0x88, 0x4B, 0x51, 0xDA, 0xDB, 0x51,
        0xAB, 0x54, 0x8C, 0xCB, 0x38, 0xAC, 0x8E, 0xBB, 0xEE, 0x18,
        0x07, 0xBF, 0x88, 0x36, 0x88, 0xFF, 0xD5
};
static const int sizeof_serv_ecc_der_256 = sizeof(serv_ecc_der_256);

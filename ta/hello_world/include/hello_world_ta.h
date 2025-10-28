/* SPDX-License-Identifier: BSD-2-Clause */
#ifndef HELLO_WORLD_TA_H
#define HELLO_WORLD_TA_H

/*
 * A unique UUID for the Hello World TA
 */
#define HELLO_WORLD_TA_UUID { 0xd96a5b45, 0x2ef0, 0x4d9a, \
			       { 0x9d, 0x8b, 0x0a, 0x1c, 0x6c, 0x1e, 0x5c, 0x3b } }

/*
 * Command ID to print a greeting. No parameters needed.
 */
#define TA_HELLO_CMD_SAY_HELLO  0

#endif /* HELLO_WORLD_TA_H */

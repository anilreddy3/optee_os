/* SPDX-License-Identifier: BSD-2-Clause */
#ifndef USER_TA_HEADER_DEFINES_H
#define USER_TA_HEADER_DEFINES_H

#include <hello_world_ta.h>

#define TA_UUID			HELLO_WORLD_TA_UUID

#define TA_FLAGS			(TA_FLAG_SINGLE_INSTANCE | TA_FLAG_MULTI_SESSION)
#define TA_STACK_SIZE			(2 * 1024)
#define TA_DATA_SIZE			(4 * 1024)

#define TA_DESCRIPTION			"Hello World trusted application"
#define TA_VERSION			"1.0"

#endif /* USER_TA_HEADER_DEFINES_H */

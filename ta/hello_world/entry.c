// SPDX-License-Identifier: BSD-2-Clause
#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>
#include <hello_world_ta.h>
#include <string.h>

TEE_Result TA_CreateEntryPoint(void)
{
	IMSG("Hello World TA CreateEntryPoint");
	return TEE_SUCCESS;
}

void TA_DestroyEntryPoint(void)
{
	IMSG("Hello World TA DestroyEntryPoint");
}

TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types __unused,
				       TEE_Param params[TEE_NUM_PARAMS] __unused,
				       void **session_ctx __unused)
{
	IMSG("Hello World TA OpenSessionEntryPoint");
	return TEE_SUCCESS;
}

void TA_CloseSessionEntryPoint(void *session_ctx __unused)
{
	IMSG("Hello World TA CloseSessionEntryPoint");
}

static TEE_Result cmd_say_hello(uint32_t pt, TEE_Param p[TEE_NUM_PARAMS])
{
	const uint32_t exp_pt = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
					  TEE_PARAM_TYPE_NONE,
					  TEE_PARAM_TYPE_NONE,
					  TEE_PARAM_TYPE_NONE);
	if (pt != exp_pt)
		return TEE_ERROR_BAD_PARAMETERS;

	IMSG("Hello, world from TA!");
	return TEE_SUCCESS;
}

TEE_Result TA_InvokeCommandEntryPoint(void *sess __unused, uint32_t cmd,
					  uint32_t pt, TEE_Param params[TEE_NUM_PARAMS])
{
	switch (cmd) {
	case TA_HELLO_CMD_SAY_HELLO:
		return cmd_say_hello(pt, params);
	default:
		EMSG("Unknown command: 0x%x", cmd);
		return TEE_ERROR_NOT_SUPPORTED;
	}
}

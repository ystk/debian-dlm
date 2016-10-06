/*
 * Copyright 2004-2012 Red Hat, Inc.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU General Public License v2 or (at your option) any later version.
 */

#ifndef __DLM_CONTROLD_DOT_H__
#define __DLM_CONTROLD_DOT_H__

/* This defines the interface between dlm_controld and libdlmcontrol, and
   should only be used by libdlmcontrol. */

#define DLMC_SOCK_PATH			"dlmc_sock"
#define DLMC_QUERY_SOCK_PATH		"dlmc_query_sock"

#define DLMC_MAGIC			0xD13CD13C
#define DLMC_VERSION			0x00010001

#define DLMC_CMD_DUMP_DEBUG		1
#define DLMC_CMD_DUMP_PLOCKS		2
#define DLMC_CMD_LOCKSPACE_INFO		3
#define DLMC_CMD_NODE_INFO		4
#define DLMC_CMD_LOCKSPACES		5
#define DLMC_CMD_LOCKSPACE_NODES	6
#define DLMC_CMD_FS_REGISTER		7
#define DLMC_CMD_FS_UNREGISTER		8
#define DLMC_CMD_FS_NOTIFIED		9
#define DLMC_CMD_DEADLOCK_CHECK		10
#define DLMC_CMD_DUMP_LOG_PLOCK		11
#define DLMC_CMD_FENCE_ACK		12
#define DLMC_CMD_DUMP_STATUS		13
#define DLMC_CMD_DUMP_CONFIG		14

struct dlmc_header {
	unsigned int magic;
	unsigned int version;
	unsigned int command;
	unsigned int option;
	unsigned int len;
	int data;	/* embedded command-specific data, for convenience */
	int unused1;
	int unsued2;
	char name[DLM_LOCKSPACE_LEN]; /* no terminating null space */
};

#define DLMC_STATE_MAXSTR       4096
#define DLMC_STATE_MAXBIN       4096

#define DLMC_STATE_DAEMON       1
#define DLMC_STATE_DAEMON_NODE  2
#define DLMC_STATE_STARTUP_NODE 3

struct dlmc_state {
	uint32_t type; /* DLMC_STATE_ */
	uint32_t flags;
	int32_t nodeid;
	uint32_t data32;
	uint32_t data64;
	uint32_t str_len;
	uint32_t bin_len;
};

#endif


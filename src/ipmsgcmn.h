/*	@(#)Copyright (C) H.Shirouzu 2011-2012   ipmsgcmn.h	Ver3.41 */
/* ========================================================================
	Project  Name			: IP Messenger for Win32
	Module Name				: IP Messenger Common Header
	Create					: 2011-05-03(Tue)
	Update					: 2012-04-03(Tue)
	Copyright				: H.Shirouzu
	Reference				: 
	======================================================================== */

#ifndef IPMSGCMN_H
#define IPMSGCMN_H


#include <QString>
#include <QTime>

#include "version.h"

/*  IP Messenger for Windows  internal define  */
#define IPMSG_REVERSEICON			0x0100
#define IPMSG_TIMERINTERVAL			500
#define IPMSG_ENTRYMINSEC			5
#define IPMSG_GETLIST_FINISH		0
#define IPMSG_DELAYMSG_OFFSETTIME	2000
#define IPMSG_DELAYFOCUS_TIME		10

#define IPMSG_BROADCAST_TIMER		0x0101
#define IPMSG_SEND_TIMER			0x0102
#define IPMSG_LISTGET_TIMER			0x0104
#define IPMSG_LISTGETRETRY_TIMER	0x0105
#define IPMSG_ENTRY_TIMER			0x0106
#define IPMSG_DUMMY_TIMER			0x0107
#define IPMSG_RECV_TIMER			0x0108
#define IPMSG_ANS_TIMER				0x0109
#define IPMSG_CLEANUP_TIMER			0x010a
#define IPMSG_BALLOON_RECV_TIMER	0x010b
#define IPMSG_BALLOON_OPEN_TIMER	0x010c
#define IPMSG_BALLOON_DELAY_TIMER	0x010d
#define IPMSG_IMAGERECT_TIMER		0x010e
#define IPMSG_KEYCHECK_TIMER		0x010f
#define IPMSG_DELAYFOCUS_TIMER		0x0110


#define IPMSG_NICKNAME			1
#define IPMSG_FULLNAME			2

#define IPMSG_NAMESORT			0x00000000
#define IPMSG_IPADDRSORT		0x00000001
#define IPMSG_HOSTSORT			0x00000002
#define IPMSG_NOGROUPSORTOPT	0x00000100
#define IPMSG_ICMPSORTOPT		0x00000200
#define IPMSG_NOKANJISORTOPT	0x00000400
#define IPMSG_ALLREVSORTOPT		0x00000800
#define IPMSG_GROUPREVSORTOPT	0x00001000
#define IPMSG_SUBREVSORTOPT		0x00002000



#define SKEY_HEADER_SIZE	12

#define PRIV_BLOB_USER			0x0001
#define PRIV_BLOB_DPAPI			0x0002
#define PRIV_BLOB_RAW			0x0003
#define PRIV_SEED_HEADER		"ipmsg:"
#define PRIV_SEED_HEADER_LEN	6
#define PRIV_SEED_LEN			(PRIV_SEED_HEADER_LEN + (128/8))	// 128bit seed

// General define
#define MAX_SOCKBUF		65536
#define MAX_UDPBUF		32768
#define MAX_BUF			1024
#define MAX_BUF_EX		(MAX_BUF * 3)
#define MAX_MULTI_PATH	(MAX_BUF * 32)
#define MAX_NAMEBUF		80
#define MAX_LISTBUF		(MAX_NAMEBUF * 4)
#define MAX_ANSLIST		100
#define MAX_FILENAME_U8	(255 * 3)

#define HS_TOOLS		"HSTools"
#define IP_MSG			"IPMsg"
#define NO_NAME			"no_name"
#define URL_STR			"://"
#define MAILTO_STR		"mailto:"
#define MSG_STR			"msg"

#define DEFAULT_PRIORITY	10
#define PRIORITY_OFFSET		10
#define DEFAULT_PRIORITYMAX	5

#define CLIP_ENABLE			0x1
#define CLIP_SAVE			0x2
#define CLIP_CONFIRM_NORMAL	0x4
#define CLIP_CONFIRM_STRICT	0x8
#define CLIP_CONFIRM_ALL	(CLIP_CONFIRM_NORMAL|CLIP_CONFIRM_STRICT)




#define CFG_ALL			0xffffffff
#define CFG_GENERAL		0x00000001
#define CFG_ABSENCE		0x00000002
#define CFG_WINSIZE		0x00000004
#define CFG_FONT		0x00000008
#define CFG_BROADCAST	0x00000010
#define CFG_CLICKURL	0x00000020
#define CFG_PRIORITY	0x00000040
#define CFG_FINDHIST	0x00000080
#define CFG_LRUUSER		0x00000100
#define CFG_HOSTINFO	0x00001000
#define CFG_DELHOST		0x00002000
#define CFG_DELCHLDHOST	0x00004000
#define CFG_CRYPT		0x00008000

#define FT_STRICTDATE	0x00000001
#define RS_REALTIME		0x00000001

enum KeyType { KEY_512, KEY_1024, KEY_2048, MAX_KEY };

#endif IPMSGCMN_H

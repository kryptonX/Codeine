/** 
  * Copyright (C) 2011 KryptonX
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef libkrypton1te_H
#define libkrypton1te_H
/* IT IS VERY IMPORTANT TO INCLUDE THE HEADERS AND NOT TO MODIFY THE DIRECTORIES! */
#include "pointer\pointer.h"
#include <PatchApi.h>
#ifdef _WIN32
	#include <Windows.h>
	#include <stdio.h>	
#endif

#ifdef _KRYPTON_
	#ifdef _FOX_
		#include <fkrypton.h>
	#endif
#endif

#ifdef _MAC_
	#include <unistd.h>
#endif

#ifdef UNIX
	#include <stdio.h>
	#include <unistd.h>
#endif

#ifdef _LINUX_
	#include <stdio.h>
	#include <unistd.h>
#endif

typedef enum {
	LIB_OK = 0,
	LIB_CANCEL = (-1),
	LIB_STDERR = 1,
	LIB_THRD = 2,
	LIB_FRTH = 3,
	LIB_REBT = 4
} std_enum;

LIB_EXPORT BOOL DeviceInDfu();
LIB_EXPORT BOOL DeviceInRecovery();
LIB_EXPORT BOOL JailbreakReady();
LIB_EXPORT BOOL RamdiskSent();
LIB_EXPORT int iboot_command_(const char* s_cmd);

/* Structures */

typedef struct {
	unsigned int mode;
	const char* ref;	
} ibootstate;

struct _device;
typedef const struct _device* cn_device_;

typedef const struct supported_dev {
	const char* n88ap;		/* iPhone 3Gs [2,1] */
	const char* n18ap;		/* iPod 3G [3,1] */
	const char* k48ap;		/* iPad 1 [1,1] */	
	const char* n90ap;		/* iPhone 4 [3,1] */
	const char* n81ap;		/* iPod 4 [4,1] */
} supported_devices;

typedef const struct connected_clients {
	unsigned int _client;
	const char* _cmd_;
}	cn_cl;

typedef struct  RamdiskValues{
	int failed;
	int success;
	int running;
} RamdiskStatus;

LIB_EXPORT void RunTestDsk(int client_, unsigned char* ret, const int _cc_);
LIB_EXPORT char* rerun(int client_, const char* s_cmd[2], int argc);
void init_callback(unsigned int _client_, const char* var[]);

union dunionf {
	int initiate_unionfs;
};

LIB_EXPORT int fsck_client(int _client_, const char* _order_operations, unsigned int argp);

typedef unsigned const int parameter;

LIB_EXPORT parameter error_if_payload_not_recieved(const char* _client, long payload);
LIB_EXPORT unsigned const char* character_interpret_fuzzing_method(int _client_, const char** bootrom, const char s_cmd[2]);

typedef union {
	const unsigned char** proton;
} eel;
int fsck_hfs_cmd;

LIB_EXPORT void lprintf(string ch, int counter, int max, int arg, const char* suffix);
LIB_EXPORT void load_iboot(int iboot_adress, const char* exp);

typedef const int* alt_string;

LIB_EXPORT int libkrypton1te_init();

struct response {
	int FAILED;
};
typedef int integer;

/* INIT */

LIB_EXPORT void libkrypton1te_dsck(int vars);
LIB_EXPORT void client_init();
LIB_EXPORT const char* reset_iboot();
LIB_EXPORT int setenv();
LIB_EXPORT void saveenv(int boolean);
LIB_EXPORT LPSTR GrabDfuPath(LPSTR _dfuPath);
LIB_EXPORT void execPayload(const char* payload_to_be_executed, int times);

/* iBSS file creation and patcher [python] */

LIB_EXPORT const char* connected_product();
LIB_EXPORT int python_start(const char* _app_);

LIB_EXPORT void create_ibss();
LIB_EXPORT int delete_ibss();

/* Mobile Services */

LIB_EXPORT int connect_to_device();


#endif
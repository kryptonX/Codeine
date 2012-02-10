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

#include "libkrypton1te.h"
#include "../../x-irecovery/include/libirecovery.h"
#include "../../x-irecovery/include/libpois0n.h"
#include <stdlib.h>

void write(const char* msg);


BOOL JailbreakReady() {
	if (DeviceInDfu() == TRUE 
		&& DeviceInRecovery() == FALSE
		) {
			return TRUE;
	} else return FALSE;		
}

BOOL RamdiskSent() {
	if (DeviceInDfu() == TRUE 
		&& DeviceInRecovery() == FALSE) {
			return TRUE;
	} else return FALSE;
	
}

int iboot_command_(const char* s_cmd) {
	int s_ret = 0;	/*Value to be returned */
	s_ret = irecv_open_attempts(&client, 10);	/* Open attempts and load client */
	irecv_send_command(client, s_cmd);	/* Send commmand {s_cmd[2]} */
	irecv_exit();	/* kill & clear client */
	return s_ret;		/* Return ret */
}

void RunTestDsk(int client_, unsigned char* ret, const int _cc_) {
	const char* pArgs = "0";
	const int cn_cli = 0;
	
	if (client_ <= 5
		&& ret != "-1"
		&& _cc_ == 0)
		fsck_client(cn_cli, pArgs, _cc_);	
	
}

int fsck_client(int _client_, const char* _order_operations, unsigned int argp) {
	argp = irecv_open_attempts(&client, 10);	/* Open attempts and load client */
	irecv_send_command(client, "fsck_hfs reset");	/* Send commmand {s_cmd[2]} */
	irecv_send_command(client, _order_operations);	/* Send specified order */
	/* Initation payload[] */
	if (argp != EOF)
		argp = irecv_send_command(client, ""); 
	do {
		//_client_ = client->DfuPath;
		argp = EOF;
	} while (argp != EOF);
	
	return 0;
}

void lprintf(string ch, int counter, int max, int arg, const char* suffix) {
	/* printf function with an included loop */
#ifdef _STD_IO_
#ifdef _WIN32
#include <stdio.h>
#endif
#endif
#ifdef _WIN32

	if (arg == 0)
		EOF;
	else if (arg == 1) {	/* counter < max */
		while (counter < max) {
			printf(ch);
		++counter;
			if (counter == (max - 1))
				printf(suffix);
		}
	} else if (arg == 2) {
		while (counter <= max) {
			printf(ch);
		++counter;
			if (counter == max)
				printf(suffix);
		}
	} else if (arg == 3) {
		while (counter > max) {
			printf(ch);
			++counter;
			if (counter == (max + 1))
				printf(suffix);
		}
	} else if (arg == 4) {
		while (counter >= max) {
			printf(ch);
			++counter;
			if (counter == (max + 1))
				printf(suffix);
		}
	}
#endif

#ifdef _MAC_
	if (arg == 0)
		EOF;
	else if (arg == 1) {	/* counter < max */
		while (counter < max) {
			printf(ch);
		++counter;
			if (counter == (max - 1))
				printf(suffix);
		}
	} else if (arg == 2) {
		while (counter <= max) {
			printf(ch);
		counter++;
			if (counter == max)
				printf(suffix);
		}
	} else if (arg == 3) {
		while (counter > max) {
			printf(ch);
			counter++;
			if (counter == (max + 1))
				printf(suffix);
		}
	} else if (arg == 4) {
		while (counter >= max) {
			printf(ch);
			counter++;
			if (counter == (max + 1))
				printf(suffix);
		}
	}
#else 
	if (arg == 0)
		EOF;
	else if (arg == 1) {	/* counter < max */
		while (counter < max) {
			printf(ch);
		++counter;
		if (counter == (max - 1))
				printf(suffix);
		}
	} else if (arg == 2) {
		while (counter <= max) {
			printf(ch);
		++counter;
			if (counter == max)
				printf(suffix);
		}
	} else if (arg == 3) {
		while (counter > max) {
			printf(ch);
			++counter;
			if (counter == (max + 1))
				printf(suffix);
		}
	} else if (arg == 4) {
		while (counter >= max) {
			printf(ch);
			++counter;
			if (counter == (max + 1))
				printf(suffix);
		}
	}
#endif
	
}

void load_iboot(int iboot_adress, const char* exp) {
	iboot_command_("go to " + iboot_adress);
	 printf("loading iBoot @ %d", iboot_adress);
	iboot_command_("setenv auto-boot false");
	iboot_command_("sanveev");
	iboot_command_("reset");
}

parameter error_if_payload_not_recieved(const char* _client, long payload) {
	if (_client == NULL && payload != 0)
		return (-1);
	else return 0;
}

int libkrypton1te_init() {
	int s_ret = 0;	/*Value to be returned */
	irecv_open_attempts(&client, 10);	/* Open attempts and load client */
	pois0n_init();
	return s_ret;
}

void libkrypton1te_exit() {
	irecv_exit();
	pois0n_exit();
}

/* INIT */

void libkrypton1te_dsck(int vars) {
	int x = 0;
	for (x < vars; x != vars; x++) {
		printf("%d\n", x);
	}
}

void client_init() {	
	irecv_open_attempts(&client, 10);	/* Open attempts and load client */	
}

const char* reset_iboot() {
#ifdef _MAC_
	load_iboot(00x0xx, "proc0x21");
#endif
	libkrypton1te_init();
	libkrypton1te_exit();
}

int setenv() {	
	libkrypton1te_init(); /* init irecovery clients */
	client_init();			/* Set client */
	iboot_command_("setenv");		
}

void saveenv(int boolean) {
	const char* var;
	if (boolean == 1)
		var = "true";
	else if (boolean == 0)
		var = "false";
	iboot_command_("auto-boot");
	iboot_command_(var);
	iboot_command_("reboot");
	libkrypton1te_exit();		
}

LPSTR GrabDfuPath(LPSTR _dfuPath) {
	client_init();
	_dfuPath = client->DfuPath;
	return _dfuPath;
}

void execPayload(const char* payload_to_be_executed, int times) {
	int state = 0;
	libkrypton1te_init();
	pois0n_init();	
	do {
	iboot_command_(payload_to_be_executed);
	++state;
	} while (state != times);
}

int python_start(const char* _app_) {
	int returnval = system(_app_);
	if (returnval == 0)
		return 0;
	else return (-1);
}

const char* connected_product() {
	libkrypton1te_init();
		if (device->chip_id == CPID_IPOD4G)
		return "patch.pyc -ipt4";
	else if (device->chip_id == CPID_IPHONE4)
		return "patch.pyc -i4";
	else if (device->chip_id == CPID_IPOD3G)
		return "patch.pyc -ipt3";
	else if (device->chip_id == CPID_IPHONE3GS)
		return "patch.pyc -i3gs";
	else if (device->chip_id == CPID_IPAD1G)
		return "patch.pyc -ipad";
	else if (device->chip_id == CPID_IPOD2G)
		return "patch.pyc -i4";
}

void create_ibss(const char* _model) {
#ifdef _WIN32
	system("patch.pyc");
#endif
}

int delete_ibss() {
	if( remove( "kr1.iBSS" ) != 0 )
    perror("Error deleting file");
  else
    printf("File successfully deleted");
  return 0;
}

unsigned const char zero_image_location = {
	0000
};

int connect_to_device() {	

	irecv_error_t error;
	
	irecv_init();

	printf("\nWaiting for device...\n");	

	error = irecv_open_attempts(&client, 10);
	if(error != IRECV_E_SUCCESS)
	{
		fprintf(stderr, "Failed to connect to iBoot, error %d.\n", error);
		return -error;
	}	
	
	if (client->mode == kDfuMode) {
		printf("Loaded DFU\n");
		model();
	}
	if (client->mode == kRecoveryMode1 || client->mode == kRecoveryMode2 || client->mode == kRecoveryMode3 || client->mode == kRecoveryMode4 ) {
		model();
	}
	

			
	
	
	
}

void write(const char* msg) {
	printf(msg);
}

int model() {
	if (device->model == "iPod4,1")
		printf("Succesfully connected to iPod4,1");
}










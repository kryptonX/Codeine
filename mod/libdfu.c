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
#include "../libkrypton1te.h"
#include "../../../x-irecovery/include/libirecovery.h"
#include "../../../x-irecovery/include/libpois0n.h"

BOOL DeviceInDfu() {		
	irecv_open_attempts(&client, 10);
	if (client->mode == kDfuMode) 
		return TRUE;
	else {return FALSE;}	
}
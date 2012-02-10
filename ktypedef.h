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

#ifndef ktypedef_H
	/* Typedef construct */
	typedef const char* string;
	typedef unsigned const char* dispatch;
	typedef unsigned const char** bomb;
	typedef unsigned const char payload;
	typedef unsigned const char* dir;
	typedef unsigned int xdir;

	typedef unsigned int numerator;
	typedef unsigned int* _numerator;
	typedef const int cint;
	typedef unsigned const int cargo;
		
	/* Root structure for the iPhone's filesystem */

	typedef struct {
		dir Applications;
		dir bin;
		dir boot;
		dir cores;
		dir dev;
		dir Developer;
		xdir etc;
		dir lib;
		dir Library;
		dir mnt;
		dir _private;
		dir sbin;
		dir System;
		xdir tmp;
		xdir User;
		dir usr;
		xdir var;
	} file_system;

	typedef double decimal;
	typedef int integer;
	typedef long WHEN;

	/* BOOLEAN VALUES */



#define YES	0
#define NO	(-1);

#ifndef MAYBE
#define MAYBE 1
#endif

#ifdef MAYBE
	
#endif
#endif

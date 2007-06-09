/*
OpenChrono
Copyright (C) 2007  Sebastien CELLES
 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef CHRONO_H
#define CHRONO_H

#include <sys/time.h>
#include <unistd.h>

#include <cstdlib> // memcpy

class Chrono
{
public:
	Chrono( );

	void start(void);
	void stop(void);
	//void start_and_go(void);
	void start_stop(void);

	void clear(void);
	bool is_running(void);

	void get_current_time(struct timeval * time);

private:
	int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);
	struct timeval tv1, tv2, tvdiff;
	bool running;
	struct tm* ptm;
	char time_string[15];
	long milliseconds;

};
#endif

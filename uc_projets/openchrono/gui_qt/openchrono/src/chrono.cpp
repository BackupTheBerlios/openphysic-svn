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

#include "chrono.h"

#include <sys/time.h>
#include <unistd.h>

#include <cstdlib> // memcpy

Chrono::Chrono( )
{

}

int Chrono::timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y)
{
  // see http://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html	
	
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }
     
  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;
     
  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}

void Chrono::start(void)
{
  running = true;
}

void Chrono::stop(void)
{
  running = false;
}

void Chrono::start_stop(void)
{
  if (running) {
    gettimeofday(&tv2, NULL);
  } else {
    gettimeofday(&tv1, NULL);
    timeval_subtract (&tv1, &tv1, &tvdiff);
  }

  running = !running;
}

void Chrono::clear(void)
{
  gettimeofday(&tv1, NULL);
  //memcpy(&tv2, &tv1, sizeof(tv1)); //ToFiX ‘memcpy’ was not declared in this scope
}

bool Chrono::is_running(void)
{
  return running;
}

void Chrono::get_current_time(struct timeval * time)
{
  //timeval_subtract (&tvdiff, &tv2, &tv1);
  timeval_subtract (time, &tv2, &tv1);
}


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

#include "logdata.h"
//
#include <QTimer>


LogData::LogData( Data * data )
{
  m_data = data;

  setDelay(500);

  N = 4096;

  start = 0;
  stop = start;

  setRecordMode(record_wrap);

  connect( &timer, SIGNAL( timeout() ), this, SLOT( update() ) );

}

LogData::~LogData(  )
{

}

void LogData::setDelay(int delay)
{
  m_msec = delay;
}

int LogData::delay(void)
{
  return m_msec;
}



void LogData::setRecordMode(Record_mode mode)
{
  if (mode == record_off) {
    setOff();
  }
  else if (mode == record_wrap) {
    setWrap();
  }
  else if (mode == record_fill) {
    setFill();
  }
}

void LogData::setOff(void)
{
  m_mode = record_off;
  timer.stop();
}

void LogData::setWrap(void)
{
  m_mode = record_wrap;
  timer.start(m_msec);
}

void LogData::setFill(void)
{
  m_mode = record_fill;
  timer.start(m_msec);
}

int LogData::RecordMode(void)
{
  return m_mode;
}

void LogData::update(  )
{
  std::cout << qPrintable(tr("Log data (update)")) << std::endl;

  stop = stop++;

/*
  if (stop == N) {
    if (m_mode == record_wrap) {
      
    }
    if (m_mode == record_fill) {
      
    }
  }
 */

}

void LogData::show()
{
  std::cout << "time" << CSV_SEP << "rpm" << CSV_SEP << "t1" << CSV_SEP << "t2" << std::endl;
// for
}



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

#include "data.h"
//


Data::Data(  )
{
  
  connect(this, SIGNAL( starting_first_lap() ),
	  this, SLOT( on_starting_first_lap() ) );

  connect(this, SIGNAL( is_new_etap() ),
	  this, SLOT( on_new_etap() ) );

  connect(this, SIGNAL( is_new_lap() ),
	  this, SLOT( on_new_lap() ) );
  
  connect(this, SIGNAL( is_last_lap() ),
	  this, SLOT( on_last_lap() ) );
  
  connect(this, SIGNAL( race_is_over() ),
	  this, SLOT( on_race_over() ) );
  
  
}

void Data::start(void)
{
  if ( position.etap() == track.etaps() ) // passage ligne depart/arrivee
    {
      position.clearEtap();

      if ( position.lap() == 0 )
	{
	  emit starting_first_lap();
	}

      if ( position.lap() == track.laps()-1 ) // debut du dernier tour de course
	{
	  emit is_last_lap();
	}

      if ( position.lap() == track.laps() ) // fin du dernier tour de course
        {
          position.clearLap();
	  //if ( track.laps() > 1 ) {
	  emit race_is_over();
	    //}
        }

      position.newLap();
      emit is_new_lap();


    } else // passage ligne temps intermediaire
    {
      position.newEtap();
      emit is_new_etap();
    }

}


void Data::test(void)
{
  std::cout << "Test Data" << std::endl;
}

void Data::on_starting_first_lap(void)
{
  std::cout << "Starting first lap" << std::endl;
}

void Data::on_new_etap(void)
{
  std::cout << "New etap" << std::endl;
}

void Data::on_new_lap(void)
{
  std::cout << "New lap" << std::endl;

  chrono.update_last_and_best_lap_time();

  chrono.start();
  chrono.clear(); 
}

void Data::on_last_lap(void)
{
  std::cout << "Last lap" << std::endl;
}

void Data::on_race_over(void)
{
  std::cout << "Race over" << std::endl;
}

//


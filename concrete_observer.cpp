#include "concrete_observer.h"

#include <iostream>
#include <cstdlib>	// rand

void LegoPark::Tick()
{
	float rr;
	rr = 10000*((double) rand() / (RAND_MAX));
	if( rr < 500 )
	{
		Notify();
	}
}

void FireDepartment::Update( Subject* theChangedSubject )
{
	std::cout << " Ingen panik, ilden er under kontrol!" << std::endl;
}


void Supervisor::Update( Subject* theChangedSubject )
{
	std::cout << " Vi beklager, kom igen en anden gang" << std::endl;
}

#include "concrete_observer.h"

#include <iostream>
#include <cstdlib>	// rand

void LegoPark::Tick()
{
	float rr;
	rr = 10000*((double) rand() / (RAND_MAX));
	if( rr < 500 )
	{
		NotifyFire();
	}

	if( rr < 1000 )
	{
		NotifyPowerFailure();
	}
}

void FireDepartment::UpdateFire( Subject* theChangedSubject )
{
	std::cout << "Ingen panik, ilden er under kontrol!" << std::endl;
}

void PowerFailure::UpdatePowerFailure( Subject* theChangedSubject )
{
	std::cout << "Jeg kommer med det samme!" << std::endl;
}

void Supervisor::UpdateFire( Subject* theChangedSubject )
{
	std::cout << "Vi beklager, kom igen en anden gang" << std::endl;
}

void Supervisor::UpdatePowerFailure( Subject* theChangedSubject )
{
	std::cout << "Vi beklager, kom igen når der er lyst" << std::endl;
}

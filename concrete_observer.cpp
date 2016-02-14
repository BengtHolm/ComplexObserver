#include "concrete_observer.h"

#include <iostream>
#include <cstdlib>	// rand

void LegoPark::Tick()
{
	float rr;
	rr = 10000*((double) rand() / (RAND_MAX));
	if( rr < 500 )
	{
		Subject<FireEvent>::Notify();
	}

	if( rr < 1000 )
	{
		Subject<PowerFailureEvent>::Notify();
	}
}

void FireDepartment::Update( Subject<FireEvent>* theChangedSubject )
{
	std::cout << "Ingen panik, ilden er under kontrol!" << std::endl;
}

void PowerFailure::Update( Subject<PowerFailureEvent>* theChangedSubject )
{
	std::cout << "Jeg kommer med det samme!" << std::endl;
}

void Supervisor::Update( Subject<FireEvent>* theChangedSubject )
{
	std::cout << "Vi beklager, kom igen en anden gang" << std::endl;
}

void Supervisor::Update( Subject<PowerFailureEvent>* theChangedSubject )
{
	std::cout << "Vi beklager, kom igen når der er lyst" << std::endl;
}

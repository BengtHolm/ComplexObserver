// Observer.cpp : Defines the entry point for the console application.
//

#include <unistd.h>
#include <iostream>
#include "concrete_observer.h"

int main()
{
	LegoPark		legoland;
	FireDepartment	fire;
	Supervisor		manager;

	legoland.Attach( &fire );
	legoland.Attach( &manager );

	for( int i=0; i<1000; i++ )
	{
		legoland.Tick();
		std::cout << "." << std::endl;

		usleep( 2000 );
	}

	legoland.Detach( &fire );
	legoland.Detach( &manager );

	return 0;
}



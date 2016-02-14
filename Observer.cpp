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
	PowerFailure	electrician;

	legoland.AttachFireEvent( &fire );
	legoland.AttachFireEvent( &manager );
	legoland.AttachPowerFailure( &manager );
	legoland.AttachPowerFailure( &electrician );

	for( int i=0; i<100; i++ )
	{
		legoland.Tick();
		std::cout << "." << std::endl;

		usleep( 2000 );
	}
	
	legoland.DetachFireEvent( &fire );
	legoland.DetachFireEvent( &manager );
	legoland.DetachPowerFailure( &manager );
	legoland.DetachPowerFailure( &electrician );

	return 0;
}

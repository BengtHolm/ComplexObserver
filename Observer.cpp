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

	legoland.Subject<FireEvent>::Attach( &fire );
	legoland.Subject<FireEvent>::Attach( &manager );
	legoland.Subject<PowerFailureEvent>::Attach( &manager );
	legoland.Subject<PowerFailureEvent>::Attach( &electrician );

	for( int i=0; i<100; i++ )
	{
		legoland.Tick();
		std::cout << "." << std::endl;		
		
		Sleep( 100 );
	}
	
	legoland.Subject<FireEvent>::Detach( &fire );
	legoland.Subject<FireEvent>::Detach( &manager );
	legoland.Subject<PowerFailureEvent>::Detach( &manager );
	legoland.Subject<PowerFailureEvent>::Detach( &electrician );

	return 0;
}

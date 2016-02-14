#include <time.h>
#include "observer.h"

class FireEvent { };
class PowerFailureEvent { };

class LegoPark : public Subject<FireEvent>, public Subject<PowerFailureEvent>
{
public:
	void Tick();

private:
};

class FireDepartment : public Observer <FireEvent>
{
public:
	void Update( Subject<FireEvent>* theChangedSubject );

private:
};

class PowerFailure : public Observer<PowerFailureEvent>
{
public:
	void Update( Subject<PowerFailureEvent>* theChangedSubject );

private:
};

class Supervisor : public Observer <FireEvent>, public Observer<PowerFailureEvent>
{
public:
	void Update( Subject<FireEvent>* theChangedSubject );
	void Update( Subject<PowerFailureEvent>* theChangedSubject );

private:
};

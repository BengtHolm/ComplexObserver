#include "observer.h"

class FireObserver : public Observer
{
public:
	void Update( Subject* theChangedSubject ) { UpdateFire( theChangedSubject ); }
	virtual void UpdateFire( Subject* theChangedSubject ) = 0;

private:
};

class PowerFailureObserver : public Observer
{
public:
	void Update( Subject* theChangedSubject ) { UpdatePowerFailure( theChangedSubject ); }
	virtual void UpdatePowerFailure( Subject* theChangedSubject ) = 0;

private:
};


class FireEvent : public Subject
{
public:
	void AttachFireEvent( FireObserver* o )	{ Attach( o ); };
	void DetachFireEvent( FireObserver* o )	{ Detach( o ); };

protected:
	void NotifyFire()						{ Notify(); };
};

class PowerFailureEvent : public Subject
{
public:
	void AttachPowerFailure( PowerFailureObserver* o )	{ Attach( o ); };
	void DetachPowerFailure( PowerFailureObserver* o )	{ Detach( o ); };

protected:
	void NotifyPowerFailure()							{ Notify(); };
};

class LegoPark : public FireEvent, public PowerFailureEvent
{
public:
	void Tick();

private:
};

class FireDepartment : public FireObserver
{
public:
	void UpdateFire( Subject* theChangedSubject );

private:
};

class PowerFailure : public PowerFailureObserver
{
public:
	void UpdatePowerFailure( Subject* theChangedSubject );

private:
};

class Supervisor : public FireObserver, public PowerFailureObserver
{
public:
	void UpdateFire( Subject* theChangedSubject );
	void UpdatePowerFailure( Subject* theChangedSubject );

private:
};

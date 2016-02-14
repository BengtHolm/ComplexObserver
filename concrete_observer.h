#include "observer.h"

class LegoPark : public Subject
{
public:
	void Tick();

private:
};

class FireDepartment : public Observer
{
public:
	void Update( Subject* theChangedSubject );

private:
};

class Supervisor : public Observer
{
public:
	void Update( Subject* theChangedSubject );

private:
};

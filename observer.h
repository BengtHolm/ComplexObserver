#include <list>

class Subject;

class Observer
{
public:
	virtual void Update( Subject* theChangedSubject ) = 0;
};

class Subject
{
public:
	void Attach( Observer* o )
	{
		m_observers.push_back( o );
	}

	void Detach( Observer* o )
	{
		m_observers.remove( o );
	}

protected:
	void Notify()
	{
		for( std::list<Observer*>::iterator it=m_observers.begin(); it!=m_observers.end(); ++it )
		{
			(*it)->Update( this );
		}
	}

private:
	std::list<Observer*> m_observers;
};

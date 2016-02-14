#include <list>


template <class TYPE>
class Subject;

template <class TYPE>
class Observer
{
public:
	virtual void Update( Subject<TYPE>* theChangedSubject ) = 0;
};

template <class TYPE>
class Subject
{
	typedef std::list<Observer<TYPE>*> ObserverList;
public:
	void Attach( Observer<TYPE>* o )
	{
		m_observers.push_back( o );
	}

	void Detach( Observer<TYPE>* o )
	{
		m_observers.remove( o );
	}

protected:
	void Notify()
	{
		for( std::list<Observer<TYPE>*>::iterator it = m_observers.begin (); it!=m_observers.end (); ++it )
		{
			(*it)->Update( this );
		}
	}

private:
	ObserverList m_observers;
};

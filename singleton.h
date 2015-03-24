#ifndef SINGLETON_H
#define SINGLETON_H

#ifdef CPPUTILBUILDDLL
#define CPPUTILEXPORT  __declspec( dllexport ) 
#else
#define CPPUTILEXPORT  __declspec( dllimport ) 
#endif

class CPPUTILEXPORT Singleton
{
public:
    static Singleton* getInstance();

    virtual ~Singleton();

protected :
    Singleton* _instance;

    Singleton();

};

#endif // SINGLETON_H

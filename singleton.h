#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
public:
    static Singleton* getInstance();

    virtual ~Singleton();

protected :
    Singleton* _instance;

    Singleton();

};

#endif // SINGLETON_H

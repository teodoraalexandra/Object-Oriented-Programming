#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class observer
{
public:
    virtual void update() = 0;
    virtual ~observer() {}
};

class observable
{
private:
    std::vector<observer*> observers;
public:
    virtual ~observable() {}
    void addObserver(observer* obs) {
        this->observers.push_back(obs);
    }

    void notify () {
        for (auto o: observers) {
            o->update();
        }
    }
};

#endif // OBSERVER_H

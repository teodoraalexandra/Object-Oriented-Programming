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
        observers.push_back(obs);
    }

    void notify() {
        for (auto obs : observers) {
            obs->update();
        }
    }
};

#endif // OBSERVER_H

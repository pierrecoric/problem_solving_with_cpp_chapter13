#include<iostream>
#include <vector>
using std::cout;
using std::vector;


class Base {
    public:
        Base() {};
        virtual void f() {
            cout << "BASE ";
        }
};

class Derived: public Base {
    public:
        Derived(): Base() {}
        virtual void f() {
            cout << "DERIVED ";
        }
};

int main() {
    vector<Base> base_objs;
    Base obj1 = Derived();
    Derived obj2 = Derived();
    Base obj3 = Base();

    base_objs.push_back(obj1);
    base_objs.push_back(obj2);
    base_objs.push_back(obj3);

    for(Base bas_obj : base_objs) {
        bas_obj.f();
    }
    obj1.f();
    obj2.f();
    obj3.f();
    
    return 0;
}
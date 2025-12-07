#include <iostream>
#include <vector>

using namespace std;

class Counter {
private: 
    unsigned int amount;
public:
    //Counter(Counter& other) = delete;
    Counter(): amount(0) {}
    
    unsigned int get_amount() {
        return amount;
    }
    
    Counter& operator++() {
        amount++;
        return *this;
    }
    Counter operator++(int) {
        auto old = *this;
        ++(*this);
        return old;
    }
    
    void operator--(int) {
        amount--;
    }
    
    bool is_zero() {
        return amount == 0;
    }
};

template <typename T>
class shared_p {
private:
    Counter* counter;
    T* obj;
    
    void detach_ptr() {
        (*counter)--;
        cout 
            << "detaching, "
            << counter->get_amount() << " references to " << *obj 
            << " left" <<endl;
        if (counter->is_zero()) {
            cout << "obj " << *obj << " is destroyed" << endl;
            delete counter;
            delete obj;
        }
    }
    
    void attach_ptr(shared_p<T>& other) {
        if (other.obj == nullptr) {
            return;
        }
        counter = other.counter;
        obj = other.obj;
        (*counter)++;
        
        cout 
            << "attaching, "
            << counter->get_amount() << " references to " << *obj 
            << " exist" <<endl;
    }
public:
    shared_p(T*_obj): 
        obj(_obj), 
        counter(new Counter()) 
    {
        (*counter)++;
        cout 
            << "create ptr for " << *obj 
            <<", ref_count=" << counter->get_amount() 
            << endl;
    }
    
    ~shared_p() {
        detach_ptr();
    }
    
    shared_p(shared_p<T>& other) {
        attach_ptr(other);
    }
    
    void operator=(shared_p<T>& other) {
        cout<< "=" << endl;
        detach_ptr();
        attach_ptr(other);
    }
};



int main(int argc, char* args[]) {
    
    shared_p<string> p1_obj1(new string("obj1"));
    shared_p<string> p1_obj2(new string("obj2"));
    {
        shared_p<string> p1_obj3(new string("obj3"));
        p1_obj1 = p1_obj3;
    }
    p1_obj2 = p1_obj1;
    
    return 0;
}

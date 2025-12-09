/* 
*/
#include<set>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<array>
#include <cmath>
#include <string>
#include <cassert>
#include <utility>

using namespace std;

template <typename T>
class Vec {
private:
    size_t next_index;
    size_t capacity;
    T* data;
    
    void resize(size_t new_capacity) {
        cout << "resizing, new_capacity=" << new_capacity << endl;
        
        T* new_data = reinterpret_cast<T*>(new byte[sizeof(T)*new_capacity]);
        
        for(size_t i=0; i< next_index; i++) {
            swap(new_data[i], data[i]);
        }
        delete data;
        data = new_data;
        
        capacity = new_capacity;
    }
    
    
public:
    Vec():
        next_index(0),
        capacity(1)
        {
            data = reinterpret_cast<T*>(new byte[sizeof(T)]);
        }
        
    void push_back(T elem) {
        T* next_elem = &data[next_index];
        new(next_elem) T(elem);
        
        cout 
            << "push_back " << elem
            << " data[" << next_index << "]=" << data[next_index]
            <<endl;
        
        next_index++;
        
        
        
        if (next_index == capacity) {
            resize(capacity*2);
        }
    }
    
    void emplace(const T& elem, size_t index) {
        data[index] = elem;
    }
    
    void remove(size_t index) {
        for(size_t i=index; i<next_index-1; i++) {
            data[i] = data[i+1];
        }
        
        next_index -= 1;
        
    }
    
    size_t size() {
        return next_index;
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    
};

class Dog {
public:
    int age{0};
    Dog(int _age): age(_age) {
        
    }
    
    friend bool operator==(const Dog& one, const Dog& other);
};

bool operator==(const Dog& one, const Dog& other) {
    return one.age == other.age;
}

ostream& operator<<(ostream& os, const Dog& dog) {
    os << dog.age;
    return os;
}

struct Test_vec {
    void removing_from_middle() {
        Vec<Dog> vec;
        vec.push_back(Dog(1));
        vec.push_back(Dog(2));
        vec.push_back(Dog(3));
        vec.push_back(Dog(4));
        vec.remove(1);
        assert(
            vec[0]==Dog(1) &&    
            vec[1]==Dog(3) &&    
            vec[2]==Dog(4) &&    
            vec.size() == 3 &&
            "removing from the middle"
        );
    }
    
    void removing_from_end() {
        Vec<Dog> vec;
        vec.push_back(Dog(1));
        vec.push_back(Dog(2));
        vec.push_back(Dog(3));
        vec.remove(2);
        assert(
            vec[0]==Dog(1) &&    
            vec[1]==Dog(2) &&    
            vec.size() == 2 &&
            "removing from the end"
        );
    }
    
    void changing_element() {
        Vec<Dog> vec;
        vec.push_back(Dog(1));
        //vec[0] = 2;
        assert(
            vec[0]==Dog(1) &&
            "changing element"
        );
    }
};



int main(int argc, char** args) {
    
    Vec<Dog> vec;
    
    Test_vec test;
    test.removing_from_middle();
    test.removing_from_end();
    test.changing_element();
    
    for(size_t i=0; i< vec.size(); i++) {
        cout << " " << vec[i];
    }
    cout << endl;
    
    // cout << "result:" << endl;
    // for(auto result: results) {
    //     cout << " " << result;
    // }

    
    return 0;
}

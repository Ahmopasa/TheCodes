// template-class.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-30
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// simple exception class
class E : public std::exception {
    const char * msg;
    E(){};    // no default constructor
public:
    explicit E(const char * s) throw() : msg(s) { }
    const char * what() const throw() { return msg; }
};

// simple fixed-size LIFO stack template
template <typename T>
class bwstack {
private:
    static const int defaultsize = 10;
    static const int maxsize = 1000;
    int _size;
    int _top;
    T * _stkptr;
public:
    explicit bwstack(int s = defaultsize);
    ~bwstack() { delete[] _stkptr; }
    T & push( const T & );
    T & pop();
    bool isempty() const { return _top < 0; }
    bool isfull() const { return _top >= _size - 1; }
    int top() const { return _top; }
    int size() const { return _size; }
};

// Stack<T> constructor
template <typename T>
bwstack<T>::bwstack ( int s ) {
    if(s > maxsize || s < 1) throw E("invalid stack size");
    else _size = s;
    _stkptr = new T[_size];
    _top = -1;
}

template <typename T>
T & bwstack<T>::push ( const T & i ) {
    if(isfull()) throw E("stack full");
    return _stkptr[++_top] = i;
}

template <typename T>
T & bwstack<T>::pop () {
    if(isempty()) throw E("stack empty");
    return _stkptr[_top--];
}

int main( int argc, char ** argv ) {
    try {
        bwstack<int> si(5);
        
        cout << "si size: " << si.size() << endl;
        cout << "si top: " << si.top() << endl;
        
        for ( int i : { 1, 2, 3, 4, 5 } ) {
            si.push(i);
        }
        
        cout << "si top after pushes: " << si.top() << endl;
        cout << "si is " << ( si.isfull() ? "" : "not " ) << "full" << endl;
        
        while(!si.isempty()) {
            cout << "popped " << si.pop() << endl;
        }
    } catch (E & e) {
        cout << "Stack error: " << e.what() << endl;
    }
    
    try {
        bwstack<string> ss(5);
        
        cout << "ss size: " << ss.size() << endl;
        cout << "ss top: " << ss.top() << endl;
        
        for ( const char * s : { "one", "two", "three", "four", "five" } ) {
            ss.push(s);
        }
        
        cout << "ss top after pushes: " << ss.top() << endl;
        cout << "ss is " << ( ss.isfull() ? "" : "not " ) << "full" << endl;
        
        while(!ss.isempty()) {
            cout << "popped " << ss.pop() << endl;
        }
    } catch (E & e) {
        cout << "Stack error: " << e.what() << endl;
    }
    
    return 0;
}

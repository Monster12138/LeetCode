#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    MinStack()
        :_size(0)
         ,_data(new vector<int>[100])
         ,_min(INT32_MAX)
         ,_capacity(100)
    {
       _data->reserve(100); 
    }
    
    ~MinStack(){
        if(_data)
            delete[] _data;

        _data = nullptr;
        _size = _capacity = _min = 0;
    }

    void check(){
        if(_size >= _capacity){
            vector<int> *tmp = new vector<int>[_capacity * 2];
            delete[] _data;
            _data = tmp;
        }
    }

    void push(int x) {
        check();
        (*_data)[_size++] = x;
        if(x < _min)_min = x;
    }
    
    void pop() {
        int tmp = _data->back();
        if(_size > 0 ){
            _data->pop_back();
            --_size;
        }

        if(tmp == _min){
            for(int i = 0; i < _size; ++i){
                if((*_data)[i] < _min)
                    _min = (*_data)[i];
            }
        }
    }
    
    int top() {
        if(_size > 0)
            return (*_data)[_size - 1];
        return -1;
    }
    
    int getMin() {
        return _min;
    }
private:
    int _size;
    vector<int>* _data;
    int _min;
    int _capacity;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


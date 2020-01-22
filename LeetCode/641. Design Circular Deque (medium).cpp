// 641. Design Circular Deque (medium)

class MyCircularDeque {
public:
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        // if size is invalid, create a queue size of 10;
        if(k <= 0)
        {
            k = 10;    
        }
        _circularQueue = new int[k];
        _head = 0;
        _tail = -1; //set empty
        _size = k;
    }
    
	//** Deconstructor. Deletes memory no longer being used.
    ~MyCircularDeque ()
    {
        delete[] _circularQueue;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
        {return false;}
        if(isEmpty())
        {
            _tail = _head; // set initial tail loc
        }
        _head -= 1;
        if(_head < 0)
        {
            _head = _size - 1;
        }
        _circularQueue[_head] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
        {return false;}
        if(isEmpty())
        {
            _tail = _head; // set initial tail loc
        }
        _circularQueue[_tail] = value;
        _tail = (_tail + 1) % _size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }
        _head += 1;
        
        if(_head == _tail) // dequeued until empty - set sempty
        {
            _tail = -1;
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }
        _tail -= 1;
        
        if(_tail < 0) // wrap around
        {
            _tail = _size -1; 
        }
        if(_head == _tail) // dequeued until empty - set sempty
        {
            _tail = -1;
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
       if(!isEmpty())
        {
            return _circularQueue[_head];
        }
        else
        {
            return -1; // error - no front
        } 
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(!isEmpty())
        {
            if(_tail == 0)
            {
                return _circularQueue[_size - 1];    
            }
            else
            {
                return _circularQueue[_tail -1];
            }
        }
        else
        {
            return -1; // error - no rear
        }
        
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _tail == -1;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _head == _tail;
    }
private:
    int* _circularQueue;
    int _head;
    int _tail;
    int _size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// LeetCode 1114. Print in Order (easy)
class Foo {
public:
    Foo() {
        
    }
    bool hasFirstExecuted = false;
    bool hasSecondExecuted = false;
    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        hasFirstExecuted = true;
    }

    void second(function<void()> printSecond) {
        
        while(true)
        {
            if(test(hasFirstExecuted))
            {
                break;
            }
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        hasSecondExecuted = true;
    }

    void third(function<void()> printThird) {
        
        while(true)
        {
            if(test(hasSecondExecuted))
            {
                break;
            }
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
    
    bool test(bool isTrue)
    {
        return isTrue;
    }
};
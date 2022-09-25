class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }
    
    void run(function<bool(int)> test, function<void(int)> print) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return i > n || test(i); });
            if (i > n) break;
            print(i++);
            lock.unlock();
            cv.notify_all();
        }
    }

    void fizz(function<void()> printFizz) {
        run([](int i){ return i % 3 == 0 && i % 5 != 0; },
            [&](int i){ printFizz(); });
    }

    void buzz(function<void()> printBuzz) {
        run([](int i){ return i % 3 != 0 && i % 5 == 0; },
            [&](int i){ printBuzz(); });
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        run([](int i){ return i % 3 == 0 && i % 5 == 0; },
            [&](int i){ printFizzBuzz(); });
    }

    void number(function<void(int)> printNumber) {
        run([](int i){ return i % 3 != 0 && i % 5 != 0; }, printNumber);
    }
};
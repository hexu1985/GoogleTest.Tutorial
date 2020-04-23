#ifndef _FUN_H_  
#define _FUN_H_  
  
#include <string.h>  
#include <algorithm>  
  
// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.  
int Factorial(int n);  
  
// Returns true if n is a prime number.  
bool IsPrime(int n);  
  
// A simple string class.  
class MyString {  
private:  
    const char* c_string_;  
    const MyString& operator=(const MyString& rhs);  
  
public:  
    // Clones a 0-terminated C string, allocating memory using new.  
    static const char* CloneCString(const char* a_c_string);  
  
    ////////////////////////////////////////////////////////////  
    //  
    // C'tors  
  
    // The default c'tor constructs a NULL string.  
    MyString() : c_string_(NULL) {}  
  
    // Constructs a MyString by cloning a 0-terminated C string.  
    explicit MyString(const char* a_c_string) : c_string_(NULL) {  
        Set(a_c_string);  
    }  
  
    // Copy c'tor  
    MyString(const MyString& string) : c_string_(NULL) {  
        Set(string.c_string_);  
    }  
  
    ////////////////////////////////////////////////////////////  
    //  
    // D'tor.  MyString is intended to be a final class, so the d'tor  
    // doesn't need to be virtual.  
    ~MyString() { delete[] c_string_; }  
  
    // Gets the 0-terminated C string this MyString object represents.  
    const char* c_string() const { return c_string_; }  
  
    size_t Length() const {  
        return c_string_ == NULL ? 0 : strlen(c_string_);  
    }  
  
    // Sets the 0-terminated C string this MyString object represents.  
    void Set(const char* c_string);  
};  
  
// Queue is a simple queue implemented as a singled-linked list.  
//  
// The element type must support copy constructor.  
template <typename E>  // E is the element type  
class Queue;  
  
// QueueNode is a node in a Queue, which consists of an element of  
// type E and a pointer to the next node.  
template <typename E>  // E is the element type  
class QueueNode {  
    friend class Queue<E>;  
  
public:  
    // Gets the element in this node.  
    const E& element() const { return element_; }  
  
    // Gets the next node in the queue.  
    QueueNode* next() { return next_; }  
    const QueueNode* next() const { return next_; }  
  
private:  
    // Creates a node with a given element value.  The next pointer is  
    // set to NULL.  
    explicit QueueNode(const E& an_element) : element_(an_element), next_(NULL) {}  
  
    // We disable the default assignment operator and copy c'tor.  
    const QueueNode& operator = (const QueueNode&);  
    QueueNode(const QueueNode&);  
  
    E element_;  
    QueueNode* next_;  
};  
  
template <typename E>  // E is the element type.  
class Queue {  
public:  
    // Creates an empty queue.  
    Queue() : head_(NULL), last_(NULL), size_(0) {}  
  
    // D'tor.  Clears the queue.  
    ~Queue() { Clear(); }  
  
    // Clears the queue.  
    void Clear() {  
        if (size_ > 0) {  
            // 1. Deletes every node.  
            QueueNode<E>* node = head_;  
            QueueNode<E>* next = node->next();  
            for (; ;) {  
                delete node;  
                node = next;  
                if (node == NULL) break;  
                next = node->next();  
            }  
  
            // 2. Resets the member variables.  
            head_ = last_ = NULL;  
            size_ = 0;  
        }  
    }  
  
    // Gets the number of elements.  
    size_t Size() const { return size_; }  
  
    // Gets the first element of the queue, or NULL if the queue is empty.  
    QueueNode<E>* Head() { return head_; }  
    const QueueNode<E>* Head() const { return head_; }  
  
    // Gets the last element of the queue, or NULL if the queue is empty.  
    QueueNode<E>* Last() { return last_; }  
    const QueueNode<E>* Last() const { return last_; }  
  
    // Adds an element to the end of the queue.  A copy of the element is  
    // created using the copy constructor, and then stored in the queue.  
    // Changes made to the element in the queue doesn't affect the source  
    // object, and vice versa.  
    void Enqueue(const E& element) {  
        QueueNode<E>* new_node = new QueueNode<E>(element);  
  
        if (size_ == 0) {  
            head_ = last_ = new_node;  
            size_ = 1;  
        } else {  
            last_->next_ = new_node;  
            last_ = new_node;  
            size_++;  
        }  
    }  
  
    // Removes the head of the queue and returns it.  Returns NULL if  
    // the queue is empty.  
    E* Dequeue() {  
        if (size_ == 0) {  
            return NULL;  
        }  
  
        const QueueNode<E>* const old_head = head_;  
        head_ = head_->next_;  
        size_--;  
        if (size_ == 0) {  
            last_ = NULL;  
        }  
  
        E* element = new E(old_head->element());  
        delete old_head;  
  
        return element;  
    }  
  
    // Applies a function/functor on each element of the queue, and  
    // returns the result in a new queue.  The original queue is not  
    // affected.  
    template <typename F>  
    Queue* Map(F function) const {  
        Queue* new_queue = new Queue();  
        for (const QueueNode<E>* node = head_; node != NULL; node = node->next_) {  
            new_queue->Enqueue(function(node->element()));  
        }  
  
        return new_queue;  
    }  
  
private:  
    QueueNode<E>* head_;  // The first node of the queue.  
    QueueNode<E>* last_;  // The last node of the queue.  
    size_t size_;  // The number of elements in the queue.  
  
    // We disallow copying a queue.  
    Queue(const Queue&);  
    const Queue& operator = (const Queue&);  
};  
  
// A simple monotonic counter.  
class Counter {  
private:  
    int counter_;  
  
public:  
    // Creates a counter that starts at 0.  
    Counter() : counter_(0) {}  
  
    // Returns the current counter value, and increments it.  
    int Increment();  
  
    // Prints the current counter value to STDOUT.  
    void Print() const;  
};  
  
// The prime table interface.  
class PrimeTable {  
public:  
    virtual ~PrimeTable() {}  
  
    // Returns true iff n is a prime number.  
    virtual bool IsPrime(int n) const = 0;  
  
    // Returns the smallest prime number greater than p; or returns -1  
    // if the next prime is beyond the capacity of the table.  
    virtual int GetNextPrime(int p) const = 0;  
};  
  
// Implementation #1 calculates the primes on-the-fly.  
class OnTheFlyPrimeTable : public PrimeTable {  
public:  
    virtual bool IsPrime(int n) const {  
        if (n <= 1) return false;  
  
        for (int i = 2; i*i <= n; i++) {  
            // n is divisible by an integer other than 1 and itself.  
            if ((n % i) == 0) return false;  
        }  
  
        return true;  
    }  
  
    virtual int GetNextPrime(int p) const {  
        for (int n = p + 1; n > 0; n++) {  
            if (IsPrime(n)) return n;  
        }  
  
        return -1;  
    }  
};  
  
// Implementation #2 pre-calculates the primes and stores the result  
// in an array.  
class PreCalculatedPrimeTable : public PrimeTable {  
public:  
    // 'max' specifies the maximum number the prime table holds.  
    explicit PreCalculatedPrimeTable(int max)  
        : is_prime_size_(max + 1), is_prime_(new bool[max + 1]) {  
            CalculatePrimesUpTo(max);  
    }  
    virtual ~PreCalculatedPrimeTable() { delete[] is_prime_; }  
  
    virtual bool IsPrime(int n) const {  
        return 0 <= n && n < is_prime_size_ && is_prime_[n];  
    }  
  
    virtual int GetNextPrime(int p) const {  
        for (int n = p + 1; n < is_prime_size_; n++) {  
            if (is_prime_[n]) return n;  
        }  
  
        return -1;  
    }  
  
private:  
    void CalculatePrimesUpTo(int max) {  
        ::std::fill(is_prime_, is_prime_ + is_prime_size_, true);  
        is_prime_[0] = is_prime_[1] = false;  
  
        for (int i = 2; i <= max; i++) {  
            if (!is_prime_[i]) continue;  
  
            // Marks all multiples of i (except i itself) as non-prime.  
            for (int j = 2*i; j <= max; j += i) {  
                is_prime_[j] = false;  
            }  
        }  
    }  
  
    const int is_prime_size_;  
    bool* const is_prime_;  
  
    // Disables compiler warning "assignment operator could not be generated."  
    void operator=(const PreCalculatedPrimeTable& rhs);  
};  
  
#endif//_FUN_H_  

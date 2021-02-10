/* 1381. custom stack
 *
 * The basic stack implementation
 */

class CustomStack {
public:
    CustomStack(int maxSize) : capacity(maxSize), size(0) {
        arr = new int[maxSize+1];  // use a dummy element to make code simpleo
    }
    
    ~CustomStack() {
        delete [] arr;
    }
    
    void push(int x) {
        if (size < capacity)
            arr[++size] = x;
    }
    
    int pop() {
        if (size <= 0)
            return -1;
        
        return arr[size--];
    }
    
    void increment(int k, int val) {
        int n = (k <= capacity ? k : capacity);
        
        for (int i = 1; i <= n; i++) {
            arr[i] += val;
        }
    }
    
private:
    int *arr;
    unsigned int size;
    unsigned int capacity;
};

/* Array:Collectin of homogenous elemets-Continious memory
 Operation on array:
    1) Insert: At End and At Specific postition
    2) Delete:
    3) Update:
    4) Sort:
    5) Search:
    6) Max/Min:
    7) Reverse:

*/
// creating an inventory system.

#include <iostream>

class Array{
private:
    int arr[50] {};
    int end {0};

    bool is_full() { return (end == 50); };
    bool is_indexed(int index) { return (index >= 0 && index < end);}
    bool is_empty () const { return (end == 0); }

public:
    Array() = default;

    void print(){
        std::cout << "[ ";
        for(int i = 0; i < end; ++i){
            std::cout << arr[i] << ' ';
        }
        std::cout << "]";
    }

    void insert(const int value){
        insert(value,end);
    }
    void insert(const int value,const int index){
        if(is_full() || index < 0 || index > end){
            std::cerr << "stack is full or invalid index!!\n";
            return;
        }
        for(int i = end; i > index; --i){
            arr[i] = arr[i - 1];
        }
        end++;
        arr[index] = value;
        return;
    }

    void remove(const int index){
        if(!is_indexed(index)){
            std::cerr << "Invalid index to remove!\n";
            return;
        }
        for(int i = index; i < end - 1; ++i){
            arr[i] = arr[i + 1];
        }
        end--;
    }
    
    void update(const int value,int index){
        if(!is_indexed(index)){
            std::cerr << "Invalid index to update!\n";
            return;
        }
        arr[index] = value;
    }

    int search(int value) const {
        for(int i = 0; i < end; ++i){
            if(arr[i] == value ) {
                return i;
            }
        }
        return -1;
    }
    int max(){
        if(is_empty()){
            return -1;
        }
        int max{arr[0]};
        for(int i = 1; i < end; ++i){
            if(arr[i] > max){
                max = arr[i];
            }
        } 
        return max;
    }
    int min(){
        if(is_empty()){
            return -1;
        }
        int min{arr[0]};
        for(int i = 1; i < end; ++i){
            if(arr[i] < min){
                min = arr[i];
            }
        } 
        return min;
    }
    void reverse(){
        int n = (end)/2;
        for(int i = 0; i < n; ++i){
            int temp { arr[end - i - 1] };
            arr[end - i - 1] = arr[i];
            arr[i] = temp; 
        }
    }
    void sort(){
        if(is_empty() || end < 2){
            return;
        }
        for(int i = 0; i < end - 1; ++i){
            for(int j = 0; j < end - i - 1; ++j){   
                if(arr[j] > arr[j + 1]){
                    int temp = arr[j+1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    


};
int main(){

    Array list{};
    list.insert(33);
    list.insert(92);
    list.insert(75);
    list.insert(99,0);
    list.remove(0);
    list.update(50,2);
    std::cout << list.search(50) << '\n';
    std::cout << list.max() << '\n';
    std::cout << list.min() << '\n';
    list.print();
    list.reverse();
    list.print();
    list.sort();
    list.print();

    

}
#include <iostream>

class List{
private:
    struct Node{
        int id {};
        Node* next;
    };
    Node* m_head { nullptr };

    bool isEmpty() const{
        return (m_head == nullptr);
    }
public:
    List() = default;
    
    void printList(){
        if(isEmpty()) { return; }
        Node* ptr = m_head;
        while(ptr){
            std::cout << ptr->id << ' ';
            ptr = ptr->next;
        }
        std::cout << '\n';
    }
    void addStart(int id){
        Node* newNode = new Node{id, m_head};
        m_head = newNode;
    }
    void addEnd(int id){
        Node* newNode = new Node{id, nullptr};
        if(isEmpty()){
            m_head = newNode;
            return;
        }
        Node* ptr = m_head;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = newNode;

    }
    void insertAt(const int id,const int position){
        if( position < 0){
            addEnd(id);
            return;
        }
        if( position == 0){ 
            addStart(id);
            return; 
        }
        Node* ptr = m_head;
        for(int i = 0; i < position -1 && ptr; ++i){
            ptr = ptr->next;
        }
        if(ptr == nullptr){
            std::cout << "Invalid Position";
        }
        Node* newNode = new Node{id, ptr->next};
        ptr->next = newNode;
        //std::cout << "new node added";
    }
    void removeStart(){
        if(isEmpty()){ return; }
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }

    void removeEnd(){

        if(isEmpty()){ return; }

        if(m_head->next == nullptr){
            delete m_head;
            m_head = nullptr;
            return;
        }

        Node* ptr = m_head;
        while(ptr->next->next){
            ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = nullptr;

    }
    
    void removeAt(int position){
        if( position <= 0){
            removeStart();
            return;
        }
        Node* ptr = m_head;
        for(int i = 0; i < position - 1 && ptr->next; ++i){
            ptr = ptr->next;
        }
        if(ptr->next == nullptr){
            std::cout << "Invalid invalid";
        }
        Node* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    void update(int n, int position){
        Node* ptr = m_head;
        for(int i = 0; i < position && ptr != nullptr; ++i){
            ptr = ptr->next;
        }
        if(ptr == nullptr){
            std::cout << "invalid Position";
            return;
        }
        ptr->id = n;
    }


    int search(int n) const {
        if( isEmpty() ) { return -1; };
        Node* ptr = m_head;
        int i { 0 };
        while(true){
            if(ptr->id == n){
                return i;
            }
            if(!ptr->next){
                return -1;
            }
            ptr = ptr->next;
            ++i;
        }
    }

};

int main(){

    List data {};

    // data.addStart(1);
    // data.addStart(2);
    // data.addStart(3);
    // data.addStart(4);
    // data.addEnd(0);
    // data.insertAt(99,2);
    // data.printList();

    // data.removeEnd();
    // data.removeAt(0);
    // data.printList();

    // data.removeAt(data.search(99));
    // data.printList();
    // data.update(99,2);
    // data.printList();

}
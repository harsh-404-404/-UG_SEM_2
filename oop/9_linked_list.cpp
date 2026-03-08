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
        m_head = new Node{id, m_head};
    }
    void addEnd(int id){
        Node** ptr = &m_head;
        while (*ptr){
            ptr = &((*ptr)->next);
        }
        *ptr = new Node{ id, nullptr };
    }

    void insertAt(const int id,const int position){
        Node** ptr { &m_head };
        int i { 0 };
        while ( i < position && *ptr){
            ptr = &((*ptr)->next);
            ++i;
        }
        if(i != position){ 
            std::cout << "Invalid posion"; 
            return;
        }
        *ptr = new Node{ id, *ptr };
        
    }

    void removeStart(){
        if(isEmpty()){ return; }
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }

    void removeEnd(){

        if(isEmpty()){ return; }
        Node** ptr { &m_head };
        while ((*ptr)->next){
            ptr = &((*ptr)->next);
        }
        delete *ptr;
        *ptr = nullptr;
    }
    
    void removeAt(int position){
        Node** ptr { &m_head };
        int i { 0 };
        while (i < position && *ptr){
            ptr = &((*ptr)->next);
            ++i;
        }
        if(i != position){
            std::cout << "Invalid removAt()";
            return;   
        }
        Node* temp { *ptr };
        *ptr = (*ptr)->next;
        delete temp; 
        
    }

    void update(int n, int position){
        Node** ptr { &m_head };
        int i { 0 }; 
        while (i < position && *ptr){
            ptr = &((*ptr)->next);
            ++i;
        }
        if(i != position){
            std::cout << "Invalid position for update()";
            return;   
        }
        (*ptr)->id = n;
        
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

    data.addStart(1);
    data.addStart(2);
    data.addStart(3);
    data.addStart(4);
    data.addEnd(0);
    data.insertAt(99,2);
    data.printList();

    data.removeEnd();
    data.removeAt(0);
    data.printList();

    data.removeAt(data.search(99));
    data.printList();
    data.update(99,2);
    data.printList();

}
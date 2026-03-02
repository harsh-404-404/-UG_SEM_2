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

    void addstart(int id){
        Node* newNode = new Node{id, m_head};
        m_head = newNode;
    }
    void addend(int id){
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
    void printList(){
        if(isEmpty()) { return; }
        Node* ptr = m_head;
        while(ptr->next){
            std::cout << ptr->id << ' ';
            ptr = ptr->next;
        }
        std::cout << ptr->id;
    }
};

int main(){

    List data {};
    data.addstart(1);
    data.addstart(2);
    data.addend(23);
    
    data.printList();
    
}
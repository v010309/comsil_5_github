#include <iostream>
#include <string>
using namespace std;

// Linked List Node
template<typename T>
class Node {
public:
    T data;
    Node *link;
    Node(T element) {
        data = element;
        link = 0;
    }
};
// Linked List Class
template<typename T>
class LinkedList {
protected:
    Node<T> *first;
    int current_size;
public:
    LinkedList() {
        first = 0;
        current_size = 0;
    };
    int GetSize() { return current_size; };
    void Insert(T element);
    virtual bool Delete(T &element); 
    void Print(); 
};

template<typename T>
void LinkedList<T>::Insert(T element) {
    Node<T> *newnode = new Node<T>(element);
    newnode->link = first;
    first = newnode;
    current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T &element) {
   
    if(first == 0) return false;
    Node<T> *current = first, *previous = 0;
    while(1){ 
        if(current->link == 0) {// find end node
            if(previous) previous->link = current->link;
            else first = first->link;
            break;
        }
        previous = current;
        current = current->link;
    }
    element = current->data;
    delete current;
    current_size--;
 return true;
}


template <typename T>
void LinkedList<T>::Print(){
        if(first == 0) return;
        Node<T> *current = first;
        int count = 1;
        while(current->link != NULL){
                 cout<<"["<<count<<"|"<<current->data<<"]->";
                current = current->link;
                count++;
        }
        cout<<"["<<count<<"|"<<current->data<<"]"<<endl;
        return;
}

template <typename T>
class Stack : public LinkedList<T>{
        private:

        public:

        bool Delete(T &element);
};

template <typename T>
bool Stack<T>::Delete(T &element){
        if(this->first == 0)  return false;
        Node<T> *current = this->first;
        this->first = this->first->link;
        element = current->data;
	delete current;
        this->current_size--;
        return true;
}


void prnMenu() {
    cout<<"*******************************************"<<endl;
    cout<<"* 1. insert 2. delete 3. print 4. exit *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
    cout<<"select menu: ";
}

int main() {
    // 스택 및 연결 리스트 테스트용 코드
    int mode, selectNumber, tmpItem;
    LinkedList<int> *p;
    bool flag = false;
    cout << "자료구조 선택(1: Stack, Other: Linked List): ";
    cin >> mode;
    // 기반 클래스의 포인터를 사용하여 기반 클래스 뿐만 아니라
    // 파생 클래스의 인스턴스 또한 접근할 수 있다. 
    if(mode == 1)
        p = new Stack<int>(); // 정수를 저장하는 스택
    else
        p = new LinkedList<int>(); // 정수를 저장하는 연결 리스트
    // 처리 부분
    do{
        prnMenu();
        cin>>selectNumber;
        switch(selectNumber) {
            case 1:
                cout<<"원하시는 값을 입력해주세요: ";
                cin>>tmpItem;
                p->Insert(tmpItem);
                cout<<tmpItem<<"가 삽입되었습니다."<<endl;
                break;
            case 2:
                if(p->Delete(tmpItem)==true)
                    cout<<tmpItem<<"가 삭제되었습니다."<<endl;
                else
                    cout<<"비어있습니다. 삭제 실패"<<endl;
                break;
            case 3:
                cout<<"크기: "<<p->GetSize()<<endl;
                p->Print();
                break;
            case 4:
                flag = true;
                break;
            default:
                cout<<"잘못 입력하셨습니다."<<endl;
                break;
        }
        if(flag)
            break;
    }
    while(1);
    return 0;
}

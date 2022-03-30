#include<iostream>
#include<string>

using namespace std;

class Node
{
private:
    int value;
    Node *next;
public:
    Node(int initvalue){
        value = initvalue;
        next = NULL;
    }

    int getValue(){
        return value;
    }

    Node *getNext(){
        return next;
    }

    void setValue(int newValue){
        value = newValue;
    }

    void setNext(Node *newNext){
        next = newNext;
    }
};

class UnorderedList{
    public:
        Node *head;//front
        Node *tail;//back
        UnorderedList(){
            head = NULL;
        }

        bool isEmpty(){//return bool empty/tidak
            return head == NULL;
        }
        
        void add(int addValue){//tambah value ke head
            Node *temp = new Node(addValue);
            temp->setNext(head);
            head = temp;
            if (head->getNext() == NULL)
                tail = head;
        }

        void append(int appValue){//add at the back (with O(1))
            Node *temp = new Node(appValue);
            temp->setNext(NULL);
            tail->setNext(temp);
            tail = temp;
        }

        int size(){//return size list
            int count = 0;
            Node *current = head;
            while(current != NULL){
                count++;
                current = current->getNext();
            }
            return count;
        }

        bool search(int testValue){//return bool ada/tidak suatu value
            Node *current = head;
            while(current != NULL){
                if(current->getValue()==testValue) 
                    return true;
                else 
                    current = current->getNext();
            }
            return false;
        }
        
        void remove(int rmValue){
            Node *current = head;
            Node *previous = NULL;
            while(current != NULL){;
                if(current->getValue()==rmValue){
                    if(previous == NULL){
                        head = head->getNext();
                        return;
                    }
                    else{ 
                        previous->setNext(current->getNext());
                        if(previous->getNext() == NULL)
                            tail = previous;
                        return;
                    }
                }
                else {
                    previous = current;
                    current = current->getNext();
                }
            }
        }

        void pop_front(){
            head = head->getNext();
        }

        void pop_back(){
            if(this->isEmpty())
                return;
            Node *current = head;
            Node *previous = NULL;
            while(current != NULL){;
                if(current->getNext()==NULL){
                    tail = previous;
                    tail->setNext(NULL);
                }
                else {
                    previous = current;
                    current = current->getNext();
                }
            }
        }

        string list(){//return isi list
            Node *current = head;
            string listStr;
            while(current != NULL){
                listStr += to_string(current->getValue())+" ";
                current = current->getNext();
            }
            return listStr;
        }
};

class OrderedList{
    public:
        Node *head;//front
        OrderedList(){
            head = NULL;
        }

        bool isEmpty(){//return bool empty/tidak
            return head == NULL;
        }
        
        void add(int addValue){//tambah value ke head
            if(head == NULL){//kalo ini node pertama
                Node *temp = new Node(addValue);
                head = temp;
                head->setNext(NULL);
                return;
            }
            Node *current = head;
            Node *previous = NULL;
            while(current!=NULL){
                if(addValue < current->getValue()){
                    Node *added = new Node(addValue);
                    added->setNext(current);
                    if(previous != NULL)//bila node tidak paling kecil
                        previous->setNext(added);
                    else{//bila node paling kecil(head)
                        added->setNext(head);
                        head = added;
                    }
                    return;
                }
                previous = current;
                current = current->getNext();
            }
            Node *added = new Node(addValue);
            added->setNext(current);
            previous->setNext(added);
        }

        int size(){//return size list
            int count = 0;
            Node *current = head;
            while(current != NULL){
                count++;
                current = current->getNext();
            }
            return count;
        }

        bool search(int testValue){//return bool ada/tidak suatu value
            Node *current = head;
            while(current != NULL){
                if(current->getValue()==testValue) 
                    return true;
                else 
                    current = current->getNext();
            }
            return false;
        }
        
        void remove(int rmValue){
            Node *current = head;
            Node *previous = NULL;
            while(current != NULL){;
                if(current->getValue()==rmValue){
                    if(previous == NULL){
                        head = head->getNext();
                        return;
                    }
                    else{ 
                        previous->setNext(current->getNext());
                        return;
                    }
                }
                else {
                    previous = current;
                    current = current->getNext();
                }
            }
        }

        string list(){//return isi list
            Node *current = head;
            string listStr;
            while(current != NULL){
                listStr += to_string(current->getValue())+" ";
                current = current->getNext();
            }
            return listStr;
        }
};

int main(){
    OrderedList mylist;
    cout << mylist.isEmpty()<<endl;

    mylist.add(5);  
    mylist.add(10);
    mylist.add(69);
    mylist.add(21);
    mylist.add(16);
    mylist.add(49);
    mylist.add(100);
    cout << mylist.list();
}
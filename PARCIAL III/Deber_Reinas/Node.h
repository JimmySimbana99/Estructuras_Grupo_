
template <typename T>
class Node{
    private:
        T data;
        Node *next = nullptr;
        Node *previous = nullptr;

    public:

        Node(T _data);

        T getValor();
        void setValor(T newData);
        
        Node *getNext();
        void setNext(Node *newNext);
        
        Node *getPrevious();
        void setPrevious(Node *newPrevious); 
};

template <typename T>
Node<T>::Node(T _data){
    this->data = _data;
}

template <typename T>
T Node<T>::getValor(){
    return data;
}

template <typename T>
void Node<T>::setValor(T newData){
    data = newData;
}

template <typename T>
Node<T>* Node<T>::getNext(){
    return next;
}

template <typename T>
void Node<T>::setNext(Node *newNext){
    next = newNext;
}

template <typename T>
Node<T> *Node<T>::getPrevious(){
    return previous;
}

template <typename T>
void Node<T>::setPrevious(Node *newPrevious){
    previous = newPrevious;
} 

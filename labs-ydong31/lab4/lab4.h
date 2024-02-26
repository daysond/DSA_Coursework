#include <iostream>

template <typename T>
class DList{
    struct Node{
        T data_;
        Node* next_;
        Node* prev_;
        Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
            data_=data;
            next_=next;
            prev_=prev;
        }
    };
    Node* front_;
    Node* back_;
public:
    DList(){
        front_=nullptr;
        back_=nullptr;
    }
    void push_front(const T& data);
    ~DList();

    class const_iterator{
        friend class DList;
    protected:
        const DList* list_;
        Node* curr_;

    public:
        const_iterator(){
            curr_ = nullptr;
            list_ = nullptr;
        }

		const_iterator(Node* current, const DList* list){
            curr_ = current;
            list_ = list;
        }
        const_iterator& operator++(){
            if (curr_)
                curr_ = curr_->next_;
            return *this;
        }

        const_iterator operator++(int){
            const_iterator copy = *this;
            if (curr_)
                curr_ = curr_->next_;
            return copy;
        }

        const_iterator& operator--(){
            if (curr_)    curr_ = curr_->prev_;
            else if (list_)    curr_ = list_->back_;
            return *this;
        }
        const_iterator operator--(int){
            const_iterator copy = *this;
            if (curr_)    curr_ = curr_->prev_;
            else if (list_)    curr_ = list_->back_;
            return copy;
        }

        bool operator==(const_iterator const &rhs) {
            return curr_ == rhs.curr_;
        }

        bool operator!=(const_iterator const &rhs) {
            return curr_ != rhs.curr_;
        }

        const T& operator*()const{
            return curr_->data_;
        }
 
    };
    class iterator: public const_iterator{
        friend class DList;
    public:
		iterator() {
			this->curr_ = nullptr;
			this->list_ = nullptr;
		}
        iterator(Node* curr, DList* list) {
			this->curr_ = curr;
			this->list_ = list;
		}
        iterator& operator++(){
            if (this->curr_)
                this->curr_ = this->curr_->next_;
            return *this;
        }

        iterator operator++(int){
            iterator copy = *this;
            if (this->curr_)
                this->curr_ = this->curr_->next_;
            return copy;
        }
        iterator& operator--(){
            if (this->curr_)    this->curr_ = this->curr_->prev_;
            else if (this->list_)    this->curr_ = this->list_->back_;
            return *this;
        }
        iterator operator--(int){
            iterator copy = *this;
            if (this->curr_)    this->curr_ = this->curr_->prev_;
            else if (this->list_)    this->curr_ = this->list_->back_;
            return copy;
        }
        T& operator*(){
            return this->curr_->data_;
        }
        const T& operator*()const{
            return this->curr_->data_;
        }

    };

    const_iterator cbegin() const{ return const_iterator(front_, this);}
    iterator begin(){ return iterator(front_, this);}
    const_iterator cend() const{ return const_iterator(nullptr, this);}
    iterator end(){ return iterator(nullptr, this);}
};


template <typename T>
void DList<T>::push_front(const T& data){
    Node *nn = new Node(data, front_, nullptr);
    if (front_)
        front_->prev_ = nn;
    else
        back_ = nn;

    front_ = nn;
}


template <typename T>
DList<T>::~DList(){
    Node *temp;
    while (front_) {
        temp = front_->next_;
        delete front_;
        front_ = temp;
    }
}


template <typename T>
class Sentinel{
    struct Node{
        T data_;
        Node* next_;
        Node* prev_;
        Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
            data_=data;
            next_=next;
            prev_=prev;
        }
    };
    Node* front_;
    Node* back_;
public:
    Sentinel(){
        front_=new Node();
        back_=new Node();
        front_->next_=back_;
        back_->prev_=front_;
    }
    void push_front(const T& data);
    ~Sentinel();

    class const_iterator{
        
        friend class Sentinel;
        
    protected:
        const Sentinel* list_;
        Node* curr_;
        const_iterator(Node* current, const Sentinel* list){
            curr_ = current;
            list_ = list;
        }
    public:
        const_iterator(){
            list_ = nullptr;
            curr_ = nullptr;
        }
        
        const_iterator& operator++(){
            if(curr_ != list_->back_)
                curr_ = curr_->next_;
            return *this;
        }
        
        const_iterator operator++(int){
            const_iterator copy = *this;
            if(curr_!= list_->back_)
                curr_ = curr_->next_;
            return copy;
        }
        
        const_iterator& operator--(){
            if(curr_ != list_->front_)
                curr_ = curr_->prev_;
            return *this;
        }
        
        const_iterator operator--(int){
            const_iterator copy = *this;
            if(curr_!= list_->front_)
                curr_ = curr_->prev_;
            return copy;
        }
        
        bool operator==(const_iterator const &rhs){
            return curr_ == rhs.curr_;
        }
        
        bool operator!=(const_iterator const &rhs){
            return curr_ != rhs.curr_;
        }
        const T& operator*()const{ return curr_->data_;}
    };
    class iterator:public const_iterator{
        friend class Sentinel;

    public:
        iterator() {
            this->curr_ = nullptr;
            this->list_ = nullptr;
        };

		iterator(Node* curr, Sentinel* list) {
			this->curr_ = curr;
			this->list_ = list;
		};
        
        iterator& operator++(){
            if (this->curr_ != this->list_->back_)
                this->curr_ = this->curr_->next_;
            return *this;
        }
        
        iterator operator++(int){
            iterator copy = *this;
            if(this->curr_!= this->list_->back_)
                this->curr_ = this->curr_->next_;
            return copy;
        }
        
        iterator& operator--(){
            if(this->curr_ != this->list_->front_)
                this->curr_ = this->curr_->prev_;
            return *this;
        }
        
        iterator operator--(int){
            iterator copy = *this;
            if(this->curr_!= this->list_->front_)
                this->curr_ = this->curr_->prev_;
            return copy;
        }
        T& operator*(){ return this->curr_->data_; }
        
        const T& operator*()const{ return this->curr_->data_; }
    };
    const_iterator cbegin() const{ return const_iterator(front_->next_, this);}
    iterator begin(){ return iterator(front_->next_, this);}
    const_iterator cend() const{ return const_iterator(back_, this);}
    iterator end(){ return iterator(back_, this);}
};


template <typename T>
void Sentinel<T>::push_front(const T& data){
    Node *nn = new Node(data, front_->next_, front_);
    front_->next_->prev_ = nn;
    front_->next_ = nn;
}


template <typename T>
Sentinel<T>::~Sentinel(){
    Node *temp;
    while (front_->next_ != back_) {
        temp = front_->next_->next_;
        delete front_->next_;
        front_->next_ = temp;
    }
}

/********************************************************************/
/*                                                                  */
/*  Put your linked list code from A1 into                          */
/*  this file                                                       */
/*                                                                  */
/********************************************************************/


#include <iostream>
#include <unistd.h>
#include <utility>

template <typename T>

class DList {

    struct Node {
        T data_;
        struct Node *prev_;
        struct Node *next_;

        Node(const T &data, Node *next = nullptr, Node *prev = nullptr) {
            data_ = data;
            next_ = next;
            prev_ = prev;
        }
    };

    //	Properties:
    Node *front_ = nullptr;
    Node *back_ = nullptr;
    int size_ = 0;

  public:
    class const_iterator {
        friend class DList;

      protected:
        Node *current_;
        const DList *list_;

      public:
        // constructors, returns iterators to nullptrs
        const_iterator() {
            current_ = nullptr;
            list_ = nullptr;
        }
        // constructors, returns iterators starting at the node passed in
        const_iterator(Node *current, const DList *list) {
            current_ = current;
            list_ = list;
        }

        /*
        prefix and postfix ++ operator
        makes iterator point to the next node in the list.
        return as appropriate for each operator
        */
        // prefix ++
        const_iterator &operator++() {
            if (current_)
                current_ = current_->next_;
            return *this;
        }
        //  postfix ++
        const_iterator operator++(int) {
            const_iterator copy = *this;
            if (current_)
                current_ = current_->next_;
            return copy;
        }
        /*
        prefix and postfix operator --
        decrements iterator so that it points to previous node in list
        return as appropriate for each operator
        */
        // prefix --        
        const_iterator &operator--() {
            if (current_)
                current_ = current_->prev_;
            else if (list_)
                current_ = list_->back_;
            return *this;
        }
        // postfix --
        const_iterator operator--(int) {
            const_iterator copy = *this;
            if (current_)
                current_ = current_->prev_;
            else if (list_)
                current_ = list_->back_;
            return copy;
        }
        // compare if two iterators are equal
        bool operator==(const_iterator const &rhs) {
            return current_ == rhs.current_;
        }
        // compare if two iterators are not equal
        bool operator!=(const_iterator const &rhs) {
            return current_ != rhs.current_;
        }
        //  returns a const reference to data in the node referred to by the iterator.
        const T &operator*() const { return current_->data_; }
    };

    class iterator : public const_iterator {
        friend class DList;

      public:
        // constructors, returns iterators to nullptrs
        iterator() {
            this->current_ = nullptr;
            this->list_ = nullptr;
        }
        // constructors, returns iterators starting at the node passed in
        iterator(Node *current, DList *list) : const_iterator(current, list) {}

        /*
        prefix and postfix ++ operator
        makes iterator point to the next node in the list.
        return as appropriate for each operator
        */
        // prefix ++
        iterator &operator++() {
            if (this->current_)
                this->current_ = this->current_->next_;
            return *this;
        }
        // postfix ++
        iterator operator++(int) {
            iterator copy = *this;
            if (this->current_)
                this->current_ = this->current_->next_;
            return copy;
        }

        /*
        prefix and postfix operator --
        decrements iterator so that it points to previous node in list
        return as appropriate for each operator
        */
        // prefix --
        iterator &operator--() {
            if (this->current_)
                this->current_ = this->current_->prev_;
            else if (this->list_)
                this->current_ = this->list_->back_;
            return *this;
        }
        // postfix --
        iterator operator--(int) {
            iterator copy = *this;
            if (this->current_)
                this->current_ = this->current_->prev_;
            else if (this->list_)
                this->current_ = this->list_->back_;
            return copy;
        }
        //  returns a reference to data in the node referred to by the iterator.
        T &operator*() { return this->current_->data_; }
        //  returns a const reference to data in the node referred to by the iterator.
        const T &operator*() const { return this->current_->data_; }
    };

    DList();
    ~DList();
    DList(const DList &rhs);
    DList &operator=(const DList &rhs);
    DList(DList &&rhs);
    DList &operator=(DList &&rhs);
    iterator insert(iterator it, const T &data);
    iterator search(const T &data);
    iterator erase(iterator it);
    void sort(iterator first, iterator last);
    bool empty() const;
    int size() const;

    iterator begin() { return iterator(front_, this); }
    iterator end() { return iterator(nullptr, this); }
    const_iterator cbegin() const { return const_iterator(front_, this); }
    const_iterator cend() const { return const_iterator(nullptr, this); }

  private: 
  //    MARK: Helper methods
    //  deletes all the nodes in the list
    void deleteNodes() {
        Node *temp;
        while (front_) {
            temp = front_->next_;
            delete front_;
            front_ = temp;
        }
        back_ = nullptr;
    }
    // copies node from a list to an EMPTY list
    void copyNode(DList<T>::Node *src, DList<T>::Node *&dest,
                  DList<T>::Node *prev) {
        // base case: source node ends
        if (src->next_ == nullptr) {
            dest = new Node(src->data_);
            back_ = dest;
        } else if (dest == nullptr) {
            dest = new Node(src->data_);
            copyNode(src->next_, dest->next_, prev);
        }
    }

    // This function takes the pointer to reference of two nodes as arguments,  
    // swaps two nodes while keeping the pointer at the same postion in the list
    void swapNodes(Node *&lhs, Node *&rhs) {
        //  edges cases
        if (lhs == rhs || !lhs || !rhs)
            return;

        // variables of neighbour nodes
        Node *lp = lhs->prev_;
        Node *rn = rhs->next_;
        Node *ln = lhs->next_;
        Node *rp = rhs->prev_;

        if (lhs->next_ == rhs) { // nodes are next to each other
            //  reconstructing relationships
            lp ? lp->next_ = rhs : front_ = rhs;

            rhs->prev_ = lp;
            rhs->next_ = lhs;
            lhs->prev_ = rhs;
            lhs->next_ = rn;

            rn ? rn->prev_ = lhs : back_ = lhs;

        } else if (rhs->next_ == lhs) { // nodes are next to each other
            //  reconstructing relationships
            rp ? rp->next_ = lhs : front_ = lhs;

            lhs->prev_ = rp;
            lhs->next_ = rhs;
            rhs->prev_ = lhs;
            rhs->next_ = ln;

            ln ? ln->prev_ = rhs : back_ = rhs;

        } else { // nodes are at least one node apart
            //  reconstructing relationships
            lp ? lp->next_ = rhs : front_ = rhs;
            rhs->prev_ = lp;

            ln ? ln->prev_ = rhs : back_ = rhs;
            rhs->next_ = ln;

            rp ? rp->next_ = lhs : front_ = lhs;
            lhs->prev_ = rp;

            rn ? rn->prev_ = lhs : back_ = lhs;
            lhs->next_ = rn;
        }
        //  swapping the pointers
        Node *temp = lhs;
        lhs = rhs;
        rhs = temp;
    }
};
// constructor, creates empty DList
template <typename T> DList<T>::DList() {}
// destructor
template <typename T> DList<T>::~DList() { deleteNodes(); }

//  copy constructor
template <typename T> DList<T>::DList(const DList &rhs) { *this = rhs; }
//  copy assignment
template <typename T> DList<T> &DList<T>::operator=(const DList &rhs) {
    if (this != &rhs && rhs.front_) {
        size_ = rhs.size_;
        deleteNodes();
        copyNode(rhs.front_, front_, nullptr);
    }
    if (!rhs.front_) {
        size_ = 0;
        deleteNodes();
    }
    return *this;
}

//  move constructor
template <typename T> DList<T>::DList(DList &&rhs) { *this = std::move(rhs); }

//  move assignment
template <typename T> DList<T> &DList<T>::operator=(DList &&rhs) {
    if (this != &rhs) {
        deleteNodes();
        size_ = rhs.size_;
        front_ = rhs.front_;
        back_ = rhs.back_;
        rhs.front_ = nullptr;
        rhs.back_ = nullptr;
        rhs.size_ = 0;
    }
    return *this;
}

template <typename T>
typename DList<T>::iterator DList<T>::insert(iterator it, const T &data) {
    /*
    This function adds new node containing data before the node refer to by it.
    function returns iterator to newly added node
    */  

    Node *nn;

    if (it.current_ == front_) {
        //  insert to the front
        nn = new Node(data, front_, nullptr);
        front_ ? front_->prev_ = nn : back_ = nn;
        front_ = nn;

    } else if (it.current_ == nullptr) {
        // insert to the end()
        nn = new Node(data, nullptr, back_);
        back_ ? back_->next_ = nn : front_ = nn;
        back_ = nn;

    } else {
        // insert any where else
        nn = new Node(data, it.current_, it.current_->prev_);
        it.current_->prev_->next_ = nn;
        it.current_->prev_ = nn;
    }
    size_ += 1;
    return iterator(nn, this);
}

template <typename T>
typename DList<T>::iterator DList<T>::search(const T &data) {
    //  returns iterator to the node containing data. If data is not found, returns end()
    Node *temp = front_;
    if (temp) {
        bool found = false;
        while (temp && !found) {
            if (temp->data_ == data)
                found = true;
            else
                temp = temp->next_;
        }
    } 
    return iterator(temp, this);
}

template <typename T> typename DList<T>::iterator DList<T>::erase(iterator it) {
    /*
    This function removes the node referred to by it
    returns iterator to node that follows the node that was removed
    */  
    if (!it.current_)
        return iterator();
    Node *curr = it.current_; // the node that needs to be erased
    Node *ret;
    if (curr == front_) { // case: front
        front_ = curr->next_;
        if(front_) front_->prev_ = nullptr;
        ret = front_;
    } else if (curr == back_) { // case: back
        back_ = curr->prev_;
        if(back_) back_->next_ = nullptr;
        ret = nullptr;
    } else { // case: any other node
        ret = curr->next_;
        curr->next_->prev_ = curr->prev_;
        curr->prev_->next_ = curr->next_;
    }
    delete curr;
    curr = nullptr;
    size_ -= 1;
    return iterator(ret, this);
}

template <typename T> void DList<T>::sort(iterator first, iterator last) {
    /*
    This function sorts all nodes from first to last, including first but not including last. 
    the data within each node is not to be swapped around... the point is to be able to move nodes around to sort.
    For example:    Initial current list: {1, 3, 4, 8, 2, 4, 7, 3, 6, 5, 9, 10}, suppose that first refers to the node with 8, last refers to the node with 5.  
    The function would sort the nodes with the bolded values:{1, 3, 4, 8,2,4,7,3,6, 5, 9, 10}
    The final list would end up with values in the following order: {1, 3, 4, 2, 3, 4, 6, 7, 8, 5, 9, 10}
    */
    Node *anchored = first.current_;
    Node *curr = anchored->next_;
    Node *smallest;

    //  selection sort
    while (curr != last.current_) {

        smallest = curr;
        //  find the smallest node
        while (curr != last.current_) {
            if (curr->data_ < smallest->data_)
                smallest = curr;
            curr = curr->next_;
        }

        // swap the smallest node with the first node of the unsorted part
        if (smallest->data_ < anchored->data_)
            swapNodes(anchored, smallest);

        //  advance nodes
        anchored = anchored->next_;
        if (anchored)
            curr = anchored->next_;
    }
}

//  This function returns true if the list is empty, false otherwise
template <typename T> bool DList<T>::empty() const { return size_ == 0; }
//  This function returns number of pieces of data stored in the list
template <typename T> int DList<T>::size() const { return size_; }

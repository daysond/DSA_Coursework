#include <iomanip>
#include <iostream>
using namespace std;
/*forward declaration*/
template <class T> class Queue;

template <class T> class BST {
    struct Node {
        T data_;
        Node *left_;
        Node *right_;
        Node(const T &data, Node *lt = nullptr, Node *rt = nullptr) {
            data_ = data;
            left_ = lt;
            right_ = rt;
        }
    };
    Node *root_;

    void printPreOrder(Node *subroot) const {
        if (subroot) {
            std::cout << subroot->data_ << " ";
            printPreOrder(subroot->left_);
            printPreOrder(subroot->right_);
        }
    }
    void printInOrder(Node *subroot) const {
        if (subroot) {
            printInOrder(subroot->left_);
            std::cout << subroot->data_ << " ";
            printInOrder(subroot->right_);
        }
    }
    void destroy(Node *subroot) {
        if (subroot) {
            destroy(subroot->left_);
            destroy(subroot->right_);
            delete subroot;
        }
    }

    bool isSame(const Node *left, const Node *right) const;

    /*used by print() to print all nodes at same level*/
    void printLine(Node *data[], int numNodes, int width) const {
        int half = width / 2;
        int firsthalf = width % 2 ? half + 1 : half;

        if (numNodes > 1) {
            for (int i = 0; i < numNodes; i++) {
                if (i % 2 == 0) {
                    if (data[i]) {
                        std::cout << std::right << std::setfill(' ')
                                  << std::setw(firsthalf) << "-";
                        std::cout << std::left << std::setfill('-')
                                  << std::setw(half) << "-";
                    } else {
                        std::cout << std::right << std::setfill(' ')
                                  << std::setw(firsthalf) << " ";
                        std::cout << std::left << std::setfill(' ')
                                  << std::setw(half) << " ";
                    }
                } else {
                    if (data[i]) {
                        std::cout << std::right << std::setfill('-')
                                  << std::setw(firsthalf) << "-";
                        std::cout << std::left << std::setfill(' ')
                                  << std::setw(half) << "-";
                    } else {
                        std::cout << std::right << std::setfill(' ')
                                  << std::setw(firsthalf) << " ";
                        std::cout << std::left << std::setfill(' ')
                                  << std::setw(half) << " ";
                    }
                }
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < numNodes; i++) {
            if (data[i]) {
                if (i % 2 == 0) {
                    std::cout << std::right << std::setw(firsthalf) << "|";
                    std::cout << std::left << std::setfill(' ')
                              << std::setw(half) << " ";
                } else {
                    std::cout << std::right << std::setfill(' ')
                              << std::setw(firsthalf) << " ";
                    std::cout << std::left << std::setfill(' ')
                              << std::setw(half) << "|";
                }
            } else {
                std::cout << std::left << std::setfill(' ') << std::setw(width)
                          << " ";
            }
        }
        std::cout << std::endl;
        for (int i = 0; i < numNodes; i++) {
            if (data[i]) {
                if (i % 2 == 0) {
                    std::cout << std::right << std::setw(firsthalf)
                              << data[i]->data_;
                    std::cout << std::left << std::setfill(' ')
                              << std::setw(half) << " ";
                } else {
                    std::cout << std::right << std::setfill(' ')
                              << std::setw(firsthalf) << " ";
                    std::cout << std::left << std::setfill(' ')
                              << std::setw(half) << data[i]->data_;
                }
            } else {
                std::cout << std::left << std::setfill(' ') << std::setw(width)
                          << " ";
            }
        }
        std::cout << std::endl;
    }

  public:
    BST() { root_ = nullptr; }

    /* Lab 7: Implement these 3 functions. */
    BST(const BST &rhs) {
        if(rhs.root_) {
            copyNode(rhs.root_, root_);
        }
    }

    void copyNode(Node *src, Node *&dest) {
        /*
        This function takes a node of a tree as source and another as destination,
        copies the tree from source to destination 
        */
        if(src) {
            dest = new Node(src->data_);
            if(src->left_) copyNode(src->left_, dest->left_);
            if(src->right_) copyNode(src->right_, dest->right_);
        }
    }

    void remove(const T &data) {
  
		Node **node = &root_;
		
		while(node) {
			if(data == (*node)->data_) break;
        	node =  (data < (*node)->data_) ? &(*node)->left_ : &(*node)->right_;
		}

		if(!node) return;

		// case 1: removing a leaf
		if(!(*node)->left_ && !(*node)->right_){
			delete (*node);
			(*node) = nullptr;
            return ;
		}
		// case 2: removing a node with one child
		if( (((*node)->left_ == nullptr) ^ ((*node)->right_==nullptr))) {
        	Node *child = ((*node)->left_ != nullptr) ? (*node)->left_ : (*node)->right_;
			delete (*node);
			(*node) = child;
            return;
   		}

		//  case 3: removing a node with two children
		if((*node)->left_ && (*node)->right_) {

            Node *rm = (*node); // storing pointer of the remove node
			Node *successor = (*node)->right_;  // pointer to the successor
			Node *suc_parent = nullptr; // pointer to the parent of successor
			while((successor)->left_) {
                // go all the way left
                suc_parent = successor;
				successor = (successor)->left_;
			}

            (*node) = successor;    // replace the position of the the remove node with successor
            
            if(suc_parent) {
                //  if rm is not the parent of the successor 
                suc_parent->left_ = successor->right_;
                if(successor->right_) suc_parent->left_ = successor->right_;
            }
                
            // taking care of the left and right children of the remove node
            successor->left_ = rm->left_;
            if(suc_parent) //skip this if rm is suc_parent, aka suc_parent is null
                successor->right_ = rm->right_;
            
            delete rm;
            rm = nullptr;

		}
    }

    void findDepth(const T &data, Node *node, int currentDepth, int &depth) {
        /*
        This function take a data, a starting node, a current depth of the node and a depth and finds the depth of the node where data is stored
        returns the depth of the node via depth
        */ 
        
        if(depth != -1) return;

        if(node->data_ == data) depth = currentDepth;

        int next = currentDepth + 1;

        if(node->left_) findDepth(data, node->left_, next, depth);

        if(node->right_) findDepth(data, node->right_, next, depth);

    }

    int depth(const T &data) {
        int d = -1; 
        findDepth(data, root_, 0, d);
        return d;
    }



    void printPreOrder() const {
        printPreOrder(root_);
        std::cout << std::endl;
    }
    void printInOrder() const {
        printInOrder(root_);
        std::cout << std::endl;
    }

    void insert(const T &data) {
        if (root_ == nullptr) {
            root_ = new Node(data);
        } else {

            Node *curr = root_;
            while (curr != nullptr) {
                if (data < curr->data_) {
                    // go left
                    if (curr->left_) {
                        curr = curr->left_;
                    } else {
                        curr->left_ = new Node(data);
                        curr = nullptr;
                    }
                } else {
                    // go right
                    if (curr->right_) {
                        curr = curr->right_;
                    } else {
                        curr->right_ = new Node(data);
                        curr = nullptr;
                    }
                }
            }
        }
    }

    bool operator==(const BST &rhs) const;
    void print() const {
        struct Output {
            Node *node_;
            int lvl_;
            int position_;
            Output(Node *n = nullptr, int l = 0, int p = 0) {
                node_ = n;
                lvl_ = l;
                position_ = p;
            }
            void set(Node *n = nullptr, int l = 0, int p = 0) {
                node_ = n;
                lvl_ = l;
                position_ = p;
            }
        };
        Queue<Output> theNodes;
        Node *line[16];
        if (root_) {
            for (int i = 0; i < 16; i++) {
                line[i] = nullptr;
            }
            theNodes.enqueue(Output(root_, 0, 0));
            int currline = 0;
            int width = 80;
            int numInLine = 1;
            while (theNodes.isEmpty() == false) {
                Output curr = theNodes.front();
                if (curr.node_->left_)
                    theNodes.enqueue(Output(curr.node_->left_, curr.lvl_ + 1,
                                            curr.position_ * 2));
                if (curr.node_->right_)
                    theNodes.enqueue(Output(curr.node_->right_, curr.lvl_ + 1,
                                            curr.position_ * 2 + 1));
                theNodes.dequeue();

                if (curr.lvl_ > currline) {
                    printLine(line, numInLine, width);
                    width = width / 2;
                    numInLine = numInLine * 2;
                    for (int i = 0; i < 16; i++) {
                        line[i] = nullptr;
                    }
                    currline++;
                }
                line[curr.position_] = curr.node_;
            }
            printLine(line, numInLine, width);
            std::cout << std::endl;

        } else {
            std::cout << "tree is empty" << std::endl;
        }
    }
    ~BST() { destroy(root_); }
};

template <class T> class Queue {
    T *theQueue_;
    int capacity_;
    int used_;
    int front_;
    int back_;
    void grow() {
        T *tmp = new T[capacity_ * 2];
        int j;
        for (int i = 0, j = front_; i < used_; i++, j = (j + 1) % capacity_) {
            tmp[i] = theQueue_[j];
        }
        delete[] theQueue_;
        theQueue_ = tmp;
        capacity_ = capacity_ * 2;
        front_ = 0;
        back_ = used_;
    }

  public:
    Queue() {
        theQueue_ = new T[50];
        capacity_ = 50;
        used_ = 0;
        front_ = 0;
        back_ = 0;
    }
    void enqueue(const T &data) {
        if (used_ == capacity_) {
            grow();
        }
        theQueue_[back_] = data;
        back_ = (back_ + 1) % capacity_;
        used_++;
    }
    void dequeue() {
        if (!isEmpty()) {
            used_--;
            front_ = (front_ + 1) % capacity_;
        }
    }
    T front() const {
        if (!isEmpty()) {
            return theQueue_[front_];
        }
        return T{};
    }
    bool isEmpty() const { return used_ == 0; }
    ~Queue() { delete[] theQueue_; }
};

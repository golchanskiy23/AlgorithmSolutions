#ifndef LIST_H
#define LIST_H
#include <stdexcept>

template<class T>
class List {
    public:
        struct ListNode {
            T value;
            ListNode* next;
            ListNode(T v) : value(v) , next(nullptr){}
            ListNode(T v, ListNode* n) : value(v) , next(n){}
        };

        List() : size(0), root(nullptr) {}

        ~List() {
            ListNode* curr = root;
            while (curr != nullptr) {
                ListNode* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
        }

        // добавление элемента
        void add(const T& value) {
            if (size == 0) {
                root = new ListNode(value);
            }
            else {
                ListNode* curr = root;
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                auto newNode = new ListNode(value);
                curr->next = newNode;
            }
            ++size;
        }

        // добавление по индексу
        void add(const T& value, int idx) {
            if (idx >= size) {
                std::cout << "Impossible!" << '\n';
                return;
            }
            if (idx == 0) {
                auto newRoot = new ListNode(value, root);
                root = newRoot;
            }
            else {
                int idx_ = 0;
                ListNode* prevNode = nullptr;
                auto currNode = root;
                while (idx_ != idx) {
                    ++idx_;
                    prevNode = currNode;
                    currNode = currNode->next;
                }
                auto newRoot = new ListNode(value);
                prevNode->next = newRoot;
                newRoot->next = currNode;
            }
            ++size;
        }
        // удаление элемента
        void erase(const T& value) {
            if (find(value) == nullptr || root == nullptr) return;
            if (size == 1) {
                --size;
                auto tmp = root;
                root = root->next;
                delete tmp;
                return;
            }
            ListNode* prevNode = nullptr;
            auto currNode = root;
            while (currNode != nullptr) {
                if (currNode->value == value) break;
                prevNode = currNode;
                currNode = currNode->next;
            }
           auto prevNextNode = currNode->next;
            prevNode->next = prevNextNode;
            --size;
        }

        void print() {
            if (root == nullptr) return;
            ListNode* curr = root;
            std::cout << curr->value << " ";
            while (curr->next != nullptr) {
                curr = curr->next;
                std::cout << curr->value << " ";
            }
        }

        ListNode* find(const T& value) {
            if (root == nullptr) return nullptr;
            ListNode* curr = root;
            while (curr != nullptr && curr->value != value) {
                curr = curr->next;
            }
            if (curr != nullptr && *curr == value) {
                return curr;
            }
            return nullptr;
        }

        void addFront(const T& value) {
            root = new ListNode(value, root);
            ++size;
        }

        void removeFront() {
            if (root == nullptr) return;
            ListNode* temp = root;
            root = root->next;
            delete temp;
            --size;
        }

        T front() const {
            if (root == nullptr) throw std::out_of_range("List is empty");
            return root->value;
        }

        bool empty() const { return size == 0; }

        size_t size_() const { return size; }

    private:
        size_t size;
        ListNode* root;
};

#endif //LIST_H

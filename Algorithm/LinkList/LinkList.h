//
// Created by ahoj hanoi on 2019-09-24.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H

namespace ahoj {
    template<class T>
    class SigList {
    public:
        SigList() {
            _head = new _node();
        }

        void pushFront(const T& v) {
            auto *new_node = new _node(v);
            new_node->next = _head->next;
            _head->next = new_node;
        }

        void pushBack(const T& v) {
            auto *new_node = new _node(v);
            _node *cur_node = _head;
            while (nullptr != cur_node->next) {
                cur_node = cur_node->next;
            }
            cur_node->next = new_node;
        }

        ~SigList() {
            _node *cur_node = _head;
            _node *next_node = _head;
            while (nullptr != cur_node) {
                next_node = cur_node->next;
                delete cur_node;
                cur_node = next_node;
            }
        }

    private:
        class _node {
        public:
            explicit _node(T v = T()) {
                val = v;
                next = nullptr;
            }

        public:
            T val;
            _node *next;
        };

        _node *_head;
    };
}

#endif //LINKLIST_LINKLIST_H

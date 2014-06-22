#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "rationalnumber.h"
#include "keyvaluenode.h"
//using namespace std;
namespace rn{
template <class KeyT,class T>
class Map{

public:
    class Iterator{
    public:
        internal::KeyValueNode<KeyT,T>* m_node;

        Iterator(internal::KeyValueNode<KeyT,T>* node):m_node(0){
            m_node = node;
        }

        void operator =(const Iterator &rhs){
            m_node = rhs;
        }

        bool operator!=(const Iterator &rhs) {
            return !(*this == rhs);
        }

        bool operator==(const Iterator &rhs) {
            return m_node  == rhs.m_node;
        }

        std::pair<KeyT,T>& operator*(){
            return this->m_node->value_t;
        }

        std::pair<KeyT,T>* operator->(){
            return &this->m_node->value_t;
        }

        Iterator operator++(){
            Iterator tmp = *this;
            m_node = m_node->findNext();
            return tmp;
        }

        Iterator operator++(int){
            Iterator tmp = *this;
            m_node = m_node->findNext();
            return tmp;
        }
    };

    internal::KeyValueNode<KeyT,T>* m_root;
    typedef KeyT key_type;
    typedef T mapped_type;
    typedef Iterator iterator;
    typedef std::pair<key_type,mapped_type> value_t;

    Map():m_root(0){}
    ~Map(){
        if(m_root)
            delete m_root;
    }
    Map(const Map<KeyT,T>& rhs):m_root(0){
        *this = rhs;
    }

    bool contains(const key_type& rhs){
        if(m_root == 0)
            return false;

        if((m_root->find(rhs)) != NULL ){
            cout << "Found" << endl;
            return true;
        }
        return false;
    }

    rn::Map<key_type,mapped_type>& operator=(const Map<key_type,mapped_type>& rhs){
        if(m_root){
            delete m_root;
        }
        m_root = rhs.m_root->clone();
        return *this;
    }

    mapped_type& operator[](const key_type& k){
        if(m_root == 0){
            m_root = new rn::internal::KeyValueNode<KeyT,T>(k);
        }
        if(m_root->find(k) == 0){
            return (m_root->insert(k,m_root->value_t.second)).value_t.second;
        }
        else{
            return (m_root->insert(k,m_root->find(k)->value_t.second)).value_t.second;
        }
    }

    const mapped_type operator[](const key_type k)const{
        return  (m_root->find(k).value_t.second);
    }

    iterator begin(){
        return Iterator(m_root->findSmallest());
    }
};
}


#endif // MAP_H

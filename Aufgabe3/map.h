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
        internal::KeyValueNode<const KeyT,T>* m_node;

        Iterator(internal::KeyValueNode<KeyT,T>* node):m_node(0){
            m_node = node;
        }

        void operator =(const Iterator &rhs){
            m_node = rhs.m_node;
        }

        bool operator!=(const Iterator &rhs) {
            return !(*this == rhs);
        }

        bool operator==(const Iterator &rhs) {
            return m_node  == rhs.m_node;
        }

        std::pair<KeyT,T>& operator*(){
            return m_node->value_t;
        }

        std::pair<KeyT,T>* operator->(){
            return &m_node->value_t;
        }

        Iterator operator++(){

            m_node = m_node->findNext();
            return *this;
        }

        Iterator operator++(int){
            Iterator tmp = *this;
            m_node = m_node->findNext();
            return tmp;
        }
    };

    internal::KeyValueNode<KeyT,T>* m_root;
    typedef KeyT const key_type;
    typedef T mapped_type;
    typedef Iterator iterator;
    typedef std::pair<const key_type,mapped_type> value_t;

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

        if((m_root->find(rhs)) != 0 ){
            return true;
        }
        return false;
    }


   //template <typename key_type,typename mapped_type>
   rn::Map<key_type, mapped_type>& operator=(const  Map<key_type, mapped_type>& rhs){
        cout << "Cloning"<<endl;

        if(m_root){
            delete m_root;
        }
        if (rhs.m_root)
            this->m_root = rhs.m_root->clone();
        return *this;
    }

    mapped_type& operator[](const key_type& k){
        if(m_root == 0){
            m_root = new rn::internal::KeyValueNode<KeyT,T>(k);
        }

        if(m_root->find(k) == 0){
            (m_root->insert(k,*(new mapped_type())));
        }


        return m_root->find(k)->value_t.second;
    }


    iterator begin(){
        return Iterator(m_root->findSmallest());
    }
    iterator end(){
        return Iterator(m_root->findBiggest());
    }
};
}


#endif // MAP_H

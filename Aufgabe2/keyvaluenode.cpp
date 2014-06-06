#include <iostream>
#include "keyvaluenode.h"


using namespace rn::internal;
using namespace std;


KeyValueNode& KeyValueNode::find(const key_type& key){
    cout << "Trying to find: " << key.num() <<"/"<<key.denom() << endl;

    if(this == 0){
        cout<< "Empty"<< endl;

        return *insert(key,0);
    }
    if(key == m_key){
        cout << "Found " << key.num() <<"/"<<key.denom() << endl;
        return *this;
    }

    else if(lTree == 0){
    cout << "ElseIf" << endl;
        return KeyValueNode(key);
    }

    else if(key < m_key){
        cout <<" else if smaller" << endl;
        lTree->find(key);
    }
    else{
        cout << "else"<< endl;
        rTree->find(key);
    }

}

KeyValueNode* KeyValueNode::clone(){

    KeyValueNode* clonedNode = new KeyValueNode(m_key,m_mapped);
    if(rTree != 0)
        rTree->clone();
    if(lTree != 0)
        lTree->clone();

    return clonedNode;
}
KeyValueNode* KeyValueNode::insert(const key_type& key,const mapped_type& mapped){

    if(this == 0){
        //this = new KeyValueNode(key,mapped);
      // this->m_key = key;

      // this->m_mapped = mapped;
    return this;
   }
    else if(key == m_key){
        m_mapped = mapped;
        return this;
    }
    else if(key < m_key){
        if(lTree == 0)
            lTree = new KeyValueNode(key,mapped);
        else
            lTree->insert(key,mapped);
    }
    else{

        if(rTree == 0)
            rTree = new KeyValueNode(key,mapped);
        else
            rTree->insert(key,mapped);
    }
}

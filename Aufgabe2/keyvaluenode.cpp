#include <iostream>
#include "keyvaluenode.h"


using namespace rn::internal;
using namespace std;


KeyValueNode& KeyValueNode::find(const key_type& key){
cout<< "Find" << key.num() << "/"<< key.denom() <<endl;
    if(this == 0){
        cout<< "Empty Tree inserting" <<endl;
        return *insert(key,0);
    }
    if(key == m_key){
    cout<< "Found " << key.num() << "/"<< key.denom() <<endl;
        return *this;
    }

    else if(key < m_key){
    cout << "smaller" << endl;
        if(lTree == 0)
           return *this->insert(key,0);
        lTree->find(key);
    }
    else{
        cout << "bigger"<< endl;
        if(rTree == 0)
           return *this->insert(key,0);

        rTree->find(key);
    }

}

KeyValueNode* KeyValueNode::clone(){

    KeyValueNode* clonedNode = new KeyValueNode(m_key,m_mapped);
    if(rTree != 0){
        clonedNode->rTree = rTree;
        rTree->clone();

    }
    if(lTree != 0){
        clonedNode->lTree = lTree;
        lTree->clone();
}
    return clonedNode;
}
KeyValueNode* KeyValueNode::insert(const key_type& key,const mapped_type& mapped){
    if(key == 0){
        return this;
    }

    if(key == m_key){
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

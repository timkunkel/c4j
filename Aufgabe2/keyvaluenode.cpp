#include <iostream>
#include "keyvaluenode.h"


using namespace rn::internal;
using namespace std;


KeyValueNode* KeyValueNode::find(const key_type& key){
    cout << "Trying to find: " << key.num() <<"/"<<key.denom() <<
    "got: " << m_key. num() <<"/"<<m_key.denom() << endl;
    if(key == m_key){
        cout << "Found " << key.num() <<"/"<<key.denom() << endl;
        return this;
    }
    else if(lTree == 0){

        return 0;
    }

    else if(key < m_key){
        lTree->find(key);
    }
    else{
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

void KeyValueNode::insert(const key_type& key,const mapped_type& mapped){
    if(key.equals(m_key)){
        m_mapped = mapped;
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

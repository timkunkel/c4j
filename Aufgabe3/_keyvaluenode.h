//#include <iostream>
//#include "keyvaluenode.h"


//using namespace rn::internal;
//using namespace std;

//template <class KeyT,class T>
typename KeyValueNode<KeyT,T>* find(const key_type& key){
    //cout<< "Find" << key.num() << "/"<< key.denom() <<endl;
        if(this == 0){
            cout<< "Empty Tree inserting" <<endl;
            return 0;
        }
        if(key == m_key){
     //   cout<< "Found " << key.num() << "/"<< key.denom() <<endl;
            return this;
        }

        else if(key < m_key){
        cout << "smaller" << endl;
            if(lTree == 0)
               return 0;
            lTree->find(key);
        }
        else{
            cout << "bigger"<< endl;
            if(rTree == 0){
            cout << "NotNull" << endl;
               return 0;
            }

            rTree->find(key);
        }

}
//template <class KeyT,class T>
typename KeyValueNode<KeyT,T>* clone(){

    KeyValueNode* clonedNode = new KeyValueNode(m_key,m_mapped);



    if(rTree != 0){
        clonedNode->rTree = rTree->clone();


    }
    if(lTree != 0){
        clonedNode->lTree = lTree->clone();

}
    return clonedNode;
}
//template <class KeyT,class T>
typename KeyValueNode<KeyT,T>& insert(const key_type& key,const mapped_type& mapped){
    if(key == 0){
        return *this;
    }

    if(key == m_key){
        m_mapped = mapped;
        return *this;
    }

    else if(key < m_key){

        if(lTree == 0){
            lTree = new KeyValueNode(key);
            lTree->m_mapped = mapped;
        }
        else
            lTree->insert(key,mapped);
    }
    else{

        if(rTree == 0){
            rTree = new KeyValueNode(key);
            rTree->m_mapped = mapped;
         }
        else
            rTree->insert(key,mapped);
    }
}

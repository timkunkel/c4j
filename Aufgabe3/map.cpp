//#include "map.h"
//#include<iostream>
//using namespace std;

//namespace rn {
//template<class KeyT,class T>
//bool Map<KeyT,T>::contains(const key_type& rhs)const{
//     cout << "Trying to find " << rhs.num() <<"/"<< rhs.denom()<<endl;
//     if((m_root->find(rhs).mapped()) != 0 ){
//       return true;
//}
//    return false;

//}

//template<class KeyT,class T>
//typename Map<KeyT,T>& Map<KeyT,T>::operator=(const typename Map<KeyT,T>& rhs){
//    if(m_root)
//    {
//        delete m_root;
//    }
//    cout << "Cloning"<< endl;
//    m_root = rhs.m_root->clone();
//    return *this;
//}


//template<class KeyT,class T>
//typename Map<KeyT,T>::mapped_type& Map<KeyT,T>::operator[](const key_type k){
//   if(m_root == 0){
//       m_root = new rn::internal::KeyValueNode<KeyT,T>(k);
//       m_root->lTree = 0;
//       m_root->rTree = 0;
//   }

//        return (m_root->find(k)).m_mapped;

//}

//template<class KeyT,class T>
//const typename Map<KeyT,T>::mapped_type Map<KeyT,T>::operator[](const key_type k)const{
//        cout << "Trying to find " << k.num()<<endl;
//         return (m_root->find(k).mapped());

//}

//}

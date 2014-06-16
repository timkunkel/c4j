//template<class KeyT,class T>
bool contains(const typename KeyT& rhs)const{
     //cout << "Trying to find " << rhs.num() <<"/"<< rhs.denom()<<endl;
     if(m_root == 0)
         return false;

     if((m_root->find(rhs)) != NULL ){
         cout << "Found" << endl;
       return true;
}
    return false;

}

//template<class KeyT,class T>
typename Map<KeyT,T>& operator=(const typename Map<KeyT,T>& rhs){
    if(m_root)
    {
        delete m_root;
    }
    cout << "Cloning"<< endl;
    m_root = rhs.m_root->clone();
    return *this;
}


//template<class KeyT,class T>
T& operator[](const typename KeyT& k){
   // cout << "Adding" << endl;


    if(m_root == 0){
        cout << "Adding" << endl;
        m_root = new rn::internal::KeyValueNode<KeyT,T>(k);
        cout << "Created new root nodel" <<endl;


    }

     if(m_root->find(k) == 0){

         return (m_root->insert(k,m_root->mapped())).m_mapped;

     }
     else{
         return (m_root->insert(k,m_root->find(k)->mapped())).m_mapped;
}
 }

//template<class KeyT,class T>
const T operator[](const typename KeyT k)const{
        //cout << "Trying to find " << k.num()<<endl;

         return (T) (m_root->find(k).mapped());

}





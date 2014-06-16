template <class key_type,class mapped_type>
bool contains(const key_type& rhs)const{
     //cout << "Trying to find " << rhs.num() <<"/"<< rhs.denom()<<endl;
     if(m_root == 0)
         return false;

     if((m_root->find(rhs)) != NULL ){
         cout << "Found" << endl;
       return true;
}
    return false;

}

template <class key_type,class mapped_type>
rn::Map<key_type,mapped_type>& operator=(const Map<key_type,mapped_type>& rhs){
    if(m_root)
    {
        delete m_root;
    }
    cout << "Cloning"<< endl;
    m_root = rhs.m_root->clone();
    return *this;
}


template <class key_type,class mapped_type>
mapped_type& operator[](const key_type& k){
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

template <class key_type,class mapped_type>
const mapped_type operator[](const key_type k)const{
        //cout << "Trying to find " << k.num()<<endl;

         return  (m_root->find(k).mapped());

}





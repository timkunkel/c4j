/*
 *
 * C / C++ für Java-Programmierer
 * Einfacher Test-Treiber für class RationalNumber
 * Autor: Hartmut Schirmacher
 *
 */

#include "assert.h"
#include "map.h"
#include <string>
#include "rationalnumber.h"

using namespace std;
using namespace rn;

void output(rn::internal::KeyValueNode<const float,string>* node){
    if(node != 0){
        cout << "\nNode:" <<node->key()<< " = "<< node->mapped()  << endl;
        if(node->lTree != 0){
            cout << "Left:" <<node->lTree->key()<< " = "<< node->lTree ->mapped()  << endl;
            if(node->rTree == 0)
                cout<<""<< endl;
        }
        if(node->rTree != 0){
            cout << "Right:" <<node->rTree->key()<< " = "<< node->rTree ->mapped() << endl;
        }
        if(node->lTree != 0)
            output(node->lTree);
        if(node->rTree != 0){
            output(node->rTree);
        }
    }
}

void doMapTests(){

    rn::RationalNumber a(1,1);
    RationalNumber b(2,3);
    RationalNumber c(1,4);
    RationalNumber d(5,1);
    string s = "eins";

    cout << "Starting tests" << endl;
    Map<const float,std::string> map;
    Map<const RationalNumber,int> mapRN;

    //Try to find RationalNumber a
    assert(!mapRN.contains(a));
    mapRN[a] = 2;
    assert(mapRN.contains(a));
    mapRN[b] = 5;
    mapRN[c] = 3;

    cout << mapRN.m_root->find(a)->value_t.first.num() << "/" << mapRN.m_root->find(a)->value_t.first.denom()
         << ": " << mapRN.m_root->find(a)->value_t.second << endl;

    //  cout << mapRN[a] << endl;
    //Copy Map
    Map<const RationalNumber,int> mapRN2 = mapRN;
    cout << mapRN2.m_root->value_t.first.num() << "/" << mapRN2.m_root->value_t.first.denom()
         << ": " << mapRN2.m_root->value_t.second << endl;

    cout<<"Address RootNode of mapRN: "<< mapRN.m_root <<endl;
    cout<<"Address RootNode of cloned Map mapRN2: "<< mapRN2.m_root << endl;

    mapRN[d] = 5;
    assert(mapRN.contains(d));
    assert(!mapRN2.contains(d));
    cout << "Passed map copy tests" << endl;

    map[15.0f] = "Fünfzehn";
    map[6.0f] = "Sechs";
    map[16.0f] = "Sechszehn";
    map[4.0f] = "Vier";
    map[7.0f] = "Sieben";
    map[6.5f] = "Sechs komma Fünf";
    map[8.0f] = "Acht";
    map[5.0f] = "Fünf";
    map[3.0f] = "Drei";
    map[3.2f] = "Drei komma Zwei";
    map[3.1f] = "Drei komma Eins";
    map[17.f] = "Siebzehn";

    string mappedString = map[4.0f];
    cout << "\nString at map 4.0f: " << mappedString << endl;

    Map<const float,string>::Iterator iter = map.begin();
    Map<const float,string>::Iterator iter2 = map.begin();

    cout << "\nIterator post increment test" << endl;
    iter = map.begin();
    while(iter != map.end()){
        cout << iter->first <<": "<< iter->second <<endl;
        iter++;
    }

    cout << "\nIterator pre increment test" << endl;
    iter = map.begin();
    while(iter != map.end()){
        cout << iter->first <<": "<< iter->second <<endl;
        ++iter;
    }

    iter = map.begin();
    iter2 = map.begin();
    assert(iter == iter2);
    assert(iter++ != ++iter2);
    assert(iter == iter2);
    assert(iter == iter2++);
    assert(++iter == iter2);
    iter2 = map.end();
    assert(iter2 != iter);
    cout << "Passed iterator test" << endl;

    //map.begin()->first = 15.0f;
    output(map.m_root);
}

void doUnitTests_RationalNumber() {    
    cout << "Starting unit tests for class RationalNumber..." << endl;
    {
        // test default constructor, isValid(), and accessor num()
        cout << "- default constructor..." << flush;
        RationalNumber a;
        assert(a.isValid());
        assert(a.num() == 0);
        cout << " passed." << endl;
    }
    {
        // test non-default constructors and both accessors num() and denom()
        cout << "- more constructors..." << flush;
        RationalNumber a(1,2);
        //a[3] = 1;
        assert(a.isValid());
        assert(a.num() == 1);
        assert(a.denom() == 2);

        // constructors with single argument: equivalent to integer
        RationalNumber b(0);
        assert(b.isValid());
        assert(b.num() == 0 && b.denom() == 1);

        RationalNumber c(7);
        assert(c.isValid());
        assert(c.num() == 7 && c.denom() == 1);

        cout << " passed." << endl;
    }
    {
        // test const RationalNumber objects, operator==(), normalization, and inverse()
        cout << "- const..." << flush;
        const RationalNumber a(6,4), b(3,2);
        assert(a.isValid());
        assert(b.isValid());
        assert(a == b);
        assert(a.inverse() == RationalNumber(2,3));

        cout << " passed." << endl;
    }
    {
        // addition and unary minus
        cout << "- operator+()..." << flush;
        const RationalNumber a(3,2), b(4,3), c(3*3+4*2,2*3);
        assert(a + b == c);
        assert(a + (-a) == RationalNumber(0));

        cout << " passed." << endl;
    }
    {
        // order
        cout << "- ordered sequence..." << flush;
        const RationalNumber a(2,3), b(3,4), c(-4,5);
        assert(a < b);
        assert(c < a);
        assert(c < b);
        assert(!(a < c));
        cout << " passed." << endl;
    }
    cout << "Unit tests for class RationalNumber finished!" << endl;
}

int main()
{
    doMapTests();
    //  doUnitTests_RationalNumber();
    //  doUnitTests_RationalNumber();
    return 0;
}

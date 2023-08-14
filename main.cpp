#include "myVector.hpp"

int main() {
    myVector<int> v,v1;
    std::cout<<v.empty()<<std::endl;
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    v.insert(44,0);
    v.insert(55,4);
    std::cout<<v.size()<<std::endl;
    std::cout<<v[4]<<std::endl;
    v1 = v;
    std::cout<<v1.size()<<std::endl;
    std::cout<<v1[4]<<std::endl;
    std::cout<<(v1==v)<<std::endl;
    myVector<int> v2(v);
    v2.erase(3);
    std::cout<<v2.find(11)<<std::endl;
    std::cout<<v2.size()<<std::endl;
    return 0;
}

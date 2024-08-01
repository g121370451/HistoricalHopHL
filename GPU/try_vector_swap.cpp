#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <iterator>  
  
using namespace std;  
  
int main ()   
{  
    int x = 10;  
    vector<int> myvector(10000, x);    
    myvector.resize(10008);
    //这里打印仅仅是元素的个数不是内存大小  
    cout << "myvector size:"
         << myvector.capacity()
         << endl
         << myvector.size()  
         << endl;  
  
    //swap交换函数释放内存：vector<T>().swap(X);  
    //T:int ; myvertor代表X  
    vector<int>(myvector).swap(myvector);  
  
    //两个输出仅用来表示swap前后的变化  
    cout << "after swap :" 
         << myvector.capacity() 
         << endl
         << myvector.size()  
         << endl;  
  
    return 0;  
}
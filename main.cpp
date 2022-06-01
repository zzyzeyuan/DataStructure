#include "Stack.h"
using namespace std;

int main(){
    MyStack S;
    int size = LONGTH;
    int increment = LONGTH;
    ElemType testArray[LONGTH] = { 1,2,3,4,5};
    ElemType testArray2[2 * LONGTH] = {11,22,33,44,55,66,77,88,99,1010};
    //测试初始化
    S.initializeStack(size,increment);
//    S.getElemAddress();
    //测试入栈
    for(auto e : testArray){
        S.Push(e);
    }
    cout << "The top elem of stack:" << S.getTopElem() << endl;

    //test Pop()
//    S.Pop();
//    cout << "The top elem of stack:" << S.getTopElem() << endl;

    //test Clear()
    S.Clear();
//    S.getElemAddress();
    cout << "The top elem of stack:" << S.getTopElem() << endl;
    S.isEmpty();

    for(auto e : testArray2){
        S.Push(e);
        cout << "The top elem of stack:" << S.getTopElem() << endl;
    }
//    S.getElemAddress();

    S.deleteStack();
    return 0;
}

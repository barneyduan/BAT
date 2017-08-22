#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> p(1, 1);
   int life, N;
   cin>>life>>N;
   int cur_f = 1, cur_t = 0;
   for (int i = 1; i <= N; i++) {
     if (i - life < 0) { //如果 i < life, 表示还没有第一对兔子死亡
      cur_t = 0;
   } else {
    cur_t = p[i - life];
    p[i - life] = 0;
   }
   if (i < 2) { //2年内，还没有第一对兔子出生
    p.push_back(0);
   } else { 
    int p_ = cur_f - p[i - 1] - cur_t;
    p.push_back(p_);
   }
   cur_f = cur_f + p[i] - cur_t;
  if (cur_f  > 10) {   //考虑总数大于10之后的情况
    int count = i - life + 1;
    int byGrab = 2;
    for (int k = count; k <= i; k++) { 
      if (p[k] >= 2) { //不断去寻找最年长的两对兔子，不断更新p数组
        p[k] = p[k] - 2;
        break;
      } else if (p[k] > 0) {
        p[k]--;
        byGrab--;
      }
      if (!byGrab) {
        break;
      }
    }
    cur_f -= 2;
  }
   }
   int total = 0;
   //兔子出生了，即为1岁
   for (int i = 0; i < p.size(); i++) {
    cout<<"第"<<N<<"年之后,"<<N - i<<"岁兔子的数量:"<<p[i] * 2<<endl;
    total += p[i] * (N - i);
   }
   cout<<total * 2<<endl; //最终结果是求只数，只要乘以2就行了
   return 0;
}
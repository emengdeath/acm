#include<cstdio>
#include<cstring>
#define limit 200000000
int prime[limit+1];
bool ok[limit+1];
void shax(int prime[])
{
    int i,j;
    for(i=2;i<=limit;i++)
    {
        if(!ok[i]) //不是质数
            prime[++prime[0]]=i;//添加到质数表中
        for(j=1;j<=prime[0]&&prime[j]*i<=limit;j++)
        {
            ok[prime[j]*i]=true;//确定prime[j]*i肯定是合数
            if(i%prime[j]==0)//跳出,不重复删除
                break;
        }
    }
}
int main()
{
    bool flag(false);
    int cnt(0);
    shax(prime);
    for(int i = 0;i<200000001;++i){
         if(flag) break;
         if(prime[i]>100000000 && prime[i]<200000001)
              cnt++;
         else if(prime[i]>200000000)
              flag = true;
    }
    printf("%d\n",cnt);
    return 0;
}

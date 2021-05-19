#include <stdio.h>
#include <stdlib.h>

void bin_search(int n,int k,int a[],long int l,long int r){
    if((l+r)/2==l){
        printf("%ld\n",r);
        return;
    }
    long int i,j,flag,check=(l+r)/2,t=0;
    flag=check;
    for(i=0;i<n;i++){
        if(a[i]>check){
            t=k+1;
            break;
        }
        flag-=a[i];
        if(flag<0){
            t++;i--;flag=check;
        }
    }
    if(t+1<=k)
        bin_search(n,k,a,l,check);
    else
        bin_search(n,k,a,check,r);
}

int main() {
    int q;
    scanf("%d",&q);
    
    while(q--)
    {
        int n,k,i,j;
        long int sum=0;
        scanf("%d %d",&n,&k);
        
        int a[n];
        
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        bin_search(n,k,a,0,sum);
    }
    return 0;
}
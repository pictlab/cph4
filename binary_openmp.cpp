#include<iostream>
#include <omp.h>
using namespace std;
 
int main()
{
    int search(int [],int,int);
    int n,i,a[100],e,res;
    cout<<"How Many Elements:";
    cin>>n;
    cout<<"\nEnter Elements of Array in Ascending order\n";
   
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
   
    cout<<"\nEnter element to search:";
    cin>>e;
double start,end;


start=omp_get_wtime();

#pragma omp parallel
    res=search(a,n,e);
   
end=omp_get_wtime();



    if(res!=-1)
        cout<<"\nElement found at position "<<res+1;
    else
        cout<<"\nElement is not found....!!!";

cout<<"\ntime = "<<time;
 
    return 0;
}
 
int search(int a[],int n,int e)
{
    int f,l,m;
    f=0;
    l=n-1;
   
    while(f<=l)
    {
        m=(f+l)/2;
        if(e==a[m])
            return(m);
        else
            if(e>a[m])
                f=m+1;
            else
                l=m-1;
    }
   
    return -1;
}
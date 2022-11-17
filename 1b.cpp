#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}

void knapsack(int p[],int w[],int n,int k_capacity)
{
    int i,j,total_profit;
    int a[n+1][k_capacity+1];     
    for(i=0;i<=n;i++)             
    {
        for(j=0;j<=k_capacity;j++)
        {
            if(i==0 || j==0)
            {
                a[i][j]=0;        
            }
            else if(w[i-1]<=j)    
            {
                a[i][j]=max(a[i-1][j],(a[i-1][j-w[i-1]]+p[i-1]));
            }
            else                  
            {
                a[i][j]=a[i-1][j];
            }
        }
    }
    
    int profit=a[n][k_capacity];
    cout<<"Total profit: "<<profit<<endl;

    cout<<"Matrix generated for Dynamic Programming: "<<endl;
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=k_capacity;j++)
    	{
    		cout<<a[i][j]<<"\t";
		}
        cout<<endl;
	} 
	cout<<endl;


    for(i=n;i>0 && profit>0;i--)
    {
        if(profit==a[i-1][j])
        {
            cout<<"This item is not included "<<i<<" ->0"<<endl;
        }
        else
        {
            cout<<"This item is included"<<i<<" ->1"<<endl;
            
            profit=profit-p[i-1];
            w=w-w[i-1];
        }
    }
}


int main()
{
    int n,k_capacity;
    cout<<"Enter the number of objects: "<<endl;
    cin>>n;
    cout<<"Enter the capacity: "<<endl;
    cin>>k_capacity;
    
    int w[n];    
    int p[n];    
    
    cout<<"Enter the weights: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];    
    }
    
    cout<<"Enter the profit: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];    
    }
    
    knapsack(p,w,n,k_capacity);   
    return 0;
}

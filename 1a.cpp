#include <bits/stdc++.h>

using namespace std;

typedef struct object
{
    int profit;
    int weight;
    
    object(int profit, int weight)
    {
        this -> profit = profit;
        this -> weight = weight;
    }
}obj;

int cmp1(obj a, obj b)
{
    int temp1,temp2;
    temp1 = a.profit;
    temp2 = b.profit;
    return temp1>temp2;
}
int cmp2(obj a, obj b)
{
    int temp1,temp2;
    temp1 = a.weight;
    temp2 = b.weight;
    return temp1<temp2;
}
int cmp3(obj a, obj b)
{
    float temp1,temp2;
    temp1 =(float)a.profit/a.weight;
    temp2 =(float)b.profit/b.weight;
    return temp1>temp2;
}

float ks1(obj a[],int k_capacity, int n)
{
    int curr_weight=0;
    float total_profit = 0.0;
    int r_capacity;
    
    sort(a,a+n,cmp1);
    
    for(int i=0;i<n;i++)
    {
        if(curr_weight+a[i].weight<=k_capacity)
        {
            curr_weight = curr_weight + a[i].weight;
            total_profit = total_profit + a[i].profit;
        }
        
        else
        {
            r_capacity = k_capacity - curr_weight;
            total_profit = total_profit+(float)(r_capacity*a[i].profit)/a[i].weight;
            break;
        }
    }
    return total_profit;
}

float ks2(obj a[],int k_capacity, int n)
{
    int curr_weight=0;
    float total_profit = 0.0;
    int r_capacity;
    
    sort(a,a+n,cmp2);
    
    for(int i=0;i<n;i++)
    {
        if(curr_weight+a[i].weight<=k_capacity)
        {
            curr_weight = curr_weight + a[i].weight;
            total_profit = total_profit + a[i].profit;
        }
        
        else
        {
            r_capacity = k_capacity - curr_weight;
            total_profit = total_profit+(float)(r_capacity*a[i].profit)/a[i].weight;
            break;
        }
    }
    return total_profit;
}

float ks3(obj a[],int k_capacity, int n)
{
    int curr_weight=0;
    float total_profit = 0.0;
    float r_capacity;
    
    sort(a,a+n,cmp3);
    
    for(int i=0;i<n;i++)
    {
        if(curr_weight+a[i].weight<=k_capacity)
        {
            curr_weight = curr_weight + a[i].weight;
            total_profit = total_profit + a[i].profit;
        }
        
        else
        {
            r_capacity = k_capacity - curr_weight;
            total_profit = total_profit+(float)(r_capacity*a[i].profit)/a[i].weight;
            break;
        }
    }
    return total_profit;
}

int main()
{
    int k_capacity = 20;
    obj a[] = {{25,18},{24,15},{15,10}};
    int size = sizeof(a)/sizeof(a[0]);
    
    std::cout << "Case I" << std::endl;
    std::cout << ks1(a,k_capacity,size) << std::endl;
    std::cout << "Case II" << std::endl;
    std::cout << ks2(a,k_capacity,size) << std::endl;
    std::cout << "Case III" << std::endl;
    std::cout << ks3(a,k_capacity,size) << std::endl;
}

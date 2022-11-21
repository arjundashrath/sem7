#include <bits/stdc++.h>
using namespace std;



struct Item{
    int value;
    int weight;
};

bool comparator(Item a, Item b){
    return float(a.value/a.weight)>float(b.value/b.weight);
}

void fractionalKnapsack(Item arr[], int W, int n){
    
    sort(arr, arr+n, comparator);
    int i = 0;
    int sum = 0;
    while(W>0){
        if(i>=n){
            break;
        }
        
        if(arr[i].weight<=W){
            sum += arr[i].value;
            W -= arr[i].weight;
            i++;
        }else{
            sum += W*float(arr[i].value/arr[i].weight);
            break;
        }
    }
    cout<<sum;
}



int main() {
    
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    
    fractionalKnapsack(arr,W,3);

    return 0;
}

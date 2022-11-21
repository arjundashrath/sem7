/*{ 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } }*/
#include <bits/stdc++.h>
using namespace std;



struct Job{
    char name;
    int deadline;
    int profit;
};

bool comparator(Job a, Job b){
    return a.profit>b.profit;
}

void JobScheduling(Job arr[]){
    sort(arr, arr+5, comparator);
    
    // for(int i =0; i<5;i++){
    //     cout<<arr[i].profit<<endl;
    // }
    int slots[5];
    
    for(int i =0; i<5;i++){
        slots[i]=-1;
    }
    
    for(int i =0; i < 5; i++){
        for(int j = arr[i].deadline; j >=1; j--){
            if(slots[j] == -1){
                slots[j] = i;
                break;
            }
        }
    }
    
    for(int i =0; i<5;i++){
        if(slots[i]!= -1){
            cout<<" "<<arr[slots[i]].name;
            
        }
    }
}

int main() {
    // Write C++ code here
    
    Job arr[] ={{ 'a', 2, 100 },{ 'b', 1, 19 },{ 'c', 2, 27 },{ 'd', 1, 25 },{ 'e', 3, 15 } };
    
    JobScheduling(arr);

    return 0;
}

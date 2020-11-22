#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

struct node{
    char left;
    char right;
};

void first_cycle(node *data_store, char start){
    int check_num = start - 'A';
    cout << start;
    if(data_store[check_num].left != '.'){
        first_cycle(data_store, data_store[check_num].left);
    }
    if(data_store[check_num].right != '.'){
        first_cycle(data_store, data_store[check_num].right);
    }
}

void second_cycle(node *data_store, char start){
    int check_num = start - 'A';
    if(data_store[check_num].left != '.'){
        second_cycle(data_store, data_store[check_num].left);
    }
    cout << start;
    if(data_store[check_num].right != '.'){
        second_cycle(data_store, data_store[check_num].right);
    }
}

void third_cycle(node *data_store, char start){
    int check_num = start - 'A';
    if(data_store[check_num].left != '.'){
        third_cycle(data_store, data_store[check_num].left);
    }   
    if(data_store[check_num].right != '.'){
        third_cycle(data_store, data_store[check_num].right);
    }
    cout << start;
}


int main(void){
    int n;
    cin >> n;

    node data_store[n];
    for(int i = 0; i < n; i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        data_store[parent - 'A'].left  = left;
        data_store[parent - 'A'].right = right; 
    }// data_store

    // First cycle output

    first_cycle(data_store, 'A');
    cout << "\n"; // first cycle output end

    // Second cycle output

    second_cycle(data_store, 'A');
    cout << "\n";

    // Third cycle output
    third_cycle(data_store, 'A');

    return 0;
}
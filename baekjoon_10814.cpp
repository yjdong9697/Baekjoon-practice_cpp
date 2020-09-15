#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

typedef struct{
    int age;
    string name;
    int check;
} name_store;

bool compare(name_store x, name_store y){
    if (x.age == y.age) return x.check < y.check;
    
    else return x.age < y.age;  
} // struct sort define



int main(void){
    int n;
    cin >> n;
    vector <name_store> name_container;
    
    // Data store in to the vector container
    for(int i = 0; i < n; i++){
        name_store struct_temp;
        cin >> struct_temp.age >> struct_temp.name;
        struct_temp.check = i;
        name_container.push_back(struct_temp);
    }

    // Sorting data

    sort(name_container.begin(), name_container.end(), compare);

    for(int i = 0; i < n; i++){
        cout << name_container[i].age << " " << name_container[i].name << "\n"; 
    }

    return 0;
}
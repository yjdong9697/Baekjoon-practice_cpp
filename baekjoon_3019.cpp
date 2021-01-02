#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int c, p;
    cin >> c >> p;
    int data_store[c];
    for(int i = 0; i < c; i++){
        int temp;
        cin >> temp;
        data_store[i] = temp;
    }
    int result = 0;

    if(p == 1){
        int store = -1;
        int occurence_store = 1;
        for(int i = 0; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store - 3 > 0) result += occurence_store - 3;
                occurence_store = 1;
                store = data_store[i];
            }
        }
        if(occurence_store - 3 > 0) result += occurence_store - 3;
        result += c;
    }

    else if(p == 2){
        int store = -1;
        int occurence_store = 1;
        for(int i = 0; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store - 1 > 0) result += occurence_store - 1;
                occurence_store = 1;
                store = data_store[i];   
            }
        }
        if(occurence_store - 1 > 0) result += occurence_store - 1;
    }

    else if(p == 3){
        int store = data_store[0];
        int occurence_store = 0;
        for(int i = 0; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store >= 2){
                    if(data_store[i] == store + 1){
                        result += 1;
                    }
                }
                occurence_store = 1;
                store = data_store[i];
            }
        }

        store = data_store[0];
        occurence_store = 1;
        for(int i = 1; i < c; i++){
            if (data_store[i] == store - 1){
                result += 1;
                store = data_store[i];
            }
            else{
                store = data_store[i];
            }
        }
    }
    else if(p == 4){
        int store = data_store[0];
        int occurence_store = 1;
        int status_store = 0; // default
        for(int i = 1; i < c; i++){
            if (data_store[i] == store - 1){
                store = data_store[i];
                status_store = 1;
            }
            else if(data_store[i] == store && status_store == 1){
                result += 1;
                store = data_store[i];
                status_store = 0;
            }
            else{
                store = data_store[i];
                status_store = 0;
            }
        }

        store = data_store[0];
        occurence_store = 1;
        for(int i = 1; i < c; i++){
            if (data_store[i] == store + 1){
                result += 1;
                store = data_store[i];
            }
            else{
                store = data_store[i];
            }
        }
    }
    else if(p == 5){
        int store = data_store[0];
        int occurence_store = 1;
        int status_store = 0; // default
        for(int i = 1; i < c; i++){
            if (data_store[i] == store - 1){
                store = data_store[i];
                status_store = 1;
            }
            else if(data_store[i] == store + 1 && status_store == 1){
                result += 1;
                store = data_store[i];
                status_store = 0;
            }
            else{
                store = data_store[i];
                status_store = 0;
            }
        }

        store = data_store[0];
        occurence_store = 1;

        for(int i = 1; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store - 2 > 0) result += occurence_store - 2;
                occurence_store = 1;
                store = data_store[i];
            }
        }
        if(occurence_store - 2 > 0) result += occurence_store - 2;

        store = data_store[0];
        occurence_store = 1;
        for(int i = 1; i < c; i++){
            if (data_store[i] == store + 1 || data_store[i] == store - 1){
                store = data_store[i];
                result += 1;
            }
            else{
                store = data_store[i];
            }
        }

    }

    else if(p == 6){
        int store = data_store[0];
        int occurence_store = 1;

        for(int i = 1; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store - 2 > 0) result += occurence_store - 2;
                occurence_store = 1;
                store = data_store[i];
            }
        }
        if(occurence_store - 2 > 0) result += occurence_store - 2;

        store = data_store[0];
        occurence_store = 1;
        int status_store = 0; // default
        for(int i = 1; i < c; i++){
            if (data_store[i] == store + 1){
                store = data_store[i];
                status_store = 1;
            }
            else if(data_store[i] == store && status_store == 1){
                result += 1;
                store = data_store[i];
                status_store = 0;
            }
            else{
                store = data_store[i];
                status_store = 0;
            }
        }

        store = data_store[0];
        occurence_store = 1;
        for(int i = 1; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store - 1 > 0) result += occurence_store - 1;
                occurence_store = 1;
                store = data_store[i];
            }
        }
        if(occurence_store - 1 > 0) result += occurence_store - 1;

        store = data_store[0];
        occurence_store = 1;
        for(int i = 1; i < c; i++){
            if (data_store[i] == store - 2){
                store = data_store[i];
                result += 1;
            }
            else{
                store = data_store[i];
            }
        }

        
    }

    else if(p == 7){
        int store = data_store[0];
        int occurence_store = 1;

        for(int i = 1; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store - 2 > 0) result += occurence_store - 2;
                occurence_store = 1;
                store = data_store[i];                
            }
        }
        if(occurence_store - 2 > 0) result += occurence_store - 2;

        store = data_store[0];
        occurence_store = 1;
        int status_store = 0; // default
        for(int i = 1; i < c; i++){
            if (data_store[i] == store){
                store = data_store[i];
                status_store = 1;
            }
            else if(data_store[i] == store - 1 && status_store == 1){
                result += 1;
                store = data_store[i];
                status_store = 0;
            }
            else{
                store = data_store[i];
                status_store = 0;
            }
        }

        store = data_store[0];
        occurence_store = 1;
        for(int i = 1; i < c; i++){
            if (data_store[i] == store){
                occurence_store += 1;
            }
            else{
                if(occurence_store - 1 > 0) result += occurence_store - 1;
                occurence_store = 1;
                store = data_store[i];
            }
        }
        if(occurence_store - 1 > 0) result += occurence_store - 1;

        store = data_store[0];
        occurence_store = 1;
        for(int i = 1; i < c; i++){
            if (data_store[i] == store + 2){
                store = data_store[i];
                result += 1;
            }
            else{
                store = data_store[i];
            }
        }
    }

    cout << result << "\n";
    return 0;
}
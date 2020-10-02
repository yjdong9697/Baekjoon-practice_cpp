#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;

    int y_pos, x_pos, direction;
    cin >> y_pos >> x_pos >> direction ; // Default setting

    int space_data_store[50][50];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            space_data_store[i][j] = temp;
        }
    } // storing space data;

    // Cleaning the space (0:not cleaning, 1:wall, 2:cleaned)

    int clean_count = 0;

    while(true){
        if(space_data_store[y_pos][x_pos] != 2){
            space_data_store[y_pos][x_pos] = 2; // cleaning current position
            clean_count += 1;
        }
        
        int temp_direction;
        if(direction == 0){
            temp_direction = 3;
            
        }
        else{
            temp_direction = direction - 1;
        }

        // north
        if(direction == 0){
            // not cleaning position
            if (x_pos - 1 >= 0){
                if(space_data_store[y_pos][x_pos - 1] == 0){
                    direction = temp_direction;
                    x_pos -= 1;
                    continue;
                }
            }
            if(x_pos + 1 < m){
                if(space_data_store[y_pos][x_pos + 1] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(y_pos - 1 >= 0){
                if(space_data_store[y_pos - 1][x_pos] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(y_pos + 1 < n){
                if(space_data_store[y_pos + 1][x_pos] == 0){
                    direction = temp_direction;
                    continue;
                }
                else if(space_data_store[y_pos + 1][x_pos] == 1){
                    break;
                }
                else if(space_data_store[y_pos + 1][x_pos] == 2){
                    y_pos += 1;
                }
            }
            
        }
        // east
        else if(direction == 1){
            // not cleaning position
            if (y_pos - 1 >= 0){
                if(space_data_store[y_pos - 1][x_pos] == 0){
                    direction = temp_direction;
                    y_pos -= 1;
                    continue;
                }
            }
            if(x_pos + 1 < m){
                if(space_data_store[y_pos][x_pos + 1] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(y_pos + 1 < n){
                if(space_data_store[y_pos + 1][x_pos] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(x_pos - 1 >= 0){
                if(space_data_store[y_pos][x_pos - 1] == 0){
                    direction = temp_direction;
                    continue;
                }
                else if(space_data_store[y_pos][x_pos - 1] == 1){
                    break;
                }
                else if(space_data_store[y_pos][x_pos - 1] == 2){
                    x_pos -= 1;
                }
            }


        }
        // south
        else if(direction == 2){
             // not cleaning position
            if (x_pos + 1 < m){
                if(space_data_store[y_pos][x_pos + 1] == 0){
                    direction = temp_direction;
                    x_pos += 1;
                    continue;
                }
            }
            if(x_pos - 1 >= 0){
                if(space_data_store[y_pos][x_pos - 1] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(y_pos + 1 < n){
                if(space_data_store[y_pos + 1][x_pos] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(y_pos - 1 >= 0){
                if(space_data_store[y_pos - 1][x_pos] == 0){
                    direction = temp_direction;
                    continue;
                }
                else if(space_data_store[y_pos - 1][x_pos] == 1){
                    break;
                }
                else if(space_data_store[y_pos - 1][x_pos] == 2){
                    y_pos -= 1;
                }
            }

        }
        // west
        else if(direction == 3){
             // not cleaning position
            if (y_pos + 1 < n){
                if(space_data_store[y_pos + 1][x_pos] == 0){
                    direction = temp_direction;
                    y_pos += 1;
                    continue;
                }
            }
            if(x_pos - 1 >= 0){
                if(space_data_store[y_pos][x_pos - 1] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(y_pos - 1 >= 0){
                if(space_data_store[y_pos - 1][x_pos] == 0){
                    direction = temp_direction;
                    continue;
                }
            }
            if(x_pos + 1 < m){
                if(space_data_store[y_pos][x_pos + 1] == 0){
                    direction = temp_direction;
                    continue;
                }
                else if(space_data_store[y_pos][x_pos + 1] == 1){
                    break;
                }
                else if(space_data_store[y_pos][x_pos + 1] == 2){
                    x_pos += 1;
                }
            }

        }
    }

    cout << clean_count << "\n";
    return 0;
}
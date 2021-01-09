#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int player_num, potion_num, max_hp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> player_num >> potion_num >> max_hp;
    int half_max_hp = max_hp / 2;
    int current_hp = max_hp;

    vector<pair<int, int> > player_data_store;
    vector<pair<int, int> > potion_data_store;
    // Plyaer한테 총 뺏기는 HP 저장
    long long decrease_value_sum = 0;
    // 포션 먹어서 총 증가하는 HP 저장
    long long increase_value_sum = 0;

    // Player 정보 저장(first: 데이터 값, second : index값)
    for(int i = 0; i < player_num; i++){
        int temp;
        cin >> temp;
        pair<int, int> pair_temp = make_pair(temp, -(i + 1));
        player_data_store.push_back(pair_temp);
        decrease_value_sum += temp;
    }

    // Potion 정보 저장(first: 데이터 값, second : index값)
    for(int i = 0; i < potion_num; i++){
        int temp;
        cin >> temp;
        pair<int, int> pair_temp = make_pair(temp, i + 1);
        potion_data_store.push_back(pair_temp);
        increase_value_sum += temp;
    }

    // 만족하는 케이스가 없는 경우
    // 체력이 절반 이하로 남을 때만 포션을 먹으므로 포션 손실은 발생하지 않는다. (최대 절반까지만 회복할 수 있으므로)
    // 따라서 체력 아이템과 싸울 때 발생하는 체력 손실 사이의 크기를 비교해서 생존가능성을 검토해주면 된다.
    if(max_hp + increase_value_sum <= decrease_value_sum){
        cout << "0\n";
        return 0;
    }

    // 정렬 (오름차순)
    sort(player_data_store.begin(), player_data_store.end());
    sort(potion_data_store.begin(), potion_data_store.end());

    // 결과값 저장하는 vector
    vector<int> result_store;

    // Player가 없어질 때까지 반복
    // Setting
    // 1. player에 해당하는 값만큼 뺸다.
    // 2. 현재 hp가 max_hp의 절반을 넘은 경우 : pass
    //    넘지 않은 경우 : 넘을 때까지 체력아이템 섭취
    //    (만약, 포션이 남지 않은 경우는 그냥 진행)
    while(player_data_store.size()){
        current_hp -= player_data_store.back().first;
        result_store.push_back(player_data_store.back().second);
        player_data_store.pop_back();

        // 뺀 값이 절반을 넘는 상황(포션을 먹어야함)
        if(current_hp <= half_max_hp){
            while(potion_data_store.size()){
                // 포션을 먹어서 hp가 최대 hp의 절반이 넘을 때까지 반복
                // 만약 포션이 없으면 그냥 진행
                current_hp += potion_data_store.back().first;
                result_store.push_back(potion_data_store.back().second);
                potion_data_store.pop_back();

                if(current_hp > half_max_hp) break;
            }
        }   
    }

    // 포션 남은 것 있으면 출력해야할 것에 저장
    while(potion_data_store.size()){
        result_store.push_back(potion_data_store.back().second);
        potion_data_store.pop_back();
    }

    // 결과값 출력
    for(int i = 0; i < result_store.size(); i++){
        cout << result_store[i] << "\n";
    }

    return 0;
}
#include <vector>
using namespace std;

void init(int N)
{
	return;
}

int call(vector<int> F, vector<int> B, int num)
{
	if(num == F.size() - 1){
		int s = 0;
		for(int i = 0; i < num; i++){
			s += F[i];
		}
		return s % 64;
	}
	else{
		int remainder = B[F.size() - 1];
		int s = 0;
		for(int i = num + 1; i < F.size() - 1; i++){
			s += B[i];
		}
		for(int i = 0; i < num; i++){
			s += F[i];
		}
		s %= 64;
		if(s > remainder) return 64 + remainder - s;
		else return remainder - s;
	}
}
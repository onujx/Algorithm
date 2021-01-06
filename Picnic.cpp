#include<cassert>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

int n, m;
bool areFriends[10][10];


int countPairings(bool taken[10]) {
	// 남은 학생들 중 가장 번호가 빠른 학생을 찾는다
	int firstFree = -1;
	for (int i = 0; i < (n); i++) {
		if (!taken[i]) {  //  n명의 학생 중 i 번째 학생이 짝을 찾은 경우
			firstFree = i;
			break;
		}
	}
	// 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1) return 1; // 1명의 학생인 경우 출력
	int ret = 0;
	for (int pairWith = (firstFree + 1); pairWith < (n); pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);  //true로 값이 변경된 bool 배열을 전달, 재귀호출
			taken[firstFree] = taken[pairWith] = false; // ret 값에 저장을 한 뒤 변경된 배열을 다시 되돌려 놓음
		}
	}
	return ret;
}
/**/

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		cin >> n >> m;
		assert(n <= 10);
		memset(areFriends, 0, sizeof(areFriends));  // 0으로 초기화
		for (int i = 0; i < (m); i++) {
			int a, b;
			cin >> a >> b;
			assert(0 <= a && a < n && 0 <= b && b < n); //학생 번호의 기본 조건 검사
			assert(!areFriends[a][b]);  //초기화 확인
			areFriends[a][b] = areFriends[b][a] = true;  // 같은 짝이고 순서만 다른 경우를 true로 처리
		}
		bool taken[10];
		memset(taken, 0, sizeof(taken));
		cout << countPairings(taken) << endl;
	}
}

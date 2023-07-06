#include<iostream>
#include<list>

using namespace std;

int main() {

	//리스트 선언
	list<int> b;
	//리스트 포인터 선언
	list<int>::iterator iter = b.begin();

	//뒤쪽으로 요소 추가하기
	for (int i = 0; i < 5; i++) {
		b.push_back(i);
	}

	//양 끝의 요소 제거하기
	b.pop_back();
	b.pop_front();

	//중간에 요소 추가하기 (삭제는 함수만 erase로 바꿈)
	iter = b.begin();
	int k = 2; //두번째 자리에 8 추가하기
	for (int i = 0; i < k - 1; ++i) {
		++iter;
	}

	b.insert(iter, 8);

	//전체 요소 출력하기

	for (iter = b.begin(); iter != b.end(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}
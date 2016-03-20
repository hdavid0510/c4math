/* This code is made for proving the answer of the question given in the book.
 * Question is from 2017 수능특강 확률과통계 p.16 Q# 1.
 * Original conditions : X={1,2,3,4,5} && f:X->X && f(1)!=f(2) && f(2)=f(3) && n(Y)=n(f(X))=3 .
 * With the conditions above, the original answer is 840.
 *
 * This source code is written and tested with AIDE.
 * CC 4.0 BY-NC-SA.
 * Copyright David.Hong 2016. All rights reserved.
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int size=5;				//원소 수 결정
const int X[size]={1,2,3,4,5};	//정의역이자 공역.  여기서는 공역으로 활용할 것이다
int fX[size]={0};				//함숫값f(x)의 집합:치역
int count = 0;					//찾은 함수의 개수

int nY(){	//치역의 원소수 검색
	int n=0;					//일단 0개라고 생각하고 여기에다 찾은개수 누적
	bool first=true;			//중복된 함숫값인지 표시함
	for(int i=0; i<size; i++){	//size만큼 반복, i번째 함숫값에 대해 조사 
		for(int j=i-1; j>=0; j--){//현재 정의역(x값)이전에 중복된 것 있는지 조사
			if(fX[i] == fX[j]){ 	//중복 발견시
				first = false;		//중복임을 표시
				break; //중복조사 중단
			}
		}
		if(first) n++;			//만약 위 중복조사에서 처음나온 함숫값이라 판명된경우 치역원소수 +1
		else first=true;		//아니면 (중복이었다면) 표시 초기화 
	}
	return n;					//찾은 치역 원소수를 반환
}

void search(int idx){			//함수가 문제 조건에 부합하는지 여부 조사
	for(int i=0; i<size; i++){		//처음부터 끝까지 조사한다
		fX[idx]=X[i];				//f(idx), 즉 idx번째 정의역의 함숫값을 공역의 i번째 원소로 지정한다
		if(idx>=size-1){			//만약 이번 조사가 마지막 함숫값인 경우
			if((fX[0]!=fX[1]) && (fX[2]!=fX[1]) && (nY()==3)){//최종 조건 판단
				count++;				//조건 부합시: 카운트(찾은 개수) 증가시킨다
				cout << "found: "<<setw(4) << count << "\t";//번호 출력
				for(int i=0; i<size; i++)//모든 함숫값을 순서대로 출력
					cout<<"f("<<X[i]<<")="<<fX[i]<<"\t";
				cout<<"// n(Y)="<<nY()<<endl;//공역 개수 확인(nY()=3 이라는 문구가 매 행 마지막에 등장해야 함)
			}else{						//조건 불충족시
				continue;					//이번 조합에 대하여 조사중단
			}
		}else{						//만약 현재 조사중인 함숫값 뒤에 함숫값이 더 있는경우
			search(idx+1);				//현재까지의 함숫값 상태로 뒷부분을 조사한다
		}
	}
}

int main(){
	search(0); //함수가 함수를 호출할때마다, 0번째부터 시작하여 뒤쪽으로 하나씩 자리를 이동해가며 조사한다.
				//즉, 위 줄에서는 0번째 함숫값인 f(1)에 대해 조사하며 그 조사의 일부분으로 f(2)를 조사,
				//또 그 일부분으로 f(3)을 조사하는 식이다. 이러한 재귀적 구조는 마지막 함숫값을 조사하며 끝난다.
	cout << "Finished. Totally "<<count<<" combination"<<(count<=1 ? " is":"s are")<<" found."<< endl; //조사 완료를 알린다.
	return 0;
}

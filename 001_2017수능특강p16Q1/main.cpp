/* This code is made for proving the answer of the question given in the book.
 * Question is from 2017 ����Ư�� Ȯ������� p.16 Q# 1.
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

const int size=5;				//���� �� ����
const int X[size]={1,2,3,4,5};			//���ǿ����� ����.  ���⼭�� �������� Ȱ���� ���̴�
int fX[size]={0};				//�Լ���f(x)�� ����:ġ��
int count = 0;					//ã�� �Լ��� ����

int nY(){	//ġ���� ���Ҽ� �˻�
	int n=0;				//�ϴ� 0����� �����ϰ� ���⿡�� ã������ ����
	bool first=true;			//�ߺ��� �Լ������� ǥ����
	for(int i=0; i<size; i++){	//size��ŭ �ݺ�, i��° �Լ����� ���� ���� 
		for(int j=i-1; j>=0; j--){//���� ���ǿ�(x��)������ �ߺ��� �� �ִ��� ����
			if(fX[i] == fX[j]){ 	//�ߺ� �߽߰�
				first = false;		//�ߺ����� ǥ��
				break; //�ߺ����� �ߴ�
			}
		}
		if(first) n++;			//���� �� �ߺ����翡�� ó������ �Լ����̶� �Ǹ�Ȱ�� ġ�����Ҽ� +1
		else first=true;		//�ƴϸ� (�ߺ��̾��ٸ�) ǥ�� �ʱ�ȭ 
	}
	return n;					//ã�� ġ�� ���Ҽ��� ��ȯ
}

void search(int idx){			//�Լ��� ���� ���ǿ� �����ϴ��� ���� ����
	for(int i=0; i<size; i++){		//ó������ ������ �����Ѵ�
		fX[idx]=X[i];				//f(idx), �� idx��° ���ǿ��� �Լ����� ������ i��° ���ҷ� �����Ѵ�
		if(idx>=size-1){			//���� �̹� ���簡 ������ �Լ����� ���
			if((fX[0]!=fX[1]) && (fX[2]!=fX[1]) && (nY()==3)){//���� ���� �Ǵ�
				count++;				//���� ���ս�: ī��Ʈ(ã�� ����) ������Ų��
				cout << "found: "<<setw(4) << count << "\t";//��ȣ ���
				for(int i=0; i<size; i++)//��� �Լ����� ������� ���
					cout<<"f("<<X[i]<<")="<<fX[i]<<"\t";
				cout<<"// n(Y)="<<nY()<<endl;//���� ���� Ȯ��(nY()=3 �̶�� ������ �� �� �������� �����ؾ� ��)
			}else{						//���� ��������
				continue;					//�̹� ���տ� ���Ͽ� �����ߴ�
			}
		}else{						//���� ���� �������� �Լ��� �ڿ� �Լ����� �� �ִ°��
			search(idx+1);				//��������� �Լ��� ���·� �޺κ��� �����Ѵ�
		}
	}
}

int main(){
	search(0); //�Լ��� �Լ��� ȣ���Ҷ�����, 0��°���� �����Ͽ� �������� �ϳ��� �ڸ��� �̵��ذ��� �����Ѵ�.
				//��, �� �ٿ����� 0��° �Լ����� f(1)�� ���� �����ϸ� �� ������ �Ϻκ����� f(2)�� ����,
				//�� �� �Ϻκ����� f(3)�� �����ϴ� ���̴�. �̷��� ����� ������ ������ �Լ����� �����ϸ� ������.
	cout << "Finished. Totally "<<count<<" combination"<<(count<=1 ? " is":"s are")<<" found."<< endl; //���� �ϷḦ �˸���.
	return 0;
}

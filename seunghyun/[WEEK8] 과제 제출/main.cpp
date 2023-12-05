#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int arr[MAX];
int sum[MAX][MAX];
int len = 0;

void Sum(int n, int x, vector<int>& ans) {
	if (x == 0 || n < 1) { //���̻� Ž������ ����
		if (x == 0) { //���� ����� ���� ��
			sum[len][0] = ans.size(); //���� ���� ������ ũ�� ����
			for (int i = 1; i <= ans.size(); i++) { //���� ������ ���� ������� ����
				sum[len][i] = ans.at(i - 1);
			}
			len++; //���� ���� ����
		}
		return;
	}

	if (x >= arr[n]) { //���� ���Һ��� ���� ���� ���� ��
		ans.push_back(arr[n]); //���Ϳ� ���� �� �ֱ�
		Sum(n - 1, x - arr[n], ans); //���� ���
		ans.pop_back(); //������ ����
	}
	Sum(n - 1, x, ans); //���� �ʾ��� �� ���
}

int main() {
	char fname[50];
	FILE* fp;
	int n, x;

	printf("���� �̸�? ");
	gets_s(fname); //���� �̸� �Է�
	fp = fopen(fname, "r"); //���� ����
	if (fp == NULL) {
		printf("������ �������� �ʽ��ϴ�.\n");
		return 0;
	}
	
	fscanf(fp, "%d", &n); //���Ͽ��� n �о����
	for (int i = 1; i <= n; i++) { //���Ͽ��� ������� ���� �ҷ��� arr�� ����
		fscanf(fp, "%d", &arr[i]);
	}
	cout << "ã���� �ϴ� ��? ";
	cin >> x; //�κ����� ���� �� �Է�
	
	vector<int>ans; 
	
	Sum(n, x, ans);

	if (len == 0)
		cout << "�κ������� �������� �ʽ��ϴ�.";
	else {
		cout << "[ ";
		for (int i = sum[0][0]; i > 0; i--) {
			cout << sum[0][i];
			if (i > 1)
				cout << ", ";
		}
		cout << " ]";
	}
	return 0;
}
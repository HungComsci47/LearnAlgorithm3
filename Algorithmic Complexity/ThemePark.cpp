#include<iostream>
#include <bits/stdc++.h>
#define maxn 2500
using namespace std;
int R,K,N;
int a[maxn], f[maxn], h[maxn],V[maxn];
void nhap()
{
	cin >> R>>K>>N;
        for (int i = 0; i < N; i++) {
        cin >> a[i];
	}
}
void TimNhomKet()
{
	for (int i = 0; i < N; i++)
		a[N + i] = a[i];
	int s = a[0];
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		while (j + 1 - i + 1 <= N && s + a[j+1] <= K)
		{
			j++;
			s += a[j];
		}

		f[i] = j % N;
		V[i] = s;
		s -= a[i];
	}
}
long long tinh(int& t,int sl)
{
	long long S = 0;
	for (int i = 1; i <= sl; i++)
	{
		S += V[t];
		t = (f[t] + 1) % N;
	}
	return S;
}
void xuli()
{
	for (int i = 0; i < N; i++) h[i] = 0;
	int t, pre, circle;
	t = 0;
	for (int i = 1; i <= N; i++)
	{
		h[t] = i;
		t = (f[t] + 1)%N;
		if (h[t] != 0)
		{
			pre = h[t] - 1;
			circle = i - h[t] + 1;
		}
	}

	long long Spre = 0, Scircle = 0,S=0;
	t = 0;
	if (R < pre)
	{
		t = 0;
		S = tinh(t, R);
	}
	else
	{
		S = tinh(t, pre);
		R -= pre;
		S += tinh(t, circle) * (R / circle);
		R = R % circle;
		S += tinh(t, R);
	}
	cout << S<<endl;
}
int main()
{

	int test;
	cin >> test;
	for (int i = 1; i <= test; i++)
	{
		nhap();
		TimNhomKet();
		cout << "Case #" << i << ": ";
		xuli();

	}
}

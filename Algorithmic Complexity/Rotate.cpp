#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;
int n,k;
string a[60];


void nhap()
{
    cin >> n >> k;
    assert(3 <= n && n <= 50);
    assert(3 <= k && k <= n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> a[i];
    }
}


void SangPhai()
{
    for (int row = 0; row < n; ++row) {
        int x = n - 1;
        for (int col = n - 1; col >= 0; col--)
            if (a[row][col] != '.') {
                a[row][x] = a[row][col]; x--;
            }
        while (x >= 0) { a[row][x] = '.'; x--; }
    }
}
bool TrongBang(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < n);
}
bool kt(int x, int y)
{
    if (a[x][y] == '.') return false;
    int ngang = 0;
    int doc = 0;
    int cheochinh = 0;
    int cheophu = 0;
    for (int i = 0; i < k; i++)
    {
        if (TrongBang(x + i, y + i) && a[x + i][y + i] == a[x][y]) cheochinh++;
        if (TrongBang(x + i, y - i) && a[x + i][y - i] == a[x][y]) cheophu++;
        if (TrongBang(x, y + i) && a[x][y + i] == a[x][y]) ngang++;
        if (TrongBang(x + i, y) && a[x + i][y] == a[x][y]) doc++;
    }
    return (doc == k || ngang == k || cheochinh == k || cheophu == k);
}
int XuLy4Huong()
{
    int R = 0;
    int B = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (kt(i,j))
            {
                if (a[i][j] == 'R') R = 1;
                if (a[i][j] == 'B') B = 1;
                if (R + B == 2) return 3;
            }
    if (R == 1) return 0;
    if (B == 1) return 1;
    return 2;

}
int main()
{
    int test;
    cin >> test;
    assert(1 <= test && test <= 100);
    for (int i = 1; i <= test; i++)
    {
        nhap();
        SangPhai();
        cout << "Case #" << i << ": ";
        string s[4] = { "Red","Blue","Neither","Both" };
        cout<<s[XuLy4Huong()]<<endl;
    }
}


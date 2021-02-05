/*Do you ever become frustrated with television because you keep seeing the same things, recycled over and over again? Well I personally don't care about television, but I do sometimes feel that way about numbers.

Let's say a pair of distinct positive integers (n, m)(n,m) is recycled if you can obtain m by moving some digits from the back of nn to the front without changing their order. For example, (12345, 34512)(12345,34512) is a recycled pair since you can obtain 3451234512 by moving 345345 from the end of 1234512345 to the front. Note that n and m must have the same number of digits in order to be a recycled pair. Neither nn nor mm can have leading zeros.

Given integers AA and BB with the same number of digits and no leading zeros, how many distinct recycled pairs (n, m)(n,m) are there with A \leq n < m \leq B?A=n<m=B?*/
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t=1;
	do{
	long long int a,b;
	cin>>a>>b;
	int power=1;
	int temp=a;
	while(temp>=10)
	{
		power*=10;
		temp=temp/10;
	}
	int dem=0;
	for(int i=a;i<=b;i++)
	{
		temp=i;
		while(true)
		{
			temp=(temp/10)+((temp%10)*power);
			if(temp==i)
			break;
			if(temp>i && temp<=b)
			dem++;
		}
	}
	cout<<"Case #"<<t<<": ";
	cout<<dem;
	cout<<endl;
	t++;
  }while(t<=n);
  return 0;
}

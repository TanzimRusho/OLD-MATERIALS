#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define myPair pair<int,int>

using namespace std;

int main()
{

	cout<<"Hello World of C++!";
	cout << endl;
	/*int x=0;
	cin>>x;

	x=x+10;

	cout << "value of x is:"<<x << " thank you!" << endl;
	*/
	/*pair<int,int> a(1,34);

	pair<int,int> b(45,34);

	pair<int,int> c(1,34);

	cout << "a equals b " << (a==b) << endl;
	cout << "a equals c " << (a==c) << endl;

	cout << a.first << " "<<a.second<<endl;

	pair <int,char> d(12,'A');

	cout << d.first <<" "<<d.second<<endl; */

	/*vector<int> myVector(5,0);

	myVector.push_back(4);
	myVector.push_back(7);

	myVector.push_back(10);
	myVector.push_back(8);
	myVector.push_back(15);

	for(int i=0;i<myVector.size();i++)
	{
		cout<< myVector[i]<<" ";
	}*/

	/*	vector<int> myVector2;

	int x;
	cin>>x;
	myVector2.push_back(x);

	cout << "vector at [0]"<<myVector2[0]<<endl;*/

	myPair a(3,5);
	myPair b(7,15);
	myPair c(1,25);
	myPair d(4,20);
	myPair e(4,45);


	vector<myPair> myVector3;

	myVector3.push_back(a);
	myVector3.push_back(b);
	myVector3.push_back(c);
	myVector3.push_back(d);
	myVector3.push_back(e);


	for(int i=0;i<myVector3.size();i++)
	{
		cout<<myVector3[i].first<<" "<<myVector3[i].second<<endl;
	}

	/*priority_queue<int,vector<int>,less<int>  > myQueue;

	myQueue.push(56);
	myQueue.push(67);
	myQueue.push(34);
	myQueue.push(98);
	myQueue.push(33);

	cout<<myQueue.top()<<endl;

	myQueue.pop();

	cout<<myQueue.top()<<endl;*/


	priority_queue<myPair,vector<myPair>,greater<myPair>> myQueue2;

	myQueue2.push(a);
	myQueue2.push(b);
	myQueue2.push(c);
	myQueue2.push(d);
	myQueue2.push(e);

	cout<<" in the  queue"<<endl;
	while (!myQueue2.empty())
	{
		cout<<myQueue2.top().first <<" "<< myQueue2.top().second<<endl;
		myQueue2.pop();
	}









	return 0;
}

#include <bits/stdc++.h>
using namespace std;
set<int> t;
int main()
{
	int n,op,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>x;
		if(op==1){
			if(t.count(x)){
				cout<<"Already Exist\n";
			}else{
				t.insert(x);
			}
		}else if(op==2){
			if(t.size()){
				auto it=t.find(x);
				if(it!=t.end()){
					cout<<*it<<endl;
					t.erase(it);
				}else{
					t.insert(x);
					it=t.find(x);
					auto it1=it;
					auto it2=it;
					it1--;
					it2++;
					if(it1==t.end()){
						cout<<*it2<<endl;
						t.erase(it2);
					}else if(it2==t.end()){
						cout<<*it1<<endl;
						t.erase(it1);
					}else{
						if(x-*it1<=*it2-x){
							cout<<*it1<<endl;
							t.erase(it1);
						}else{
							cout<<*it2<<endl;
							t.erase(it2);
						}
					}
					t.erase(it);
				}
			}else{
				cout<<"Empty\n";
			}
		}
	}
	return 0;
}

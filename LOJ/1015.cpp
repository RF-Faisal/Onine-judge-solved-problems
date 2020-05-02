#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tst, TC;
    cin>>TC;
    for(tst=1; tst<=TC; tst++){
        int n, sum=0;
        cin>>n;
        vector<int>a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i]>0) sum += a[i];
        }
        cout<<"Case "<<tst<<": "<<sum<<endl;
    }
return 0;
}
#include<iostream>
using namespace std;

class queen{
    public:
    int place(int r,int c);
    int nqueen(int r,int n);
    int display(int n);
    int x[20], count=0;

};

int queen::place(int r,int c){
    for(int i=1;i<=r-1;i++){
        if(x[i]==c){
            return 0;
        }
        else{
            if(abs(x[i]-c)==abs(i-r)){
                return 0;
            }
        }
    }
    return 1;
}
int queen::nqueen(int r,int n){
     for(int c=1;c<=n;c++){
        if(place(r,c)){
            x[r]=c;
            if(r==n){
                display(n);
            }
            else{
                nqueen(r+1,n);
            }
        }
     }
     return 0;
}
int queen::display(int n){
    cout<<"solutuon : "<<endl<<++count;
    for(int i=1;i<=n;i++)
    {
        cout<<"\t"<<i;
    }
     for(int i=1;i<=n;i++)
    {
        cout<<"\n"<<i;
        for(int j=1;j<=n;j++){
             if(x[i]==j){
                cout<<"     Q     ";
             }
             else{
                cout<<"     -     ";
             }
        }

    }
    return 0;
}

int main(){
    queen q;
    int n;
    cout<<"enter queen : ";
    cin>>n;
    q.nqueen(1,n);
    return 0;

}
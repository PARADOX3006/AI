#include<iostream>
#include<algorithm>
#include<vector>

struct Job{
    int id;
    int deadline;
    int profit;
};
using namespace std;
bool compare(Job a,Job b){
    return(a.profit > b.profit);
}


void jobscheduling(vector<Job>& jobs){
    sort(jobs.begin(),jobs.end(),compare);

    int md=0;
    for(Job job:jobs){
        md=max(md,job.deadline);
    }

    vector<int>result(md+1,-1);
    int tprofit=0;
    int tjobs=0;

    for(Job job:jobs){
        for( int i=job.deadline;i>0;i--){
              if(result[i]==-1){
                result[i]=job.id;
                tprofit+=job.profit;
                tjobs++;
                break;
              }
        }
    }

    for(int i=1;i<md;i++){
        cout<<result[i];

    }
    cout<<"total profit : "<<tprofit;
    cout<<"total jobs : "<<tjobs;

}

int main(){
    //vector<Job>jobs(n);
    int n;
    cout<<"Enter the no. of jobs : ";
    cin>>n;
    vector<Job>jobs(n);
    for(int i=0;i<n;i++){
        cout<<"job : "<<i+1;
        cout<<"deadline : ";
        cin>>jobs[i].deadline;
        cout<<"profit : ";
        cin>>jobs[i].profit;
        jobs[i].id=i+1;
    }
    jobscheduling(jobs);
}
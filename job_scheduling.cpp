#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct Job{
    string id;
    int deadline;
    int profit;
};

bool compareJobs(const Job& j1,const Job& j2){
    return j1.profit>j2.profit;
}

void maxProfit(vector<Job> jobs){


    sort(jobs.begin(),jobs.end(),compareJobs);

    int maxdeadline=0;

    for(auto job:jobs){
        maxdeadline=max(maxdeadline,job.deadline);
    }

    vector<string> schedule(maxdeadline,"");
    vector<bool> slotOccupied(maxdeadline,false);

    int maxProfit=0;
    for(auto job:jobs){
        for(int i=job.deadline-1;i>=0;i--){
            if(!slotOccupied[i]){
                schedule[i]=job.id;
                slotOccupied[i]=true;
                maxProfit+=job.profit;
                break;
            }
        }
    }

    cout<<"Schedule of Jobs: ";

    for(string jobid:schedule){
        cout<<jobid<<" ";
    }
    cout<<endl;


    cout<<"Maximum profit is: " <<maxProfit;
  

}

int main(){


  vector<Job> jobs;

    int n;
    cout<<"Enter Number of Jobs: ";
    cin>>n;

    for(int i=0;i<n;i++){
        Job job;
        cout<<"Enter id,deadline and profit of Job "<<i+1<<": ";
        cin>>job.id>>job.deadline>>job.profit;
        jobs.push_back(job);
    }

    maxProfit(jobs);

    
    
//   a            2          100
//   b            1          19
//   c            2          27
//   d            1          25
//   e            3          15



    return 0;
}
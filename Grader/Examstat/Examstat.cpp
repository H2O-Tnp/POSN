#include <bits/stdc++.h>
using namespace std;

int main(){
    int S,N;
    cin >> S >> N;
    double avg[S]={0};
    int minarr[S];
    int maxarr[S];
    double sdsum[S]={0};
    double sd[S]={0};
    double sumN[N]={0};
    double allsum=0;
    double allavg=0;
    double sum_min = INT_MAX;
    double sum_max = INT_MIN;

    for(int i=0;i<S;i++){
        minarr[i] = INT_MAX;
        maxarr[i] = INT_MIN;
    }

    int sc[N][S];
    for(int i=0;i<N;i++){
        for(int j=0;j<S;j++){
            cin >> sc[i][j];
            minarr[j] = min(minarr[j],sc[i][j]);
            maxarr[j] = max(maxarr[j],sc[i][j]);
            sumN[i] += sc[i][j];
            avg[j] += sc[i][j];
            
            if(i==N-1){
                avg[j]=avg[j]/N;
            }
        }
    }
    for(int i=0;i<N;i++){
        sum_min = min(sum_min,sumN[i]);
        sum_max = max(sum_max,sumN[i]);
        allsum += sumN[i];
        for(int j=0;j<S;j++){
            sdsum[j]+=pow((sc[i][j]-avg[j]),2);
        }
    }
    allavg=allsum/N;
    double allsdsum={0};
    double allsd={0};
    for(int i=0;i<N;i++){
        allsdsum+=pow((sumN[i]-allavg),2);
    }
    allsd = sqrt(allsdsum/(N-1));

    for(int j=0;j<S;j++){
        sd[j] = sqrt(sdsum[j]/(N-1));
    }

    for(int i=0;i<S;i++){
        cout<<minarr[i]<<" ";
        cout<<maxarr[i]<<" ";
        printf("%.2f ",avg[i]);
        printf("%.2f\n",sd[i]);
    }
    cout<<sum_min<<" ";
    cout<<sum_max<<" ";
    printf("%.2f ",allavg);
    printf("%.2f\n",allsd);

    double piv = allavg - sqrt(allsd);
    int pass_n = 0;
    for(int i=0;i<N;i++){
        if(sumN[i] >= piv){
            pass_n ++;
        }
    }
    cout<<pass_n<<' '<<N-pass_n<<"\n";
}
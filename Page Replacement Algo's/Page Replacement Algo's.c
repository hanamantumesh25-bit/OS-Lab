#include <stdio.h>

void FIFO(int p[], int n, int f){
    int frame[f], k=0, fault=0;
    for(int i=0;i<f;i++) frame[i]=-1;
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<f;j++) if(frame[j]==p[i]) found=1;
        if(!found){ frame[k]=p[i]; k=(k+1)%f; fault++; }
    }
    printf("FIFO Page Faults=%d\n",fault);
}

void LRU(int p[], int n, int f){
    int frame[f], time[f], cnt=0, fault=0;
    for(int i=0;i<f;i++) frame[i]=time[i]=-1;
    for(int i=0;i<n;i++){
        int found=0,pos=0;
        for(int j=0;j<f;j++)
            if(frame[j]==p[i]){ time[j]=++cnt; found=1; }
        if(!found){
            for(int j=1;j<f;j++)
                if(frame[j]==-1 || time[j]<time[pos]) pos=j;
            frame[pos]=p[i]; time[pos]=++cnt; fault++;
        }
    }
    printf("LRU Page Faults=%d\n",fault);
}

void Optimal(int p[], int n, int f){
    int frame[f], fault=0;
    for(int i=0;i<f;i++) frame[i]=-1;
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<f;j++) if(frame[j]==p[i]) found=1;
        if(!found){
            int pos=-1,farthest=i+1;
            for(int j=0;j<f;j++){
                int k;
                for(k=i+1;k<n;k++) if(frame[j]==p[k]) break;
                if(k==n){ pos=j; break; }
                if(k>farthest){ farthest=k; pos=j; }
            }
            if(pos==-1) for(int j=0;j<f;j++) if(frame[j]==-1){pos=j; break;}
            frame[pos]=p[i]; fault++;
        }
    }
    printf("Optimal Page Faults=%d\n",fault);
}

int main(){
    int n,f;
    printf("Pages: "); scanf("%d",&n);
    int p[n]; printf("Reference string: ");
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    printf("Frames: "); scanf("%d",&f);

    FIFO(p,n,f);
    LRU(p,n,f);
    Optimal(p,n,f);
    return 0;
}

long long merge(long long *arr,long long s,long long e){
    long long mid=(s+e)/2;
    long long i=s;
    long long j=mid+1;
    long long k=s;
    long long temp[e+1];
    long long cnt=0;
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            cnt+=mid-i+1;
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }
    return cnt;
}

long long int solve(long long *arr,long long s,long long e){
    if(s>=e){
        return 0;
    }
    long long mid=(s+e)/2;
    long long x=solve(arr,s,mid);
    long long y=solve(arr,mid+1,e);
    long long z=merge(arr,s,e);
    return x+y+z;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return solve(arr,0,n-1);
}
import numpy as np
x,y,z,n=list(map(int,input().split()))
a=np.array(list(map(int,input().split())))
a=a.reshape(x,y,z)
summer=0
# print(a)
def bs(c,n,d):
    if(len(c)==0):
        return 0
    else:
        l=len(c)-1
        s=0
        leng=0
        # notFound=True
        while(s<=l):
            leng+=1
            mid=(s+l)//2
            # print(s,l,mid)
            # print(c[s],c[l],c[mid])
            # print("-----------------")
            if(c[mid]<=n and d[mid]>=n):
                # notFound=False
                return mid, leng

            elif(c[mid]>n):
                l=mid-1
            
            else:
                s=mid+1
        return l,leng
indx1,s=bs(a[:,0,0],n,a[:,y-1,z-1])
summer+=s
if(n<=a[indx1][y-1][z-1] and n>=a[indx1][0][0]):
    print(a[indx1][0][0],a[indx1][y-1][z-1])
    indx2,s=bs(a[indx1,:,0],n,a[indx1,:,z-1])
    summer+=s
    if(n<=a[indx1][indx2][z-1] and n>=a[indx1][indx2][0]):
        print(a[indx1][indx2][0],a[indx1][indx2][z-1])
        indx3,s=bs(a[indx1,indx2,:],n,a[indx1,indx2,:])
        summer+=s
        if(n<=a[indx1][indx2][indx3] and n>=a[indx1][indx2][indx3]):
            print(indx1,indx2,indx3)
        else: 
            print(0)

    else:
        print(0)
else:
    print(0)
print(summer)
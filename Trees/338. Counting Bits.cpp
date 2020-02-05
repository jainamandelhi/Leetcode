class Solution {
public:
    vector<int> countBits(int num) {
       vector<int>arr(num+1);
        if(num==0)
            return arr;
        arr[0]=0;
        arr[1]=1;
        int i=0;
        while(pow(2,i)<=num)
        {
            arr[pow(2,i)]=1;
            i++;
        }
        for(int i=1;i<=num;i++)
        {
            if(arr[i]>0)
                continue;
            int j=log(i)/log(2);
            j=pow(2,j);
            arr[i]=arr[j]+arr[i-j];
        }
        return arr;
    }
};
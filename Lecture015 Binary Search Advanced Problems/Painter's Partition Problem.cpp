bool isPossible(vector<int> &boards,int n,int m,int mid){
    int studentCount = 1;
    int pageSum = 0;    
    for(int i = 0; i<n; i++) {
        if(pageSum + boards[i] <= mid) {
            pageSum += boards[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || boards[i] > mid ) {
            return false;
        }
            pageSum = boards[i];
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    int n = boards.size();
    for(int i=0;i<n;i++){
        sum+=boards[i];
    }
    int e=sum;
    int ans = -1;
    int mid=s + (e-s)/2;
    while(s<=e){
        if(isPossible(boards,n,k,mid)){
            ans = mid;
          	e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
};

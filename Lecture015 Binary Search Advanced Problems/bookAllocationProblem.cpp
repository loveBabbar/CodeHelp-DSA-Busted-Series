bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) pageSum += arr[i];
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid ) return false;
            pageSum = arr[i];
        }
        if(studentCount > m) return false;
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {

    if(m>n) return -1;

    int s = 0;
    int e = 0;
    
    for(int i = 0; i<n; i++) e += arr[i];
    
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
        mid = s + (e-s)/2;
    }
    return ans;
}

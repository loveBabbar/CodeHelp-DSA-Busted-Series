// Solution for problem: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVR6bE5iZ1pwTW16dUhDN0g0LUdabHpkTXMtZ3xBQ3Jtc0tsLXpOdndqSjc5TkNLWFlrdEJwZzNkV242X1lEeU11Zy1zWnJ6akJ3NVV6dzdrQTFTLUIzUnR0VFl5Y1NnWmxKMTNBbU9pSF9qVl94SHdkcVQ3ZFpRRTJWaHctVzF4c2JNaHpVNUUxdGotZE1UWTNxTQ&q=https%3A%2F%2Fbit.ly%2F31v3Jiy&v=YTTdLgyqOLY

int sumofa(vector<int> &a){
    int sum = 0;
    for(int i=0; i<a.size(); i++){
        sum += a[i];
    }
    return sum;
}

int isPossible(vector<int> a, int k, int mid){
    int sum = 0;
    int count = 1;

    for(int i=0; i<a.size(); i++){
        if(sum + a[i] <= mid){
            sum += a[i];
        }
        else{
            count++;
            sum = a[i];
        }
    }
    return count;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s = *max_element(boards.begin(), boards.end());
    int e = sumofa(boards);
    int ans = -1;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(boards, k, mid) > k){
            s = mid +1;
        }
        else{
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}
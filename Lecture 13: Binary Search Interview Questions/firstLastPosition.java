
public static int firstOcc(ArrayList<Integer> arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr.get(mid) == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr.get(mid)) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr.get(mid)) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

public static int lastOcc(ArrayList<Integer>arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr.get(mid) == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr.get(mid)) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr.get(mid)) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

public static Pair<Integer, Integer> firstAndLastPosition(ArrayList<Integer> arr, int n, int k)
{
    Pair<Integer,Integer> p = new Pair<Integer,Integer>(firstOcc(arr, n, k),lastOcc(arr, n, k));
  
    return p;
}

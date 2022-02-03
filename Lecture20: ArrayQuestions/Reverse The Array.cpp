vector<int> reverse(vector<int> v) {

    int s = 0, e =v.size()-1;

    while(s<=e) {
        swap(v[s], v[e]);
        s++;
        e--;
    }

    return v;

}

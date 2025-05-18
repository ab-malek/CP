string subtraction(string b, string c){
    string one = "";

    int j = b.size();
    int i = c.size();
    i--,j--;
    int carry  = 0;
    while(i >= 0){
        int x = c[i] - '0';
        int y = (j>=0) ? b[j] - '0' : 0;
        i--,j--;
        y += carry;
        // cout<<x<<" "<<y<<endl;
        if(x >= y){
            int val = x - y;
            char l = '0'+val;
            one.push_back(l);
            carry = 0;
        }
        else{
            x += 10;
            int val = x - y;
            char l = '0'+val;
            one.push_back(l);
            carry = 1;
        }
        carry = x / 10;
        x %= 10;
    }

    while(!one.empty()){
        if(one.back() == '0'){
            one.pop_back();
        }
        else{
            break;
        }
    }
    reverse(one.begin(), one.end());
    return one;
}


string summatioin(string s1, string s2){
    int i = s1.size();
    int j = s2.size();
    i--,j--;
    int carry = 0;
    while(i>=0 || j >= 0){
        int up = (i >= 0) ? s1[i] - '0' : 0;
        int down = (j >= 0) ? s2[j] - '0' : 0;
        i--,j--;
        up += carry;
        int s = up + down;
        carry = s / 10;
        s %= 10;
        char xx = '0' + s;
        ans.push_back(xx);
    }
    if(carry > 0){
        char xx = '0' + carry;
        ans.push_back(xx);
    }
    // cout<<ans<<endl;
    while(!ans.empty()){
        if(ans.back() == '0'){
            ans.pop_back();
        }
        else{
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

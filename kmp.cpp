vector<int> prefix_function(string &s) {// take pattern
    int n = (int)s.length();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i-1];
        while (j > 0 && s[i] != s[j])
            j = lps[j-1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

void KMPMultipleTimes (string text, string pattern) {// return how many time occurs with index
    bool found = false;
    vector<int> lps = prefix_function(pattern);
    int j = 0, i = 0;
    vector<int> ans;
    // i --> text, j --> pattern
    while (i < (int) text.length()) {
        if (text[i] == pattern[j]) ++i, ++j;
        else {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }

        if (j == (int) pattern.length()) {
            ans.push_back(i-pattern.size()+1);
            j = lps[j-1];
            found = true;
        }
    }

    if (!found) cout << "Not Found" <<nl;
    else{
        cout<<ans.size()<<nl;
        printVec(ans);
    }
    cout<<nl;
}

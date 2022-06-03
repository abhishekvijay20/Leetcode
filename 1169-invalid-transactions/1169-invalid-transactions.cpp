class Transaction {
public:   
    string name;
    int time;
    int amount;
    string city;
   
    Transaction(string n, int t, int a, string c) {
        name = n;
        time = t;
        amount = a;
        city = c;
    }   
};

class Solution {
public:
    Transaction convert(string s) {
        string name="", city="";
        int amount=0, time=0;
        int i=0;
        for (; s[i] != ','; i++) {
            name += s[i];
        }
        i++;
        string x = "";
        for (; s[i] != ','; i++) {
            x += s[i];
        }
        time = stoi(x);
        i++;
        x = "";
        for (; s[i] != ','; i++) {
            x += s[i];
        }
        amount = stoi(x);
        for (; i < s.size(); i++) {
            city += s[i];
        }
        
        return Transaction(name, time, amount, city);
    } 
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        vector<Transaction> v;
        for (int i=0; i<transactions.size(); i++) {
            v.push_back(convert(transactions[i]));
        }
        
        for (int i=0; i<transactions.size(); i++) {
            if (v[i].amount > 1000) {
                ans.push_back(transactions[i]);
                continue;
            }
            for (int j=0; j<transactions.size(); j++) {
                if (j == i) continue;
                if (v[j].time-60 <= v[i].time && v[j].time+60 >= v[i].time 
                    && v[i].name == v[j].name && v[i].city != v[j].city) {
                    ans.push_back(transactions[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
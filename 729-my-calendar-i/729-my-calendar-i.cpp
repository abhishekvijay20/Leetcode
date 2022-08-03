class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (s.empty()) {
            s.insert({start, end});
            return true;
        } else {
            for (auto i: s) {
                if (end <= i.first) {
                    continue;
                } else if (start >= i.second) {
                    continue;
                } else {
                    return false;
                }
            }
            s.insert({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
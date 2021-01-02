class Log {
    public:
        vector<int> liz;
        int n;
        void record(int id) {
            if(liz.size() == this->n) {
                liz.erase(liz.begin());
                liz.emplace_back(id);
            } else {
                liz.emplace_back(id);
            }
        }
        int get_last(int id) {
            return liz[n - id + 1];
        }
};

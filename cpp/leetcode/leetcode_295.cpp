#include <bits/stdc++.h>
using namespace std;

template<typename comp = less<int>>
struct heap{
    vector<int> data;
    size_t p(size_t i) const {return i >> 1;};
    size_t l(size_t i) const {return (i << 1) + 1; }
    size_t r(size_t i) const {return (i + 1) << 1;}
    size_t size() const {return data.size();}
    void insert(int num){
        data.push_back(num);
        int i = data.size() - 1;
        while(i > 0 && comp()(data[p(i)], data[i])){
            std::swap(data[i], data[p(i)]);
            i = p(i);
        }
    }

    int top() const {return data[0];}

    void heapify(size_t root){
        size_t left = l(root);
        size_t right = r(root);
        int tmp;
        if(left < size() && comp()(data[root], data[left])){
            tmp = left;
        } else {
            tmp = root;
        }
        if(right < size() && comp()(data[tmp],data[right])){
            tmp = right;
        }

        if(tmp != root){
            std::swap(data[root],data[tmp]);
            heapify(tmp);
        }
    }

    void pop() {
        if(data.empty()) return;
        std::swap(data[0], data[data.size()-1]);
        data.pop_back();
        heapify(0);
    }
};

class MediaHeap
{
public:
    MediaHeap(){};
    ~MediaHeap(){};
    void addNum(int num){
        max_h.insert(num);
        min_h.insert(max_h.top());
        max_h.pop();
        if(max_h.size() < min_h.size()){
            max_h.insert(min_h.top());
            min_h.pop();
        }
    }

    double get_media(){
        if((max_h.size()+min_h.size()) % 2 == 0){
            return (max_h.data[0] + min_h.data[0]) / 2.0;
        } else {
            return max_h.data[0] * 1.0;
        }
    }
private:
    heap<> max_h;
    heap<greater<int> > min_h;
    
};

int main(int argc, char const *argv[])
{
    MediaHeap mh;
    vector<int> test = {1,3,4,5,6,743,4,2,3,4,5,6,7,8,1,1,1,1,1,1,1,1,1,1,1};
    for(auto i : test){
        mh.addNum(i);
        cout << mh.get_media() << endl;
    }
    return 0;
}
class MedianFinder {
public:
    priority_queue<int> maxH; //stores the lower half
    priority_queue<int,vector<int>,greater<int>> minH; //stores the upper half

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //we need to balance
        maxH.push(num);//start by adding to maxheap

        //if the smallest in second half is smaller than largest in first half, transfer
        if(!minH.empty() && minH.top() < maxH.top()) {
            minH.push(maxH.top());
            maxH.pop();
        }

        // if one is not balanced, transfer to the other 
        if(minH.size() > 1 + maxH.size()) { //remember this balancing condition
            maxH.push(minH.top());
            minH.pop();
        }

         if(maxH.size() > 1 + minH.size()) {
            minH.push(maxH.top());
            maxH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()){ //even elements
            return (maxH.top() + minH.top())/2.0;
        }

        else if (maxH.size() > minH.size()) { //median in lower half
            return static_cast<double>(maxH.top());
        }

        else return static_cast<double>(minH.top());
    }
};

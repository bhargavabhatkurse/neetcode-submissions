class MedianFinder {
public:
vector<int> arr; //o(n) space
    MedianFinder() {
       //bruteforce - nlogn
    }
    
    void addNum(int num) {
        arr.push_back(num); //o(m) for m calls
    }
    
    double findMedian() {
        sort(arr.begin(),arr.end()); //m*nlogn (m = no of calls)
        int n = arr.size();
        int low = 0, high = n-1;
        int mid = low + (high-low)/2;
        if((n & 1) == 0) { //(n & 1) == 0 because of operator precedence
            return (arr[mid] + arr[mid+1])/2.0;
        }
        else {
            return (double)arr[mid];
        }

    }
};

#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set> 
#include <sstream>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
        //quick_sort(nums, 0, nums.size()-1);
        //merge_sort(nums, 0, nums.size()-1);
        heap_sort(nums);
        return nums;
    }

    int partition(vector<int>& nums, int l, int r){
        int i=l, j=r-1;
        while(i < j){
            for(; i<r && nums[i]<=nums[r]; i++);
            for(; i<j && nums[j]>nums[r]; j--);
            if(i < j) swap(nums[i], nums[j]);
        }
        if(nums[i]>nums[r]) swap(nums[i], nums[r]);
        return i;
    }

    int partition_d(vector<int>& nums, int l, int r){
        int i=l, j=l;
        for(; j<r; j++){
            if(nums[j]<nums[r]) swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[r]);
        return i;
    }

    void quick_sort(vector<int>& nums, int l, int r){
        int mid = partition(nums, l, r);
        if(l<mid-1) quick_sort(nums, l, mid-1);
        if(mid+1<r) quick_sort(nums, mid+1, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r){
        vector<int> tmp(r-l+1);
        int i=l, j=mid+1, k=0;
        while(i<=mid && j<=r){
            if(nums[i] < nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while(j <= r) tmp[k++] = nums[j++];
        while(i <= mid) tmp[k++] = nums[i++];
        for(i=0; i<r-l+1; i++) nums[l+i] = tmp[i];
    }

    void merge_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }

    void adjust_heap(vector<int>& nums, int x, int length){
        int k, tmp=nums[x];
        for(k=2*x+1; k<length; k=2*k+1){
            if(k+1 < length && nums[k] < nums[k+1]) k++;
            if(nums[k] > tmp) nums[(k-1)/2] = nums[k];
            else break;
        }
        nums[(k-1)/2] = tmp;
    }

    void make_heap(vector<int>& nums){
        for(int i=nums.size()/2-1; i>=0; i--){
            adjust_heap(nums, i, nums.size());
        }
    }

    void heap_sort(vector<int>& nums){
        make_heap(nums);
        for(int i=nums.size()-1; i>0; i--){
            swap(nums[0], nums[i]);
            adjust_heap(nums, 0, i);
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		vector<int> ret = Solution().sortArray(nums);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}

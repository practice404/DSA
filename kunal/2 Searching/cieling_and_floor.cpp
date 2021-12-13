int ceiling(vector<int> &nums, int target)
{
	int start = 0;
	int end = nums.size() - 1;
	
	if(target > nums[end])
		return -1;
	

	while(start<=end)
	{
		int mid = start + (end - start) / 2;

		if(nums[mid] > target)
			end = mid - 1;
		else if(nums[mid] <= target)
			start = mid + 1;
		else
			return nums[mid];

	}

	return nums[start];
}

int floor(vector<int>&nums, int target)
{
	int start = 0;
	int end = nums.size() - 1;

	if(target <= nums[start])
		return -1;

	while(start<=end)
	{
		int mid = start + (end - start)/2;

		if(nums[mid] > target)
			end = mid - 1;
		else if(nums[mid] < target)
			start = mid + 1;
		else
			return nums[mid];
	}

	return nums[end];
}
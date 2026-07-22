int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int area = h * (right - left);

        if (area > maxArea)
            maxArea = area;

        // Move the shorter line
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}
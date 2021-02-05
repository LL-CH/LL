class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() <= 1) {
			return 0;
		}

		int minId = 0;
		int maxId = height.size() - 1;
		int mostWater = 0;

		while (minId < maxId) {
			int minHeight = min(height[minId], height[maxId]); // �õ���С��height
			mostWater = max(mostWater, (maxId - minId) * minHeight); // ��������ˮ��
			height[minId] > height[maxId] ? --maxId : ++minId; // y��С���Ǳ��ƶ�
		}

		return mostWater;
	}
};
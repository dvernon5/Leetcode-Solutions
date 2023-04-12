class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto vectorSize = prices.size();
        int minimumNumber = INT_MAX;
        int maximumProfit = 0;

        for (int i = 0; i < vectorSize; i++)
        {
            if (prices[i] < minimumNumber)
            {
                minimumNumber = prices[i];
            }
            else if (prices[i] - minimumNumber > maximumProfit)
            {
                maximumProfit = prices[i] - minimumNumber;
            }
        }

        return maximumProfit;
    }
};
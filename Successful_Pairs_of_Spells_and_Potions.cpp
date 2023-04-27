// Leetcode Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution
{
    //  INTUITION: we have been given spells and portions array,
    // eg: spells = [5,1,3], potions = [1,5,3,2,4].
    //    A spell and potion pair is considered successful if the product of their strengths is at least success.
    //  for each spell we have to count successful pairs with potions and store the count of it in a vector,
    //  so what we can do is sort the potions vector.
    //  so if for a particular spell and potion pair the product is greater than success, then we will move
    // so right , high = mid-1.
    // else lo = mid+1.

public:
    int l_bound(int spell, vector<int> &potions, long long success)
    {
        int lo = 0, high = potions.size() - 1;
        long long ans = -1;
        while (lo <= high)
        {
            int mid = (lo + high) >> 1;

            long long eligible = 1ll * spell * potions[mid];

            if (eligible >= success)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {

        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (auto elem : spells)
        {
            int lb = l_bound(elem, potions, success);

            if (lb == -1)
                ans.push_back(0);
            else
                ans.push_back(potions.size() - lb);
        }
        return ans;
    }
};

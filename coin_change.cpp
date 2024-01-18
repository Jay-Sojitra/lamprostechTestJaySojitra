// Coin Change (Dynamic Programming):
// ● Problem Description: Given a list of coin denominations (e.g., 1-cent, 5-cent, 10-cent) and a specific target
// amount (e.g., 27 cents), find the minimum number of coins needed to reach the exact amount, considering
// all possible combinations.
// ● Example: Denominations [1, 5, 10], target amount 27
// ● Expected Code Output: The minimum number of coins needed (5)
// ● Hint: Use dynamic programming to build a table where each entry represents the minimum number of
// coins needed to reach a specific amount. Iterate through denominations and amounts, filling the table
// based on minimum coin combinations for smaller sub-amounts.
// Function to find the minimum number of coins needed to reach the target amount

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// create the function that will return required num of coins
int find_min_Coins(vector<int> &denominations, int target)
{

    // create a table to store the minimum number of coins needed for each amount
    vector<int> arr(target + 1, INT_MAX);

    // Base case : 0 coin needed to make change for 0 amount
    arr[0] = 0;

    // create a for that will try every combination
    for (int coin : denominations)
    {

        // create for loop that will start from first denomination
        for (int amt = coin; amt <= target; ++amt)
        {

            // Update the table entry with the minimum num of coins needed
            if (arr[amt - coin] != INT_MAX && arr[amt - coin] + 1 < arr[amt])
            {
                arr[amt] = arr[amt - coin] + 1;
            }
        }
    }

    // if not found the answer then return -1
    return (arr[target] == INT_MAX) ? -1 : arr[target];
}

int main()
{

    vector<int> denominations = {1, 5, 10};
    int targetAmt = 27;

    // result will store the answer for particular input
    int result = find_min_Coins(denominations, targetAmt);

    if (result != -1)
    {
        cout << "The minimum number of coins needed: " << result << endl;
    }
    else
    {
        cout << "no valid combination found" << endl;
    }
    return 0;
}

#include <stdio.h>

int main()
{

    double REALLY_BIG_NO = 1e99;
    double bottom = REALLY_BIG_NO; // arbirtrary large number
    double currBestBuy = 0.0;
    double top = 0.0;
    double currBestSell = 0.0;
    double profit = 0.0;

    // array of prices
    double prices[] = {10.50, 55.39, 109.23, 48.29, 81.59, 105.53, 94.45, 12.24, 152.0, 2, 170.0};
    int numPrices = 10;// number of prices
    for (int i = 0; i < numPrices; ++i)
    {
         if (prices[i] < bottom)
         {
            bottom = prices[i];
            // reset the search on a new bottom
            top = 0.0;
         }
         else if (prices[i] > top)
         {
            top = prices[i];
           // calculate profit
            double potentialProfit = (top - bottom);
            if (potentialProfit > profit &&
                bottom != REALLY_BIG_NO)
            {
                profit = potentialProfit;
                currBestSell = top;
                currBestBuy = bottom;
            }
         }
    }
    printf("Best Buy: %f",currBestBuy);
    printf("Best Sell: %f",currBestSell);
}

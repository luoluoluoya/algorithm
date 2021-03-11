//
// Created by 张锐 on 2021/3/11.
//

#ifndef ALGORITHM_STONEGAME_H
#define ALGORITHM_STONEGAME_H

/*
 * 877. 石子游戏
 *  亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
 *  游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
 *  亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
 *  假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。
 * eg:
 *  输入：[5,3,4,5]
 *  输出：true
 * 解释：
 *  亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
 *  假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
 *  如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
 *  如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
 *  这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。
 *
 * 1. 动态规划
 *  dp[i][j] 表示当剩下的石子堆为下标 i 到下标 j 时，当前玩家与另一个玩家的石子数量之差的最大值。
 *  dp[i][j] = std::max(piles[i] - dp[i-1][j], piles[j] - dp[i][j-1]);
 */

#include <vector>

bool stoneGame(std::vector<int> &piles) {
    int n = piles.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        dp[i][i] = piles[i];
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            dp[i][j] = std::max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
    return dp[0][n - 1] >= 0;
}

#endif //ALGORITHM_STONEGAME_H

# 🎨 Painting Fence Problem

## 📌 Problem Statement

Given `N` fence posts and `K` colors, count the number of ways to paint the fence such that:

> ❗ No more than **2 adjacent posts** have the same color.

Return the answer modulo **10^9 + 7**.

---

## 🧠 Intuition

At every post, we only care about one thing:

* Is the current post painted **same as previous**?
* Or **different from previous**?

This leads to an efficient **Dynamic Programming (DP)** solution.

---

## 🔄 State Definition

We define two states:

* `same` → Last two posts have the **same color**
* `diff` → Last two posts have **different colors**

---

## 🟢 Base Cases

### 🔹 When `N = 1`

```
Total ways = K
```

---

### 🔹 When `N = 2`

```
same = K                  // Both posts have same color
diff = K * (K - 1)        // Both posts have different colors

Total = K * K
```

---

## 🔁 Transition (For N ≥ 3)

### ✅ Case 1: Current post has SAME color as previous

```
same = diff (previous)
```

👉 We can only make them same if previous two were different
(otherwise 3 same colors would violate the constraint)

---

### ✅ Case 2: Current post has DIFFERENT color

```
diff = (same + diff) * (K - 1)
```

---

## 📌 Final Recurrence

```
dp[i] = (dp[i-1] + dp[i-2]) * (K - 1)
```

---

## ❓ Why Multiply by `(K - 1)`?

When choosing a color for the current post:

* Total available colors = `K`
* One color (previous post’s color) is **not allowed**

```
Valid choices = K - 1
```

👉 So for every valid previous arrangement, we have `(K - 1)` choices.

---

## 🧪 Example

### Input:

```
N = 3, K = 2
```

### Calculation:

```
dp[1] = 2
dp[2] = 4

dp[3] = (dp[2] + dp[1]) * (K - 1)
      = (4 + 2) * 1
      = 6
```

---

## 💻 Code (C++)

```cpp
int solve(int n, int k) {
    const int MOD = 1e9 + 7;

    if (n == 1) return k;

    long long prev2 = k;           // dp[1]
    long long prev1 = 1LL * k * k; // dp[2]

    for (int i = 3; i <= n; i++) {
        long long curr = ((prev1 + prev2) % MOD * (k - 1)) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
```

---

## ⚡ Complexity

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(1)` (optimized)

---

## 🚀 Key Takeaways

* Convert constraints into **states (same/diff)**
* Use **DP recurrence** to avoid recomputation
* `(K - 1)` comes from **excluding one invalid color**
* Always think in terms of **choices per step**

---

## 📎 Tags

`Dynamic Programming` `DP` `Combinatorics` `Optimization`

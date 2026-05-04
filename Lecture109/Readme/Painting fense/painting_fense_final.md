<!-- ========================= HEADER ========================= -->

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?color=00F7FF&center=true&vCenter=true&lines=Painting+Fence+Problem;Dynamic+Programming+Made+Easy;Crack+Interviews+Like+a+Pro🚀;Understand+Logic+Deeply" />
</p>

<h1 align="center">🎨 Painting Fence Problem</h1>

<p align="center">
  <b>Dynamic Programming • Visual Intuition • Interview Ready</b><br>
  <i>Understand the logic, not just the formula 🚀</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/DP-Pattern-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Time-O(N)-green?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Space-O(1)-orange?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Level-Interview🔥-red?style=for-the-badge"/>
</p>

<p align="center">━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━</p>

---

# 📌 Problem Statement

### Given:

* 🪵 **`N` fence posts**
* 🎨 **`K` colors**

---

# 🎯 Objective

Paint the fence such that:

> ❗ **No more than 2 adjacent posts have the same color**

Return the number of valid ways modulo **10⁹ + 7**

---

# 🧠 Core Intuition

```text
Is it SAME as previous?
OR
Is it DIFFERENT from previous?
```

👉 Reduce problem into **2 states instead of N possibilities**

---

# 🔄 State Definition

| State | Meaning                              |
| ----- | ------------------------------------ |
| same  | Last two posts have SAME color       |
| diff  | Last two posts have DIFFERENT colors |

---

# 🟢 Base Cases

### 🔹 N = 1

```text
Total = K
```

---

### 🔹 N = 2

```text
same = K
diff = K * (K - 1)

Total = K * K
```

---

# 🎥 Dry Run Visualization

### 🧪 Example

```text
N = 3, K = 2
Colors = {0, 1}
```

---

## 🪵 Step 1

```text
[ _ ] → {0, 1}
Total = 2
```

---

## 🪵 Step 2

```text
00 (same)
01 (diff)
11 (same)
10 (diff)

same = 2
diff = 2
total = 4
```

---

## 🪵 Step 3

> ⚡ Observe transitions carefully

### 🔁 SAME

```text
01 → 011
10 → 100

same = 2
```

### 🔄 DIFF

```text
00 → 001
11 → 110
01 → 010
10 → 101

diff = 4
```

---

### 📊 Progress Visualization

```text
Step 1  ▓▓░░░░░░░░ 20%
Step 2  ▓▓▓▓░░░░░░ 40%
Step 3  ▓▓▓▓▓▓░░░░ 60%
Final   ▓▓▓▓▓▓▓▓▓▓ 100% ✅
```

---

### 📊 Final Answer

```text
Total = same + diff = 6 ✅
```

---

# 📊 Flow Logic

```text
dp[1] = K
dp[2] = K*K

for i = 3 → N:
  SAME = diff
  DIFF = (same + diff) * (K - 1)

  dp[i] = SAME + DIFF
```

---

# 🎬 Interview Thinking

### Step 1

```text
3 same consecutive NOT allowed ❌
```

### Step 2

```text
Only previous matters → use states
```

### Step 3

```text
same = diff
diff = (same + diff) * (K - 1)
```

### Step 4

```text
total = same + diff
```

---

# 📌 Final Formula

```text
dp[i] = (dp[i-1] + dp[i-2]) * (K - 1)
```

---

# ❓ Why (K - 1)?

```text
Total colors = K
Invalid = previous color

Valid = K - 1
```

---

# 💻 C++ Code

```cpp
int solve(int n, int k) {
    const int MOD = 1e9 + 7;

    if (n == 1) return k;

    long long prev2 = k;
    long long prev1 = 1LL * k * k;

    for (int i = 3; i <= n; i++) {
        long long curr = ((prev1 + prev2) % MOD * (k - 1)) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
```

---

# 🖥️ Execution Feel

```bash
> Initializing DP...
> Tracking SAME & DIFF...
> Avoiding invalid patterns...
> Final Answer = 6 ✅
```

---

# ⚡ Complexity

| Type  | Value |
| ----- | ----- |
| Time  | O(N)  |
| Space | O(1)  |

---

# 🚀 Key Takeaways

* 🔹 Think in **states**
* 🔹 Avoid brute force
* 🔹 Use previous results
* 🔹 Focus on transitions

---

<p align="center">
⭐ <b>If this helped you, star your repo!</b><br>
🧠 <i>Master patterns, not problems.</i>
</p>
